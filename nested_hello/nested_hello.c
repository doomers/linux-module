


#include <linux/kernel.h>
#include <linux/module.h>

int init_module(void){
  int i,j;
  for(i=0;i<100;i++)
  {
    for(j=0;j<100;j++)
    {
      printk(KERN_INFO "hello world");
    }
  }
	return 0;
}

void cleanup_module(void){
	printk(KERN_INFO "GoodBye world");
}
