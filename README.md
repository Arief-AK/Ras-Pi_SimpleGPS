# Ras-Pi_SimpleGPS
A "Simple" GPS driver for communicating with RaspberryPi using WiringPi.

**@Brief**
The purpose of this library is to establish serial communication with a GPS device and apply
basic NMEA sentence parsing functions. This library is written in C++ to support serial
communication with RaspberryPi modules. With a little tweaking, "SimpleGPS" driver can be
used to handle NMEA sentences from a standard serial communicating GPS device.
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
Arief Kurniawan and Herry Kurniawan

**@References**
For more information regarding NMEA Sentences, see link below:
https://www.gpsinformation.org/dale/nmea.htm

THIS LIBRARY IS BASED ON THE WORK BY DANIEL HARRIS.
Copyright © 2020 Parallax Inc.
All rights reserved.
