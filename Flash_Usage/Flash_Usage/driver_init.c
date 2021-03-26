/*
 * Code generated from Atmel Start.
 *
 * This file will be overwritten when reconfiguring your Atmel Start project.
 * Please copy examples or other code you want to keep to a separate file
 * to avoid losing it when reconfiguring.
 */

#include "driver_init.h"
#include <peripheral_clk_config.h>
#include <utils.h>
#include <hal_init.h>
#include <hpl_gclk_base.h>
#include <hpl_pm_base.h>

#include <hpl_rtc_base.h>

struct timer_descriptor TIMER_0;

struct flash_descriptor FLASH_0;

void FLASH_0_CLOCK_init(void)
{

	_pm_enable_bus_clock(PM_BUS_APBB, NVMCTRL);
}

void FLASH_0_init(void)
{
	FLASH_0_CLOCK_init();
	flash_init(&FLASH_0, NVMCTRL);
}

/**
 * \brief Timer initialization function
 *
 * Enables Timer peripheral, clocks and initializes Timer driver
 */
static void TIMER_0_init(void)
{
	_pm_enable_bus_clock(PM_BUS_APBA, RTC);
	_gclk_enable_channel(RTC_GCLK_ID, CONF_GCLK_RTC_SRC);
	timer_init(&TIMER_0, RTC, _rtc_get_timer());
}

void system_init(void)
{
	init_mcu();

	FLASH_0_init();

	TIMER_0_init();
}
