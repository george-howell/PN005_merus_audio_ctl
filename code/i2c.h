/* i2c.h
*
* i2c functions using standard linux i2c driver module
*
* Created By: G. Howell
* Created On: 08/07/2020
*
*/

#ifndef INC_I2C_H_
#define INC_I2C_H_

/* function declarations */
void i2cOpen(uint8_t);
void i2cClose();
void i2cInit(uint8_t);
void i2cWrite (uint8_t*, uint32_t);
uint8_t* i2cRead (uint32_t);
uint8_t i2cEnRdByte(uint8_t);
void i2cEnWrByte(uint8_t, uint8_t);

#endif
