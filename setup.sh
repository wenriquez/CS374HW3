#!/bin/bash 


mkdir /home/wenriquez/floppy0
dd if=/dev/zero of=/home/wenriquez/floppy0.img bs=512 count=2880
losetup /dev/loop0 /home/wenriquez/floppy0.img 
mkfs.vfat /dev/loop0
mount /dev/loop0 -t vfat -o rw,sync /home/wenriquez/floppy0

mkdir /home/wenriquez/floppy1
dd if=/dev/zero of=/home/wenriquez/floppy1.img bs=512 count=2880
losetup /dev/loop1 /home/wenriquez/floppy1.img 
mkfs.vfat /dev/loop1
mount /dev/loop1 -t vfat -o rw,sync /home/wenriquez/floppy1

mkdir /home/wenriquez/floppy2
dd if=/dev/zero of=/home/wenriquez/floppy2.img bs=512 count=2880
losetup /dev/loop2 /home/wenriquez/floppy2.img 


echo "Test length 1"  > /home/wenriquez/data1.txt
echo "Test length 2 and extra"  > /home/wenriquez/data2.txt

mv /home/wenriquez/data1.txt /home/wenriquez/floppy0
mv /home/wenriquez/data2.txt /home/wenriquez/floppy1

chmod a=rw /dev/loop0
chmod a=rw /dev/loop1
chmod a=rw /dev/loop2

chmod a=rw /home/wenriquez/floppy0
chmod a=rw /home/wenriquez/floppy1
chmod a=rw /home/wenriquez/floppy2

chmod a=rw /home/wenriquez/floppy0.img
chmod a=rw /home/wenriquez/floppy1.img
chmod a=rw /home/wenriquez/floppy2.img


