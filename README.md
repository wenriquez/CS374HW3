CS374HW3
========

Homework 3

The methods depend on 3 devices having already been created. Two of the devices should contain some data in them before using write mode. The read mode should be used only after having used the write mode. The read mode assumes that one device is okay, and that the parity device is okay. The device that is to be recovered must be passed as well to the read method.

Write Mode

device1, device2, parity device, write

example: /dev/loop0 /dev/loop1 /dev/loop2 write


Read Mode

device1, parity device, device to recover, read

example: /dev/loop1 /dev/loop2 /dev/loop0 write
