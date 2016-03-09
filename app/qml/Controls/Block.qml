import QtQuick 2.5
import "../Styles"

Rectangle {
    default property alias children: content.children

    color: AppStyle.borderColor

    Rectangle {
        anchors {
            fill: parent
            margins: 2
        }
        color: "#fff"

        Item {
            id: content

            anchors {
                fill: parent
                margins: 8
            }
        }
    }
}

