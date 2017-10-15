#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/slab.h>
#include <linux/string.h>
#include <linux/timer.h>
#include <linux/major.h>
#include <linux/fs.h>
#include <linux/err.h>
#include <linux/ioctl.h>
#include <linux/init.h>
#include <linux/proc_fs.h>
#include <asm-generic/uaccess.h>
#include <linux/types.h>
#include <linux/bug.h>
#include <linux/io.h>
#include <asm/page.h>



#ifndef __GFP_WAIT
#define __GFP_WAIT __GFP_RECLAIM
#endif

#ifndef GFP_IOFS
#define GFP_IOFS STP_ALLOC_FLAGS
#endif

#ifdef CONFIG_PROC_FS

#define procfs_msg "Hello World\n"
#define procfs_name "procfs_hello_world"
#define procfs_perms 0644
#define procfs_parent NULL

static struct file_operations procfs_fops;
static char    *message;
static int	read_p;


static		ssize_t
pfs_hw_read(struct file *file,
	    char __user * buf, size_t count, loff_t * offp)
{
	ssize_t		len = strlen(message);

	read_p = !read_p;
	if (read_p) {
		return 0;
	}
	printk("proc called read %ld\n", count);
	printk("proc called len %ld\n", len);
	printk("about to copy %s\n", message);

	/*
	 * should be len instead of 0, but that causes an oops
	 */

	/* @todo figure out why copy_to_user so upset wich nonzero */
	copy_to_user(buf, message, 0);

	return 0;
}

static int
pfs_hw_open(struct inode *sp_inode, struct file *sp_file)
{
	printk("proc called open\n");

	read_p = 1;

	//message = kmalloc(sizeof(char) * 1024, __GFP_WAIT | __GFP_IO | __GFP_FS);
	message = kmalloc(1024, GFP_KERNEL);

	if (message == NULL) {
		printk("ERROR, pfs_hw_init");
		return -ENOMEM;
	}
	strcpy(message, procfs_msg);
	return 0;
}

static int
pfs_hw_release(struct inode *sp_inode, struct file *sp_file)
{
	printk("proc called release\n");
	kfree(message);
	return 0;

}


static __init int
pfs_hw_create_entry(void)
{
	printk("/proc/%s create\n", procfs_name);
	/* procfs_fops.owner = THIS_MODULE; */
	procfs_fops.open = pfs_hw_open;
	procfs_fops.read = pfs_hw_read;
	procfs_fops.release = pfs_hw_release;

	if (!proc_create(procfs_name, procfs_perms, procfs_parent, &procfs_fops)) {
		printk(KERN_ALERT "Error creating:/proc/%s\n", procfs_name);
		remove_proc_entry(procfs_name, procfs_parent);
		return -ENOMEM;
	}
	return 0;
}

static void	__exit
pfs_hw_exit(void)
{
	remove_proc_entry(procfs_name, procfs_parent);
	printk(KERN_INFO "/proc/%s removed\n", procfs_name);
}

module_init(pfs_hw_create_entry);
module_exit(pfs_hw_exit);
#else
#error "Set CONFIG_PROC_FS=y in you .config"
#endif				/* CONFIG_PROC_FS */

MODULE_AUTHOR("d-grossman");
MODULE_DESCRIPTION("procfs hello world");
