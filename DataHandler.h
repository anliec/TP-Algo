/*************************************************************************
                           DataHandler  -  description
                             -------------------
    begin                : 19/10/2015
    copyright            : (C) 2015 by Edern Haumont & Nicolas Six
*************************************************************************/

//---------- Interface of the class DataHandler (file DataHandler.h) ------
#ifndef TP_ALGO_DATAHANDLER_H
#define TP_ALGO_DATAHANDLER_H

//INCLUDE
//include system
#include <iostream>

#include "IdHash.h"

//uncomment to use optimum function:
#define OPT

const unsigned int ERROR_INVALID_TRAFIC_UCHAR = 201;

const int NUMBER_OF_COLORS = 4;
const int NUMBER_OF_SENSORS = 1500;
const int NUMBER_OF_MINUTES = 1440;
const int NUMBER_OF_HOURS = 24;
const int NUMBER_OF_DAYS = 7;

typedef unsigned int uint;

//------------------------------------------------------------------------
// This class manages all data of the applications
// It contains all useful information and answers to statistic queries
//------------------------------------------------------------------------
class DataHandler {

//Public methods
public:
    int addData(const char &traffic,const uint &min,const uint &hours,const uint &id,const uint &day7);
    /* parameters : useful information sent by the user in an ADD request
     * update member arrays in corresponding cells
     * contract :
     * hours between 0 and 23, min between 0 and 59, hours between 0 and 23 and day7 between 0, for monday, and 6.
     * To work properly traffic must be set to one of: 'V','J','R','N'.
     */

    int sensorStats(usint id);
    /* prints the sensor statistics for the id given in parameter
     * contract
     */

    int jamStats(uchar day7);
    /* prints jam statistics for the day given in parameter
     */

    int dayStats(uchar day7);
    /* print a week day statistics for the day given in parameter
     */

#ifdef OPT
    int optimum(uchar day7, uint begginHours, uint endHours, uint idTab[], uint tabSize);
    /*
     *
     */
#endif
    DataHandler();
    ~DataHandler();

//Private methods
private:
#ifdef OPT
    uint computeTime(uchar day7, uint leavingMin, uint idsInTab[], uint tabSize, uint currantBestTime = 1440);
    uint duration(uchar day7, uint minuteTime, uint idInTab);
#endif
//Private attributes
private:
    IdHash idHash;
    uint sensors[NUMBER_OF_SENSORS][NUMBER_OF_COLORS];
    uint days[NUMBER_OF_DAYS][NUMBER_OF_COLORS];
    uint daysAndHours[NUMBER_OF_DAYS][NUMBER_OF_HOURS][NUMBER_OF_COLORS];
#ifdef OPT
    unsigned char *daysAndMin[NUMBER_OF_DAYS][NUMBER_OF_MINUTES][NUMBER_OF_COLORS];
#endif

}; //class DataHandler


#endif //TP_ALGO_DATAHANDLER_H
