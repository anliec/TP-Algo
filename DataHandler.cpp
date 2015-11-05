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
    for (int day = 0; day < NUMBER_OF_DAYS; day++)
    {
        for (int h = 0; h < NUMBER_OF_HOURS; ++h)
        {
            for (int t = 0; t < NUMBER_OF_COLORS; ++t)
            {
                daysAndHours[day][h][t] = 0;
            }
        }
    }
#ifdef OPT
    for (uint id = 0; id < 2; id++)
    {
        for(uint i = 0; i<NUMBER_OF_DAYS; i++)
        {
            for(uint j = 0; j<NUMBER_OF_MINUTES; j++)
            {
                for(uint k = 0; k<NUMBER_OF_COLORS; k++)
                {
                    daysAndMin[id][i][j][k]=0;
                }
            }
        }
    }
#endif
}

DataHandler::~DataHandler()
{

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

    sensors[id][color]++;
    days[day7][color]++;
    daysAndHours[day7][hours][color]++;
#ifdef OPT
    daysAndMin[id][day7][dayMin][color]++;
#endif
    return 0;
}

int DataHandler::sensorStats(usint id)
{
    int total = sensors[id][0]+sensors[id][1]+sensors[id][2]+sensors[id][3];
    int V=100*sensors[id][0]/total;
    int J=100*sensors[id][1]/total;
    int R=100*sensors[id][2]/total;
    int N=100*sensors[id][3]/total;
    std::cout << "V " << V << "%\r\n";
    std::cout << "J " << J << "%\r\n";
    std::cout << "R " << R << "%\r\n";
    std::cout << "N " << N << "%\r\n";
    return 0;
}

int DataHandler::dayStats(uchar day7)
{
    int total = days[day7][0]+days[day7][1]+days[day7][2]+days[day7][3];
    int V=100*days[day7][0]/total;
    int J=100*days[day7][1]/total;
    int R=100*days[day7][2]/total;
    int N=100*days[day7][3]/total;
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
    /*int red[24] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    int black[24] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    int total[24] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    for(int i=0; i<24; i++)
    {
        int jam;
        for(int j=0; j<60; j++)
        {
            for(int k=0; k<NUMBER_OF_COLORS; k++)
            {
                total[i] += daysAndMin[day7][i*60+j][k];
            }
            red[i] += daysAndMin[day7][i*60+j][2];
            black[i] += daysAndMin[day7][i*60+j][3];
        }
        if(total[i] != 0)
        {
            jam = (red[i]+black[i])*100/total[i];
        }
        else
        {
            jam = 0;
        }
        std::cout << weekDay << " " << i << " " << jam << "%\r\n";
    }*/
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
    uint bestTime=1440, currentTime=1440, leavingMin=begginHours;
    uint endMin = endHours*60;
    for(uint currentMin=begginHours*60 ; currentMin < endMin ; currentMin++)
    {
        currentTime = computeTime(day7,currentMin,idTab,tabSize,bestTime);
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

uint DataHandler::computeTime(uchar day7, uint leavingMin, uint idTab[], uint tabSize, uint currantBestTime)
{
    uint currantMin = leavingMin;
    uint currantDuration = 0;
    for(int i=0 ; i<tabSize ; i++)
    {
        currantDuration += duration(day7, currantMin, idTab[i]);
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

uint DataHandler::duration(uchar day7, uint minuteTime, uint id)
{
    uint duration=0;
    uint maxValue=0;
    uint color=0;
    for (uint i = 0; i < 4; ++i) {
        uint value = daysAndMin[id][day7][minuteTime][i];
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




























