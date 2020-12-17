import QtQuick 2.12
import QtQuick.Controls 2.5

Page {
    width: 600
    height: 400
    property alias element: element

    header: Label {
        //        text: qsTr("Dashboard")
        font.pixelSize: Qt.application.font.pixelSize * 2
        padding: 10
    }

    Text {
        id: element
        x: 210
        y: 120
        width: 180
        color: "#d3d7cf"
        text: qsTr("1:15 PM")
        font.pixelSize: 48
    }

    Text {
        id: element1
        x: 183
        y: 192
        color: "#d3d7cf"
        text: qsTr("December 15th, 2020")
        font.pixelSize: 24
    }
}
