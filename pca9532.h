/*
 * pca9532.h
 *
 * Created: 26.01.2015
 *  Author: HyP3r
 */ 


#ifndef PCA9532_H_
#define PCA9532_H_

#include "i2cmaster.h"

// address
#define PCA9532_ADDRESS 0b11000000

// registers
#define PCA9532_INPUT0 0b00000000
#define PCA9532_INPUT1 0b00000001
#define PCA9532_PSC0 0b00000010
#define PCA9532_PWM0 0b00000011
#define PCA9532_PSC1 0b00000100
#define PCA9532_PWM1 0b00000101
#define PCA9532_LS0 0b00000110
#define PCA9532_LS1 0b00000111
#define PCA9532_LS2 0b00001000
#define PCA9532_LS3 0b00001001

// states
#define PCA9532_LED_OFF 0b00
#define PCA9532_LED_ON 0b01
#define PCA9532_LED_PWM0 0b10
#define PCA9532_LED_PWM1 0b11

// functions 
extern void pca9532_set_prescaler(uint8_t index, uint8_t value);
extern void pca9532_set_pwm(uint8_t index, uint8_t value);
extern void pca9532_set_led_mode(uint8_t index, uint8_t mode);

#endif /* PCA9532_H_ */