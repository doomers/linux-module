#include < linux/module.h >	
#include <linux/kernel.h>	
#include <linux/proc_fs.h>

#ifdef CONFIG_PROC_FS

#define procfs_name "procfs_hello_world"
#define procfs_msg "Hello World\n"

struct proc_dir_entry *my_pFile;

static int
pfs_hw_read(char *page,
	    char **start,
	    off_t off, int buffer_length, int *eof, void *data)
{
	int		ret;

	if (off > 0) {
		ret = 0;
	} else {
		/* totally ignore the size of the buffer */
		ret = sprintf(page, procfs_msg);
	}

	return ret;
}

static int
pfs_hw_create_entry()
{
	my_pFile = create_proc_entry(procfs_name, 0644, NULL);

	if (my_pFile == NULL) {
		remove_proc_entry(procfs_name, &proc_root);
		printk(KERN_ALERT "Error creating:/proc/%s\n", procfs_name);
		return -ENOMEM;
	}
	my_pFile->read_proc = procfile_read;
	my_pFile->owner = THIS_MODULE;
	my_pFile->mode = S_IFREG | S_IRUGO;
	my_pFile->uid = 0;
	my_pFile->gid = 0;
	my_pFile->size = 37;

	return 0;

}


static int	__init
pfs_hw_init()
{
	int		ret_val;

	ret_val = pfs_hw_create_entry();
	return ret_val;
}

static void	__exit
pfs_hw_exit()
{
	remove_proc_entry(procfs_name, &proc_root);
	printk(KERN_INFO "/proc/%s removed\n", procfs_name);
}

module_init(pfs_hw_init)
module_exit(pfs_hw_exit)
#else
#error "Set CONFIG_PROC_FS=y in you .config"
#endif				/* CONFIG_PROC_FS */

MODULE_AUTHOR("d-grossman");
MODULE_DESCRIPTION("procfs hello world");

MODULE_LICENSE("GPL");
