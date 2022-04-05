#!/usr/bin/env bash

source ./dbus-functions.sh


generate_dbus_metadata  complexinterface.h \
                        com.cana.complex.xml \
                        complexAdaptor \
                        complexProxy


