/*
 * Ephemeris.hpp
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

#include <string.h>

// To speed up upload, you can disable planets calculations if not needed.
// VSOP87 and ELP2000 will not be loaded and solarSystemObjectAtDateAndTime()
// will simply return an empty object.
#define DISABLE_PLANETS 0

#ifndef Ephemeris_h
#define Ephemeris_h

#include "Calendar.hpp"

#if !DISABLE_PLANETS
#include "VSOP87.hpp"
#include "ELP2000.hpp"
#endif

/*! This structure describes equatorial coordinates. */
struct EquatorialCoordinates
{
    /*! Floating value for Right Ascension. */
    float ra;
    
    /*! Floating value for Declination */
    float dec;
};

/*! This structure describes horizontal coordinates. */
struct HorizontalCoordinates
{
    /*! Floating value for altitude. */
    float alt;
    
    /*! Floating value for azimuth */
    float azi;
};

/*! This structure describes Heliocentric ecliptic coordinates. */
struct HeliocentricCoordinates
{
    /*! Floating value for ecliptic longitude. */
    float lon;
    
    /*! Floating value for ecliptic latitude.*/
    float lat;
    
    /*! Floating value for radius vector (distance from Sun). */
    float radius;
};

/*! This structure describes geocentric coordinates. */
struct GeocentricCoordinates
{
    /*! Floating value for longitude. */
    float lon;
    
    /*! Floating value for latitude.*/
    float lat;
};

/*! This structure describes rectangular coordinates. */
struct RectangularCoordinates
{
    float x;
    float y;
    float z;
};

/*! This structure describes available solar system objects for computation of ephemerides. */
enum SolarSystemObjectIndex
{
    Sun        = 0,
    Mercury    = 1,
    Venus      = 2,
    Earth      = 3,
    Mars       = 4,
    Jupiter    = 5,
    Saturn     = 6,
    Uranus     = 7,
    Neptune    = 8,
    
    EarthsMoon = 9
};

enum RiseAndSetState
{
    LocationOnEarthUnitialized,
    RiseAndSetUdefined,
    RiseAndSetOk,
    ObjectAlwaysInSky,
    ObjectNeverInSky
};

/*! This structure describes a planet for a specific date and time. */
struct SolarSystemObject
{
    /*! Equatorial coordinates (RA/Dec). */
    EquatorialCoordinates   equaCoordinates;
    
    /*! Horizontal coordinates (Alt/Az). */
    HorizontalCoordinates horiCoordinates;
    
    /*! Apparent diameter from earth in arc minutes. */
    float diameter;
    
    /*! Distance from earth in astronomical unit. */
    float distance;
    
    /*! Rise/Set state. */
    RiseAndSetState riseAndSetState;
    
    /*! Rise in floating hours. */
    float rise;
    
    /*! Set in floating hours. */
    float set;
};

/*! This structure describes planetary orbit. */
struct PlanetayOrbit
{
    /*! Mean longitude. */
    float L;
    
    /*! Semimajor axis. */
    float a;
    
    /*! Eccentricity. */
    float e;
    
    /*! Inclination. */
    float i;
    
    /*! Longitude ascending node. */
    float omega;
    
    /*! Perihelion. */
    float pi;
    
    /*! Mean anomaly. */
    float M;
    
    /*! Perihelion argument. */
    float w;
};

/*!
 * This class is used for astronomical calculations. The code is based on the book "Astronomical Algorithms" by Jean Meeus.
 */
class Ephemeris
{
    
public:
    
    /*! Flip longitude coordinate. Default: West is negative and East is positive. */
    static void flipLongitude(bool flip);
    
    /*! Set location on earth (used for horizontal coordinates conversion). */
    static void setLocationOnEarth(float floatingLatitude, float floatingLongitude);
    
    /*! Set location on earth (used for horizontal coordinates conversion). */
    static void setLocationOnEarth(float latDegrees, float latMinutes, float latSeconds,
                                   float lonDegrees, float lonMinutes, float lonSeconds);
    
    /*! Set altitude in meters for location on earth (improve precision for rise and set). */
    static void setAltitude(int altitude);
    
    /*! Convert floating hours to integer hours, minutes, seconds. */
    static void  floatingHoursToHoursMinutesSeconds(float floatingHours, int *hours, int *minutes, float *seconds);
    
    /*! Convert integer hours, minutes, seconds to floating hours. */
    static float hoursMinutesSecondsToFloatingHours(int hours, int minutes, float seconds);
    
    /*! Convert floating degrees to integer degrees, minutes, seconds. */
    static void  floatingDegreesToDegreesMinutesSeconds(float floatingDegrees, int *degrees, int *minutes, float *seconds);
    
