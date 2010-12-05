################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../ConsoleWindow.cpp \
../Format.cpp \
../Logger.cpp \
../conpix.cpp 

C_SRCS += \
../Rgb.c 

OBJS += \
./ConsoleWindow.o \
./Format.o \
./Logger.o \
./Rgb.o \
./conpix.o 

C_DEPS += \
./Rgb.d 

CPP_DEPS += \
./ConsoleWindow.d \
./Format.d \
./Logger.d \
./conpix.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/include/ncurses -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


