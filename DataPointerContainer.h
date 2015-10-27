/*************************************************************************
                           DataPointerContainer  -  description
                             -------------------
    begin                : 19/10/2015
    copyright            : (C) 2015 by Edern Haumont & Nicolas Six
*************************************************************************/

//---------- Interface of the class DataPointerContainer (file DataPointerContainer.h) ------
#ifndef TP_ALGO_DATAPOINTERCONTAINER_H
#define TP_ALGO_DATAPOINTERCONTAINER_H

#include "Data.h"

//------------------------------------------------------------------------
// what is this class useful for ?
//
//------------------------------------------------------------------------
class DataPointerContainer {

//Public methods
public:

    //adds a value
    int add(Data* newDataPointer);

    //reads a value
    Data* at(int index) const;

    //get last index
    unsigned int endingIndex() const;

    //Constructor
    DataPointerContainer(unsigned int capacity = DEFAULT_CONTAINER_SIZE);

    //Destructor
    virtual ~DataPointerContainer ( );


//Private methods
private:
    //Adjusts the capacity of the container
    int adjust(unsigned int newCapacity);
    int adjust() {return adjust(2*m_capacity);}


//Private attributes
private:
    unsigned int m_used;
    unsigned int m_capacity;
    Data* * m_tab;

}; //class DataPointerContainer


#endif //TP_ALGO_DATAPOINTERCONTAINER_H
