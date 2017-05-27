
#include <linux/kernel.h>
#include <linux/module.h>

static int n = 5;
module_param(n,int,0);
MODULE_PARM_DESC(n,"given number");

int init_module(void){

	static int i =1;
	static int prime =0;
	for( i=2; i<=n/2;i++)if(n%i==0){
		prime =1;
	    break;}


	if(!prime)printk(KERN_INFO "Number is Prime");
	else printk(KERN_INFO "NOT PRIME");
    
    return 0;   
}

void cleanup_module(void){
    printk(KERN_INFO "goodbye world");

}
