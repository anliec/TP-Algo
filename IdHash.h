//
// Created by nicolas on 07/11/15.
//

#ifndef TP_ALGO_IDHASH_H
#define TP_ALGO_IDHASH_H


#define SIZE_OF_HASHTABLE 1000
//hash function parameters
#define PRIME_NUMBER 2999
#define A 1
#define B 0

class IdHash
{
public:
    IdHash();
    ~IdHash();

    void addId(const unsigned & id);
    unsigned getTabId(const unsigned & id) const;

private:
    unsigned hashFunction(const unsigned & id) const;
    void insertAt(const unsigned & pos, const unsigned & id);
    unsigned readAt(const unsigned & pos, const unsigned &id) const;

private:
    unsigned * hashTable[SIZE_OF_HASHTABLE][2]; // 0: id // 1: id in tabs
    unsigned sizeOfHashList[SIZE_OF_HASHTABLE][2];// 0: used size // 1:usable size
    unsigned lastIdInTab;

};


#endif //TP_ALGO_IDHASH_H
