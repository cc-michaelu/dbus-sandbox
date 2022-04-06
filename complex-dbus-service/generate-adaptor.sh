#!/usr/bin/env bash

source ./dbus-functions.sh


generate_dbus_metadata  complexinterface.h \
                        dbus/com.cana.complex.xml \
                        dbus/complexAdaptor \
                        dbus/complexProxy


