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

int DataHandler::addData(const Data &data)
{
    container.add(data);
    Data* currantData = &container.at(container.endingIndex());
    weekDays[currantData->getDayNumber()].add(currantData);
    sensors[currantData->getId()].add(currantData);
    return 0;
}

int DataHandler::sensorStats(usint id)
{
    double V=0,J=0,R=0,N=0;
    for (int i=0; i<=sensors[id].endingIndex(); i++)
    {
        uchar iColor = sensors[id].at(i)->getTrafic();
        switch(iColor)
        {
            case 'V' :
                V++;
                break;
            case 'J' :
                J++;
                break;
            case 'R' :
                R++;
                break;
            case 'N' :
                N++;
                break;
            default :
                return ERROR_INVALID_TRAFIC_UCHAR;
        }
    }
    double total = N+R+J+V;
    V=100*V/total;
    J=100*J/total;
    R=100*R/total;
    N=100*N/total;
    std::cout << "V " << V << "%\r\n";
    return 0;
}

int DataHandler::jamStats(uchar day7)
{
    double V=0,J=0,R=0,N=0;
    for(int i=0; i<weekDays[day7].endingIndex();i++)
    {
        //a finir
    }
}
