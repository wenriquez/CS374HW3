#!/bin/bash 

mount /dev/loop0 -t vfat -o rw,sync /home/wenriquez/floppy0
mount /dev/loop1 -t vfat -o rw,sync /home/wenriquez/floppy1

chmod a=rw /dev/loop0
chmod a=rw /dev/loop1
chmod a=rw /dev/loop2

chmod a=rw /home/wenriquez/floppy0
chmod a=rw /home/wenriquez/floppy1
chmod a=rw /home/wenriquez/floppy2

chmod a=rw /home/wenriquez/floppy0.img
chmod a=rw /home/wenriquez/floppy1.img
chmod a=rw /home/wenriquez/floppy2.img
