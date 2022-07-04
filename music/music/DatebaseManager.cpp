#include "DatebaseManager.h"
#include <QDebug>

bool DatebaseManager::init()
{
    m_sqlDatebase.setDatabaseName(m_datebaseName);
    bool ret = m_sqlDatebase.open();
    if(ret)
    {
        ret = initSongs();
        if(!ret)
        {
           qDebug() << "初始化歌单表失败";
           destroy();
        }
    }
    else
    {
        qDebug() << "数据库打开失败";
    }
    return ret;
}

bool DatebaseManager::initSongs()
{
    bool ret = m_sqlDatebase.isOpen();
    if(ret)
    {
        QSqlQuery query;
        ret = query.exec("create table if not exists songs("
                  "id integer primary key,"
                   "url text not null,"
                   "name text not null,"
                   "artist text not null,"
                   "album text not null);");
        qDebug() << "******************";
        if(!ret)
        {
            qDebug() << "歌曲表添加失败" << query.lastError();
        }
    }
    else
    {
        qDebug() << "歌曲表添加失败,数据库打开失败";
    }
    return ret;
}

void DatebaseManager::destroy()
{
    if(m_sqlDatebase.isOpen())
    {
        m_sqlDatebase.close();
    }
}

bool DatebaseManager::addSong(const Song &song)
{
    bool ret = m_sqlDatebase.isOpen();
    if(ret)
    {
        QSqlQuery query;
         qDebug() << song.url();
         qDebug() << song.name();
         qDebug() << song.artist();
         qDebug() << song.album();

        query.prepare("insert into songs(url,name,artist,album)"
                      "values(:url,:name,:artist,:album);");
        query.bindValue(":url",song.url());
        query.bindValue(":name",song.name());
        query.bindValue(":artist",song.artist());
        query.bindValue(":album",song.album());

        ret = query.exec();
        if(!ret)
        {

            qDebug() << "添加歌曲失败：" << query.lastError();
        }
    }
    else
    {
        qDebug() << "添加歌曲失败,数据库打开失败";
    }
    return  ret;
}

bool DatebaseManager::querySongs(QList<Song *> &songs)
{
    bool ret = m_sqlDatebase.isOpen();
    if(ret)
    {
        QSqlQuery query;
        ret = query.exec("select url,name,artist,album from songs");
        if(ret)
        {
            QString url,name,artist,album;
            Song *song = nullptr;
            while (query.next())
            {
                url = query.value("url").toString();
                name = query.value("name").toString();
                artist = query.value("artist").toString();
                album = query.value("album").toString();
                song = new Song(url,name,artist,album);
                songs.push_back(song);            }
        }
        else {
            qDebug() << "查询1歌曲失败：" << query.lastError();
        }
    }
    else
    {
        qDebug() << "查询歌曲失败,数据库打开失败";
    }
    return ret;
}

bool DatebaseManager::clearSongs()
{
    bool ret = m_sqlDatebase.isOpen();
    if(ret)
    {
        QSqlQuery query;
        ret = query.exec("delete from songs");
        if(!ret) {
            qDebug() << "清除歌曲失败：" << query.lastError();
        }
    }
    else
    {
        qDebug() << "清除歌曲失败,数据库打开失败";
    }
    return ret;
}
