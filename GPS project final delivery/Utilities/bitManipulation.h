/*
 * bitManipulation.h
 *
 * Created: 9/9/2022 4:34:21 PM
 *  Author: hp
 */ 


#ifndef BITMANIPULATION_H_
#define BITMANIPULATION_H_

#define CLEAR_BIT(REG,NUM) REG&=~(1<<NUM)
#define SET_BIT(REG,NUM) REG|=(1<<NUM)
#define TOGGLE_BIT(REG,NUM) REG^=(1<<NUM)
#define READ_BIT(REG,NUM) ((REG&(1<<NUM))>>NUM)

#endif /* BITMANIPULATION_H_ */

