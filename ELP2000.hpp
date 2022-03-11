/*
 * ELP2000.h
 *
 * Copyright (c) 2017 by Sebastien MARCHAND (Web:www.marscaper.com, Email:sebastien@marscaper.com)
 */
/*
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include<cstdint>

#ifndef ELP2000_h
#define ELP2000_h

#if ARDUINO
#define CONST const PROGMEM
#else
#define CONST const
#endif

struct ELP2000Coefficient
{
    int8_t Ec;
    int8_t D;
    int8_t M;
    int8_t Mp;
    int8_t F;
};

CONST float LMoonCoefficients[] =
{
    6288774,
    1274027,
     658314,
     213618,
    -185116,
    -114332,
      58793,
      57066,
      53322,
      45758,
     -40923,
     -34720,
     -30383,
      15327,
     -12528,
      10980,
      10675,
      10034,
       8548,
      -7888,
      -6766,
      -5163,
       4987,
       4036,
       3994,
       3861,
       3665,
      -2689,
      -2602,
       2390,
      -2348,
       2236,
      -2120,
      -2069,
       2048,
      -1773,
      -1595,
       1215,
      -1110,
       -892,
       -810,
        759,
       -713,
       -700,
        691,
        596,
        549,
        537,
        520,
       -487,
       -399,
       -381,
        351,
       -340,
        330,
        327,
       -323,
        299,
        294,
       -275
};

CONST ELP2000Coefficient LMoonAngleCoefficients[] =
{
    //Ec  D   M   Mp  F
    { 0,  0,  0,  1,  0 },
    { 0,  2,  0, -1,  0 },
    { 0,  2,  0,  0,  0 },
    { 0,  0,  0,  2,  0 },
    { 1,  0,  1,  0,  0 },
    { 0,  0,  0,  0,  2 },
    { 0,  2,  0, -2,  0 },
    { 1,  2, -1, -1,  0 },
    { 0,  2,  0,  1,  0 },
    { 1,  2, -1,  0,  0 },
    { 1,  0,  1, -1,  0 },
    { 0,  1,  0,  0,  0 },
    { 1,  0,  1,  1,  0 },
    { 0,  2,  0,  0, -2 },
    { 0,  0,  0,  1,  2 },
    { 0,  0,  0,  1, -2 },
    { 0,  4,  0, -1,  0 },
    { 0,  0,  0,  3,  0 },
    { 0,  4,  0, -2,  0 },
    { 1,  2,  1, -1,  0 },
    { 1,  2,  1,  0,  0 },
    { 0,  1,  0, -1,  0 },
    { 1,  1,  1,  0,  0 },
    { 1,  2, -1,  1,  0 },
    { 0,  2,  0,  2,  0 },
    { 0,  4,  0,  0,  0 },
    { 0,  2,  0, -3,  0 },
    { 1,  0,  1, -2,  0 },
    { 0,  2,  0, -1,  2 },
    { 1,  2, -1, -2,  0 },
    { 0,  1,  0,  1,  0 },
    { 2,  2, -2,  0,  0 },
    { 1,  0,  1,  2,  0 },
    { 2,  0,  2,  0,  0 },
    { 2,  2, -2, -1,  0 },
    { 0,  2,  0,  1, -2 },
    { 0,  2,  0,  0,  2 },
    { 1,  4, -1, -1,  0 },
    { 0,  0,  0,  2,  2 },
    { 0,  3,  0, -1,  0 },
    { 1,  2,  1,  1,  0 },
    { 1,  4, -1, -2,  0 },
    { 2,  0,  2, -1,  0 },
    { 2,  2,  2, -1,  0 },
    { 1,  2,  1, -2,  0 },
    { 1,  2, -1,  0, -2 },
    { 0,  4,  0,  1,  0 },
    { 0,  0,  0,  4,  0 },
    { 1,  4, -1,  0,  0 },
    { 0,  1,  0, -2,  0 },
    { 1,  2,  1,  0, -2 },
    { 0,  0,  0,  2, -2 },
    { 1,  1,  1,  1,  0 },
    { 0,  3,  0, -2,  0 },
    { 0,  4,  0, -3,  0 },
    { 1,  2, -1,  2,  0 },
    { 2,  0,  2,  1,  0 },
    { 1,  1,  1, -1,  0 },
    { 0,  2,  0,  3,  0 },
    { 0,  2,  0,  1,  2 }
};


CONST float BMoonCoefficients[] =
{
    5128122,
     280602,
     277693,
     173237,
      55413,
      46271,
      32573,
      17198,
       9266,
       8822,
       8216,
       4324,
       4200,
      -3359,
       2463,
       2211,
       2065,
      -1870,
       1828,
      -1794,
      -1749,
      -1565,
      -1491,
      -1475,
      -1410,
      -1344,
      -1335,
       1107,
       1021,
        833,
        777,
        671,
        607,
        596,
        491,
       -451,
        439,
        422,
        421,
       -366,
       -351,
        331,
        315,
        302,
       -283,
       -229,
        223,
        223,
       -220,
       -220,
       -185,
        181,
       -177,
        176,
        166,
       -164,
        132,
       -119,
        115,
        107
};

CONST ELP2000Coefficient BMoonAngleCoefficients[] =
{
    //Ec  D   M   Mp  F
    { 0,  0,  0,  0,  1 },
    { 0,  0,  0,  1,  1 },
    { 0,  0,  0,  1, -1 },
    { 0,  2,  0,  0, -1 },
    { 0,  2,  0, -1,  1 },
    { 0,  2,  0, -1, -1 },
    { 0,  2,  0,  0,  1 },
    { 0,  0,  0,  2,  1 },
    { 0,  2,  0,  1, -1 },
    { 0,  0,  0, -2, -1 },
    { 1,  2, -1,  0, -1 },
    { 0,  2, -1,  0,  1 },
    { 0,  2,  0, -2, -1 },
    { 1,  2,  1,  0, -1 },
    { 1,  2, -1, -1,  1 },
    { 1,  2, -1,  0,  1 },
    { 1,  2, -1, -1, -1 },
    { 1,  0,  1, -1, -1 },
    { 0,  4,  0, -1, -1 },
    { 1,  0,  1,  0,  1 },
    { 0,  0,  0,  0,  3 },
    { 1,  0,  1, -1,  1 },
    { 0,  1,  0,  0,  1 },
    { 1,  0,  1,  1,  1 },
    { 1,  0,  1,  1, -1 },
    { 1,  0,  1,  0, -1 },
    { 0,  1,  0,  0, -1 },
    { 0,  0,  0,  3,  1 },
    { 0,  4,  0,  0, -1 },
    { 0,  4,  0, -1,  1 },
    { 0,  0,  0,  1, -3 },
    { 0,  4,  0, -2,  1 },
    { 0,  2,  0,  0, -3 },
    { 0,  2,  0,  2, -1 },
    { 1,  2, -1,  1, -1 },
    { 0,  2,  0, -2,  1 },
    { 0,  0,  0,  3, -1 },
    { 0,  2,  0,  2,  1 },
    { 0,  2,  0, -3, -1 },
    { 1,  2,  1, -1,  1 },
    { 1,  2,  1,  0,  1 },
    { 0,  4,  0,  0,  1 },
    { 1,  2, -1,  1,  1 },
    { 2,  2,  2,  0, -1 },
    { 0,  0,  0,  1,  3 },
    { 1,  2,  1,  1, -1 },
    { 1,  1,  1,  0, -1 },
    { 1,  1,  1,  0,  1 },
    { 1,  0,  1, -2,  1 },
    { 1,  2,  1, -1, -1 },
    { 0,  1,  0,  1,  1 },
    { 1,  2, -1, -2, -1 },
    { 1,  0,  1,  2,  1 },
    { 0,  4,  0, -2, -1 },
    { 1,  4, -1, -1, -1 },
    { 0,  1,  0,  1, -1 },
    { 0,  4,  0,  1, -1 },
    { 0,  1,  0, -1, -1 },
    { 1,  4, -1,  0, -1 },
    { 2,  2, -2,  0,  1 }
};


CONST float RMoonCoefficients[] =
{
    -4572.237417,
    -1923.307308,
    -1719.292878,
     -754.933772,
      496.143125,
     -452.311839,
     -413.198500,
     -390.048715,
     -360.027777,
      329.762035,
      323.658771,
      282.242803,
      221.106309,
     -186.499330,
      175.567651,
      155.589203,
     -152.348285,
     -147.091808,
     -129.131716,
      120.012499,
     -113.274004,
     -107.935166,
     -102.200783,
      101.592323,
      100.279609,
      -99.418308,
       93.552125,
      -91.536878,
      -83.683929,
       79.511006,
       75.835348,
      -70.356236,
      -66.490601,
       64.265076,
      -62.912638,
       57.078893,
      -56.115951,
       51.146847,
       48.518038,
      -46.010868,
      -43.554563,
      -41.701319,
      -39.635842,
      -37.722672,
       34.132096,
      -33.421550
};

CONST ELP2000Coefficient RMoonAngleCoefficients[] =
{
    //Ec  D   M   Mp  F
    { 0,  0,  0,  1,  0 },
    { 0,  2,  0, -1,  0 },
    { 0,  2,  0,  0,  0 },
    { 0,  0,  0,  2,  0 },
    { 0,  2,  0, -2,  0 },
    { 1,  2,  0, -1,  0 },
    { 0,  2,  0,  1,  0 },
    { 1,  2, -1, -1,  0 },
    { 1,  0,  1, -1,  0 },
    { 0,  1,  0,  0,  0 },
    { 1,  0,  1,  1,  0 },
    { 0,  0,  1,  0, -2 },
    { 1,  0,  1,  0,  0 },
    { 0,  4,  0, -1,  0 },
    { 1,  2,  1,  0,  0 },
    { 1,  2,  1, -1,  0 },
    { 0,  0,  0,  3,  0 },
    { 0,  4,  0, -2,  0 },
    { 1,  1,  0,  1,  0 },
    { 0,  2,  0, -3,  0 },
    { 1,  2, -1,  1,  0 },
    { 0,  4,  0,  0,  0 },
    { 0,  2,  0,  2,  0 },
    { 0,  2,  0,  0, -2 },
    { 1,  2, -1, -2,  0 },
    { 2,  2, -2,  0,  0 },
    { 0,  2,  0, -1, -2 },
    { 0,  1,  0, -1,  0 },
    { 1,  0,  1, -2,  0 },
    { 0,  1,  0,  1,  0 },
    { 1,  0,  1,  2,  0 },
    { 2,  2, -2, -1,  0 },
    { 0,  0,  0,  2, -2 },
    { 0,  2,  0,  1, -2 },
    { 1,  4, -1, -1,  0 },
    { 0,  3,  0, -1,  0 },
    { 0,  0,  0,  0,  2 },
    { 1,  2,  1,  1,  0 },
    { 2,  2,  2, -1,  0 },
    { 2,  0,  2, -1,  0 },
    { 1,  4, -1, -2,  0 },
    { 0,  1,  0, -2,  0 },
    { 1,  4, -1,  0,  0 },
    { 0,  4,  0,  1,  0 },
    { 2,  0,  2,  1,  0 },
    { 0,  0,  0,  4,  0 }
};

#endif
