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
    std::cout << "J " << J << "%\r\n";
    std::cout << "R " << R << "%\r\n";
    std::cout << "N " << N << "%\r\n";
    return 0;
}

int DataHandler::jamStats(uchar day7)
{
    int colorByHour[24][4];
    for(int i=0; i<24;i++)
        for(int j=0;j<4;j++)
            colorByHour[i][j]=0;
    for(int ite=0; ite<weekDays[day7].endingIndex();ite++)
    {
        uchar iColor = weekDays[day7].at(ite)->getTrafic();
        uchar hour = weekDays[day7].at(ite)->getHours();
        switch(iColor)
        {
            case 'V' :
                colorByHour[hour][0]++;
                break;
            case 'J' :
                colorByHour[hour][1]++;
                break;
            case 'R' :
                colorByHour[hour][2]++;
                break;
            case 'N' :
                colorByHour[hour][3]++;
                break;
            default :
                return ERROR_INVALID_TRAFIC_UCHAR;
        }
    }
    for(int ite=0; ite<24;ite++)
    {
        double hourResult = (colorByHour[ite][2]+colorByHour[ite][3])/(colorByHour[ite][0]+colorByHour[ite][1]+
                colorByHour[ite][2]+colorByHour[ite][3])*100;
        std::cout << day7 << " " << ite << " " << hourResult << "%\r\n";
    }
    return 0;
}

int DataHandler::dayStats(uchar day7)
{
    double V=0,J=0,R=0,N=0;
    for (int i=0; i<=sensors[day7].endingIndex(); i++)
    {
        uchar iColor = sensors[day7].at(i)->getTrafic();
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
    std::cout << "J " << J << "%\r\n";
    std::cout << "R " << R << "%\r\n";
    std::cout << "N " << N << "%\r\n";
    return 0;
}
