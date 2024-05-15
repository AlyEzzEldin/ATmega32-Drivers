/*
 * PUSHBUTTON_interface.h
 *
 *  Created on: 13 Sep 2023
 *      Author: Ali
 */

#ifndef PUSHBUTTON_INTERFACE_H_
#define PUSHBUTTON_INTERFACE_H_

void SWITCH_INIT(u8 Port , u8 Pin);
void DIP_SWITCH_INIT(u8 Port);

u8 GET_SWITCH_STATE(u8 Port,u8 Pin);
u8 GET_DIP_SWITCH_STATE(u8 Port);


#endif /* PUSHBUTTON_INTERFACE_H_ */
