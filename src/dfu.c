/*

The MIT License (MIT)

Copyright (c) 2016 Hubert Denkmair

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.

*/

#include "dfu.h"
#include <stdint.h>
#include "stm32f4xx_hal.h"

#define RESET_TO_BOOTLOADER_MAGIC_CODE 0xDEADBEEF

#define SYSMEM_STM32F405 0x1FFFC400

static uint32_t dfu_reset_to_bootloader_magic;

static void dfu_jump_to_bootloader();

void dfu_run_bootloader()
{
	dfu_reset_to_bootloader_magic = RESET_TO_BOOTLOADER_MAGIC_CODE;
	NVIC_SystemReset();
}

void __initialize_hardware_early(void)
{
	if (dfu_reset_to_bootloader_magic == RESET_TO_BOOTLOADER_MAGIC_CODE)
	{
		switch (HAL_GetDEVID())
		{
			case 0x448: // STM32F4xx
				dfu_jump_to_bootloader(SYSMEM_STM32F405);
				break;

		}
	}

	SystemInit();
}

static void dfu_jump_to_bootloader(uint32_t sysmem_base)
{
	void (*bootloader)(void) = (void (*)(void)) (*((uint32_t *) (sysmem_base + 4)));

	__set_MSP(*(__IO uint32_t*) sysmem_base);
	bootloader();

	while (42)
	{
	}
}
