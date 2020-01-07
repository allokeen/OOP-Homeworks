import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.3
import pl.gwizdz 1.0
import displacement 1.0
import speed 1.0
import acceleration 1.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
//==================================

    Acceleration{
        id: acceleration
    }

    Speed{
        id: speed
    }

    Displacement{
        id: displacement
    }

    Button {
        id: button1
        x: 113
        y: 42
        text: qsTr("Displacement")
        onClicked: function() {
            displacement.value = textInput.text;
        }
    }

    Label {
        id: label2
        x: 227
        y: 121
        text: qsTr("0")
    }

    Label {
        id: label3
        x: 227
        y: 154
        text: qsTr("0")
    }

    Text {
        id: element
        x: 175
        y: 122
        text: qsTr("Speed:")
        font.pixelSize: 12
    }

    Text {
        id: element1
        x: 142
        y: 156
        text: qsTr("Acceleration:")
        font.pixelSize: 12
    }

    TextInput {
        id: textInput
        x: 235
        y: 42
        width: 218
        height: 40
        text: qsTr("Text Input")
        font.pixelSize: 12
    }
}


//===============================
/*
Demo{
    id: demo
    value: 10.2
    onTest: function(){
        console.log("It works...")
        textField.clear()
    }
}

TextField {
    id: textField
    x: 301
    y: 121
    text: qsTr("Text Field")
    visible: false
}

Button {
    id: button
    x: 89
    y: 114
    text: qsTr("Button")
    visible: false
    onClicked: function() {                                                     //
        label.text = textField.text;
        demo.doSomething();
    }
}

Label {
    id: label
    x: 263
    y: 217
    text: qsTr("Label")
    visible: false
}

Label {
    id: label1
    x: 263
    y: 247
    text: textField.text +" "+ demo.value
    visible: false

}*/
