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
    //char c_entry[20]; //using scanf is a bit slower than cin for string...
    //variable used in the while loop:
    uint id, hours, min, weekDay,year,month,day;
    char trafic;

    while(loop && !std::cin.eof())
    {
        std::cin >> entry;
        //scanf("%19s",c_entry);
        // input example: ADD 400 2015 11 02 14 08 1 N
        if(/*strcmp(c_entry,"ADD")==0*/entry.substr(0,3).compare("ADD")==0)
        {
            std::cin >> id >> year >> month >> day >> hours >> min >> weekDay >> trafic;
            //scanf("%u * * * %u %u %u %c",&id,&hours,&min,&weekDay,&trafic);
            handler.addData(trafic,min,hours,id,weekDay-1);
        }
        else if(/*strcmp(c_entry,"STATS_C")==0*/entry.substr(0,7).compare("STATS_C")==0)
        {
            std::cin >> id;
            //scanf("%u",&id);
            handler.sensorStats(id);
        }
        else if(/*strcmp(c_entry,"JAM_DH")==0*/entry.substr(0,6).compare("JAM_DH")==0)
        {
            std::cin >> weekDay;
            //scanf("%u",&weekDay);
            handler.jamStats(weekDay-1);
        }
        else if(/*strcmp(c_entry,"STATS_D7")==0*/entry.substr(0,8).compare("STATS_D7")==0)
        {
            std::cin >> weekDay;
            //scanf("%u",&weekDay);
            handler.dayStats(weekDay-1);
        }
#ifdef OPT
        else if(/*strcmp(c_entry,"OPT")==0*/entry.substr(0,3).compare("OPT")==0)
        {
            uint startHours, endHours, tabSize;
            std::cin >> weekDay >> startHours >> endHours >> tabSize;
            //scanf("%u %u %u %u",&weekDay,&startHours,&endHours,&tabSize);
            uint idTab[tabSize];
            for (int i = 0; i < tabSize; i++)
            {
                std::cin >> idTab[i];
                //scanf("%u",&idTab[i]);
            }
            handler.optimum(weekDay-1,startHours,endHours,idTab,tabSize);
        }
#endif
        else if(/*strcmp(c_entry,"EXIT")==0*/entry.substr(0,4).compare("EXIT")==0)
        {
            loop = false;
        }
        else if(/*strcmp(c_entry,"GENERATE2")==0*/entry.substr(0,9).compare("GENERATE2")==0)
        {
            generateTest2();
        }
        else if(/*strcmp(c_entry,"GENERATE3")==0*/entry.substr(0,9).compare("GENERATE3")==0)
        {
            generateTest3();
        }
    }
    return 0;
}