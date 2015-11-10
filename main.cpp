#include <string>
#include <sstream>
#include <string.h>
#include "DataHandler.h"
#include "Test.h"



int main()
{
    std::cin.sync_with_stdio(false);

    DataHandler handler;

    bool loop= true;
    std::string entry;
    //variable used in the while loop:
    uint id, hours, min, weekDay,year,month,day;
    char traffic;

    while(loop && !std::cin.eof())
    {
        std::cin >> entry;
        // input example: ADD 400 2015 11 02 14 08 1 N
        if(entry.substr(0,3).compare("ADD")==0)
        {
            std::cin >> id >> year >> month >> day >> hours >> min >> weekDay >> traffic;
            handler.addData(traffic,min,hours,id,weekDay-1);
        }
        else if(entry.substr(0,7).compare("STATS_C")==0)
        {
            std::cin >> id;
            handler.sensorStats(id);
        }
        else if(entry.substr(0,6).compare("JAM_DH")==0)
        {
            std::cin >> weekDay;
            handler.jamStats(weekDay-1);
        }
        else if(entry.substr(0,8).compare("STATS_D7")==0)
        {
            std::cin >> weekDay;
            handler.dayStats(weekDay-1);
        }
#ifdef OPT
        else if(entry.substr(0,3).compare("OPT")==0)
        {
            uint startHours, endHours, tabSize;
            std::cin >> weekDay >> startHours >> endHours >> tabSize;
            uint idTab[tabSize];
            for (int i = 0; i < tabSize; i++)
            {
                std::cin >> idTab[i];
            }
            handler.optimum(weekDay-1,startHours,endHours,idTab,tabSize);
        }
#endif
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
        else if(entry.substr(0,9).compare("GENERATE4")==0)
        {
            generateTest4();
        }
        else if(entry.substr(0,9).compare("GENERATE5")==0)
        {
            generateTest5();
        }
    }
    return 0;
}