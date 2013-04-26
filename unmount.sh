#!/bin/bash

umount /dev/loop0
umount /dev/loop1

chmod a=rw /dev/loop0
chmod a=rw /dev/loop1
chmod a=rw /dev/loop2
