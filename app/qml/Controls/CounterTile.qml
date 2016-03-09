import QtQuick 2.5
import "../Styles"


Item {
    property alias text: textLabel.text
    property alias value: valueLabel.text

    implicitWidth: 120

    Column {
        anchors {
            fill: parent
            leftMargin: AppStyle.margin
        }

        Label {
            id: textLabel
            width: parent.width
            height: AppStyle.lineHeight

            color: AppStyle.fontColorLight
            font.pixelSize: AppStyle.fontSizeSmall
        }

        Label {
            id: valueLabel
            width: parent.width
            height: AppStyle.lineHeight
            font.bold: true
        }
    }
}

