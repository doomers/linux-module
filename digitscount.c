#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/moduleparam.h>

static int n = 5832;
module_param(n,int,0);
MODULE_PARM_DESC(n,"given number");


int init_module(void){

	static int sum=0;
	static int temp=n;
  static int power=0;
	
  while(temp>0)
	{
		power++;
		temp/=10;
	}
   	printk(KERN_INFO "Sum_of_digits: %d",sum);
    	return 0;   
}

void cleanup_module(void){
    printk(KERN_INFO "goodbye world");
}
