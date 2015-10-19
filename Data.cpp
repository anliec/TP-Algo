//
// Created by Edern Haumont on 19/10/2015.
//

#include "Data.h"

Data::Data(usint &id,uchar &year,uchar &month,uchar &dayNumber,uchar &hours,uchar &min,uchar &weekDay,uchar &trafic):\
    m_id(id), m_year(year), m_month(month), m_dayNumber(dayNumber), m_hours(hours), m_min(min), m_weekDay(weekDay),
    m_trafic(trafic)
{

}