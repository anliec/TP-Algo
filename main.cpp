#include <string>
#include <sstream>
#include "DataHandler.h"
#include "Test.h"

int main()
{
    DataHandler handler;

    bool loop=true;
    std::string entry;
    //variable used in the while loop:
    usint id, year, month, day, hours, min, weekDay;
    uchar c_month, c_day, c_hours, c_min, c_weekDay;
    char trafic;

    while(loop && !std::cin.eof())
    {
        std::cin >> entry;
        //std::cout << "comande lu: \"" << entry << "\"" << std::endl;
        // input example: ADD 400 2015 11 02 14 08 1 N
        if(entry.substr(0,3).compare("ADD")==0)
        {
            /*---working version:---
            usint id, year;
            usint month, day, hours, min, weekDay;
            char trafic;
            //get the values from cin into integer:
            std::cin >> id >> year >> month >> day >> hours >> min >> weekDay >> trafic;
            //translate the value into uchar:
            uchar c_month = month, c_day = day, c_hours = hours, c_min = min, c_weekDay = weekDay-1;
            handler.addData(Data(id,year,c_month,c_day,c_hours,c_min,c_weekDay,trafic));
             ---optimisation---*/

            //get the values from cin into integer:
            std::cin >> id >> year >> month >> day >> hours >> min >> weekDay >> trafic;
            //translate the value into uchar:
            c_hours = hours; c_min = min; c_weekDay = weekDay-1;
            handler.addData(trafic,min,hours,id,c_weekDay);
        }
        else if(entry.substr(0,7).compare("STATS_C")==0)
        {
            std::cin >> id;
            handler.sensorStats(id);
        }
        else if(entry.substr(0,6).compare("JAM_DH")==0)
        {
            std::cin >> weekDay;
            c_weekDay = weekDay-1;
            handler.jamStats(c_weekDay);
        }
        else if(entry.substr(0,8).compare("STATS_D7")==0)
        {
            std::cin >> weekDay;
            c_weekDay = weekDay-1;
            handler.dayStats(c_weekDay);
        }
        else if(entry.substr(0,3).compare("OPT")==0)
        {
            usint startHours, endHours, tabSize;
            std::cin >> weekDay >> startHours >> endHours >> tabSize;
            c_weekDay = weekDay-1;
            uint idTab[tabSize];
            for (int i = 0; i < tabSize; i++)
            {
                std::cin >> idTab[i];
            }
            handler.optimum(c_weekDay,startHours,endHours,idTab,tabSize);
        }
        else if(entry.substr(0,4).compare("EXIT")==0)
        {
            loop = false;
        }
        else if(entry.substr(0,9).compare("GENERATE2")==0)
        {
            generateTest2();
        }
        else if(entry.substr(0,9).compare("GENERATE3")==0)
        {
            generateTest3();
        }
    }
    return 0;
}