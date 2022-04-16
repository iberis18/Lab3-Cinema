import QtQuick 6.0
import QtQuick.Window 6.0
import QtQuick.Controls 6.0 // это версия библиотеки, содержащей Contol (аналоги виджетов) для версии Qt 5.6
import QtQuick.Layouts 6.0


Window {
    id: root
    modality: Qt.ApplicationModal  // окно объявляется модальным
    title: qsTr("Добавление информации о фильме")
    minimumWidth: 400
    maximumWidth: 400
    minimumHeight: 200
    maximumHeight: 200

    GridLayout {
        anchors { left: parent.left; top: parent.top; right: parent.right; bottom: buttonCancel.top; margins: 10 }
        columns: 2

        Label {
            Layout.alignment: Qt.AlignRight  // выравнивание по правой стороне
            text: qsTr("Название фильма:")
        }
        TextField {
            id: textName
            Layout.fillWidth: true
            placeholderText: qsTr("Введите название")
        }
        Label {
            Layout.alignment: Qt.AlignRight
            text: qsTr("Жанр:")
        }
        TextField {
            id: textGenre
            Layout.fillWidth: true
            placeholderText: qsTr("Введите жанр")
        }
        Label {
            Layout.alignment: Qt.AlignRight
            text: qsTr("Режиссер:")
        }
        TextField {
            id: textDirector
            Layout.fillWidth: true
            placeholderText: qsTr("Введите режиссера")
        }
        Label {
            Layout.alignment: Qt.AlignRight
            text: qsTr("Год выхода:")
        }
        TextField {
            id: textYear
            Layout.fillWidth: true
            placeholderText: qsTr("Введите год выхода")
        }
        Label {
            Layout.alignment: Qt.AlignRight
            text: qsTr("Возрастные ограничения:")
        }
        TextField {
            id: textAge
            Layout.fillWidth: true
            placeholderText: qsTr("Введите возрастные ограничения")
        }
    }

    Button {
        visible: {textName.length>0 && textGenre.length>0}
        anchors { right: buttonCancel.left; verticalCenter: buttonCancel.verticalCenter; rightMargin: 10 }
        text: qsTr("Добавить в список")
        width: 100
        onClicked: {
            root.hide()

            add(textName.text, textGenre.text, textDirector.text, textYear.text, textAge.text)
        }
    }
    Button {
        id: buttonCancel
        anchors { right: parent.right; bottom: parent.bottom; rightMargin: 10; bottomMargin: 10 }
        text: qsTr("Отменить")
        width: 100
        onClicked: {
             root.hide()
        }
    }

    // изменение статуса видимости окна диалога
    onVisibleChanged: {
      if (visible) {
          textName.text = ""
          textGenre.text = ""
          textDirector.text = ""
          textYear.text = ""
          textAge.text = ""
      }
    }
 }
