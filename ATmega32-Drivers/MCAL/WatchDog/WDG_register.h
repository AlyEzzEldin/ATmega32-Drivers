/*
 * WGD_register.h
 *
 *  Created on: 14 Oct 2023
 *      Author: Ali
 */

#ifndef WDG_REGISTER_H_
#define WDG_REGISTER_H_

#define WDTCR_register  *((volatile u8*)(0x41))

#define WDTOE 4
#define WDE 3
#define WDP2 2
#define WDP1 1
#define WDP0 0

#endif /* WDG_REGISTER_H_ */
