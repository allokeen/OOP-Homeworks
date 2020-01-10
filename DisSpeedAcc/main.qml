import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.3
import acc 1.0
import spe 1.0
import dis 1.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Acceleration{
        id: acceleration
        value: 0
    }

    Speed{
        id: speed
        value: 0
        onChanged: function(){
            acceleration.onSpeedChanged(value);
        }
    }

    Displacement{
        id: displacement
        value: 0
        onChanged: function(){
           speed.onDisplacementChanged(value);
        }
    }

    Button {
        id: button
        x: 99
        y: 56
        text: qsTr("Displacement")
        onClicked: function(){
            displacement.set(textInput.text);
            label.text = speed.get();
            label1.text = acceleration.get();
        }
    }

    TextInput {
        id: textInput
        x: 235
        y: 56
        width: 126
        height: 40
        text: qsTr("Text Input")
        font.pixelSize: 20
    }

    Text {
        id: element
        x: 109
        y: 150
        width: 99
        height: 30
        text: qsTr("SPEED")
        font.pixelSize: 12
    }

    Text {
        id: element1
        x: 109
        y: 196
        text: qsTr("ACCELERATION")
        font.pixelSize: 12
    }

    Label {
        id: label
        x: 245
        y: 150
        text: qsTr("Label")
    }

    Label {
        id: label1
        x: 245
        y: 196
        text: qsTr("Label")
    }
}
