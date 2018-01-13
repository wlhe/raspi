#!/bin/bash

# Build Qt for raspberry
# configure shell command
# root file system mount to /mnt
# cross compile toolchain to /home/wind/opt/raspi/tools

TOOLCHAIN=/home/wind/opt/raspi/tools
CROSS_COMPILER=${TOOLCHAIN}/arm-bcm2708/gcc-linaro-4.9-2015.02-3-x86_64_arm-linux-gnueabihf/bin/arm-linux-gnueabihf-

DEVICE=linux-rasp-pi3-g++
ROOTFS=/mnt
PREFIX=/usr/local/qt5

./configure -opengl es2 -device $DEVICE \
			-device-option CROSS_COMPILE=${CROSS_COMPILER} \
			-sysroot ${ROOTFS} \
			-opensource -confirm-license \
			-optimized-qmake -reduce-exports -release \
			-make libs \
			-prefix ${PREFIX} \
			-hostprefix ${PREFIX} 

# -make libs -make tools -make examples \
# run in rasp pi: sudo apt-get install qt5-qmake qt5-default