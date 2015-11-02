#include <string>
#include <sstream>
#include <stdlib.h>
#include "DataHandler.h"
#include "Data.h"

int main()
{
    DataHandler handler;

    bool loop=true;
    std::string entry;
    while(loop)
    {
        std::cin >> entry;
        //std::cout << entry;
        // input example: ADD 400 2015 11 02 14 08 0 N
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
}

//new version//

/*
int sensors[NUMBER_OF_SENSORS][NUMBER_OF_COLORS];
int days[NUMBER_OF_DAYS][4];
int daysAndMin[NUMBER_OF_DAYS][NUMBER_OF_MINUTES][NUMBER_OF_COLORS];

int addData(int sensorId,uchar color);
int sensorStats(int id);
int dayStats(int day7);

int main()
{
    bool loop=true;
    std::string entry;
    while(loop)
    {
        std::cin >> entry;
        // input example: ADD 400 2015 11 02 14 08 0 N
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
*/
//end of new version//