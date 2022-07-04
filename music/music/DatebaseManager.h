#ifndef SQL_H
#define SQL_H
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include "song.h"
class DatebaseManager
{
public:
    static DatebaseManager *getlentance()
    {
        static DatebaseManager manager;
        return  &manager;
    }
    bool init();
    bool initSongs();
    void destroy();
    bool addSong(const Song &song);
    bool querySongs(QList<Song*> &songs);
    bool clearSongs();
private:
    QString m_datebaseName = "myMusic.db";
    QSqlDatabase m_sqlDatebase;
    DatebaseManager()
    {
        m_sqlDatebase = QSqlDatabase::addDatabase("QSQLITE");
    }

};

#endif // SQL_H
