/*************************************************************************
                           DataHandler  -  description
                             -------------------
    begin                : 19/10/2015
    copyright            : (C) 2015 by Edern Haumont & Nicolas Six
*************************************************************************/

//---------- Interface of the class DataHandler (file DataHandler.h) ------
#ifndef TP_ALGO_DATAHANDLER_H
#define TP_ALGO_DATAHANDLER_H

#include <iostream>

#include "Data.h"

const unsigned int SENSORS_SIZE = 1500;
const unsigned int WEEKDAYS_SIZE = 7;
const unsigned int ERROR_INVALID_TRAFIC_UCHAR = 201;

const int NUMBER_OF_COLORS = 4;
const int NUMBER_OF_SENSORS = 1500;
const int NUMBER_OF_MINUTES = 1440;
const int NUMBER_OF_DAYS = 7;

typedef unsigned int uint;

//------------------------------------------------------------------------
// what is this class useful for ?
//
//------------------------------------------------------------------------
class DataHandler {

//Public methods
public:
    int addData(const Data &data);
    int sensorStats(usint id);
    int jamStats(uchar day7);
    int dayStats(uchar day7);
    int optimum(uchar day7, uint begginHours, uint endHours, uint idTab[], uint tabSize);

    DataHandler();
    ~DataHandler();

//Private methods
private:
    uint computeTime(uchar day7, uint leavingMin, uint idTab[], uint tabSize, uint currantBestTime = 1440);
    uint duration(uchar day7, uint minuteTime, uint id);

//Private attributes
private:
    int sensors[NUMBER_OF_SENSORS][NUMBER_OF_COLORS];
    int days[NUMBER_OF_DAYS][4];
    int daysAndMin[NUMBER_OF_DAYS][NUMBER_OF_MINUTES][NUMBER_OF_COLORS];

}; //class DataHandler


#endif //TP_ALGO_DATAHANDLER_H
