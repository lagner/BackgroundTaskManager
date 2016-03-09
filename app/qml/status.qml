import QtQuick 2.5
import QtQuick.Controls 1.4 as QtControls
import QtQuick.Dialogs 1.2
import "Controls"
import "Styles"


Page {
    id: statusPage
    title: qsTr("Status page")

    Column {
        anchors.fill: parent
        spacing: AppStyle.margin

        Block {
            id: progressBlock

            width: parent.width
            height: 100

            Column {
                anchors.fill: parent
                spacing: AppStyle.margin

                Row {
                    width: parent.width
                    height: 70
                    spacing: AppStyle.margin

                    CounterTile {
                        height: parent.height
                        text: qsTr("Lines:")
                        value: Context.processedLines
                    }

                    Rectangle {
                        width: 1
                        height: parent.height
                        color: AppStyle.grey
                    }

                    CounterTile {
                        height: parent.height
                        text: qsTr("Words:")
                        value: Context.uniqueWords
                    }
                }

            }

            ProgressBar {
                width: parent.width
                height: 4
                anchors.bottom: parent.bottom

                maximumValue: 100
                value: Context.progress
            }
        }

        ListView {
            x: AppStyle.margin
            width: parent.width - 2*AppStyle.margin
            height: parent.height - progressBlock.height - AppStyle.margin
            clip: true

            model: Context.mentions

            delegate: Component {
                ListItemDelegate {
                    keyText: model.word
                    valueText: model.amount
                }
            }
        }
    }

    QtControls.Button {
        id: backButton
        width: 64
        height: 64

        anchors {
            leftMargin: 24
            bottomMargin: 24
            left: parent.left
            bottom: parent.bottom
        }
        text: qsTr("Back")

        onClicked: {
            Context.cancelProcessing();
            sceneManager.pop();
        }
    }
}
