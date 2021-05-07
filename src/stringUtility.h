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
bool isDigit( const char *str );

String binToHexString( uint32_t bin, int radix = 2 );
uint32_t HexStringToBin( const char *str, int radix = 2 );
int32_t  IntStringToBin( const char *str, int radix = 2 );

String formatString( const char *fmt, ... );

int split( char *str , char *argv[], int sz );
int split( char comp, char *str , char *argv[], int sz );

int char2Int( const char *str );
float char2Float( const char *str );
char char2Char( const char *str );

#endif  /* _STRING_UTILITY_H_ */

/***********************************************************************/
/*                    Copyright (C) 2020 hamayan All Rights Reserved.  */
/*                                           hamayan.contact@gmail.com */
/***********************************************************************/
