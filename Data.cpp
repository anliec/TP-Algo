//
// Created by Edern Haumont on 19/10/2015.
//

#include "Data.h"

Data::Data(usint &id,usint &year,uchar &month,uchar &dayNumber,uchar &hours,uchar &min,uchar &weekDay,char &traffic):\
    m_id(id), m_year(year), m_month(month), m_dayNumber(dayNumber), m_hours(hours), m_min(min), m_weekDay(weekDay),
    m_traffic(traffic)
{

}

Data::Data():\
    m_id(0),m_year(0),m_month(0),m_dayNumber(0),m_hours(0),m_min(0),m_weekDay(0),m_traffic(0)
{

}


usint Data::getId() const {
    return m_id;
}

usint Data::getYear() const {
    return m_year;
}

uchar Data::getMonth() const {
    return m_month;
}

uchar Data::getDayNumber() const {
    return m_dayNumber;
}

uchar Data::getHours() const {
    return m_hours;
}

uchar Data::getMin() const {
    return m_min;
}

uchar Data::getWeekDay() const {
    return m_weekDay;
}

char Data::getTrafic() const {
    return m_traffic;
}

