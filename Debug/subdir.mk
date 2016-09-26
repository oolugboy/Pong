################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Shader.cpp \
../Transform.cpp \
../display.cpp \
../main.cpp \
../mesh.cpp \
../obj_loader.cpp 

OBJS += \
./Shader.o \
./Transform.o \
./display.o \
./main.o \
./mesh.o \
./obj_loader.o 

CPP_DEPS += \
./Shader.d \
./Transform.d \
./display.d \
./main.d \
./mesh.d \
./obj_loader.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


