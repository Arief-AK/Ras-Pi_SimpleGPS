# Ras-Pi_SimpleGPS
"Simple" GPS driver for RaspberryPi using WiringPi.

/*
 * @Files
 * SimpleGPS.h
 * SimpleGPS.cpp
 *
 * @Authors
 * ARIEF KURNIAWAN AND HERRY KURNIAWAN
 *
 * @Brief
 * THE PURPOSE OF THIS LIBRARY IS TO ESTABLISH SERIAL COMMUNICATION WITH GPS DEVICE AND APPLY
 * BASIC NMEA SENTENCE PARSING FUNCTIONS. THIS LIBRARY IS WIRTTEN TO SUPPORT RASPBERRYPI MODULES.
 * A BASIC RUN-DOWN OF "SimpleGPS" DRIVER IS SUMMARISED BELOW:
 *
 * ////////// PROCESS //////////
 *
 * 1. ESTABLISH SERIAL COMMUNICATION
 * 2. SEARCH FOR DESIGNATED SENTENCE
 * 3. PARSE NMEA SENTENCE INTO TOKENS
 * 4. ASSIGN TOKENS INTO GPS DATA STRUCTURE
 * 5. GET GPS DATA WITH ACCESSOR METHODS
 *
 * @References
 * FOR INFORMATION ON NMEA SENTENCES, SEE THE LINK BELOW:
 * https://www.gpsinformation.org/dale/nmea.htm
 *
 * THIS LIBRARY IS BASED ON THE WORK BY DANIEL HARRIS.
 * Copyright © 2020 Parallax Inc.
 * All rights reserved.
 *
*/
