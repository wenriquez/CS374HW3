
#!/bin/bash

rm /home/wenriquez/floppy0/data1.txt

rm /home/wenriquez/floppy1/data2.txt

umount /dev/loop0
losetup -d /dev/loop0
rmdir /home/wenriquez/floppy0

umount /dev/loop1
losetup -d /dev/loop1
rmdir /home/wenriquez/floppy1

umount /dev/loop2
losetup -d /dev/loop2
rmdir /home/wenriquez/floppy2

rm /home/wenriquez/floppy0.img
rm /home/wenriquez/floppy1.img
rm /home/wenriquez/floppy2.img
