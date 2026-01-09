import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import App 1.0

ApplicationWindow {
    visible: true
    width: 400
    height: 600
    title: "Qt6 Notes App"

    NoteModel {
        id: noteModel
    }

    ColumnLayout {
        anchors.fill: parent
        anchors.margins: 10
        spacing: 10

        Label {
            text: "My Notes"
            font.pixelSize: 24
            font.bold: true
            Layout.alignment: Qt.AlignHCenter
        }

        ListView {
            id: listView
            Layout.fillWidth: true
            Layout.fillHeight: true
            clip: true
            model: noteModel

            delegate: Rectangle {
                width: ListView.view.width
                height: 80
                color: "#f9f9f9"
                border.color: "#e0e0e0"
                radius: 5

                MouseArea {
                    anchors.fill: parent
                    onClicked: noteModel.removeNote(index)
                }

                ColumnLayout {
                    anchors.centerIn: parent
                    width: parent.width - 20
                    
                    // Accessing data using role names
                    Text { 
                        text: model.title
                        font.bold: true 
                    }
                    Text { 
                        text: model.content
                        color: "#666" 
                    }
                }
            }
        }

        RowLayout {
            Layout.fillWidth: true

            TextField {
                id: titleInput
                placeholderText: "Title"
                Layout.preferredWidth: 100
            }

            TextField {
                id: contentInput
                placeholderText: "Content"
                Layout.fillWidth: true
            }

            Button {
                text: "Add"
                onClicked: {
                    if (titleInput.text !== "") {
                        noteModel.addNote(titleInput.text, contentInput.text)
                        
                        titleInput.text = ""
                        contentInput.text = ""
                    }
                }
            }
        }
    }
}