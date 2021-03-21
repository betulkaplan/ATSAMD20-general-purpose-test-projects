#include <atmel_start.h>

static struct timer_task TIMER_0_task1;
/**
 * Example of using TIMER_0.
 */
static void TIMER_0_task1_cb(const struct timer_task *const timer_task) // ISR
{
	gpio_toggle_pin_level(LED_onBoard);
}

void TIMER_0_example(void)
{
	TIMER_0_task1.interval = 800;
	TIMER_0_task1.cb       = TIMER_0_task1_cb;
	TIMER_0_task1.mode     = TIMER_TASK_REPEAT;


	timer_add_task(&TIMER_0, &TIMER_0_task1);
	timer_start(&TIMER_0);
}


int main(void)
{
	/* Initializes MCU, drivers and middleware */
	atmel_start_init();
	TIMER_0_example();

	/* Replace with your application code */
	while (1) {
	}
}
