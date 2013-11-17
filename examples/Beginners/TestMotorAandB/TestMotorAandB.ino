/* Arduino Motor shield library (ArduMotorShield)
   copyright Christian González <christiangda@gmail.com>, 2013
   this code is public domain, enjoy!
*/

#include <ArduMotorShield.h>

AMS_DCMotor m_A(CHANNEL_A);
AMS_DCMotor m_B(CHANNEL_B);

void setup() {
  // enable serial console
  Serial.begin(9600);  // set up Serial library at 9600 bps
  Serial.println("ArduMotorShield test!");
  
  // turn on motor
  m_A.begin();
  m_B.begin();
}

void loop() {  
  Serial.println("Testing Motor A in Forward and Motor B in Backward ...");
  
  m_A.move(FORWARD);
  m_B.move(BACKWARD);
  
  Serial.print("Motor A is moving: ");
  Serial.println(m_A.getMove());
  
  Serial.print("Motor B is moving: ");
  Serial.println(m_B.getMove());

  //accelerate 
  for (int i=0; i<255; i++) {
    m_A.setSpeed(i);
    m_B.setSpeed(i);
    delay(10);
  }
  //decelerate  
  for (int i=255; i!=0; i--) {
    m_A.setSpeed(i);
    m_B.setSpeed(i);  
    delay(10);
  }
  
  Serial.println("Testing Motor A in Backward and Motor B in Forward...");

  m_A.move(BACKWARD);
  m_B.move(FORWARD);
 
  Serial.print("Motor A is moving: ");
  Serial.println(m_A.getMove());
  
  Serial.print("Motor B is moving: ");
  Serial.println(m_B.getMove());
 
  //accelerate
  for (int i=0; i<255; i++) {
    m_A.setSpeed(i);
    m_B.setSpeed(i);
    delay(10);
  }
  //decelerate
  for (int i=255; i!=0; i--) {
    m_A.setSpeed(i);
    m_B.setSpeed(i);
    delay(10);
  }
  
  m_A.stop();
  m_B.stop();
  m_A.brake();
  m_B.brake();
  m_A.release();
  m_B.release();
  
  while(1);
}
