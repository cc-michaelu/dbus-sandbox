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
