#ifndef WIDGET_H
#define WIDGET_H
#include <QMediaPlayer>
#include <QWidget>
#include <QMediaPlaylist>
#include <QTimer>
#include "song.h"
#include "DatebaseManager.h"
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void readlrcFilePath(const QString &lrcFilePath);
    void updatelrcAll();
    void updatelrcOnTime();
    void getSongInfoFronMP3File(const QString &filepath);
    bool initDatebase();
    void getPlaylistFromSql();
    void addSongsToSqlPlaylist(const Song &song);
    void clearSqlPlaylist();
    void destoryDatebase();

private slots:
    void on_addmusic_clicked();

    void on_playButton_clicked();

    void on_pauseButton_clicked();

    void on_progress_sliderReleased();

    void handPlayerPositionChanged(qint64 position);

    void handlePlaylistCurrentMediaChanged(const QMediaContent& content);

    void on_playbackMode_clicked();

    void handplaybackModeChanged(QMediaPlaylist::PlaybackMode mode);


    void on_previousButton_clicked();

    void on_nextButton_clicked();

    void handTimeout();

    void handplayState(QMediaPlayer::State state);

    void on_addmusic_2_clicked();

    void on_clearButton_clicked();



private:
    Ui::Widget *ui;
    QMediaPlayer *m_player;
    QMediaPlaylist *m_playlist;
    QMap<qint64,QString> m_lrc;
    QTimer *m_timer;
    DatebaseManager *m_datebase;
    QMap<QString,Song*> m_currenplaylist;
};
#endif // WIDGET_H
