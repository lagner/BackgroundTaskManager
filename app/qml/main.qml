import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Window 2.2

Window {
    visible: true

    minimumWidth: 400
    minimumHeight: 600

    width: 400
    height:  650

    StackView {
        id: sceneManager
        anchors.fill: parent

        initialItem: Rectangle {
            color: "black"
        }

        Component.onCompleted: sceneManager.push(Qt.resolvedUrl("qrc:///qml/index.qml"))
    }
}

