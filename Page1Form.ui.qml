import QtQuick 2.11
import QtQuick.Controls 2.4

Page {
    width: 1024
    height: 600
    property alias element: element

    header: Label {
        //        text: qsTr("Dashboard")
        font.pixelSize: Qt.application.font.pixelSize * 2
        padding: 10
    }

    Text {
        id: element
        x: 422
        y: 193
        width: 180
        color: "#d3d7cf"
        text: qsTr("1:15 PM")
        font.pixelSize: 48
    }

    Text {
        id: element1
        x: 395
        y: 265
        color: "#d3d7cf"
        text: qsTr("December 15th, 2020")
        font.pixelSize: 24
    }
}
