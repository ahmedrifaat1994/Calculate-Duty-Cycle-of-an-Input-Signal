/*
 * timer1.h
 *
 *  Created on: 6 Jun 2021
 *      Author: A.Rifaat
 */

#ifndef TIMER1_H_
#define TIMER1_H_

#include"common_macros.h"
#include"micro_config.h"
#include"std_types.h"


void TIMER1_init(void);
void TIMER1_start(void);
uint16 TIMER1_read (void);

#endif /* TIMER1_H_ */
