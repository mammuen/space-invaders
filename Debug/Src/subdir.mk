################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/30010_io.c \
../Src/LCDdisplay.c \
../Src/ansi.c \
../Src/game.c \
../Src/joystick.c \
../Src/main.c \
../Src/menu.c \
../Src/speaker.c \
../Src/syscalls.c \
../Src/sysmem.c \
../Src/system_stm32f30x.c \
../Src/timer.c 

OBJS += \
./Src/30010_io.o \
./Src/LCDdisplay.o \
./Src/ansi.o \
./Src/game.o \
./Src/joystick.o \
./Src/main.o \
./Src/menu.o \
./Src/speaker.o \
./Src/syscalls.o \
./Src/sysmem.o \
./Src/system_stm32f30x.o \
./Src/timer.o 

C_DEPS += \
./Src/30010_io.d \
./Src/LCDdisplay.d \
./Src/ansi.d \
./Src/game.d \
./Src/joystick.d \
./Src/main.d \
./Src/menu.d \
./Src/speaker.d \
./Src/syscalls.d \
./Src/sysmem.d \
./Src/system_stm32f30x.d \
./Src/timer.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F302R8Tx -DSTM32F3 -DNUCLEO_F302R8 -DDEBUG -DUSE_STDPERIPH_DRIVER=1 -c -I"/Users/oscar/Documents/c/30010/space-invaders/SPL/inc" -I"/Users/oscar/Documents/c/30010/space-invaders/Inc" -I"/Users/oscar/Documents/c/30010/space-invaders/cmsis" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/30010_io.d ./Src/30010_io.o ./Src/LCDdisplay.d ./Src/LCDdisplay.o ./Src/ansi.d ./Src/ansi.o ./Src/game.d ./Src/game.o ./Src/joystick.d ./Src/joystick.o ./Src/main.d ./Src/main.o ./Src/menu.d ./Src/menu.o ./Src/speaker.d ./Src/speaker.o ./Src/syscalls.d ./Src/syscalls.o ./Src/sysmem.d ./Src/sysmem.o ./Src/system_stm32f30x.d ./Src/system_stm32f30x.o ./Src/timer.d ./Src/timer.o

.PHONY: clean-Src

