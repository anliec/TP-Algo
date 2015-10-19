#include <iostream>
#include <string>

int main()
{
    bool loop=true;
    std::string entry;
    while(loop)
    {
        std::getline(std::cin,entry);
        if(entry.substr(0,3).compare("ADD")==0)
        {

        }
        else if(entry.substr(0,7).compare("STATS_C")==0)
        {

        }
        else if(entry.substr(0,6).compare("JAM_DH")==0)
        {

        }
        else if(entry.substr(0,8).compare("STATS_D7")==0)
        {

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
