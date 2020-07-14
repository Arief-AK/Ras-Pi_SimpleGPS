/*
 * @File
 * SimpleGPS.h
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
#ifndef SIMPLEGPS_H
#define SIMPLEGPS_H

//** INCLUDES **//

#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

#include <wiringPi.h>
#include <wiringSerial.h>

//** DEFINITIONS **//

// RaspberryPi4 default Serial receiving pin (GPIO 15(RXD))
#define SERIAL_PIN "/dev/ttyS0"

// BAUD RATE OF SERIAL DEVICE
#define BAUD_RATE 9600

// Defining connection status with GPS module.
#define GPS_CONNECTEDTRUE   "CONNECTED"
#define GPS_CONNECTEDFALSE  "NOT CONNECTED"

// Defining a data buffer so that information from GPS can be
// stored with extra space.
#define GPS_DATABUFFER_SIZE 128

using namespace std;

// Creating a data type structure for GPS information.

//** GPS DATA STRUCTURE ** //

typedef struct NMEA_DATA_S
{
    // GPS CONNECTION STATS: //
    int Fix;
    int ValidFix;
    int SattsTracked;

    string Status;

    // GPS LOCATION STATS: //
    float LatVal;
    float LongVal;
    float AltVal;
    float HeadVal;
    float VelVal;
    float MagnetVal;

    // GPS DATE AND TIME STATS: //
    int DateVal;
    int TimeVal;

} nmea_data;

void StartGPS();

string &GetOneSentence(string &OneSentence);
string &GetInfo(string &Prefix);

void ParseRMC();
void ParseGGA();

// GPS_DATA ACCESSOR METHODS //

int get_Fix();
int get_ValidFix();
int get_Sattelites();

float get_Lattitude();
float get_Longitude();
float get_Altitude();
float get_Veloctiy();
float get_Heading();
float get_MagneticVariation();

int get_Date();
int get_Time();

#endif // SIMPLEGPS_H
