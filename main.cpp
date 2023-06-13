//Made By Levi A aka https://github.com/BioShot \\


#pragma region VEXcode Generated Robot Configuration
// Make sure all required headers are included.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>


#include "vex.h"

using namespace vex;

// Brain should be defined by default
brain Brain;


// START IQ MACROS
#define waitUntil(condition)                                                   \
  do {                                                                         \
    wait(5, msec);                                                             \
  } while (!(condition))

#define repeat(iterations)                                                     \
  for (int iterator = 0; iterator < iterations; iterator++)
// END IQ MACROS


// Robot configuration code.
bumper Bumper12 = bumper(PORT12);
motor leftMotorA = motor(PORT7, 1, false);
motor leftMotorB = motor(PORT8, 1, false);
motor_group LeftDriveSmart = motor_group(leftMotorA, leftMotorB);
motor rightMotorA = motor(PORT10, 1, true);
motor rightMotorB = motor(PORT11, 1, true);
motor_group RightDriveSmart = motor_group(rightMotorA, rightMotorB);
drivetrain Drivetrain = drivetrain(LeftDriveSmart, RightDriveSmart, 200, 173, 76, mm, 1);
#pragma endregion VEXcode Generated Robot Configuration

// Include the IQ Library
#include "vex.h"
  
// Allows for easier use of the VEX Library
using namespace vex;

int Brain_precision = 0, Console_precision = 0;

float currentThread;
// "when started" hat block


class customFeatures{
  long calcuteMoveBump(){
      return 0;
  }

  void Move(int direction){
    /* 
    1: left, 2: right, 3 up , 4 down
    */ 
    
  };
};

  
bool hasStarted = false;

int startMove(void){
  Drivetrain.drive(forward);
}

void onBumperTouch(){
  if(hasStarted){
     Brain.Screen.print("Hey! Move!");
    Drivetrain.drive(reverse);
    wait(3,seconds);
    startMove(void);
  }else{
      hasStarted = true; 
    Brain.Screen.print("Goodbye!"); 
    wait(1,seconds);
  
    Brain.Screen.clearScreen();
    Brain.Screen.print("I am Speed!");
    startMove(void);
  }
 
}

int whenStarted1() {

  Brain.Screen.print("Press the bumper.");
  Bumper12.pressed(onBumperTouch);
  return 0;
}


int main() {
  whenStarted1();
}
