/*
 * Usb hotplug program. Currently only supports a wireless logitech mouse
 */

#include <linux/module.h>
#include <linux/init.h>
#include <linux/usb.h>
#include <linux/kernel.h>
#include <linux/kmod.h>
#include <linux/proc_fs.h>
#include <asm/uaccess.h>

static int usb_probe(struct usb_interface *interface, const struct usb_device_id *id)
{
	printk(KERN_INFO "The usb device is registered\n");

	return 0;	
}

void usb_disconnect(struct usb_interface *interface)
{
	printk(KERN_INFO "Removed the usb device");
}

static struct usb_device_id table[] = 
{
	{USB_DEVICE(0x046D,0xC534)},
	{}
};
MODULE_DEVICE_TABLE(usb,table);

static struct usb_driver randriver =
{
	.name = "Bharath",
	.probe = usb_probe,
	.disconnect = usb_disconnect,
	.id_table = table,
};

/*
 * Register the usb driver on kernel module insertion
 */
static int reg_func(void)
{
	return usb_register(&randriver);
}

/*
 * Remove it on kernel module removal
 */
void dereg_func(void)
{

	usb_deregister(&randriver);
}

module_init(reg_func);
module_exit(dereg_func);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Bharath Vedartham");
MODULE_DESCRIPTION("USB Module");
MODULE_VERSION("0.01");
