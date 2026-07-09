# Custom Linux Character Device Driver

## Overview

This project demonstrates the development of a custom Linux Character Device Driver as a Linux Kernel Module (LKM). The primary objective is to understand the Linux device driver framework, character device registration, and kernel module development from scratch.

## Features

* Linux Kernel Module (LKM)
* Character Device Driver implementation
* Static and Dynamic Major Number Allocation
* Character Device Registration
* Device Initialization and Cleanup
* Kernel Logging using `printk`
* Module Loading and Unloading
* Error Handling during Driver Initialization

## Technologies Used

* C Programming
* Linux Kernel
* Linux Device Drivers
* Embedded Linux
* GCC
* Makefile
* Ubuntu Linux

## Project Structure

```
hello_cdev/
├── hello_cdev.c
├── Makefile
└── README.md
```

## Build

```bash
make
```

## Load the Driver

```bash
sudo insmod hello_cdev.ko
```

## Verify Driver Registration

```bash
cat /proc/devices
```

or

```bash
dmesg
```

## Unload the Driver

```bash
sudo rmmod hello_cdev
```

## Learning Outcomes

This project helped me understand:

* Linux Kernel Module development
* Character Device Driver architecture
* Major and Minor Number allocation
* Character device registration using `cdev`
* Kernel module lifecycle
* Linux kernel logging with `printk`
* Driver loading, unloading, and debugging
* Error handling in Linux device drivers

## Future Improvements

* Implement File Operations (`open`, `read`, `write`, `release`)
* Create Device Node using `udev`
* Support User Space communication
* Add IOCTL implementation
* Implement Polling and Blocking I/O
* Extend to Platform Driver Development
* Add Device Tree support

## Author

Akash Srivastava