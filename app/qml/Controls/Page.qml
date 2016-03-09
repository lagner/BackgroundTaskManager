import QtQuick 2.5
import "../Styles"


Item {
    default property alias children: body.children

    property alias title: titleText.text

    id: page

    Column {
        anchors.fill: parent

        Rectangle {
            id: header

            width: parent.width
            height: 60
            color: AppStyle.blue

            Label {
                id: titleText
                anchors {
                    fill: parent
                    margins: 16
                }
                color: "white"
                font.pixelSize: AppStyle.fontSizeBig
            }
        }

        Rectangle {
            id: body
            color: AppStyle.grey

            width: parent.width
            height: parent.height - header.height
        }
    }
}

