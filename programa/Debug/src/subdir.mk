################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Controller.c \
../src/LinkedList.c \
../src/Menu.c \
../src/libro.c \
../src/parser.c \
../src/pedir_valores.c \
../src/programa.c 

OBJS += \
./src/Controller.o \
./src/LinkedList.o \
./src/Menu.o \
./src/libro.o \
./src/parser.o \
./src/pedir_valores.o \
./src/programa.o 

C_DEPS += \
./src/Controller.d \
./src/LinkedList.d \
./src/Menu.d \
./src/libro.d \
./src/parser.d \
./src/pedir_valores.d \
./src/programa.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


