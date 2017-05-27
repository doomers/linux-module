
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/moduleparam.h>

static int n = 5;
module_param(n,int,0);
MODULE_PARM_DESC(n,"given number");


int init_module(void){

	static int fact=1;
	static int i =0;
	for( i=1; i<=n;i++)fact=fact*i;
    printk(KERN_INFO "Factorial: %d %n",fact,n);
    return 0;   
}

void cleanup_module(void){
    printk(KERN_INFO "goodbye world");
}
