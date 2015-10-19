//
// Created by Edern Haumont on 19/10/2015.
//

#include "Data.h"

Data::Data(usint &id,uchar &year,uchar &month,uchar &dayNumber,uchar &hours,uchar &min,uchar &weekDay,uchar &trafic):\
    m_id(id), m_year(year), m_month(month), m_dayNumber(dayNumber), m_hours(hours), m_min(min), m_weekDay(weekDay),
    m_trafic(trafic)
{

}

usint Data::getId() const {
    return m_id;
}

uchar Data::getYear() const {
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

uchar Data::getTrafic() const {
    return m_trafic;
}