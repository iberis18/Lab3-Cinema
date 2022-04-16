import QtQuick 6.0
import QtQuick.Window 6.0
import QtQuick.Controls 6.0// это версия библиотеки, содержащей Contol (аналоги виджетов) для версии Qt 5.6
import QtQuick.Layouts 6.0

Window {
    visible: true
    width: 800
    height: 550
    title: qsTr("Справочник фильмов")

    // объявляется системная палитра
    SystemPalette {
          id: palette;
          colorGroup: SystemPalette.Active
       }

    Rectangle{
        anchors.left: parent.left
        anchors.top: parent.top
        anchors.right: parent.right
        anchors.bottom: butAdd.top
        anchors.bottomMargin: 8
        border.color: "SteelBlue"


    ScrollView {
        anchors.fill: parent
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 15
        //flickableItem.interactive: true  // сохранять свойство "быть выделенным" при потере фокуса мыши

        ListView {
            id: movList
            anchors.fill: parent
            model: movieModel // назначение модели, данные которой отображаются списком
            delegate: DelegateForMovie{}
            clip: true //
            activeFocusOnTab: true  // реагирование на перемещение между элементами ввода с помощью Tab
            focus: true  // элемент может получить фокус
        }
    }
    }

    Button {
        id: butAdd
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 8
        anchors.rightMargin: 8
        anchors.right:butEdit.left
        text: "Добавить"
        width: 100
        onClicked: windowAdd.show()
    }

    Button {
        id: butEdit
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 8
        anchors.right: butDel.left
        anchors.rightMargin: 8
        text: "Редактировать"
        width: 100
        onClicked: {
            var nameMov = movList.currentItem.movieData.nameOfMovie
            var genreMov = movList.currentItem.movieData.genreOfMovie
            var directorMov = movList.currentItem.movieData.directorOfMovie
            var yearMov = movList.currentItem.movieData.yearOfMovie
            var ageMov = movList.currentItem.movieData.ageOfMovie

            windowEdit.execute(nameMov, genreMov, directorMov, yearMov, ageMov, movList.currentIndex)
        }
    }

    Button {
        id: butDel
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 8
        anchors.right:parent.right
        anchors.rightMargin: 8
        text: "Удалить"
        width: 100
        enabled: movList.currentIndex >= 0
        onClicked: del(movList.currentIndex)
    }

        Label {
            id: labelArea
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 12
            anchors.left: parent.left
            //anchors.right: butAdd.left
            anchors.rightMargin: 8
            anchors.leftMargin: 8
            Layout.alignment: Qt.AlignRight  // выравнивание по правой стороне
            text: qsTr("Введите жанр:")
        }
        TextField {
            id: textCountGenre
            Layout.fillWidth: true
            placeholderText: qsTr("")
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 10
            anchors.leftMargin: 8
            anchors.left: labelArea.right
            anchors.rightMargin: 8
        }
        Button {
            id: butCount
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 8
            //anchors.right:parent.right
            anchors.left: textCountGenre.right
            anchors.leftMargin: 8
            text: "Подсчитать"
            width: 100
            enabled: textCountGenre.text != ""
            onClicked: windowAnswer.countMovies(textCountGenre.text)
        }

    DialogForAdd {
        id: windowAdd
    }
    DialogForEdit {
        id: windowEdit
    }
    DialogForAnswer {
        id: windowAnswer
    }
}

