//
// Created by Edern Haumont on 19/10/2015.
//

#ifndef TP_ALGO_DATA_H
#define TP_ALGO_DATA_H


class Data
{
public:
    Data(int &id,char &year,char &month,char &dayNumber,char &hours,char &min,char &weekDay,char &trafic);


private:
    int m_id;
    char m_year;
    char m_month;
    char m_dayNumber;
    char m_hours;
    char m_min;
    char m_weekDay;
    char m_trafic;
};


#endif //TP_ALGO_DATA_H
