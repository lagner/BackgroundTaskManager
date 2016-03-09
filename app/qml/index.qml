import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Dialogs 1.2
import "Controls"
import "Styles"


Page {
    id: indexPage
    title: qsTr("Select file")

    Block {
        width: parent.width
        height: 100

        Column {
            anchors.fill: parent
            spacing: AppStyle.margin

            Row {
                width: parent.width
                height: AppStyle.lineHeight

                spacing: AppStyle.margin

                FileDialog {
                    id: fileDialog
                    title: qsTr("Please select a file")
                    selectMultiple: false
                }

                TextField {
                    width: parent.width - AppStyle.margin - selectFileBtn.width
                    height: parent.height
                    readOnly: true
                    placeholderText: qsTr("select file to process")
                    text: fileDialog.fileUrl
                }

                Button {
                    id: selectFileBtn
                    width: 96
                    height: parent.height
                    text: qsTr("select file")
                    onClicked: fileDialog.open()
                }
            }

            Row {
                width: parent.width
                height: AppStyle.lineHeight
                layoutDirection: Qt.RightToLeft

                Button {
                    id: runBtn
                    width: 96
                    height: parent.height
                    text: qsTr("Run processing")

                    onClicked: {
                        if (!fileDialog.fileUrl.toString()) {
                            return;
                        }

                        Context.runFileProcessing(fileDialog.fileUrl);
                        sceneManager.push(Qt.resolvedUrl("qrc:///qml/status.qml"));
                    }
                }
            }
        }
    }
}
