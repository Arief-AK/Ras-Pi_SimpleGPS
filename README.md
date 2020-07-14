# Ras-Pi_SimpleGPS
A "Simple" GPS driver for RaspberryPi using WiringPi.

**@Brief**
The purpose of this library is to establish serial communication with GPS device and apply
basic NMEA sentence parsing functions. This library is written to support RaspberryPi modules.
Run-down of "SimpleGPS" driver is summarised below:

**////////// PROCESS //////////**

1. ESTABLISH SERIAL COMMUNICATION
2. SEARCH FOR DESIGNATED SENTENCE
3. PARSE NMEA SENTENCE INTO TOKENS
4. ASSIGN TOKENS INTO GPS DATA STRUCTURE
5. GET GPS DATA WITH ACCESSOR METHODS

**@Files**
SimpleGPS.h
SimpleGPS.cpp

**@Authors**
ARIEF KURNIAWAN AND HERRY KURNIAWAN

**@References**
FOR INFORMATION ON NMEA SENTENCES, SEE THE LINK BELOW:
https://www.gpsinformation.org/dale/nmea.htm

THIS LIBRARY IS BASED ON THE WORK BY DANIEL HARRIS.
Copyright © 2020 Parallax Inc.
All rights reserved.
