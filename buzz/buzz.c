/**
* if (theNumber is divisible by 3) then
*	print "Fizz"
*  else if (theNumber is divisible by 5) then
*	print "Buzz"
*  else // theNumber is not divisible by 3 or 5
*	print theNumber
*  end if
*/

#include <linux/kernel.h>
#include <linux/module.h>

int init_module(void){

	static int i =0;
  for(i=0;i<100;i++){
	    if( i % 3 )
	      printk(KERN_INFO "Fizz");
	    if( i % 5 )
	      printk(KERN_INFO "Buzz");
	    else
	      printk(KERN_INFO "%d", i);

	}

  return 0;

}

void cleanup_module(void){
    printk(KERN_INFO "goodbye world");
}
