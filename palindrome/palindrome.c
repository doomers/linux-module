/*  
 *  hello-1.c - The simplest kernel module.
 */
#include <linux/module.h>	/* Needed by all modules */
#include <linux/kernel.h>	/* Needed for KERN_INFO */
#include <linux/moduleparam.h>
#include <linux/string.h>

static char * str = "nonu";
module_param(str,charp,0000);
MODULE_PARM_DESC(str,"A Text String");


int init_module(void)
{
	static int l =0;
	l= strlen(str);
	static int i ;
	static int flag = 1;
	for(i =0;i<l;i++){
		if(str[i]!=str[l-1-i]){
        flag =0;
        break;
	}
}
	if(flag)printk(KERN_INFO "Palindrome");
	else printk(KERN_INFO "Not a Palindrome ");


	/* 
	 * A non 0 return means init_module failed; module can't be loaded. 
	 */
	return 0;
}

void cleanup_module(void)
{
	printk(KERN_INFO "Goodbye world 1.\n");
}
