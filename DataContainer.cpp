//
// Created by Edern Haumont on 19/10/2015.
//

#include "DataContainer.h"
#include "ErrorCode.h"

int DataContainer::add(Data newData)
{
    if (m_capacity == m_used)
    {
        if (adjust() != 0)
        {
            return ERROR_RESIZE_FAILED; //error code: failed to resize the container
        }
    }
    m_tab[m_used]=newData;
    m_used++;
    return 0;
}//End of method "add"

Data DataContainer::at(int index) const
{
    return m_tab[index];
}

DataContainer::DataContainer(unsigned int capacity) : m_capacity(capacity)
{
    m_used = 0;
    #ifdef MAP
        cout << "Default constructor of DataContainer called" << endl;
    #endif
    m_tab = new Data[m_capacity];
} // End of constructor

DataContainer::~DataContainer()
{
    #ifdef MAP
        cout << "Destructor of DataContainer called" << endl;
    #endif
    delete [] m_tab;
}

int DataContainer::adjust(unsigned int newCapacity)
{
    if(newCapacity < m_used)
    {
        return ERROR_NON_INTUITIVE_ADJUSTMENT; //error code: impossible intuitive adjustment
    }
    else if(newCapacity == m_used)
    {
        return 0;
    }
    Data * ansTab = m_tab;
    m_tab = new Data[newCapacity];
    m_capacity = newCapacity;
    for(int i=0 ; i<m_used ; i++)
    {
        m_tab[i] = ansTab[i];
    }
    delete [] ansTab;
    return 0;
}
