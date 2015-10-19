//
// Created by Edern Haumont on 19/10/2015.
//

#include "DataHandler.h"

DataHandler::DataHandler()
{
    weekDays = new DataPointerContainer[WEEKDAYS_SIZE];
    sensors = new DataPointerContainer[SENSORS_SIZE];
}

DataHandler::~DataHandler()
{
    delete [] weekDays;
    delete [] sensors;
}

void DataHandler::addData(const Data &data)
{
    container.add(data);
    Data* currantData = &container.at(container.endingIndex());
    weekDays[currantData->getDayNumber()].add(currantData);
    sensors[currantData->getId()].add(currantData);
}
