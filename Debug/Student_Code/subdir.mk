################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Student_Code/Archer.cpp \
../Student_Code/Arena.cpp \
../Student_Code/Cleric.cpp \
../Student_Code/Factory.cpp \
../Student_Code/Fighter.cpp \
../Student_Code/Robot.cpp 

OBJS += \
./Student_Code/Archer.o \
./Student_Code/Arena.o \
./Student_Code/Cleric.o \
./Student_Code/Factory.o \
./Student_Code/Fighter.o \
./Student_Code/Robot.o 

CPP_DEPS += \
./Student_Code/Archer.d \
./Student_Code/Arena.d \
./Student_Code/Cleric.d \
./Student_Code/Factory.d \
./Student_Code/Fighter.d \
./Student_Code/Robot.d 


# Each subdirectory must supply rules for building sources it contributes
Student_Code/%.o: ../Student_Code/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


