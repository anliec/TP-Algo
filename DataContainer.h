/*************************************************************************
                           DataContainer  -  description
                             -------------------
    begin                : 19/10/2015
    copyright            : (C) 2015 by Edern Haumont & Nicolas Six
*************************************************************************/

//---------- Interface of the class DataContainer (file DataContainer.h) ------
#ifndef TP_ALGO_DATACONTAINER_H
#define TP_ALGO_DATACONTAINER_H

#include "Data.h"


//Constants
const int DEFAULT_CONTAINER_SIZE = 78125;


//------------------------------------------------------------------------
// what is this class useful for ?
//
//------------------------------------------------------------------------
class DataContainer {

//Public methods
public:

    //adds a value
    int add(Data newData);

    //reads a value
    Data at(int index) const;

    //Constructor
    DataContainer(unsigned int capacity = DEFAULT_CONTAINER_SIZE);

    //Destructor
    virtual ~DataContainer ( );


//Private methods
private:
    //Adjusts the capacity of the container
    int adjust(unsigned int newCapacity = 2*m_capacity);


//Private attributes
private:
    unsigned int m_used;
    unsigned int m_capacity;
    Data *m_tab;

}; //class DataContainer


#endif //TP_ALGO_DATACONTAINER_H
