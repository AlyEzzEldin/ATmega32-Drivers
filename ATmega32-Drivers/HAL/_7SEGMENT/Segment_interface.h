/*
 * Segment_interface.h
 *
 *  Created on: 8 Sep 2023
 *      Author: Ali
 */

#ifndef SEGMENT_INTERFACE_H_
#define SEGMENT_INTERFACE_H_

#define COMMON_CATHODE 0
#define COMMON_ANODE 1

#define SEGMENT_ZERO  0b00111111
#define SEGMENT_ONE   0b00000110
#define SEGMENT_TWO   0b01011011
#define SEGMENT_THREE 0b01001111
#define SEGMENT_FOUR  0b01100110
#define SEGMENT_FIVE  0b01101101
#define SEGMENT_SIX   0b01111101
#define SEGMENT_SEVEN 0b00000111
#define SEGMENT_EIGHT 0b01111111
#define SEGMENT_NINE  0b01101111

void SEGMENT_INIT(u8 DataPort,u8 ControlPort,u8 ControlPin,u8 SegmentType);
void SEGMENT_ENABLE(u8 ControlPort,u8 ControlPin,u8 SegmentType);
void SEGMENT_DISABLE(u8 ControlPort,u8 ControlPin,u8 SegmentType);
void SEGMENT_DISPLAY_NUMBER(u8 DataPort,u8 SegmentType,u8 Number);


#endif /* SEGMENT_INTERFACE_H_ */
