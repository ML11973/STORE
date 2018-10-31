################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/Middleware/input.c \
../Src/Middleware/triac.c 

OBJS += \
./Src/Middleware/input.o \
./Src/Middleware/triac.o 

C_DEPS += \
./Src/Middleware/input.d \
./Src/Middleware/triac.d 


# Each subdirectory must supply rules for building sources it contributes
Src/Middleware/%.o: ../Src/Middleware/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -mfloat-abi=soft '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F103xB -I"C:/Users/marc_/git/STORE/Inc" -I"C:/Users/marc_/git/STORE/Drivers/STM32F1xx_HAL_Driver/Inc" -I"C:/Users/marc_/git/STORE/Drivers/STM32F1xx_HAL_Driver/Inc/Legacy" -I"C:/Users/marc_/git/STORE/Drivers/CMSIS/Device/ST/STM32F1xx/Include" -I"C:/Users/marc_/git/STORE/Drivers/CMSIS/Include"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


