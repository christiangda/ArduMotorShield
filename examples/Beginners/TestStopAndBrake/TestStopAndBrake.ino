/* Arduino Motor shield library (ArduMotorShield)
   copyright Christian González <christiangda@gmail.com>, 2013
   this code is public domain, enjoy!
*/

#include <ArduMotorShield.h>

AMS_DCMotor m_A(CHANNEL_A);

void setup() {
  // enable serial console
  Serial.begin(9600);  // set up Serial library at 9600 bps
  Serial.println("ArduMotorShield test!");
  
  // turn on motor
  m_A.begin();
}

void loop() {  
  Serial.println("Testing Motor A in Forward ...");
  m_A.move(FORWARD);
  
  Serial.println("Accelerating Motor A (setSpeed) ...");
  //accelerate 
  for (int i=0; i<255; i++) {
    m_A.setSpeed(i);
    delay(10);
  }
  
  delay(2000);

  Serial.println("Stoping Motor A (stop)...");
  m_A.stop();
  
  delay(2000);
  
  Serial.println("Accelerating Motor A again (setSpeed) ...");
  //accelerate 
  for (int i=0; i<255; i++) {
    m_A.setSpeed(i);
    delay(10);
  }
  
  delay(2000);

  Serial.println("Breaking Motor A (brake) without decelerate (no stop) ...");
  m_A.brake();
  
  delay(1000);
  
  Serial.println("Releasing breaking Motor A (releaseBrake) ...");
  m_A.releaseBrake();
  
  delay(3000);

  Serial.println("Stoping Motor A (stop)...");
  m_A.stop();
  
  delay(2000);

  Serial.println("Accelerating Motor A again ...");
  //accelerate 
  for (int i=0; i<255; i++) {
    m_A.setSpeed(i);
    delay(10);
  }
  
  Serial.println("Stopping and Breaking Motor A ...");
  m_A.stopAndBrake();
      
  while(1);
}
