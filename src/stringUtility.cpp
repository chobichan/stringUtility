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
      if( index == 0 ) return false;
      else if( *str == '.' )
      {
        if( ++count >= 2 ) return false;
      }
      else return false;
    }
    str++;
    index++;
  }
  return true;
}

/**********************************************************/
/* number  is true.                                       */
/**********************************************************/
bool isDigit( const char *str )
{
  while( *str )
  {
    if( !isdigit( *str ) ) return false;
    str++;
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

/**********************************************************/
/* like sprintf.                                          */
/**********************************************************/
String formatString( const char *fmt, ... )
{
  char buf[ 256 ];
  va_list args;
  va_start( args, fmt );
  vsnprintf( buf, sizeof(buf), fmt, args );
  va_end( args );

  return (String)buf;
}


/**********************************************************/
/* split character.                                       */
/**********************************************************/
int split( char *str , char *argv[], int sz )
{
  int argc = 0;

  while( *str != '\0' && argc < sz )
  {
    if( isgraph( (int)*str ) != 0 )
    {
      argv[ argc++ ] = str;
      while( *str != '\0' && isgraph( (int)*str ) != 0 ) str++;
    }
    else *str++ = '\0';
  }

  return argc;
}

int split( char comp, char *str , char *argv[], int sz )
{
  int argc = 0;
  char *origin = str;

  while( *str != '\0' && argc < sz )
  {
    if( *str != comp && isgraph( (int)*str ) != 0 )
    {
      argv[ argc++ ] = str;
      while( *str != '\0' && *str != comp && isgraph( (int)*str ) != 0 ) str++;
    }
    else if( *str == comp )
    {
      *str = '\0';
      if( str != origin && *(str - 1) == '\0' )
      {
        argv[ argc++ ] = str;
      }
      str++;
    }
    else *str++ = '\0';
  }

  return argc;
}


/**********************************************************/
/* character convert to int.                              */
/**********************************************************/
int char2Int( const char *str )
{
  if( !*str ) return 0;
  String s = str;
  return s.toInt();
}


/**********************************************************/
/* character convert to float.                            */
/**********************************************************/
float char2Float( const char *str )
{
  if( !*str ) return 0.0F;
  String s = str;
  return s.toFloat();
}

/**********************************************************/
/* character convert to character.                        */
/**********************************************************/
char char2Char( const char *str )
{
  if( !*str ) return 0;
  return *str;
}

