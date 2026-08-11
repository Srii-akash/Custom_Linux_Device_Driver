#include <linux/module.h>
#include <linux/export-internal.h>
#include <linux/compiler.h>

MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};



static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x9f222e1e, "alloc_chrdev_region" },
	{ 0x54bfaabc, "cdev_init" },
	{ 0x294c16b9, "cdev_add" },
	{ 0x27c34b45, "class_create" },
	{ 0x80057d3a, "cdev_del" },
	{ 0x0bc5fb0d, "unregister_chrdev_region" },
	{ 0x4b1d1105, "device_create" },
	{ 0x67b6092a, "class_unregister" },
	{ 0x67b6092a, "class_destroy" },
	{ 0x04b38a18, "device_destroy" },
	{ 0xd272d446, "__fentry__" },
	{ 0xe8213e80, "_printk" },
	{ 0xd272d446, "__x86_return_thunk" },
	{ 0xb0c84d61, "module_layout" },
};

static const u32 ____version_ext_crcs[]
__used __section("__version_ext_crcs") = {
	0x9f222e1e,
	0x54bfaabc,
	0x294c16b9,
	0x27c34b45,
	0x80057d3a,
	0x0bc5fb0d,
	0x4b1d1105,
	0x67b6092a,
	0x67b6092a,
	0x04b38a18,
	0xd272d446,
	0xe8213e80,
	0xd272d446,
	0xb0c84d61,
};
static const char ____version_ext_names[]
__used __section("__version_ext_names") =
	"alloc_chrdev_region\0"
	"cdev_init\0"
	"cdev_add\0"
	"class_create\0"
	"cdev_del\0"
	"unregister_chrdev_region\0"
	"device_create\0"
	"class_unregister\0"
	"class_destroy\0"
	"device_destroy\0"
	"__fentry__\0"
	"_printk\0"
	"__x86_return_thunk\0"
	"module_layout\0"
;

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "80B8859F885241E4BA37095");
