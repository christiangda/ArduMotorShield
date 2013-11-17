/* 
 ArduMotorShield.cpp - Arduino library to control DC motors using the Arduino Motor Shield V3
 Copyright 2013 Christian González (christiangda@gmail.com)
*/
#include <Arduino.h>

// Local Headers
#include "ArduMotorShield.h"

/*
 CLASS AMS_DCMotor
*/
AMS_DCMotor::AMS_DCMotor(uint8_t motor)
{	
	switch (motor)
	{
		case CHANNEL_A:
			_DCMOTOR.PIN_DIR = PIN_DIR_A;
			_DCMOTOR.PIN_PWM = PIN_PWM_A;
			_DCMOTOR.PIN_BRK = PIN_BRK_A;
			_DCMOTOR.PIN_SNS = PIN_SNS_A;
			break;
		case CHANNEL_B:
			_DCMOTOR.PIN_DIR = PIN_DIR_B;
			_DCMOTOR.PIN_PWM = PIN_PWM_B;
			_DCMOTOR.PIN_BRK = PIN_BRK_B;
			_DCMOTOR.PIN_SNS = PIN_SNS_B;
			break;
	default:
		return;
  }
}

// Constructor
AMS_DCMotor::~AMS_DCMotor()
{
	//do something here? (free(), delete()?)
}

// Initialization
void AMS_DCMotor::begin()
{
	init(&_DCMOTOR);
}

// 
void AMS_DCMotor::init(dc_motor_t* m)
{
	pinMode(m->PIN_DIR, OUTPUT);
	pinMode(m->PIN_PWM, OUTPUT);
	pinMode(m->PIN_BRK, OUTPUT);
	pinMode(m->PIN_SNS, INPUT);
	release();
}

//
void AMS_DCMotor::move(uint8_t cmd)
{
	switch (cmd) {
		case FORWARD:
			release();
			digitalWrite(_DCMOTOR.PIN_DIR, HIGH);
			_DCMOTOR.MOVE = FORWARD;
			break;
		case BACKWARD:
			release();
			digitalWrite(_DCMOTOR.PIN_DIR, LOW);
			_DCMOTOR.MOVE = BACKWARD;
			break;
		default:
			return;
  }	
}

//
void AMS_DCMotor::setSpeed(uint8_t speed)
{
	analogWrite(_DCMOTOR.PIN_PWM, speed);
	_DCMOTOR.SPEED = speed;
}

//
void AMS_DCMotor::throttleUntil(uint8_t speed)
{
	if ( speed < _DCMOTOR.SPEED )
	{
		// accelerate
		for (int i=_DCMOTOR.SPEED; i<speed; i++) 
		{
			setSpeed(i);
			delay(10);
		}
	}
	else if ( speed > _DCMOTOR.SPEED )
	{
		//decelerate  
		for (int i=speed; i>_DCMOTOR.SPEED; i--) {
			setSpeed(i);
			delay(10);
		}
	}
}

// 
void AMS_DCMotor::stop()
{
	setSpeed(MIN_SPEED);
}

// 
void AMS_DCMotor::brake()
{
	digitalWrite(_DCMOTOR.PIN_BRK, HIGH);
	_DCMOTOR.BRAKE = HIGH;
}

// Release the motor, releasing the brake
void AMS_DCMotor::release()
{
	setSpeed(MIN_SPEED); //Release motor
	digitalWrite(_DCMOTOR.PIN_DIR, HIGH); //Forward direction
	digitalWrite(_DCMOTOR.PIN_BRK, LOW); //Release de brake
	_DCMOTOR.MOVE = FORWARD; //Set status
	_DCMOTOR.BRAKE = LOW; //Set status
}

// Releasing the brake
void AMS_DCMotor::releaseBrake()
{
	digitalWrite(_DCMOTOR.PIN_BRK, LOW);
	_DCMOTOR.BRAKE = LOW;
}

// Release the motor, releasing the brake
void AMS_DCMotor::stopAndBrake()
{
	stop();
	brake();
}

//
uint8_t AMS_DCMotor::getSpeed()
{
	return _DCMOTOR.SPEED;
}

//
uint8_t AMS_DCMotor::getMove()
{
	return _DCMOTOR.MOVE;
}

//
uint8_t AMS_DCMotor::getBrake()
{
	return _DCMOTOR.BRAKE;
}

/*
	CLASS AMS_StepperMotor
*/
/* Future implementation
AMS_StepperMotor::AMS_StepperMotor()
{
	//
}

// Destructor
AMS_StepperMotor::~AMS_StepperMotor()
{
	//do something here? (free(), delete()?)
}

// 
void AMS_DCMotor::init(stepper_motor_t* m)
{
	//
}
*/