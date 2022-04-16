#ifndef MOVIELIST_H
#define MOVIELIST_H

#include <QAbstractListModel>
#include <QVariant>
#include <QList>
#include <QModelIndex>
#include <QItemSelectionModel>
#include "movie.h"

class MovieList : public QAbstractListModel
{
    Q_OBJECT

    Q_PROPERTY(QAbstractListModel* movieModel READ getModel CONSTANT)  /* первый параметр - тип свойства (property)
                                                                     второй параметр - имя свойства, по которому будем обращаться к реальной модели в qml-файле
                                                                     третий параметр - метод С++ для получения значения свойства (получим саму модель)
                                                                     CONSTANT - qml получит свойство однократно, и в процессе работы это свойство изменяться не будет */
private:
    QList<Movie> listOfMovies; // непосредственно данные
    QAbstractListModel *getModel();

public:
    MovieList(QObject *parent = nullptr);
    ~MovieList() override;

    // количество колонок
    int rowCount(const QModelIndex& parent = QModelIndex()) const override;

    // возвращение данных модели по указанному индексу и роли
    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const override;

    enum ResentRoles {
            name = Qt::DisplayRole,
            genre = Qt::DisplayRole + 1,
            director = Qt::DisplayRole + 2,
            year = Qt::DisplayRole + 3,
            age = Qt::DisplayRole + 4
       };

    QHash<int, QByteArray> roleNames() const override;

    Q_INVOKABLE QString count(const QString& textSelArea);

    Q_INVOKABLE void add(const QString& nameMov, const QString& genreMov, const QString& directorMov, const QString& yearMov, const QString& ageMov);  // макрос указывает, что к методу можно обратиться из QML
    Q_INVOKABLE void del(const int index);
    Q_INVOKABLE void edit(const QString& nameMov, const QString& genreMov, const QString& directorMov, const QString& yearMov, const QString& ageMov, const int index);
};

#endif // MOVIELIST_H
