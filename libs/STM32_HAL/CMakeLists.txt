project(STM32_HAL)

set(SOURCES
    config/stm32f4xx_hal_conf.h

    src/stm32f4xx/stm32f4xx_hal.c
    src/stm32f4xx/stm32f4xx_hal_can.c
    src/stm32f4xx/stm32f4xx_hal_cortex.c
    src/stm32f4xx/stm32f4xx_hal_dma.c
    src/stm32f4xx/stm32f4xx_hal_flash.c
    src/stm32f4xx/stm32f4xx_hal_flash_ex.c
    src/stm32f4xx/stm32f4xx_hal_gpio.c
    src/stm32f4xx/stm32f4xx_hal_i2c.c
    src/stm32f4xx/stm32f4xx_hal_i2c_ex.c
    src/stm32f4xx/stm32f4xx_hal_pcd.c
    src/stm32f4xx/stm32f4xx_hal_pcd_ex.c
    src/stm32f4xx/stm32f4xx_hal_pwr.c
    src/stm32f4xx/stm32f4xx_hal_pwr_ex.c
    src/stm32f4xx/stm32f4xx_hal_rcc.c
    src/stm32f4xx/stm32f4xx_hal_rcc_ex.c
    src/stm32f4xx/stm32f4xx_hal_tim.c
    src/stm32f4xx/stm32f4xx_hal_tim_ex.c
    src/stm32f4xx/stm32f4xx_ll_usb.c

    src/newlib/assert.c
    src/newlib/_exit.c
    src/newlib/_sbrk.c
    src/newlib/_startup.c
    src/newlib/_syscalls.c

    src/cortexm/exception_handlers.c
    src/cortexm/_initialize_hardware.c
    src/cortexm/_reset_hardware.c

    src/cmsis/system_stm32f4xx.c

    include/stm32f4xx/stm32f4xx_hal_tim.h
    include/stm32f4xx/stm32f4xx_hal_pcd.h
    include/stm32f4xx/stm32f4xx_hal_gpio.h
    include/stm32f4xx/stm32f4xx_hal_i2c_ex.h
    include/stm32f4xx/stm32f4xx_hal_flash_ex.h
    include/stm32f4xx/stm32f4xx_hal_dma_ex.h
    include/stm32f4xx/stm32f4xx_hal_i2c.h
    include/stm32f4xx/stm32f4xx_hal_pwr.h
    include/stm32f4xx/stm32f4xx_hal_pwr_ex.h
    include/stm32f4xx/stm32f4xx_hal_dma.h
    include/stm32f4xx/stm32f4xx_hal_gpio_ex.h
    include/stm32f4xx/Legacy/stm32_hal_legacy.h
    include/stm32f4xx/stm32f4xx_hal_rcc_ex.h
    include/stm32f4xx/stm32f4xx_hal_def.h
    include/stm32f4xx/stm32f4xx_hal.h
    include/stm32f4xx/stm32f4xx_hal_rcc.h
    include/stm32f4xx/stm32f4xx_hal_cortex.h
    include/stm32f4xx/stm32f4xx_hal_flash.h
    include/stm32f4xx/stm32f4xx_hal_tim_ex.h
    include/stm32f4xx/stm32f4xx_hal_pcd_ex.h
    include/stm32f4xx/stm32f4xx_hal_can.h
    include/stm32f4xx/stm32f4xx_hal_flash_ramfunc.h
    include/stm32f4xx/stm32f4xx_ll_usb.h
    include/cmsis/cmsis_armcc.h
    include/cmsis/arm_math.h
    include/cmsis/cmsis_armcc_V6.h
    include/cmsis/arm_common_tables.h
    include/cmsis/core_cm3.h
    include/cmsis/core_cm0plus.h
    include/cmsis/core_cm7.h
    include/cmsis/cmsis_gcc.h
    include/cmsis/core_cmInstr.h
    include/cmsis/core_cmFunc.h
    include/cmsis/core_cm0.h
    include/cmsis/arm_const_structs.h
    include/cmsis/core_sc300.h
	include/cmsis/device/stm32f4xx.h
    include/cmsis/device/stm32f405xx.h
    include/cmsis/device/system_stm32f4xx.h
    include/cmsis/cmsis_device.h
    include/cmsis/core_cm4.h
    include/cmsis/core_sc000.h
    include/cmsis/core_cmSimd.h
    include/arm/semihosting.h
    include/cortexm/ExceptionHandlers.h
    include/diag/Trace.h
)

set(INCLUDE_DIRS
    include/
    include/cmsis
    include/stm32f4xx
    include/cmsis/device
    config/
)

add_library(STM32_HAL_STM32F405xx OBJECT ${SOURCES} src/cmsis/startup_stm32f405xx.S)
    target_include_directories(STM32_HAL_STM32F405xx PUBLIC ${INCLUDE_DIRS})
    target_compile_options(STM32_HAL_STM32F405xx PRIVATE -Wno-unused-parameter -Wno-deprecated)
    target_compile_definitions(STM32_HAL_STM32F405xx PUBLIC STM32F405xx)

