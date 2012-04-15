#!/bin/sh
Terminal -e 'python -m utsg -p /dev/ttyACM0 -b 57600 --convert --ser-nl=CRLF -d "<broadcast>" -u 9000 -P 9002 --spy'&
Terminal -e 'python -m utsg -p /dev/ttyUSB0 -b 57600 --convert --ser-nl=CRLF -d "<broadcast>" -u 9001 -P 9000 --spy'&
