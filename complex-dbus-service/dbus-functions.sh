#
# Bash script functions for generating Qt-DBus Proxy and Adaptor classes
#

function generate_dbus_xml {
    IF_HEADER=$1
    XML_FILE=$2
    echo "Generating ${XML_FILE} from ${IF_HEADER}"
    qdbuscpp2xml -A ${IF_HEADER} -o ${XML_FILE}
    if [ $? -ne 0 ]; then
        echo "ERROR: Non-zero result code"
    fi
}

function generate_dbus_adaptor {
    XML_FILE=$1
    ADAPTOR_BASE_NAME=$2

    echo "Generating adaptor class ${ADAPTOR_BASE_NAME} from ${XML_FILE}"
    qdbusxml2cpp -a ${ADAPTOR_BASE_NAME} ${XML_FILE}
    if [ $? -ne 0 ]; then
        echo "ERROR: Non-zero result code"
    fi
}


function generate_dbus_proxy {
    XML_FILE=$1
    PROXY_BASE_NAME=$2

    echo "Generating proxy class ${PROXY_BASE_NAME} from ${XML_FILE}"
    qdbusxml2cpp -N -p ${PROXY_BASE_NAME} ${XML_FILE}
}

function generate_dbus_metadata {
    IF_HEADER=$1
    XML_FILE=$2
    ADAPTOR_BASE_NAME=$3
    PROXY_BASE_NAME=$4

    # generate_dbus_xml ${IF_HEADER} ${XML_FILE}
    generate_dbus_adaptor ${XML_FILE} ${ADAPTOR_BASE_NAME}
    generate_dbus_proxy ${XML_FILE} ${PROXY_BASE_NAME}
    # install_proxy ${PROXY_BASE_NAME}
    # update_git_staging ${XML_FILE} ${ADAPTOR_BASE_NAME} ${PROXY_BASE_NAME}
}
