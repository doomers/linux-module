# linux-module
It consist of a basic hello world linux module

How to compile:
$ make 

How to compile new modules:
1.) Create a new Module
2.) add these to Makefile
obj-m+= "your-module-name.o"
3.) $ make

How to load module in kernel:
$ insmod "your-module-name.ko"

How to remove module from Kernel:
$ rmmod "your-kernel-name.ko"

List of all the Modules in Kernel:
$ lsmod

