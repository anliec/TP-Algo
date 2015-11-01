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

#include "DataContainer.h"
#include "DataPointerContainer.h"

const unsigned int SENSORS_SIZE = 1500;
const unsigned int WEEKDAYS_SIZE = 7;
const unsigned int ERROR_INVALID_TRAFIC_UCHAR = 201;

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

    DataHandler();
    ~DataHandler();

//Private methods
private:


//Private attributes
private:
    DataContainer container;
    DataPointerContainer* sensors;
    DataPointerContainer* weekDays;

}; //class DataHandler


#endif //TP_ALGO_DATAHANDLER_H
