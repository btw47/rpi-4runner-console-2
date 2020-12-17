import QtQuick 2.11
import QtQuick.Controls 2.4

import com.hqconsole.bluetooth 1.0

ApplicationWindow {
    visible: true
    width: 1024
    height: 600
    title: qsTr("4Runner HQ")

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
            element.onToggled: {
                bt.toggleRelayA();
            }
            element1.onToggled: {
                bt.toggleRelayB();
            }
            element2.onToggled: {
                bt.toggleRelayC();
            }
            element7.onToggled: {
                bt.toggleRelayD();
            }
        }
    }

    footer: TabBar {
        id: tabBar
        currentIndex: swipeView.currentIndex

        TabButton {
            text: qsTr("Home")
        }
        TabButton {
            text: qsTr("Lights")
        }
    }
}
