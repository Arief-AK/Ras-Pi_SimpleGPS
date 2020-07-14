
//** INCLUDES **//

#include "SimpleGPS.h"

NMEA_DATA_S GPS_DATA;

int main()
{
    StartGPS();
}

void StartGPS()
{
    ParseRMC();
    ParseGGA();

    printf("\nEND");
}

string &GetOneSentence(string &OneSentence)
{
    int Handle;
    int idx;

    char characters;
    char GPS_BUFFER_HANDLE[GPS_DATABUFFER_SIZE];

    string ErrMsg ="No Serial Device Found";

    Handle = serialOpen(SERIAL_PIN,BAUD_RATE);
    if(Handle < 0)
    {
        fprintf(stderr,"Unable to open serial device: %s\n",strerror(errno));
        return ErrMsg;
    }

    OneSentence.clear();

    bool Run = true;
    bool StopSearch = false;

    // Get one sentence;
    idx = 0;
    while(StopSearch == false)
        {
           characters = serialGetchar(Handle);
           if(characters == 36)
            {
               GPS_BUFFER_HANDLE[idx] = characters;
               while(Run == true)
                {
                    characters = serialGetchar(Handle);
                    ++idx;
                    GPS_BUFFER_HANDLE[idx] = characters;
                    if(GPS_BUFFER_HANDLE[idx] == 13)
                    {
                        for (int i = 0; i <= idx; ++i)
                        {
                           OneSentence = OneSentence + GPS_BUFFER_HANDLE[i];
                        }

                        Run = false;
                        StopSearch = true;
                    }
                }
           }
        }

    printf("\nRECEIVED ONE COMPLETE NMEA MESSAGE\n");
    cout << OneSentence;
    cout << "\n";

    return OneSentence;
}

string &GetInfo(string &Prefix)
{
    string Sentence;
    string strSentencePrefix = "";

    const char delimitor[2] = ",";
    //char *Token;  //Uncomment for printing sentences that are seperated.

    bool comparing = true;

    int LengthSentence;
    int result = 0;

    while(comparing == true)
    {
       GetOneSentence(Sentence);
       LengthSentence = Sentence.length();

       char CharacterSentence[LengthSentence + 1];
       strcpy(CharacterSentence,Sentence.c_str());

//       Token = strtok(CharacterSentence, delimitor);  // Print all messages found and seperate them into tokens.
//       while (Token != NULL)
//       {
//           cout << Token;
//           cout << "\n";
//           Token = strtok(NULL, delimitor);
//       }

       strSentencePrefix = strtok(CharacterSentence,delimitor);
       string Token(strSentencePrefix);

       result = Token.compare(Prefix);
       if(result == 0)
       {
          comparing = false;
          cout << "Found " << Prefix << " message.";
          cout << "\n";
       }
    }

    Prefix = Sentence;
    return Prefix;
}

void ParseRMC()
{
    string RMCPrefix = "$GPRMC";
    string RMCSentence = "";

    const char delimitor[2] = ",";
    char *Token;

    int SentenceLength;
    int x = 0;

    RMCSentence = GetInfo(RMCPrefix);
    SentenceLength = RMCSentence.length();

    char c_RMCSentence[SentenceLength +1];
    strcpy(c_RMCSentence,RMCSentence.c_str());

    Token = strtok(c_RMCSentence, delimitor);
    while (Token && x< 11)
    {
        if(x == 1)
            GPS_DATA.TimeVal = atof(Token);
        if(x == 2)
            GPS_DATA.Status = strcmp(Token,"A") ? GPS_CONNECTEDTRUE:GPS_CONNECTEDFALSE;
        if(x == 3)
        {
            int sign;
            int degs;
            float Temp = (float)atof(Token);
            Token = strtok(NULL,",");
            x++;

            sign = strcmp(Token,"N") ? -1:1;    //create a sign multiplier from N/S
            degs = (int)Temp/100;               //grab the whole number of degrees
            Temp -= (degs*100);                 //remove the degrees from the calculation

            GPS_DATA.LatVal = sign*((Temp/60)+degs);    // Calulate decimal degrees from remaining minutes. Add back the degrees and apply the sign.
        }

        if(x == 5)
        {
            int sign;
            int degs;
            float Temp = (float)atof(Token);
            Token = strtok(NULL,",");
            x++;

            sign = strcmp(Token,"E") ? -1:1;    //create a sign multiplier from N/S
            degs = (int)Temp/100;               //grab the whole number of degrees
            Temp -= (degs*100);                 //remove the degrees from the calculation

            GPS_DATA.LongVal = sign*((Temp/60)+degs);    // Calulate decimal degrees from remaining minutes. Add back the degrees and apply the sign.
        }
        if(x == 7)
            GPS_DATA.VelVal = (float)atof(Token);
        if(x == 8)
            GPS_DATA.HeadVal = (float)atof(Token);
        if(x == 9)
            GPS_DATA.DateVal = atoi(Token);
        if(x == 10)
            GPS_DATA.MagnetVal = (float)atof(Token);

        Token = strtok(NULL, delimitor);
        x++;
    }

    printf("\nRMC Sentence succesfully assigned to typedef..");
    cout << "\n";
}

void ParseGGA()
{
    string GGAPrefix = "$GPGGA";
    string GGASentence;

    const char delimitor[2] = ",";
    char *Token;

    int SentenceLength;
    int x = 0;

    GGASentence = GetInfo(GGAPrefix);
    SentenceLength = GGASentence.length();

    char c_GGASentence[SentenceLength +1];
    strcpy(c_GGASentence,GGASentence.c_str());

    Token = strtok(c_GGASentence, delimitor);
    while (Token && x<14)
    {
        if(x == 6)
            GPS_DATA.Fix = atoi(Token);
        if(x == 7)
            GPS_DATA.SattsTracked = atoi(Token);
        if(x == 9)
            GPS_DATA.AltVal = (float)atof(Token);

        Token = strtok(NULL,delimitor);
        x++;

    }

    printf("\nGGA Sentence succesfully assigned to typedef..");
    cout << "\n";
}

int get_Fix()
{
    return GPS_DATA.Fix;
}

int get_ValidFix()
{
    return GPS_DATA.ValidFix;
}

int get_Sattelites()
{
    return GPS_DATA.SattsTracked;
}

float get_Lattitude()
{
    return GPS_DATA.LatVal;
}

float get_Longitude()
{
    return GPS_DATA.LongVal;
}

float get_Altitude()
{
    return GPS_DATA.AltVal;
}

float get_Veloctiy()
{
    return GPS_DATA.VelVal;
}

float get_Heading()
{
    return GPS_DATA.HeadVal;
}

float get_MagneticVariation()
{
    return GPS_DATA.MagnetVal;
}

int get_Date()
{
    return GPS_DATA.DateVal;
}

int get_Time()
{
    return GPS_DATA.TimeVal;
}
