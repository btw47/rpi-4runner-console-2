import QtQuick 2.11
import QtQuick.Controls 2.4

Page {
    id: page
    width: 1024
    height: 600
    property alias element7: element7
    property alias slider: slider
    property alias element2: element2
    property alias element1: element1
    property alias element: element

    header: Label {
        //        text: qsTr("Lights")
        font.pixelSize: Qt.application.font.pixelSize * 2
        padding: 10
    }

    Column {
        anchors.left: parent.left
        anchors.leftMargin: 600
        anchors.top: parent.top
        anchors.topMargin: 150

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

        Switch {
            id: element7
            text: qsTr("Hood")
        }
    }

    Column {
        x: 269
        anchors.right: parent.right
        anchors.rightMargin: 600
        anchors.top: parent.top
        anchors.topMargin: 150
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

    Text {
        id: element5
        x: 469
        width: 89
        height: 21
        color: "#d3d7cf"
        text: qsTr("Exterior")
        anchors.top: parent.top
        anchors.topMargin: 85
        anchors.horizontalCenterOffset: 0
        anchors.horizontalCenter: parent.horizontalCenter
        font.pixelSize: 24
    }

    Text {
        id: element6
        x: 256
        y: 312
        width: 89
        height: 21
        color: "#d3d7cf"
        text: qsTr("Interior")
        anchors.verticalCenterOffset: 50
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenterOffset: 1
        anchors.horizontalCenter: parent.horizontalCenter
        font.pixelSize: 24
    }

    Slider {
        id: slider
        x: 201
        y: 357
        anchors.verticalCenterOffset: 150
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenterOffset: 1
        anchors.horizontalCenter: parent.horizontalCenter
        value: 0
    }
}

/*##^##
Designer {
    D{i:2;anchors_x:649;anchors_y:105}D{i:8;anchors_y:114}D{i:15;anchors_y:70}
}
##^##*/

