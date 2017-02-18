# linux-module
It consist of a basic hello world linux module

How to compile:  <br />
$ make 

How to compile new modules: <br />
1.) Create a new Module  <br />
2.) add these to Makefile  <br />
obj-m+= "your-module-name.o"  <br />
3.) $ make

How to load module in kernel:  <br />
$ insmod "your-module-name.ko"

How to remove module from Kernel:  <br />
$ rmmod "your-kernel-name.ko"

List of all the Modules in Kernel:  <br />
$ lsmod

