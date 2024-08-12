#include "ESP32Servo.h"
#include "Servo.h"

Servo myServo[ServoNum];
int Servo_target[ServoNum];

#define servo0Pin 02

// Published values for SG90 servos; adjust if needed
#define MIN_MICROS      800  //544
#define MAX_MICROS      2450

void Servo_init(void)
{
    myServo[0].attach(servo0Pin,MIN_MICROS,MAX_MICROS);
}

void Servo_control(void)
{
    for(uint8_t i; i<ServoNum ; i++)
    {
        myServo[i].write(Servo_target[i]);
    }

}
