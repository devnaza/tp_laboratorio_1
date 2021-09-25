################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/SantaCruzTP1.c \
../src/UTN_FUNCIONES_PROPIAS.c 

OBJS += \
./src/SantaCruzTP1.o \
./src/UTN_FUNCIONES_PROPIAS.o 

C_DEPS += \
./src/SantaCruzTP1.d \
./src/UTN_FUNCIONES_PROPIAS.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


