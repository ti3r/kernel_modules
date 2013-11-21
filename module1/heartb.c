#include "heartb.h"

void calculate_display_hear_beats(char *name, int age)
{
	//72 beats average per minute * 60 minutes * 24 hrs 
	//* 365.25 days/year * num of year lived
	float beats = 72 * 60 * 24 * 365.25 * age;
	printk(KERN_INFO "Hi %s, your heart has beat %0.2f times since birth",name,beats);
}
