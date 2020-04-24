/***********************************************************************/
/* date and time utility header                                        */
/*                    Copyright (C) 2014 hamayan All Rights Reserved.  */
/*                                           hamayan.contact@gmail.com */
/***********************************************************************/
#include  "stringUtility.h"

extern "C"
{
}

/**********************************************************/
/* defines                                                */
/**********************************************************/


/**********************************************************/
/* global variables                                       */
/**********************************************************/


/**********************************************************/
/* constructor,destructor                                 */
/**********************************************************/


/**********************************************************/
/* alphabet and number and any more are true.             */
/**********************************************************/
bool isAlnumAndAny( const char *str )
{
  while( *str )
  {
    if( !isalnum( *str ) && !(*str == '_') && !(*str == '-')  ) return false;
    str++;
  }
  return true;
}

/**********************************************************/
/* number and comma are true.                             */
/**********************************************************/
bool isDigitAndComma( const char *str )
{
  int count = 0;
  int index = 0;
  while( *str )
  {
    if( !isdigit( *str ) )
    {
      if( index == 0 ) return (-1);
      else if( *str == '.' )
      {
        if( ++count >= 2 ) return (-1);
      }
      else return false;
    }
    str++;
    index++;
  }
  return true;
}

/**********************************************************/
/* binary to hex string.                                  */
/**********************************************************/
String binToHexString( uint32_t bin, int radix )
{
  static const char hex[] = "0123456789ABCDEF";
  int mod = bin % 16;
  String str = (String)hex[ mod ];
  bin -= mod;

  for( int i = 1; i < radix; i++ )
  {
    bin >>= 4;
    mod = bin % 16;
    str = (String)hex[ mod ] + str;
  }

  return str;
}


