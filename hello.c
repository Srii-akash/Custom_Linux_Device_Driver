#include<linux/module.h>
#include<linux/init.h>
static  int my_init(void)
{
	printk("Hello!- Hello World");
	return 0;
}
static  void my_exit(void)
{
	printk("Hello!- Goodbye World");
	
}
module_init(my_init);
module_exit(my_exit);
MODULE_LICENSE("GPL");

