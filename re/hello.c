


#include <linux/kernel.h>
#include <linux/module.h>

int init_module(void){
	printk(KERN_INFO "hello world");
	return 0;
}

void cleanup_module(void){
	printk(KERN_INFO "GoodBye world");
}