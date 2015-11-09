//
// Created by Edern Haumont on 19/10/2015.
//
#include <fstream>
#include <iostream>

#ifndef TP_ALGO_TEST_H
#define TP_ALGO_TEST_H

const int FILE_ERROR = 99;

int generateTest2();
int generateTest3();
int generateTest4();
int generateTest5();

int randSensList(int * sensors, int size);
int randDay7();
int randState();
int randHour();
int randMin();

#endif //TP_ALGO_TEST_H