#ifndef SONG_H
#define SONG_H
#include<QString>
#include<QUrl>

class Song
{
public:
    Song(){}
    ~Song(){}
    Song(const QUrl &url):m_url(url){}
    Song(const QUrl &url,const QString &name,const QString &artist,const QString &album)
        :m_url(url),m_name(name),m_artist(artist),m_album(album){}
    const QUrl &url()const;
    const QString &name()const;
    const QString &artist()const;
    const QString &album()const;

private:
    QUrl m_url;
    QString m_name;
    QString m_artist;
    QString m_album;

};

#endif // SONG_H
