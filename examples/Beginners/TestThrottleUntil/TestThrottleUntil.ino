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
  
  Serial.print("Motor A is moving: ");
  Serial.println(m_A.getMove());

  //accelerate 
  m_A.throttleUntil(MAX_SPEED);
  
  delay(4000);
  //decelerate
  m_A.throttleUntil(MIN_SPEED);  
  
  Serial.println("Testing Motor A in Backward ...");

  m_A.move(BACKWARD);
 
  Serial.print("Motor A is moving: ");
  Serial.println(m_A.getMove());
 
  //accelerate 
  m_A.throttleUntil(MAX_SPEED);
  
  delay(4000);
  //decelerate
  m_A.throttleUntil(MIN_SPEED);
  
  m_A.stop();
  m_A.brake();
  m_A.release();
  
  while(1);
}
