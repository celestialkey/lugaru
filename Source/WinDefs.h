/*
Copyright (C) 2003, 2010 - Wolfire Games

This file is part of Lugaru.

Lugaru is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

Lugaru is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Lugaru.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef _WINDEFS_H_
#define _WINDEFS_H_
#ifdef WIN32


#include <stdio.h>
#include <math.h>

// stuff to make Mac code compatable with Windows


// disable warnings about double to float conversions
#pragma warning(disable:4305)
#pragma warning(disable:4244)

// disable warnings about boolean to int conversions
#pragma warning(disable:4800)

// disable warning about unreferenced local variables
#pragma warning(disable:4101)

typedef bool Boolean;

struct Point {
    short v;
    short h;
};

typedef signed char SInt8;
typedef unsigned int UInt32;


#include "Random.h"


typedef struct AbsoluteTime {
    unsigned long   hi;
    unsigned long   lo;
} AbsoluteTime;

AbsoluteTime UpTime(); // NOTE: returns time since app started, not system start

typedef long Duration;

enum {
    durationMicrosecond             = -1,
    durationMillisecond             = 1,
    durationSecond                  = 1000,
    durationMinute                  = 1000 * 60,
    durationHour                    = 1000 * 60 * 60,
    durationDay                     = 1000 * 60 * 60 * 24,
    durationForever                 = 0x7FFFFFFF,
    durationImmediate               = 0,
};

Duration AbsoluteDeltaToDuration( AbsoluteTime& a, AbsoluteTime& b);


/*
inline bool isnormal( double x)
{
    int ret = _fpclass( x);
    return (ret == _FPCLASS_NN || ret == _FPCLASS_PN);
}
*/


// fix file names to use '/' instead of ':'
char* ConvertFileName( const char* orgfilename);
char* ConvertFileName( const char* orgfilename, const char* junk);


#define fopen(a, b) fopen(ConvertFileName(a), b);

#ifndef __MINGW32__
inline float abs(float f)
{
    if (f < 0)
        return -f;
    return f;
}

inline double abs(double f)
{
    if (f < 0)
        return -f;
    return f;
}
#endif // __MINGW32__


#endif
#endif
