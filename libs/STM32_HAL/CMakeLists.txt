project(STM32_HAL)

set(SOURCES
    config/stm32f0xx_hal_conf.h

    src/stm32f0xx/stm32f0xx_hal.c
    src/stm32f0xx/stm32f0xx_hal_can.c
    src/stm32f0xx/stm32f0xx_hal_cortex.c
    src/stm32f0xx/stm32f0xx_hal_flash.c
    src/stm32f0xx/stm32f0xx_hal_flash_ex.c
    src/stm32f0xx/stm32f0xx_hal_gpio.c
    src/stm32f0xx/stm32f0xx_hal_pcd.c
    src/stm32f0xx/stm32f0xx_hal_pcd_ex.c
    src/stm32f0xx/stm32f0xx_hal_rcc.c
    src/stm32f0xx/stm32f0xx_hal_rcc_ex.c
    src/stm32f0xx/stm32f0xx_hal_tim.c
    src/stm32f0xx/stm32f0xx_hal_tim_ex.c
    src/stm32f0xx/stm32f0xx_ll_usb.c

    src/newlib/assert.c
    src/newlib/_exit.c
    src/newlib/_sbrk.c
    src/newlib/_startup.c
    src/newlib/_syscalls.c

    src/cortexm/exception_handlers.c
    src/cortexm/_initialize_hardware.c
    src/cortexm/_reset_hardware.c

    src/cmsis/system_stm32f0xx.c
)

set(INCLUDE_DIRS
    include/
    include/cmsis
    include/stm32f0xx
    include/cmsis/device
    config/
)

add_library(STM32_HAL_STM32F042x6 OBJECT ${SOURCES} src/cmsis/startup_stm32f042x6.s)
    target_include_directories(STM32_HAL_STM32F042x6 PUBLIC ${INCLUDE_DIRS})
    target_compile_options(STM32_HAL_STM32F042x6 PRIVATE -Wno-unused-parameter)
    target_compile_definitions(STM32_HAL_STM32F042x6 PUBLIC STM32F042x6)

add_library(STM32_HAL_STM32F072xB OBJECT ${SOURCES} src/cmsis/startup_stm32f072xb.s)
    target_include_directories(STM32_HAL_STM32F072xB PUBLIC ${INCLUDE_DIRS})
    target_compile_options(STM32_HAL_STM32F072xB PRIVATE -Wno-unused-parameter)
    target_compile_definitions(STM32_HAL_STM32F072xB PUBLIC STM32F072xB)