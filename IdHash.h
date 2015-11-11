/*************************************************************************
                           IdHash  -  description
                             -------------------
    begin                : 25/10/2015
    copyright            : (C) 2015 by Edern Haumont & Nicolas Six
*************************************************************************/

//---------- Interface of the class IdHash (file IdHash.h) ------
#ifndef TP_ALGO_IDHASH_H
#define TP_ALGO_IDHASH_H


const int SIZE_OF_HASHTABLE = 5000;
//hash function parameters
const int PRIME_NUMBER = 7001;
const int A = 1;
const int B = 0;

//------------------------------------------------------------------------
// This class makes the link between a sensor id of the user and indexes in data tables
// It is a hashTable and its structure is an array
// It is not designed for more than 25000 ids
//------------------------------------------------------------------------
class IdHash
{

//----------------------------------------------------------------- PUBLIC
public:
//public methods
    unsigned addId(const unsigned & id);
    /* add the user id to the hash table if not already in
     * returns : an array position used by the program
     * contract : id in int range
     */

    unsigned getTabId(const unsigned & id) const;
    /* parameter : a sensor id called by the the user
     * returns : an array position used by the program
     * contract : id in unsigned int range
     */

//constructor - destructor
    IdHash();
    ~IdHash();

//------------------------------------------------------------------ PRIVATE
// private methods
private:
    unsigned hashFunction(const unsigned & id) const;
    unsigned insertAt(const unsigned & pos, const unsigned & id); //return the tab id
    unsigned readAt(const unsigned & pos, const unsigned &id) const;
    bool alreadyAdded(const unsigned & id, const unsigned pos, unsigned & retToTabId) const;

//private attributes
private:
    unsigned * hashTable[SIZE_OF_HASHTABLE][2]; // 0: id // 1: id in tabs
    unsigned sizeOfHashList[SIZE_OF_HASHTABLE][2];// 0: used size // 1:usable size
    unsigned lastIdInTab;

}; // class IdHash


#endif //TP_ALGO_IDHASH_H
