#include "movielist.h"
#include <QDebug>
#include <QMessageBox>
#include <QWidget>
#include <QApplication>

MovieList::MovieList(QObject* parent):QAbstractListModel(parent)
{
    add("Солярис","Фантастика", "Андрей Тарковский",  "1972", "12+");
    add("Список Шиндлера","Драма", "Стивен Спилберг", "1993", "16+");
    add("Молчание ягнят","Триллер", "Джонатан Демми", "1991", "18+");
}

MovieList::~MovieList()
{

}

int MovieList::rowCount(const QModelIndex&) const
{
    return listOfMovies.size();
}


QVariant MovieList::data(const QModelIndex &index, int role) const
{
    if (index.row() < 0 || index.row() >= listOfMovies.size())
            return QVariant();
      {
        switch (role) {
                case name:
                    return QVariant(listOfMovies.at(index.row()).getName());
                case genre:
                    return QVariant(listOfMovies.at(index.row()).getGenre());
                case director:
                    return QVariant(listOfMovies.at(index.row()).getDirector());
                case year:
                    return QVariant(listOfMovies.at(index.row()).getYear());
                case age:
                    return QVariant(listOfMovies.at(index.row()).getAge());

                default:
                    return QVariant();
            }

    }
}

QHash<int, QByteArray> MovieList::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[name] = "nameOfMovie";
    roles[genre] = "genreOfMovie";
    roles[director] = "directorOfMovie";
    roles[year] = "yearOfMovie";
    roles[age] = "ageOfMovie";
       return roles;
}

void MovieList::add(const QString& nameMov, const QString& genreMov, const QString& directorMov, const QString& yearMov, const QString& ageMov){
     Movie move;
     move.setName(nameMov);
     move.setGenre(genreMov);
     move.setDirector(directorMov);
     move.setYear(yearMov);
     move.setAge(ageMov);

    beginInsertRows(QModelIndex(),listOfMovies.size(),listOfMovies.size());
    listOfMovies.append(move);  //добавление в конец списка
    endInsertRows();

}

QAbstractListModel* MovieList::getModel(){
    return this;
}

void MovieList::del(const int index){

     if (index >= 0 && index < listOfMovies.size())
     {

    // сообщение модели о процессе удаления данных
         beginRemoveRows(QModelIndex(), index, index);
        listOfMovies.removeAt(index);
              endRemoveRows();
     }
     else qDebug() << "Error index";

}

QString MovieList::count(const QString& textCountGenre){
    int count = 0;
    for(int i = 0; i < listOfMovies.size(); i++)
        if(listOfMovies[i].getGenre() == textCountGenre)
            count++;
    QString c = QString::number(count);
    return c;
}

void MovieList::edit(const QString& nameMov, const QString& genreMov, const QString& directorMov, const QString& yearMov, const QString& ageMov, const int index) {
     if(index >= 0 && index < listOfMovies.size() )
     {
        auto& currentMovie = listOfMovies[index];
        if (currentMovie.getName().compare(nameMov)!=0 || currentMovie.getGenre() != genreMov || currentMovie.getDirector() != directorMov
                || currentMovie.getYear() != yearMov || currentMovie.getAge() != ageMov)
        {
            currentMovie.setName(nameMov);
            currentMovie.setDirector(directorMov);
            currentMovie.setGenre(genreMov);
            currentMovie.setYear(yearMov);
            currentMovie.setAge(ageMov);

            auto modelIndex = createIndex(index, 0);
            emit dataChanged(modelIndex, modelIndex);
            qDebug() << listOfMovies[index].getAge();
        }

     }
      else qDebug() << "Error index";
}
