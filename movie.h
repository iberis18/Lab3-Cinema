#ifndef MOVIE_H
#define MOVIE_H
#include "QString"
//#include <QObject>

class Movie /*public QObject*/
{
    //Q_OBJECT

public:
    Movie();
    virtual ~Movie();
    void setID(const QString id);
    void setName(const QString name);
    void setGenre(const QString genre);
    void setDirector(const QString director);
    void setYear(const QString year);
    void setAge(const QString age);

    QString getID() const;
    QString getName() const;
    QString getGenre() const;
    QString getDirector() const;
    QString getYear() const;
    QString getAge() const;

private:
    QString id;
    QString name;
    QString genre;
    QString director;
    QString year;
    QString age;
};

#endif // MOVIE_H
