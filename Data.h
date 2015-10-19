//
// Created by Edern Haumont on 19/10/2015.
//

#ifndef TP_ALGO_DATA_H
#define TP_ALGO_DATA_H

typedef unsigned short int usint;
typedef unsigned char uchar;

class Data
{
public:
    Data(usint &id,uchar &year,uchar &month,uchar &dayNumber,uchar &hours,uchar &min,uchar &weekDay,uchar &trafic);

private:
    usint m_id;
    uchar m_year;
    uchar m_month;
    uchar m_dayNumber;
    uchar m_hours;
    uchar m_min;
    uchar m_weekDay;
    uchar m_trafic;
};


#endif //TP_ALGO_DATA_H
