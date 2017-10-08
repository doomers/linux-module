# linux-module
linux modules 

## How to compile:  <br />
$ make 

## How to compile new modules: <br />
1.) Create a new Module  <br />
2.) add these to Makefile  <br />
obj-m+= "your-module-name.o"  <br />
3.) $ make

## How to load module in kernel:  <br />
$ insmod "your-module-name.ko"

## How to remove module from Kernel:  <br />
$ rmmod "your-kernel-name.ko"

## List of all the Modules in Kernel:  <br />
$ lsmod

## Contributing

Fork the project on github.

Create a module branch.

Please keep PR titles easy to read and descriptive of changes, this will make them easier to merge.

Pull requests must be made against development branch. Any other branch (unless specified by the maintainers) will get rejected.

Have fun!

## Authors
* **Rahul Tuteja**  - [doomers](https://github.com/doomers) 




