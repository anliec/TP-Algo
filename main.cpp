#include <string>
#include <sstream>
#include <stdlib.h>
#include "DataHandler.h"
#include "Data.h"

/*int main()
{
    DataHandler handler;

    bool loop=true;
    std::string entry;
    while(loop)
    {
        std::cin >> entry;
        //std::cout << entry;
        if(entry.substr(0,3).compare("ADD")==0)
        {
            usint id, year;
            usint month, day, hours, min, weekDay;
            char trafic;
            //get the values from cin into integer:
            std::cin >> id >> year >> month >> day >> hours >> min >> weekDay >> trafic;
            //translate the value into uchar:
            uchar c_month = month, c_day = day, c_hours = hours, c_min = min, c_weekDay = weekDay;
            handler.addData(Data(id,year,c_month,c_day,c_hours,c_min,c_weekDay,trafic));
        }
        else if(entry.substr(0,7).compare("STATS_C")==0)
        {
            usint id;
            std::cin >> id;

        }
        else if(entry.substr(0,6).compare("JAM_DH")==0)
        {
            usint weekDay;
            std::cin >> weekDay;
            uchar c_weekday = weekDay;

        }
        else if(entry.substr(0,8).compare("STATS_D7")==0)
        {
            usint weekDay;
            std::cin >> weekDay;
            uchar c_weekday = weekDay;

        }
        else if(entry.substr(0,3).compare("OPT")==0)
        {

        }
        else if(entry.substr(0,4).compare("EXIT")==0)
        {
            loop = false;
        }
    }
    return 0;
}*/

//new version//
const int NUMBER_OF_COLORS = 4;
const int NUMBER_OF_SENSORS = 1500;
const int NUMBER_OF_DAYS = 7;

int sensors[NUMBER_OF_SENSORS][NUMBER_OF_COLORS];
int days[NUMBER_OF_DAYS][4];

int addData(int sensorId,uchar color);
int sensorStats(int id);
int dayStats(int day7);

int main()
{
    for(int i = 0; i<NUMBER_OF_SENSORS; i++)
        for(int j = 0; j<NUMBER_OF_SENSORS; j++)
            sensors[i][j]=0;

    bool loop=true;
    std::string entry;
    while(loop)
    {
        std::cin >> entry;
        if(entry.substr(0,3).compare("ADD")==0)
        {
            usint id, year;
            usint month, day, hours, min, weekDay;
            char traffic;
            //get the values from cin into integer:
            std::cin >> id >> year >> month >> day >> hours >> min >> weekDay >> traffic;
            //translate the value into uchar:
            uchar c_month = month, c_day = day, c_hours = hours, c_min = min, c_weekDay = weekDay;
            addData(id, traffic);
        }
        else if(entry.substr(0,7).compare("STATS_C")==0)
        {
            usint id;
            std::cin >> id;
            sensorStats(id);
        }
        else if(entry.substr(0,6).compare("JAM_DH")==0)
        {
            usint weekDay;
            std::cin >> weekDay;
            uchar c_weekday = weekDay;

        }
        else if(entry.substr(0,8).compare("STATS_D7")==0)
        {
            usint weekDay;
            std::cin >> weekDay;

        }
        else if(entry.substr(0,3).compare("OPT")==0)
        {

        }
        else if(entry.substr(0,4).compare("EXIT")==0)
        {
            loop = false;
        }
    }
    return 0;
}

int addData(int sensorId,uchar color)
{
    switch(color)
    {
        case 'V' :
            sensors[sensorId][0]++;
            break;
        case 'J' :
            sensors[sensorId][1]++;
            break;
        case 'R' :
            sensors[sensorId][2]++;
            break;
        case 'N' :
            sensors[sensorId][3]++;
            break;
        default :
            return ERROR_INVALID_TRAFIC_UCHAR;
    }
    return 0;
}
int sensorStats(int id)
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

int jamStats();
int dayStats(int day7)
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
};
//end of new version//