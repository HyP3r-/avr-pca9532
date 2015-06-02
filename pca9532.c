/*
 * pca9532.c
 *
 * Created: 26.01.2015
 *  Author: HyP3r
 */ 
 
#include "pca9532.h"

void pca9532_set_prescaler(uint8_t index, uint8_t value) {
	// wrong index
	if (index > 1) return;
	// write data
	i2c_start_wait(PCA9532_ADDRESS + I2C_WRITE);
	if (index == 0) {
		i2c_write(PCA9532_PSC0);
	} else {
		i2c_write(PCA9532_PSC1);
	}
	i2c_write(value);
	i2c_stop();
}

void pca9532_set_pwm(uint8_t index, uint8_t value) {
	// wrong index
	if (index > 1) return;
	i2c_start_wait(PCA9532_ADDRESS + I2C_WRITE);
	// write data
	if (index == 0) {
		i2c_write(PCA9532_PWM0);
	} else {
		i2c_write(PCA9532_PWM1);
	}
	i2c_write(value);
	i2c_stop();
}

// mode:
// 0 = off
// 1 = on
// 2 = PWM0
// 3 = PWM1
void pca9532_set_led_mode(uint8_t index, uint8_t mode) {
	// first determine which ls we have to read
	uint8_t ls_content;
	uint8_t ls_address;
	if (index > 15) return;
	if (index >= 0 && index <= 3) ls_address = PCA9532_LS0;
	if (index >= 4 && index <= 7) ls_address = PCA9532_LS1;
	if (index >= 8 && index <= 11) ls_address = PCA9532_LS2;
	if (index >= 12 && index <= 15) ls_address = PCA9532_LS3;	
	
	// read the ls
	i2c_rep_start(PCA9532_ADDRESS + I2C_READ);
	i2c_write(ls_address);
	ls_content = i2c_readNak();
	i2c_stop();
	
	// modify readed data
	ls_content &= ~(0b11 << (index % 4));
	ls_content |= mode << (index % 4);
	
	// write data back
	i2c_start_wait(PCA9532_ADDRESS + I2C_WRITE);
	i2c_write(ls_address);
	i2c_write(ls_content);
	i2c_stop();
}