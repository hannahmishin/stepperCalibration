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
