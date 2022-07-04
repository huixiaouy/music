#include "widget.h"
#include "ui_widget.h"
#include <QFileDialog>
#include <QDebug>
#include <QFileInfo>
#include <QFile>
#include <QPixmap>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowTitle("我的音乐播放器");
    m_player = new QMediaPlayer;
    m_playlist = new QMediaPlaylist;
    m_player->setPlaylist(m_playlist);
    ui->playbackMode->setText("顺序播放");
    m_playlist->setPlaybackMode(QMediaPlaylist::PlaybackMode::Sequential);
    connect(m_player,&QMediaPlayer::positionChanged,this,&Widget::handPlayerPositionChanged);

    connect(m_player,&QMediaPlayer::stateChanged,this,&Widget::handplayState);
    connect(m_playlist,&QMediaPlaylist::currentMediaChanged,this,&Widget::handlePlaylistCurrentMediaChanged);

    connect(m_playlist,&QMediaPlaylist::playbackModeChanged,this,&Widget::handplaybackModeChanged);

    m_timer = new QTimer(this);
    connect(m_timer,&QTimer::timeout,this,&Widget::handTimeout);
    m_timer->start(100);

    ui->showlrcWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
    ui->showlrcWidget->setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
    ui->showlrcWidget->setStyleSheet("background-color:transparent");
    ui->showlrcWidget->setFrameShape(QListWidget::NoFrame);

    ui->playlistWidget->setStyleSheet("background-color:transparent");
    ui->playlistWidget->setFrameShape(QListWidget::NoFrame);
    if(initDatebase())
    {
        getPlaylistFromSql();
    }
}

Widget::~Widget()
{
    for(auto item : m_currenplaylist)
    {
        delete item;
    }
    delete m_timer;
    delete m_player;

    delete m_playlist;
      destoryDatebase();
    delete ui;
}
//读取歌词
void Widget:: readlrcFilePath(const QString &lrcFilePath)
{
    m_lrc.clear();
    QString line;  //存放每一行的内容
    QStringList lineContents;  //存放分割“]”的内容
    QStringList timeContents;   //存放分割“：”的内容
     qDebug() << lrcFilePath;
    QFile file(lrcFilePath);
    if(file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        
        QTextStream textStream(&file);
        while (!textStream.atEnd()) {
            line = textStream.readLine();
            if(!line.isEmpty())
            {
            lineContents = line.split("]");
            timeContents = lineContents[0].split(":");
            int min = timeContents[0].mid(1).toInt();
            double sec = timeContents[1].toDouble();
            m_lrc.insert((min * 60 + sec) * 1000,lineContents[1]);

            lineContents.clear();
            timeContents.clear();
            }
        }
    }


}

void Widget::updatelrcAll()
{
   ui->showlrcWidget->clear();
   if(!m_lrc.isEmpty())
   {
       for(auto text : m_lrc.values())
       {
           
           QListWidgetItem *item = new QListWidgetItem(text);
           ui->showlrcWidget->addItem(item);
       }
   }
   else {
       qDebug() << "当前歌曲无歌词";
   }
}

void Widget::updatelrcOnTime()
{
    if(!m_lrc.isEmpty())
    {
        if(ui->showlrcWidget->currentRow() == -1)
        {
            ui->showlrcWidget->setCurrentRow(0);
        }
        else
        {
            int currentRow = ui->showlrcWidget->currentRow();  //获取歌词当前行
            qint64 playPosition = m_player->position();        //获取当前播放位置
            QList<qint64> lrcPositions = m_lrc.keys();         //获得所有歌词时间

            if(playPosition < lrcPositions[currentRow])
            {
                while (currentRow > 0)
                {
                  currentRow--;
                  if(lrcPositions[currentRow] < playPosition)
                  {
                      break;
                  }
                }
            }
            else if (playPosition > lrcPositions[currentRow])
            {
                while (currentRow < lrcPositions.size() - 1)
                {

                ++currentRow;
                if(playPosition < lrcPositions[currentRow])
                {
                   --currentRow;
                    break;
                }
                }

            }
            QListWidgetItem *item = ui->showlrcWidget->item(currentRow);
            ui->showlrcWidget->setCurrentItem(item);
            ui->showlrcWidget->scrollToItem(item,QAbstractItemView::PositionAtCenter);
            return;
        }
    }
}

void Widget::getSongInfoFronMP3File(const QString &filepath)
{
    qDebug() << "MP3名字：" << filepath;

    QFile file(filepath);
     QString name,artisr,album;
    if(file.open(QIODevice::ReadOnly | QIODevice::Text))
    {

        int len = file.size();
        file.seek(len - 128);
        char infoArray[128];
        if(file.read(infoArray,sizeof (infoArray)) > 0)
        {
            QString TAG = QString::fromLocal8Bit(infoArray,3);
            qDebug() << "tag:" << TAG;
            name = QString::fromLocal8Bit(infoArray+3,30);
            artisr = QString::fromLocal8Bit(infoArray+33,30);
            album = QString::fromLocal8Bit(infoArray+63,30);
            qDebug() << "歌手名字：" << artisr;
            name.truncate(name.indexOf(QChar::Null));
            artisr.truncate(artisr.indexOf(QChar::Null));
            album.truncate(album.indexOf(QChar::Null));
            qDebug() << "歌曲名字：" << name;
            qDebug() << "歌手名字：" << artisr;
        }
        else
        {
            qDebug() << "获取MP3歌曲信息失败";
        }
        file.close();
    }
    else
    {
            qDebug() << "打开MP3歌曲信息失败";
    }
    Song *song = new Song(filepath,name,artisr,album);
    addSongsToSqlPlaylist(*song);
    m_currenplaylist.insert(filepath,song);


}

