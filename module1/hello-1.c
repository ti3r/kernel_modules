#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/moduleparam.h>

#define DRIVER_AUTHOR "Alexandro Blanco <ti3r.bubblenet@gmail.com>"
#define DRIVER_DESC "An example of kernel modules programming"
#define DRIVER_VERSION "v0.1"
#define DRIVER_SUPP_DEVICE "None Yet"
#define HEART_BEAT_MOD_NAME_NOT_PROVIDED -1

int age = 0;
char *name = NULL;
module_param(age, int, 0);
module_param(name, charp, 0000);

void calculate_display_heart_beats(char *pname, int page)
{
	//72 beats average per minute * 60 minutes * 24 hrs 
	//* 365.25 days/year * num of year lived
	float beats = 72 * 60 * 24 * 365.25 * page;
	printk(KERN_INFO "Hi %s, your heart has beat %f times since birth",pname,beats);
}

int init_module(void)
{
	printk(KERN_INFO "Calculate Hear beats module.\n");
	if (name == NULL)
	{
		printk(KERN_ERR "No name received. Module can't continue\n");
		return HEART_BEAT_MOD_NAME_NOT_PROVIDED;
	}
	printk(KERN_INFO "Age received: %d\n", age);	
	calculate_display_heart_beats(name, age);
	return 0;
}

void cleanup_module(void)
{

	printk(KERN_INFO "Goodbye world 1.\n");
}


MODULE_LICENSE("GPL");
MODULE_AUTHOR(DRIVER_AUTHOR);
MODULE_DESCRIPTION(DRIVER_DESC);
MODULE_SUPPORTED_DEVICE(DRIVER_SUPP_DEVICE);
