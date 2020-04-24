/***********************************************************************/
/* string utility header                                               */
/*                    Copyright (C) 2020 hamayan All Rights Reserved.  */
/*                                           hamayan.contact@gmail.com */
/***********************************************************************/
#ifndef _STRING_UTILITY_H_
#define _STRING_UTILITY_H_

#include  <Arduino.h>

extern "C"
{
  #include  <time.h>
  #include  <stdlib.h>
  #include  <string.h>
  #include  <ctype.h>
}

/*
  prototype
*/
bool isAlnumAndAny( const char *str );
bool isDigitAndComma( const char *str );
String binToHexString( uint32_t bin, int radix = 2 );


#endif  /* _STRING_UTILITY_H_ */

/***********************************************************************/
/*                    Copyright (C) 2020 hamayan All Rights Reserved.  */
/*                                           hamayan.contact@gmail.com */
/***********************************************************************/
