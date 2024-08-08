https://www.wisdomjobs.com/e-university/qt-qml-interview-##s.html

***

### What Is Qt?

Qt is a cross-platform application framework that is widely used for developing application software that can be run on various software and hardware
platforms with little or no change in the underlying codebase.

***
### What is QObject ?

- The Q_OBJECT macro must appear in the private section of a class definition that declares its own signals and slots or that uses other services provided by Qt's meta-object system. 
- we need to define this macro to use signal and slot, and probably for other purposes (meta-object related) as well.

***
### What is QObject Class in Qt ?

- The QObject class is the base class of all Qt objects. Let's us use the object communication using signal ans slots.
- QObjects organize themselves in object trees. When you create a QObject with another object as parent, the object will automatically add itself to the parent's children() list. The parent takes ownership of the object; i.e., it will 
automatically delete its children in its destructor. You can look for an object by name and optionally type using 
findChild() or findChildren().

***
### What ia moc Meta Object Compiler ?

The Meta-Object Compiler, moc, is the program that handles Qt's C++ extensions. The moc tool reads a C++ header file. 
If it finds one or more class declarations that contain the Q_OBJECT macro, it produces a C++ source file containing the
meta-object code for those classes. Among other things, meta-object code is required for the signals and slots mechanism,
the run-time type information, and the dynamic property system.

***


### What Is Qmake?

qmake is a utility that automates the generation of Makefiles.
Makefiles are used by the program make to build executable programs from source code; therefore qmake is a make-makefile tool, or makemake for short.
QMake does not call g++/gcc directly. Instead, qmake creates native make files on your current platform. Under linux it creates standard GNU make files,
under windows it can generate visual studio make files, under Mac OS X it can generate XCode project files. You then invoke your native build system
(either GNU make, or MS NMake, or xcode build or whatever), which will call your native compiler (g++/gcc or whatever).

***
### What Is Qt And Qml?

Qt is a cross-platform application framework.
QML is the name of the language (just like C++, which is another language...)
QML stands for Qt Meta Language or Qt Modelling Language is a user interface markup language.
QtQuick is a toolkit for QML, allowing to develop graphical interface in QML language (there are other toolkits for QML, some are graphical like
Sailfish Silica or BlackBerry Cascade, and some are non-graphical like QBS which is a replacement for QMake/CMake/make...)
QtQuick 1.x was Qt4.x-based and used the QPainter/QGraphicsView API to draw the scene. QtQuick 2.X was introduced with Qt5.0, based on Scene Graph,
an OpenGLES2 abstraction layer, highly optimized.
With Qt5.1, Scene Graph was enhanced to use multithreading (QtQuick 2.1) With Qt5.2,

***
### What Is Qt's Meta Object System?

Qt's meta-object system provides the signals and slots mechanism for inter-object communication, run-time type information, and the dynamic property system.
The meta-object system is based on three things:
The QObject class provides a base class for objects that can take advantage of the meta-object system.
The Q_OBJECT macro inside the private section of the class declaration is used to enable meta-object features, such as dynamic properties, signals, and slots.
The Meta-Object Compiler (moc) supplies each QObject subclass with the necessary code to implement meta-object features.
The moc tool reads a C++ source file. If it finds one or more class declarations that contain the Q_OBJECTmacro, it produces another C++ source file which
contains the meta-object code for each of those classes.

***
### Can Moc File Handle All Class Type?

No, class template can not have signal slot. can not be handled by moc.

***
### What Are Limitations Of Moc?

moc does not handle all of C++.e.g.
The main problem is that class templates cannot have signals or slots.
Function Pointers Cannot Be Signal or Slot Parameters
Type Macros Cannot Be Used for Signal and Slot Parameters
Nested Classes Cannot Have Signals or Slots
Signal/Slot return types cannot be references

***
### What Is Qvariant?

QVariant is a container of variables. It can store variables of different types. Similar in some way to void*. But it provides You information about the
stored type.
It can be used for example to return different types of values from a function.