    /*! Convert integer degrees, minutes, seconds to floating degrees. */
    static float degreesMinutesSecondsToFloatingDegrees(int degrees, int minutes, float seconds);
    
    /*! Convert floating hours by applying UTC offset. */
    static float floatingHoursWithUTCOffset(float floatingHours, int UTCOffset);
    
    /*! Convert equatorial coordinates for a specified equinox to apparent equatorial coordinates (JNow)
     *  for a specified date and time. Conversion applies, drift per year, precession of the equinoxes, nutation and aberration. 
     *  eqDriftPerYear.ra must be expressed in s/year.
     *  eqDriftPerYear.dec must be expressed in "/year. */
    static EquatorialCoordinates equatorialEquinoxToEquatorialJNowAtDateAndTime(EquatorialCoordinates eqEquinoxCoordinates,
                                                                                int equinox,
                                                                                EquatorialCoordinates eqDriftPerYear,
                                                                                unsigned int day,   unsigned int month,   unsigned int year,
                                                                                unsigned int hours, unsigned int minutes, unsigned int seconds);
    
    /*! Convert equatorial coordinates for a specified equinox to apparent equatorial coordinates (JNow)
     *  for a specified date and time. Conversion applies precession of the equinoxes, nutation and aberration. */
    static EquatorialCoordinates equatorialEquinoxToEquatorialJNowAtDateAndTime(EquatorialCoordinates eqEquinoxCoordinates,
                                                                                int equinox,
                                                                                unsigned int day,   unsigned int month,   unsigned int year,
                                                                                unsigned int hours, unsigned int minutes, unsigned int seconds);
    
    /*! Convert equatorial coordinates to horizontal coordinates. Location on Earth must be initialized first. */
    static HorizontalCoordinates equatorialToHorizontalCoordinatesAtDateAndTime(EquatorialCoordinates eqCoordinates,
                                                                                unsigned int day,   unsigned int month,   unsigned int year,
                                                                                unsigned int hours, unsigned int minutes, unsigned int seconds);
    
    /*! Convert horizontal coordinates to equatorial coordinates. Location on Earth must be initialized first. */
    static EquatorialCoordinates horizontalToEquatorialCoordinatesAtDateAndTime(HorizontalCoordinates hCoordinates,
                                                                                unsigned int day,   unsigned int month,   unsigned int year,
                                                                                unsigned int hours, unsigned int minutes, unsigned int seconds);

    /*! Compute solar system object for a specific date, time and location on earth (if location has been initialized first). */
    static SolarSystemObject solarSystemObjectAtDateAndTime(SolarSystemObjectIndex planet,
                                                            unsigned int day,   unsigned int month,   unsigned int year,
                                                            unsigned int hours, unsigned int minutes, unsigned int seconds);
    
    /*! Compute rise and set for the equatorial coordinates we want. */
    static RiseAndSetState riseAndSetForEquatorialCoordinatesAtDateAndTime(EquatorialCoordinates coord,
                                                                           float *rise, float *set,
                                                                           unsigned int day,   unsigned int month,   unsigned int year,
                                                                           unsigned int hours, unsigned int minutes, unsigned int seconds);

private:
    
    /*! Compute apparent sideral time (in floating hours) for a given date and time.
     *  Reference: Chapter 7, page 35: Temps sidéral à Greenwich. */
    static float apparentSideralTime(unsigned int day,   unsigned int month,   unsigned int year,
                                     unsigned int hours, unsigned int minutes, unsigned int seconds);
    
    /*! Compute mean sideral time for Greenwich.
     *  Reference: Chapter 7, page 35: Temps sidéral à Greenwich. */
    static float meanGreenwichSiderealTimeAtDateAndTime(unsigned int day,   unsigned int month,   unsigned int year,
                                                        unsigned int hours, unsigned int minutes, unsigned int seconds);
    
    /*! Compute mean sideral time for Greenwich.
     *  Reference: Chapter 7, page 35: Temps sidéral à Greenwich. */
    static float meanGreenwichSiderealTimeAtJD(JulianDay jd);
    
    /*! Compute heliocentric coordinates.
     *  Reference: Chapter 22, page 83: Position des planètes. */
    static HeliocentricCoordinates heliocentricCoordinatesForPlanetAndT(SolarSystemObjectIndex planet, float T);
    
    /*! Compute Kepler equation.
     *  Reference: Chapter 20, page 73: Equation de Kepler. */
    static float kepler(float M, float e);
    
    /*! Convert equatorial coordinates to horizontal coordinates.
     *  Reference: Chapter 8,  page 37: Transformation de coordonnées. */
    static HorizontalCoordinates equatorialToHorizontal(float H, float delta, float phi);
    
