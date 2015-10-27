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
        std::cout << entry;
        if(entry.substr(0,3).compare("ADD")==0)
        {
            usint id;
            uchar year, month, day, hours, min, weekDay, trafic;
            std::cin >> year >> month >> day >> hours >> min >> weekDay >> trafic;
            handler.addData(Data(id,year,month,day,hours,min,weekDay,trafic));
        }
        else if(entry.substr(0,7).compare("STATS_C")==0)
        {
            usint id;
            std::cin >> id;

        }
        else if(entry.substr(0,6).compare("JAM_DH")==0)
        {
            uchar weekDay;
            std::cin >> weekDay;

        }
        else if(entry.substr(0,8).compare("STATS_D7")==0)
        {
            uchar weekDay;
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