***
### What Is Qt Widgets?

Widgets are the basic building blocks for graphical user interface (GUI) applications built with Qt. Each GUI component (e.g. buttons, labels, text editor)
is a widget that is placed somewhere within a user interface window, or is displayed as an independent window. Each type of widge is provided by a subclass
of QWidget, which is itself a subclass of QObject.
QWidget is not an abstract class. It can be used as a container for other widgets, and it can be subclassed with minimal effort to create new, custom
widgets. QWidget is often used to create a window inside which other QWidgets are placed.
As with QObjects, QWidgets can be created with parent objects to indicate ownership, ensuring that objects are deleted when they are no longer used. With
widgets, these parent-child relationships have an additional meaning: Each child widget is displayed within the screen area occupied by its parent widget.
This means that when you delete a window widget, all the child widgets it contains are also deleted.

***
### What Is Q_object Macro?

The Q_OBJECT macro must appear in the private section of a class definition that declares its own signals and slots or that uses other services
provided by Qt's meta-object system.

***
### What Is Moc(meta Object Compiler)?

The Meta-Object Compiler, moc, is the program that handles Qt's C++ extensions.
The moc tool reads a C++ header file. If it finds one or more class declarations that contain the  Q_OBJECT macro, it produces a C++ source file
containing the meta-object code for those classes. Among other things, meta-object code is required for the signals and slots mechanism, the run-time
type information, and the dynamic property system.

***
### Which Class Is The Parent Class Of Qline Edit ?

QWidget is the parent class to all widgets(push button,line Edit,label like that).

***
### What Is Qml?

QML is the name of the language (just like C++, which is another language...).
QML stands for Qt Meta Language or Qt Modelling Language is a user interface markup language.

***
### How To Call C++ Call From Qml?

QML call C + + methods with the Qt meta-object system. Like below:
onClicked: parent.color = parent.randomColor ().

***
### What Are Four Ways Of Integrating C++ With Qml?

Subclassing QQuickItem: QQuickItem allows you to write your own visual and non-visual QML items using C++.
Registering C++ types with QML: C++ classes can be registered with the QML type system, allowing them to be instantiated as QML types.
Registering Context Properties: QObjects can be registered with the QML context, allowing their properties to be directly accessed.
Accessing QML objects through the QML object tree: All QML objects reside in a tree hierarchy and can be accessed via the root of the tree.

***
### How To Call A C++ Function From A Qml?

Through setcontext property.
Loading a main.qml with a simple Item as the root type through the QqmlApplicationEngine will not show anything on your display, as it requires a window to manage a surface for rendering. The engine is capable of loading qml code which does not contain any user interface (e.g plain objects). Because of this it does not create a window for you by default.
The qmlscene or the new qml runtime will internally first check if the main qml file contains a window as a root item and if not create one for you and set the root item as a child to the newly created window.

***
### What Is Q_invokable?

Add callable methods using Q_INVOKABLE or Qt slots, and connect to Qt signals with an on Signal syntax.

***
### How To Call A Qml Function From C++?

QML functions can be called from C++ and vice-versa.
All QML functions are exposed to the meta-object system and can be called using QMetaObject::invokeMethod().
Here is a C++ application that uses this to call a QML function:
```
// MyItem.qml
import QtQuick 1.0
Item
{
    function mysql Function(msg)
    {
        console.log("Got message:", msg)
        return "some return value"
    }
}

// main.cpp
QDeclarativeEngine engine;
QDeclarativeComponent component(&engine, "MyItem.qml");
QObject *object = component.creator();
QVariant returned Value;
QVariant msg = "Hello from C++";
QMetaObject::invokeMethod(object, "mysql Function",Q_RETURN_ARG(QVariant, returned Value),Q_ARG(QVariant, msg));
qDebug() << "QML function returned:" << returnedValue.toString();
delete object;
```

**************************************************************************************************************************************************
