// SPDX-License-Identifier: GPL-2.0
#include<linux/module.h>
#include<linux/init.h>
static int __init my_init(void)
{
	printk(KERN_INFO "Hello! - Hello Kernel");
	return 0;
}
static void __exit my_exit(void)
{
	printk(KERN_INFO "Hello - Bye Kernel");
}
module_init(my_init);
module_exit(my_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("SRII");
MODULE_DESCRIPTION("SIMPLE MODULE");

