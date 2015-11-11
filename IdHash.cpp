/*************************************************************************
                           IdHash  -  description
                             -------------------
    debut                : 05/10/2015
    copyright            : (C) 2015 by Edern Haumont & Nicolas Six
*************************************************************************/

//---------- Realisation of the class IdHash (file IdHash.cpp) --
#include "IdHash.h"

//----------------------------------------------------------------- PUBLIC

// public methods
IdHash::IdHash()
/* Algorithm : initializes sizeOfHashList values and set lastIdInTab to 0;
 */
{
    for (int i = 0; i < SIZE_OF_HASHTABLE; i++)
    {
        sizeOfHashList[i][0]=0;
        sizeOfHashList[i][1]=0;
    }
    lastIdInTab = 0;
}

IdHash::~IdHash()
{
/* Algorithm : deletes dynamically allocated elements (hashTable)
 */
    for (int i = 0; i < SIZE_OF_HASHTABLE; i++)
    {
        if(sizeOfHashList[i][1]!=0)
        {
            delete [] hashTable[i][0];
            delete [] hashTable[i][1];
        }
    }
}

unsigned IdHash::addId(const unsigned &id)
/* checks if the id already exists.
 */
{
    unsigned idInTab, pos=hashFunction(id);
    if(alreadyAdded(id,pos,idInTab))
    {
        return idInTab;
    }
    else
    {
        return insertAt(pos,id);
    }
}

unsigned int IdHash::getTabId(const unsigned & id) const
{
    return readAt(hashFunction(id),id);
}

unsigned IdHash::hashFunction(const unsigned &id) const
{
    return ((id*A+B)%PRIME_NUMBER)%SIZE_OF_HASHTABLE;
}

unsigned IdHash::insertAt(const unsigned &pos, const unsigned &id)
{
    if(sizeOfHashList[pos][0]+1>sizeOfHashList[pos][1])
    {
        unsigned * tempId = hashTable[pos][0];
        unsigned * tempTabId = hashTable[pos][1];
        if(sizeOfHashList[pos][1] == 0)
        {
            sizeOfHashList[pos][1] = 2;
        }
        else
        {
            sizeOfHashList[pos][1] *= 2;
        }
        hashTable[pos][0] = new unsigned[sizeOfHashList[pos][1]];
        hashTable[pos][1] = new unsigned[sizeOfHashList[pos][1]];

        for (int i = 0; i < sizeOfHashList[pos][0]; i++)
        {
            hashTable[pos][0][i] = tempId[i];
            hashTable[pos][1][i] = tempTabId[i];
        }
        delete [] tempId;
        delete [] tempTabId;
    }
    hashTable[pos][0][sizeOfHashList[pos][0]] = id;
    hashTable[pos][1][sizeOfHashList[pos][0]] = lastIdInTab;
    lastIdInTab++;
    sizeOfHashList[pos][0]++;
    return lastIdInTab-1;
}

unsigned IdHash::readAt(const unsigned &pos, const unsigned &id) const
{
    for (int i = 0; i < sizeOfHashList[pos][0]; i++)
    {
        if(hashTable[pos][0][i] == id)
        {
            return hashTable[pos][1][i];
        }
    }
    return 0;
}

bool IdHash::alreadyAdded(const unsigned &id, const unsigned pos, unsigned &retToTabId) const
{
    for (int i = 0; i < sizeOfHashList[pos][0]; ++i) {
        if(hashTable[pos][0][i] == id)
        {
            retToTabId = hashTable[pos][1][i];
            return true;
        }
    }
    return false;
}
