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
void CalibrateIR(){

  for (int i = 0; i < 400; i++)  // make the calibration take about 10 seconds
  {
    myStepper1.setSpeed(40);
    myStepper2.setSpeed(30);
    
    myStepper1.step(1);
    stepCount++;

    myStepper2.step(1);
    stepCount++;  


    latestVal1 = analogRead(IR1);
    if(latestVal1 < minVal1) {
      minVal1 = latestVal1; 
    }
    if(latestVal1 > maxVal1) {
      maxVal1 = latestVal1;  
    }

    latestVal2 = analogRead(IR2);
    if(latestVal2 < minVal2) {
      minVal2 = latestVal2; 
    }
    if(latestVal2 > maxVal2) {
      maxVal2 = latestVal2;  
    }

    Serial.print("MaxONE: ");
    Serial.print(maxVal1);
    Serial.print("MaxTWO: ");
    Serial.print(maxVal2);

    Serial.print("MinONE:");
    Serial.print(minVal1);
    Serial.print(" MinTWO: ");
    Serial.print(minVal2);

    Serial.print(" LatestONE: ");
    Serial.print(latestVal1);
    Serial.print(" LatestTWO: ");
    Serial.println(latestVal2);
  }
  Serial.println("CALIBRATED");
}


void CalibrateMotors(){
  int IRThreshold1 = maxVal1;
  int IRThreshold2 = maxVal2;

  myStepper1.step(CB1);
  delay(10);
  stepCount++;
  
 latestVal1 = analogRead(IR1);
  if (latestVal1 > IRThreshold1){
    Serial.println("TRUE 1");
    CB1=0;
  }

 latestVal2 = analogRead(IR2);
  myStepper2.step(CB2);
  delay(10);
  stepCount++; 

  if (latestVal2 > IRThreshold2){
    Serial.println("TRUE 2");
    CB2=0;

  } 


}






