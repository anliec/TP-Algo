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
//system include
#include <iostream>
//personal include
#include "IdHash.h"

//comment to deactivate optimum function:
#define OPT

//Constants
const unsigned int ERROR_INVALID_TRAFIC_UCHAR = 201;

const int NUMBER_OF_COLORS = 4;
const int NUMBER_OF_SENSORS = 1500;
const int NUMBER_OF_MINUTES = 1440;
const int NUMBER_OF_HOURS = 24;
const int NUMBER_OF_DAYS = 7;

typedef unsigned int uint;
typedef unsigned short int usint;
typedef unsigned char uchar;

//------------------------------------------------------------------------
// This class manages all data of the applications
// It contains all useful information and answers to statistic queries
//------------------------------------------------------------------------
class DataHandler {
//----------------------------------------------------------------- PUBLIC

//Public methods
public:
    int addData(const char &traffic,const uint &min,const uint &hours,const uint &id,const uint &day7);
    /* parameters : useful information sent by the user in an ADD request
     * update member arrays in corresponding cells
     * contract :
     * hours between 0 and 23, min between 0 and 59, hours between 0 and 23 and day7 between 0, for monday, and 6.
     * To work properly traffic must be set to one of: 'V','J','R','N'.
     */

    int sensorStats(uint id) const;
    /* prints the sensor statistics for the id given in parameter
     * contract : id in unsigned int range
     * prints null stats if 0 corresponding event
     */

    int jamStats(uchar day7) const;
    /* prints jam statistics for the day given in parameter
     * contract : day7 between 0 and 6
     * prints null stats if 0 corresponding event
     */

    int dayStats(uchar day7) const;
    /* prints a week day statistics for the day given in parameter
     * contract : day7 between 0 and 6
     * prints null stats if 0 corresponding event
     */

#ifdef OPT
    int optimum(uchar day7, uint beginHours, uint endHours, uint idTab[], uint tabSize) const;
    /* optimum look for the best departure time in a given interval
     * contract : day7 must be between 0 and 6
     * beginHours and endHours must be between 0 and 23 with beginHours smaller than endHours
     * idTab must be an array of size tabSize filled with already added sensors id (if an id
     * is not added the first added sensors will be used)
     */
#endif

// constructor - destructor
    DataHandler();
    ~DataHandler();

//------------------------------------------------------------------ PRIVATE
//Private methods
private:
#ifdef OPT
    uint computeTime(uchar day7, uint leavingMin, uint idsInTab[], uint tabSize, uint currentBestTime = 1440) const;
    uint duration(uchar day7, uint minuteTime, uint idInTab) const;
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
