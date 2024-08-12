#ifndef __SERVO_H
#define __SERVO_H

#define ServoNum 8

extern int Servo_target[ServoNum];


void Servo_init(void);
void Servo_control(void);


#endif
