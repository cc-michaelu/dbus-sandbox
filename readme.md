# DBus Sandbox

## Overview

This repo contains example code of how to pass a custom data type from a DBus service and consume it on the client. There are two sub-projects included:

### complex-dbus-service

This is the DBus service which exposes a function `getCustomData()` which returns data in a custom class named `customData`. This class is defined in the `common/inc/customdata.h` file. It includes a static function which registers its type with the Qt Dbus type system.

### complex-dbus-client

This is the DBus client which simply calls the `getCustomData()` method and displays the results returned.

## Build Instructions

```
git clone git@github.com:cc-michaelu/dbus-sandbox.git
cd dbus-sandbox
mkdir build
cd build
cmake ..
make
```

## Notes

The `com.cana.complex.xml` file is hand-modified to include the following XML nodes:

```xml
    <method name="getCustomData">
      <arg type="a{sv}" direction="out" />
      <annotation name="org.qtproject.QtDBus.QtTypeName.Out0" value="customData" />
    </method>
    <method name="getCustomDataList">
      <arg type="av" direction="out" />
    </method>
```

As a result the generation of the Adaptor and Proxy classes does not involve the `qdbusxml2cpp` step (converting the C++ interface class to xml).

The Adaptor class is modified:

#### `complexAdaptor.h`

```c++
  public Q_SLOTS: // METHODS
    customData getCustomData();
    QList<customData> getCustomDataList();
```
#### `complexAdaptor.cpp`

```c++
customData ComplexAdaptor::getCustomData() {
    // handle method call com.cana.complex.getCustomData
    customData out0;
    QMetaObject::invokeMethod(parent(), "getCustomData",
                              Q_RETURN_ARG(customData, out0));
    return out0;
}

QList<customData> ComplexAdaptor::getCustomDataList() {
    // handle method call com.cana.complex.getCustomDataList
    QList<customData> out0;
    QMetaObject::invokeMethod(parent(), "getCustomDataList",
                              Q_RETURN_ARG(QList<customData>, out0));
    return out0;
}
```

