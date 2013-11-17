/* 
 ArduMotorShield.h - Arduino library to control DC motos using the ArduMotorShield Shield
 Copyright 2013 Christian González (christiangda@gmail.com)
*/

#ifndef ArduMotorShieldrShield_h
#define ArduMotorShieldrShield_h

#include <Arduino.h>

// DEBUG
//#define DEBUG_ARDUMOTORSHIELD

// Arduino Pins for Arduino Motor Shield V3 
#define PIN_DIR_A  12
#define PIN_DIR_B  13
#define PIN_PWM_A  3
#define PIN_PWM_B  11
#define PIN_BRK_A  9
#define PIN_BRK_B  8
#define PIN_SNS_A  A0
#define PIN_SNS_B  A1

// Constants for movements (cmd)
#define FORWARD 1
#define BACKWARD 2

// Constants for movements (cmd)
#define MIN_SPEED	0
#define MAX_SPEED	255
#define AVG_SPEED	127

// Ports Identifiers
#define CHANNEL_A 1
#define CHANNEL_B 2

// Motor Structures
typedef struct 
{
	//PIN ports
	uint8_t PIN_DIR;
	uint8_t PIN_PWM;
	uint8_t PIN_BRK;
	uint8_t PIN_SNS;
	//Motor values
	uint8_t SPEED;
	uint8_t MOVE;
	uint8_t BRAKE;
} dc_motor_t;

/* Future implementation
typedef struct 
{
	//PIN ports
	//Motor values
} stepper_motor_t;
*/

//
class AMS_DCMotor
{
	public:
		AMS_DCMotor(uint8_t motor);		// Constructor
		~AMS_DCMotor();					// Destructor
		void begin();
		void move(uint8_t cmd);
		void setSpeed(uint8_t speed);
		void stop();
		void brake();
		void release();
		void releaseBrake();
		void stopAndBrake();
		void throttleUntil(uint8_t speed);
		uint8_t getSpeed();
		uint8_t getMove();
		uint8_t getBrake();
	
	private:
		void init(dc_motor_t* m);
		dc_motor_t _DCMOTOR;
};

/* Future implementation
class AMS_StepperMotor
{
	public:
		AMS_StepperMotor();		// Constructor
		~AMS_StepperMotor();	// Destructor
	
	private:
		void init(stepper_motor_t* m);
		stepper_motor_t _STEPPERMOTOR;
};
*/
#endif