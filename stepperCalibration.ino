#include <QTRSensors.h>
#include <Stepper.h>

///INFRA////
byte IR1=0;
byte IR2=1;
int latestVal1=0;
int latestVal2=0;
int maxVal1=0;
int maxVal2=0;
int minVal1=1024; 
int minVal2=1024; 

int CB1= 1;
int CB2= 1;

//STEPPPPPPPPEEERRRR
#define DIR_PIN 2
#define STEP_PIN 3

const int stepsPerRevolution1 = 512;  // change this to fit the number of steps per revolution
// for your motor
// initialize the stepper library on pins 8 through 11:
Stepper myStepper2(stepsPerRevolution1, 8,9,10,11);   
// initialize the stepper library on pins 8 through 11:
Stepper myStepper1(stepsPerRevolution1, 2,3,4,5); 
int stepCount = 0;         // number of steps the motor has taken

void setup(){
  Serial.begin(9600);
  ////IR////
  CalibrateIR();
}

void loop(){
  CalibrateMotors();
}










