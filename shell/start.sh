#!/bin/bash 

IP=192.168.1.203
PI_DIR=/home/pi
LOCAL_DIR=/home/pi

sshfs pi@$IP:$PI_DIR $LOCAL_DIR
ssh pi@$IP