bool Widget::initDatebase()
{
    return m_datebase->getlentance()->init();
}

void Widget::getPlaylistFromSql()
{
    QList<Song*> songsResult;
    bool ret = m_datebase->getlentance()->querySongs(songsResult);
    if(ret)
    {
        for (int i = 0;i < songsResult.size();i++)
        {
            m_currenplaylist.insert(songsResult[i]->url().toString(),songsResult[i]);
            QListWidgetItem *item = new QListWidgetItem();
            item->setText(songsResult[i]->name() + "-" + songsResult[i]->artist());
            ui->playlistWidget->addItem(item);
            m_playlist->addMedia(songsResult[i]->url());
        }
    }
}

void Widget::addSongsToSqlPlaylist(const Song &song)
{
    bool ret = m_datebase->getlentance()->addSong(song);
    if(ret)
    {
        qDebug() << "歌曲添加数据库成功";
    }
    else {
         qDebug() << "歌曲添加数据库失败";
    }
}

//添加歌曲槽函数
void Widget::on_addmusic_clicked()
{
    QStringList files = QFileDialog::getOpenFileNames(this,tr("添加音乐"),QString(),tr("音频文件(*.mp3)"));

    for(auto file : files)
    {
//        m_player->setMedia(QMediaContent(file));
//        ui->showName->setText(QDir(file).dirName());
        m_playlist->addMedia(QMediaContent(file));
        QListWidgetItem *item = new QListWidgetItem;
        item->setText(QFileInfo(QDir(file).dirName()).baseName());
                ui->playlistWidget->addItem(item);
                getSongInfoFronMP3File(file);
    }
}
//调用播放器播放功能
void Widget::on_playButton_clicked()
{
 //   m_player
  //  m_player->play();
    if(m_player->state() != m_player->PlayingState)
    {
          m_player->play();
    }
    else
    {
        m_player->pause();
    }
}
//调用暂停功能
void Widget::on_pauseButton_clicked()
{
    m_player->pause();
}
//进度条移动调节播放进度
void Widget::on_progress_sliderReleased()
{
   m_player->setPosition(double(ui->progress->value()) / ui->progress->maximum() * m_player->duration());

}
//显示播放进度
void Widget::handPlayerPositionChanged(qint64 position)
{
    qint64 duration = m_player->duration();
    double progressVallue = (double)position / duration * 99;
    ui->progress->setValue(progressVallue);

    char time[16] = {0};

    snprintf(time,sizeof(time),"%02lld:%02lld/%02lld:%02lld",
             position/60000,
             position%60000/1000,
             m_player->duration()/60000,
             m_player->duration()%60000/1000);
    ui->showProgress->setText(time);
}
//获取歌曲路径   名字
void Widget::handlePlaylistCurrentMediaChanged(const QMediaContent &content)
{
//    QString songName = QFileInfo(content.canonicalUrl().fileName()).baseName();
//    ui->showName->setText(songName);
     auto item = m_currenplaylist.begin();
     while (item != m_currenplaylist.end())
     {
            qDebug () << "path:" << item.key();
            if(QUrl(item.key()).path() == QUrl(content.canonicalUrl().toString()).path())
            {
                qDebug() << "It is the file: " << item.key() << ", " << content.canonicalUrl().toString();

                ui->showName->setText(item.value()->name() + "-" + item.value()->artist());
                break;
            }
            else {
                qDebug() << "这不是一个mp3文件";
            }
            item++;
     }
    QString mediaPath = content.canonicalUrl().path();

    QString lrcFilePath = mediaPath.replace(".mp3",".lrc");
    if(QFileInfo(lrcFilePath).isFile())
    {
        qDebug() <<"这是个文件";
        readlrcFilePath(lrcFilePath);
        updatelrcAll();
    }
    else {
        qDebug() << "这不是个文件";
    }

}

void Widget::on_playbackMode_clicked()
{
    QMediaPlaylist::PlaybackMode mode = m_playlist->playbackMode();
    int nextMode = (mode + 1) % 5;
    m_playlist->setPlaybackMode(QMediaPlaylist::PlaybackMode(nextMode));
}

void Widget::handplaybackModeChanged(QMediaPlaylist::PlaybackMode mode)
{
    QStringList modeIconlist = {":/images/currentItemOnce.png",
                                ":/images/currentItemOnce.png",
                                ":/images/sequential.png", ":/images/loop.png",
                                ":/images/random.png"};
    ui->playbackMode->setIcon(QPixmap(modeIconlist[mode]));
}

void Widget::on_previousButton_clicked()
{
    m_playlist->previous();
}

void Widget::on_nextButton_clicked()
{
    m_playlist->next();
}

void Widget::handTimeout()
{
    updatelrcOnTime();
}

void Widget::handplayState(QMediaPlayer::State state)
{
    if(state == QMediaPlayer::PlayingState)
    {
        ui->playButton->setIcon(QPixmap(":/images/play.png"));
    }
    else
    {
        ui->playButton->setIcon(QPixmap(":/images/pause.png"));
    }
}


void Widget::on_clearButton_clicked()
{
    m_playlist->clear();
    ui->playlistWidget->clear();
    clearSqlPlaylist();
}

void Widget::clearSqlPlaylist()
{
    m_datebase->getlentance()->clearSongs();
}

void Widget::destoryDatebase()
{
    m_datebase->getlentance()->destroy();
}