    /*! Convert horizontal coordinates to equatorial coordinates.
     *  Reference: Chapter 8,  page 37: Transformation de coordonnées. */
    static EquatorialCoordinates horizontalToEquatorial(float azimuth, float altitude, float latitude);
    
    /*! Convert ecliptic coordinates to equatorial coordinates.
     *  Reference: Chapter 8,  page 37: Transformation de coordonnées. */
    static EquatorialCoordinates EclipticToEquatorial(float lambda, float beta, float epsilon);
    
    /*! Convert heliocentric coordinates to rectangular coordinates.
     *  Reference: Chapter 23,  page 87: Mouvement elliptique. */
    static RectangularCoordinates HeliocentricToRectangular(HeliocentricCoordinates hc, HeliocentricCoordinates hc0);
    
    /*! Compute the true obliquity (angle in floating degrees) of the ecliptic,
     *  delta obliquity and delta nutation for T.
     *  Reference: Chapter 13, page 53: Nutation et obliquité de l'écliptique. */
    static float obliquityAndNutationForT(float T, float *deltaObliquity, float *deltaNutation);
    
    /*! Compute planet informations for T.
     *  Reference: Chapter 21, page 77: Eléments des orbites planétaires. */
#if !DISABLE_PLANETS
    static PlanetayOrbit planetayOrbitForPlanetAndT(SolarSystemObjectIndex planet, float T);
#endif
    
    /*! Compute Moon coordinates in the sky (R.A.,Dec) for a specific date and time.
     *  Reference: Chapter 28, page 109: Position de la Lune.
     *             Chapter 8,  page 37: Transformation de coordonnées. */
#if !DISABLE_PLANETS
    static EquatorialCoordinates equatorialCoordinatesForEarthsMoonAtJD(JulianDay jd, float *distance);
#endif
    
    /*! Compute Sun coordinates in the sky (R.A.,Dec) for a specific date and time.
     *  Reference: Chapter 16, page 63: Les coordonnées du soleil. */
#if !DISABLE_PLANETS
    static EquatorialCoordinates equatorialCoordinatesForSunAtJD(JulianDay jd, float *distance);
#endif
    
    /*! Compute planet equatorial coordinates (and geocentric if needed) for a a specific Julian day.
     *  Reference: Chapter 23, page 87: Mouvement elliptique.
     *             Chapter 8,  page 37: Transformation de coordonnées. */
#if !DISABLE_PLANETS
    static EquatorialCoordinates equatorialCoordinatesForPlanetAtJD(SolarSystemObjectIndex planet, JulianDay jd, float *distance);
#endif
    
#if !DISABLE_PLANETS
    /*! Compute VSOP87 (Planets) coefficients for T.
     *  Reference: Chapter 22, page 83: Position des planètes. */
    static float sumVSOP87Coefs(const VSOP87Coefficient *valuePlanetCoefficients, int coefCount, float T);
#endif
    
#if !DISABLE_PLANETS
    /*! Compute ELP2000 (Earth's Moon) coefficients for T.
     *  Reference: Chapter 28, page 109: Position de la Lune. */
    static float sumELP2000Coefs(const float *moonCoefficients, const ELP2000Coefficient *moonAngleCoefficients, int coefCount,
                                 float E, float D, float M, float Mp, float F, bool squareMultiplicator);
#endif
    
    /*! Compute rise and set for specified equatorial coordinates, T0 (Mean sideral time at midnight), paralax, apparent diameter, and altitude.
     *  Reference: https://www.imcce.fr/langues/en/grandpublic/systeme/promenade-en/pages3/367.html */
    static RiseAndSetState riseAndSetForEquatorialCoordinatesAndT0(EquatorialCoordinates coord, float T0, float *rise, float *set,
                                                                   float paralax, float apparentDiameter);
    
    /*! Convert equatorial coordinates for a specified equinox to apparent equatorial coordinates (JNow) for a specified T. 
     *  Conversion applies, drift per year, precession of the equinoxes, nutation and aberration.
     *  eqDriftPerYear.ra must be expressed in s/year.
     *  eqDriftPerYear.dec must be expressed in "/year.
     *  Reference: Chapter 12, page 49: Precession.
     *             Chapter 14, page 57: Position apparente d'une étoile. */
    static EquatorialCoordinates equatorialEquinoxToEquatorialJNowAtDateForT(EquatorialCoordinates eqEquinoxCoordinates,
                                                                             int equinox,
                                                                             EquatorialCoordinates eqDriftPerYear,
                                                                             float T,
                                                                             unsigned int year);
};

#endif
