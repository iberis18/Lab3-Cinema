#include "movie.h"

Movie::Movie()
{
}

void Movie::setID(const QString i)
{
    id = i;
}
void Movie::setName(const QString n)
{
    name = n;
}
void Movie::setGenre(const QString g)
{
    genre = g;
}
void Movie::setDirector(const QString d)
{
    director = d;
}
void Movie::setYear(const QString y)
{
    year = y;
}
void Movie::setAge(const QString a)
{
    age = a;
}

QString Movie::getID() const
{
    return id;
}
QString Movie::getName() const
{
    return name;
}
QString Movie::getGenre() const
{
    return genre;
}
QString Movie::getDirector() const
{
    return director;
}
QString Movie::getYear() const
{
    return year;
}
QString Movie::getAge() const
{
    return age;
}

 Movie::~Movie()
{
}
