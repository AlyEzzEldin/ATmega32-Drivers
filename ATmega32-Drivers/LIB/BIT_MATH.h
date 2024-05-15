/*
 * BIT_MATH.h
 *
 *  Created on: 1 Sep 2023
 *      Author: Ali
 */


#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define Set_Bit(Var,BitNo) Var=Var|(1<<BitNo)
#define Clr_Bit(Var,BitNo) 	Var=Var&(~(1<<BitNo))
#define Toggle_Bit(Var,BitNo) Var=Var^(1<<BitNo)
#define Get_Bit(Var,BitNo) ((Var>>BitNo)&1)

#endif /* BIT_MATH_H_ */
