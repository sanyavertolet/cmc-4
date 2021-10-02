################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../con-3-complex-eval.cpp \
../con-3-complex-main.cpp \
../con-3-complex.cpp \
../con-3-complex_stack.cpp 

OBJS += \
./con-3-complex-eval.o \
./con-3-complex-main.o \
./con-3-complex.o \
./con-3-complex_stack.o 

CPP_DEPS += \
./con-3-complex-eval.d \
./con-3-complex-main.d \
./con-3-complex.d \
./con-3-complex_stack.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


