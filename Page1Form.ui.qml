import QtQuick 2.11
import QtQuick.Controls 2.4

Page {
    id: page
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
        width: 180
        color: "#d3d7cf"
        text: qsTr("1:15 PM")
        anchors.top: parent.top
        anchors.topMargin: parent.height / 3
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.horizontalCenterOffset: 0
        font.pixelSize: 48
    }

    Text {
        id: element1
        color: "#d3d7cf"
        text: qsTr("December 15th, 2020")
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.horizontalCenterOffset: 0
        font.pixelSize: 24
        anchors.centerIn: parent
    }
}
