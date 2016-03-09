import QtQuick 2.5
import "../Styles"

Rectangle {
    property alias keyText: textKey.text
    property alias valueText: textValue.text

    width: parent.width
    height: 2*AppStyle.lineHeight

    color: "#fff"

    Row {
        anchors {
            fill: parent
            leftMargin: AppStyle.margin
            rightMargin: AppStyle.margin
        }

        Label {
            id: textKey
            width: parent.width * .75
            height: parent.height
            color: AppStyle.fontColorLight

            font.pixelSize: AppStyle.fontSizeSmall
        }

        Label {
            id: textValue

            width: parent.width * .25
            height: parent.height

            horizontalAlignment: Text.AlignRight
            font.pixelSize: AppStyle.fontSizeSmall
        }
    }

    Rectangle {
        width: parent.width
        height: 2
        anchors.bottom: parent.bottom

        color: AppStyle.darkGrey
    }
}

