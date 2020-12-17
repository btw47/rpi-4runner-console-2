import QtQuick 2.11
import QtQuick.Controls 2.4

Page {
    width: 600
    height: 400
    property alias element2: element2
    property alias element1: element1
    property alias element: element

    header: Label {
        text: qsTr("Lights")
        font.pixelSize: Qt.application.font.pixelSize * 2
        padding: 10
    }

    Column {
        x: 352
        y: 33

        Row {
            Text {
                id: element4
                color: "#d3d7cf"
                text: qsTr("Other")
                font.pixelSize: Qt.application.font.pixelSize * 1.5
            }
        }

        Row {
            Switch {
                id: element2
                text: qsTr("Ditch Lights")
            }
        }
    }

    Column {
        x: 112
        y: 33
        Row {
            Text {
                id: element3
                color: "#d3d7cf"
                text: qsTr("Light Bar (Front)")
                font.pixelSize: Qt.application.font.pixelSize * 1.5
            }
        }

        Row {
            spacing: 0
            Switch {
                id: element
                width: 100
                text: qsTr("White")
            }
        }

        Row {
            Switch {
                id: element1
                text: qsTr("Ambers")
            }
        }
    }
}
