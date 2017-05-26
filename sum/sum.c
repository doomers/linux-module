
#include <linux/kernel.h>
#include <linux/module.h>

int init_module(void){

	static int a[5] = {1,2,3,4,5};
	static int n = 5;
	static int sum=0;
	static int i =0;
	for( i=0; i< n;i++)sum=sum+a[i];
    printk(KERN_INFO "sum: %d",sum);
    return 0;   
}

void cleanup_module(void){
    printk(KERN_INFO "goodbye world");

}
