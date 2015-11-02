//
// Created by Edern Haumont on 19/10/2015.
//

#include "DataHandler.h"

DataHandler::DataHandler()
{
    for(int i = 0; i<NUMBER_OF_SENSORS; i++)
    {
        for(int j = 0; j<NUMBER_OF_COLORS; j++)
        {
            sensors[i][j] = 0;
        }
    }
    for(int i = 0; i<NUMBER_OF_DAYS; i++)
    {
        for(int j = 0; j<NUMBER_OF_COLORS; j++)
        {
            days[i][j] = 0;
        }
    }
    for(int i = 0; i<NUMBER_OF_DAYS; i++)
    {
        for(int j = 0; j<NUMBER_OF_MINUTES; j++)
        {
            for(int k = 0; k<NUMBER_OF_MINUTES; k++)
            {
                daysAndMin[i][j][k]=0;
            }
        }
    }
}

DataHandler::~DataHandler()
{

}

int DataHandler::addData(const Data &data)
{
    switch(data.getTrafic())
    {
        case 'V' :
            sensors[data.getId()][0]++;
            break;
        case 'J' :
            sensors[data.getId()][1]++;
            break;
        case 'R' :
            sensors[data.getId()][2]++;
            break;
        case 'N' :
            sensors[data.getId()][3]++;
            break;
        default :
            return ERROR_INVALID_TRAFIC_UCHAR;
    }
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
int int DataHandler::jamStats(uchar day7)
{
    int red[24] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    int black[24] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    int total[24] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    for(int i=0; i<24; i++)
    {
        int jam;
        for(int j=0; j<NUMBER_OF_MINUTES; j++)
        {
            for(int k=0; k<NUMBER_OF_COLORS; k++)
            {
                total[i] += daysAndMin[day][i*60+j][k];
            }
            red[i] += daysAndMin[day][i*60+j][2];
            black[i] += daysAndMin[day][i*60+j][3];
        }
        jam = (red[i]+black[i])/total[i];
        std::cout << day7 << " " << i << " " << jam << "%\r\n";
    }
}