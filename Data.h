//
// Created by Edern Haumont on 19/10/2015.
//

#ifndef TP_ALGO_DATA_H
#define TP_ALGO_DATA_H


//Constants
const int DEFAULT_CONTAINER_SIZE = 78125;

typedef unsigned short int usint;
typedef unsigned char uchar;

class Data
{
public:
    //getters:
    usint getId() const;
    usint getYear() const;
    uchar getMonth() const;
    uchar getDayNumber() const;
    uchar getHours() const;
    uchar getMin() const;
    uchar getWeekDay() const;
    char getTrafic() const;

    Data(usint &id,usint &year,uchar &month,uchar &dayNumber,uchar &hours,uchar &min,uchar &weekDay,char &trafic);
    Data();

private:
    usint m_id;
    usint m_year;
    uchar m_month;
    uchar m_dayNumber;
    uchar m_hours;
    uchar m_min;
    uchar m_weekDay;
    char m_trafic;
};


#endif //TP_ALGO_DATA_H
