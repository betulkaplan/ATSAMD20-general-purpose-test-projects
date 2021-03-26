#include <atmel_start.h>

static uint8_t src_data[128];
static uint8_t chk_data[128];
/**
	* Example of using FLASH_0 to read and write Flash main array.
	*/
void FLASH_0_func(void)
{
	uint32_t page_size;
	uint16_t i;

	/* Init source data */
	page_size = flash_get_page_size(&FLASH_0);

	for (i = 0; i < 3; i++) {
		src_data[i] = 0x08;
	}

	/* Write data to flash */
	flash_write(&FLASH_0, 0x3200, src_data, page_size);

	/* Read data from flash */
	flash_read(&FLASH_0, 0x3200, chk_data, page_size);
}


int main(void)
{
	/* Initializes MCU, drivers and middleware */
	atmel_start_init();
	
	FLASH_0_func();
	

	/* Replace with your application code */
	while (1) {
	}
}
