/*
 * WDG_interface.h
 *
 *  Created on: 14 Oct 2023
 *      Author: Ali
 */

#ifndef WDG_INTERFACE_H_
#define WDG_INTERFACE_H_


#define WDG_16_3_ms 0
#define WDG_32_5_ms 1
#define WDG_65_ms   2
#define WDG_0_13_ms 3
#define WDG_0_26_ms 4
#define WDG_0_52_ms 5
#define WDG_1_s     6
#define WDG_2_1_s   7

void WDG_INIT(u8 Timeout);
void WDG_ENABLE(void);
void WDG_DISABLE(void);
void WDG_RESET(void);

#endif /* WDG_INTERFACE_H_ */
