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

