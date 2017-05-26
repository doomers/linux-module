
#include <linux/kernel.h>
#include <linux/module.h>

int init_module(void){

	static int n =5;
	static int fact=1;
	static int i =0;
	for( i=1; i<=n;i++)fact=fact*i;
    printk(KERN_INFO "Factorial: %d",fact);
    return 0;   
}

void cleanup_module(void){
    printk(KERN_INFO "goodbye world");

}
