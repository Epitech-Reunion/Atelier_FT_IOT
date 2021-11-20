#!/bin/bash
set -e

$user=$1

if [[ $(/usr/bin/id -u) -ne 0 ]]; then
    echo "Must be run with sudo"
    exit 84
fi

dnf install -y arduino
mkdir /usr/share/arduino/tools-builder
gpasswd –a $user dialout
gpasswd –a $user lock
pkill X