import QtQuick 2.11
import QtQuick.Controls 2.4

import com.hqconsole.bluetooth 1.0

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Tabs")

    Bluetooth {
        id: bt
    }

    SwipeView {
        id: swipeView
        anchors.fill: parent
        currentIndex: tabBar.currentIndex

        Page1Form {
        }

        Page2Form {
        }
    }

    footer: TabBar {
        id: tabBar
        currentIndex: swipeView.currentIndex

        TabButton {
            text: qsTr("Dashboard")
        }
        TabButton {
            text: qsTr("Lights")
        }
    }
}
