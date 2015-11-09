//
// Created by Edern Haumont on 19/10/2015.
//

#include "DataHandler.h"

DataHandler::DataHandler()
{
    for(uint i = 0; i<NUMBER_OF_SENSORS; i++)
    {
        for(uint j = 0; j<NUMBER_OF_COLORS; j++)
        {
            sensors[i][j] = 0;
        }
    }
    for(uint i = 0; i<NUMBER_OF_DAYS; i++)
    {
        for(uint j = 0; j<NUMBER_OF_COLORS; j++)
        {
            days[i][j] = 0;
        }
    }
    for (int day = 0; day<NUMBER_OF_DAYS; day++)
    {
        for (int h = 0; h<NUMBER_OF_HOURS; ++h)
        {
            for (int t = 0; t<NUMBER_OF_COLORS; ++t)
            {
                daysAndHours[day][h][t] = 0;
            }
        }
    }
#ifdef OPT
    for(uint day = 0; day<NUMBER_OF_DAYS; day++)
    {
        for(uint min = 0; min<NUMBER_OF_MINUTES; min++)
        {
            for(uint color = 0; color<NUMBER_OF_COLORS; color++)
            {
                daysAndMin[day][min][color] = new unsigned char[NUMBER_OF_SENSORS];
                for(uint id=0 ; id<NUMBER_OF_SENSORS ; id++)
                {
                    daysAndMin[day][min][color][id]=0;
                }
            }
        }
    }
#endif
}

DataHandler::~DataHandler()
{
    for(uint day = 0; day<NUMBER_OF_DAYS; day++)
    {
        for(uint min = 0; min<NUMBER_OF_MINUTES; min++)
        {
            for(uint color = 0; color<NUMBER_OF_COLORS; color++)
            {
                delete [] daysAndMin[day][min][color];
            }
        }
    }
}

int DataHandler::addData(const Data &data)
{
    return addData(data.getTrafic(),data.getMin(),data.getHours(),data.getId(),data.getWeekDay());
}
int DataHandler::addData(const char &trafic,const uint &min,const uint &hours,const uint &id,const uint &day7)
{
    uint color;
    switch(trafic)
    {
        case 'V' :
            color =0;
            break;
        case 'J' :
            color =1;
            break;
        case 'R' :
            color =2;
            break;
        case 'N' :
            color =3;
            break;
        default :
            return ERROR_INVALID_TRAFIC_UCHAR;
    }
    uint dayMin = hours*60 + min;
    uint idInTab = idHash.addId(id); //add the id in the hash tab if necessary and return a number for tab use
    sensors[idInTab][color]++;
    days[day7][color]++;
    daysAndHours[day7][hours][color]++;
#ifdef OPT
    daysAndMin[day7][dayMin][color][idInTab]++;
#endif

    return 0;
}

int DataHandler::sensorStats(usint id)
{
    uint idInTab = idHash.getTabId(id);
    int total = sensors[idInTab][0]+sensors[idInTab][1]+sensors[idInTab][2]+sensors[idInTab][3];
    int V,J,R,N;
    if(total!=0)
    {
        V=100*sensors[idInTab][0]/total;
        J=100*sensors[idInTab][1]/total;
        R=100*sensors[idInTab][2]/total;
        N=100*sensors[idInTab][3]/total;
    }
    else
    {
        V=0;
        J=0;
        R=0;
        N=0;
    }
    std::cout << "V " << V << "%\r\n";
    std::cout << "J " << J << "%\r\n";
    std::cout << "R " << R << "%\r\n";
    std::cout << "N " << N << "%\r\n";
    return 0;
}

int DataHandler::dayStats(uchar day7)
{
    int total = days[day7][0]+days[day7][1]+days[day7][2]+days[day7][3];
    int V,J,R,N;
    if(total!=0)
    {
        V=100*days[day7][0]/total;
        J=100*days[day7][1]/total;
        R=100*days[day7][2]/total;
        N=100*days[day7][3]/total;
    }
    else
    {
        V=0;
        J=0;
        R=0;
        N=0;
    }
    std::cout << "V " << V << "%\r\n";
    std::cout << "J " << J << "%\r\n";
    std::cout << "R " << R << "%\r\n";
    std::cout << "N " << N << "%\r\n";
    return 0;
}
int DataHandler::jamStats(uchar day7)
{
    int weekDay = day7;
    weekDay++; // increment for display
    uint total, redAndBlack, jam;
    for (int h = 0; h < NUMBER_OF_HOURS; ++h)
    {
        redAndBlack = daysAndHours[day7][h][2]+daysAndHours[day7][h][3];
        total = daysAndHours[day7][h][0]+daysAndHours[day7][h][1]+redAndBlack;
        if(total != 0)
        {
            jam = (redAndBlack)*100/total;
        }
        else
        {
            jam = 0;
        }
        std::cout << weekDay << " " << h << " " << jam << "%\r\n";
    }

    return 0;
}
#ifdef OPT
int DataHandler::optimum(uchar day7, uint begginHours, uint endHours, uint idTab[], uint tabSize)
{
    //convertion of the id tab to daysAndMin usable value;
    unsigned idsInTab[tabSize];
    for (int i = 0; i < tabSize; i++)
    {
        idsInTab[i] = idHash.getTabId(idTab[i]);
    }

    uint bestTime=1440, currentTime=1440, leavingMin=begginHours;
    uint endMin = endHours*60;
    for(uint currentMin=begginHours*60 ; currentMin < endMin ; currentMin++)
    {
        currentTime = computeTime(day7,currentMin,idsInTab,tabSize,bestTime);
        if(currentTime < bestTime)
        {
            bestTime = currentTime;
            leavingMin = currentMin;
        }
    }
    uint weekday = day7;
    weekday++;
    uint min = leavingMin%60;
    uint hours = (leavingMin-min)/60;
    std::cout << weekday << " " << hours << " " << min  << " " << bestTime << "\r\n";
    return 0;
}

uint DataHandler::computeTime(uchar day7, uint leavingMin, uint idsInTab[], uint tabSize, uint currantBestTime)
{
    uint currantMin = leavingMin;
    uint currantDuration = 0;
    for(int i=0 ; i<tabSize ; i++)
    {
        currantDuration += duration(day7, currantMin, idsInTab[i]);
        currantMin = currantDuration + leavingMin;
        if(currantDuration >currantBestTime)
        {
            return 1440;
        }
        //check for min overflow:
        if(currantMin > 1440)
        {
            currantMin -= 1440;
            day7++;
            if(day7>6)
            {
                day7=0;
            }
        }
    }
    return currantDuration;
}

uint DataHandler::duration(uchar day7, uint minuteTime, uint idInTab)
{
    uint duration=0;
    uint maxValue=0;
    uint color=0;
    for (uint i = 0; i < 4; ++i) {
        uint value = daysAndMin[day7][minuteTime][i][idInTab];
        if(value>maxValue)
        {
            maxValue = value;
            color = i;
        }
    }
    switch(color)
    {
        case 0:
            duration=1;
            break;
        case 1:
            duration=2;
            break;
        case 2:
            duration=4;
            break;
        case 4:
            duration=10;
            break;
        default:
            return ERROR_INVALID_TRAFIC_UCHAR;
    }
    return duration;
}
#endif




























