#ifndef STD_MATH_H
#define STD_MATH_H
#define SET_BIT(BYTE,bitNum) BYTE |= 1<<(bitNum)
/*
set bit:
'one byte' 
0000 0000 bit number 2
or
0000 0100 1<<2

*/
#define CLEAR_BIT(BYTE,bitNum) BYTE &= ~(1<<bitNum)
/*
clear bit:
'one byte' 
0100 1111 bit number 6
and 
0000 1111 !(1<<6)
*/
#define TOGGLE_BIT(BYTE,bitNum) BYTE^=(1<<bitNum)
/*
toggle bit:
'one byte' 

0000 1100 bit number 3
xor
0000 0100 ^(1<<3)

1 1 0
0 1 1
*/
#define GET_BIT(BYTE,bitNum) (BYTE>>bitNum)&0x01

/*
get bit:
'one byte' 
0101 0000 bit number 4
0101 0000 -> 4
0000 0101 and 0000 0001
=
0000 0001
*/

#endif
