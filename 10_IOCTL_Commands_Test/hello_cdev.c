#include<linux/module.h>
#include<linux/init.h>
#include<linux/fs.h>
#include<linux/cdev.h>
#include "my_ioctl.h"

static dev_t dev_nr;
static struct cdev my_cdev;
static struct class *my_class;
static int answer = 42;
static long int my_ioctl(struct file *f, unsigned int cmd, unsigned long args)
{
	int status;
	struct mystruct s;
	pr_info("Hello_cdev - ioctl called with cmd: 0x%x and args: %p\n",cmd , (void *) args);
	switch(cmd)
	{
		case WR_VAL:
			status= copy_from_user(&answer, (int *) args, sizeof(int));
			if(status)
			{
				pr_err("hello_cdev - Error onWR_VAL\n");
				return status;
			}
			break;
		case RD_VAL:
			status = copy_to_user((int *)	args, &answer, sizeof(int));
			if(status)
			{
				pr_err("hello_cdev - Error on RD_VAL\n");
				return status;
			}
			break;
		case GREET:
			status = copy_from_user(&s,  (struct mystruct *) args,  sizeof(struct mystruct));
			if(status)
			{
				pr_err("hello_cdev - Error on GREET \n");
				return status;
			}
			for(int i=0;i<s.repeat;i++)
			{
				pr_info("hello_cdev- hello %s\n", s.name);
			}

			break;
	

		default:
			return -EOPNOTSUPP;
	}
	return 0;
}
static struct file_operations fops = {
	.unlocked_ioctl=my_ioctl,	
};

static int __init my_init(void)
{
	int status;
#ifdef STATIC_DEVNR
	dev_nr = STATIC_DEVNR;
	status = register_chardev_region(dev_nr, MINORMASK+1,"Hello_cdev");

#else
	status = alloc_chrdev_region(&dev_nr, 0 , MINORMASK+1 , "hello_cdev");
#endif
	if(status)
	{
		pr_err("hello_cdev - error reserving the region of device numbers\n");
		return status;
	}

	cdev_init(&my_cdev, &fops);

	my_cdev.owner = THIS_MODULE;
	
	status=cdev_add(&my_cdev, dev_nr, MINORMASK+1);
	if(status)
	{
		pr_err("hello_cdev- error adding cdev\n");
		goto free_devnr;		
	}
	pr_info("hello_cdev  -REGISTERED  a character device for Majot %d starting with minor %d\n", MAJOR(dev_nr),MINOR(dev_nr));
	my_class = class_create("my_class");
	if(!my_class)
	{
		pr_err("hello_cdev - Could not create class my_class \n");
		status = ENOMEM;
		cdev_del(&my_cdev);
		unregister_chrdev_region(dev_nr, MINORMASK +1);
		return status;
	}
	if (!device_create(my_class, NULL, dev_nr, NULL, "Hello%d", 0)) 
	{
		pr_err("hello_cdev - Could not create class device hello0\n");
		status=ENOMEM;
		goto delete_class;
	}
	pr_info("Helloo_cdev -created device under /sys/class/my_class/hello0 \n");	
	return 0;
delete_class:
	class_unregister(my_class);
	class_destroy(my_class);
delete_cdev:
	cdev_del(&my_cdev);
free_devnr:
	unregister_chrdev_region(dev_nr, MINORMASK+1);
	return status;
}
static void __exit my_exit(void)

{
	device_destroy(my_class, dev_nr);
	class_unregister(my_class);
	class_destroy(my_class);
	cdev_del(&my_cdev);
	unregister_chrdev_region(dev_nr, MINORMASK+1);
}
module_init(my_init);
module_exit(my_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("SRII");
MODULE_DESCRIPTION("A sample driver for manually  registering a character driver");

