#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/moduleparam.h>

static int n = 5;
module_param(n,int,0);
MODULE_PARM_DESC(n,"given number");


int init_module(void){

	static int rev=0;
	static int temp=n;
	while(temp>0)
	{
		rev*=10;
		rev+=(temp%10);
		temp/=10;
	}
   	printk(KERN_INFO "Reverse Number: %d",rev);
    	return 0;   
}

void cleanup_module(void){
    printk(KERN_INFO "goodbye world");
}
