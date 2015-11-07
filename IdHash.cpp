//
// Created by nicolas on 07/11/15.
//

#include <sys/types.h>
#include "IdHash.h"

IdHash::IdHash()
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
    for (int i = 0; i < SIZE_OF_HASHTABLE; i++)
    {
        if(sizeOfHashList[i][1]!=0)
        {
            delete [] hashTable[i][0];
            delete [] hashTable[i][1];
        }
    }
}

void IdHash::addId(const unsigned &id)
{
    insertAt(hashFunction(id),id);
}

unsigned int IdHash::getTabId(const unsigned & id) const
{
    return readAt(hashFunction(id),id);
}

unsigned IdHash::hashFunction(const unsigned &id) const
{
    return ((id*A+B)%PRIME_NUMBER)%SIZE_OF_HASHTABLE;
}

void IdHash::insertAt(const unsigned &pos, const unsigned &id)
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
