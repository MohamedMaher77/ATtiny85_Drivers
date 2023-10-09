/* 
 * File:   mcal_std_types.h
 * Author: HP
 *
 * Created on October 5, 2023, 6:56 PM
 */

#ifndef MCAL_STD_TYPES_H
#define	MCAL_STD_TYPES_H
/* section: includes */
#include"std_libraries.h"
#include"compiler.h"

/* section: macro declaration */
#define STD_HIGH      0X01
#define STD_LOW       0X00

#define STD_ON        0X01
#define STD_OFF       0X00

#define STD_ACTIVE    0X01
#define STD_IDLE      0X00

#define E_OK           (Std_ReturnType)0x01
#define E_NOT_OK       (Std_ReturnType)0x00
/* section: macro function declarations */

/* section: data type declarations */
typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;
typedef signed char sint8;
typedef signed short sint16;
typedef signed int sint32;

typedef uint8 Std_ReturnType;







/* section: function declarations */


#endif	/* MCAL_STD_TYPES_H */
