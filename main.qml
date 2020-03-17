import QtQuick 2.13
import QtQuick.Window 2.13

Window {
    visible: true
    width: 640
    height: 480
    title: qsTrId("greetings-the-world")

    Text {
        id: txt1
        text: Qt.locale().name + ":" + qsTrId("greetings-the-world")
        font.pixelSize: 32
    }

    Text {
        anchors.top: txt1.bottom
        id: txt2
        text: Qt.locale().name + ":" + qsTrId("just-another-text")
        font.pixelSize: 32
    }
}
