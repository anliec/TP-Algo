//
// Created by Edern Haumont on 19/10/2015.
//
#include <stdlib.h>
#include <time.h>
#include "Test.h"

using namespace std;

int generateTest2()
{
    ofstream inFile("C:\\Users\\Edern Haumont\\Documents\\test2.in", ios::out | ios::trunc);  // ouverture en écriture avec effacement du fichier ouvert
    ofstream outFile("C:\\Users\\Edern Haumont\\Documents\\test2.out", ios::out | ios::trunc);  // ouverture en écriture avec effacement du fichier ouvert
    if(!inFile || !outFile)
    {
        cout << "erreur d'ouverture de fichier" << endl;
        return FILE_ERROR;
    }

    else
    {
        for (int id=0; id<1500; id++) {
            for (int month=6; month <7; month++)
            {
                for (int day=0; day <15; day++)
                {
                    int relativeMonth = 6 - month;
                    int day7 = (relativeMonth*30+day)%7+1;
                    for (int hour=0; hour <12; hour++)
                    {
                        for (int min=0; min <10; min++)
                        {
                            inFile << "ADD " << id << " " << 2015 << " " << month << " " << day << " " << hour << " " <<
                                    min << " " << day7 << " " << 'V' <<"\r\n";
                        }
                    }
                }
            }
        }

        inFile << "JAM_DH " << 1;
        for (int i=0; i<24; i++)
        {
            outFile << "1 " << i << " 0%\r\n";
        }
        inFile << "EXIT\r\n";

    }

    cout << "end of test generation" << endl;
    return 0;
}

int generateTest3()
{
    ofstream inFile("C:\\Users\\Edern Haumont\\Documents\\test3.in", ios::out | ios::trunc);  // ouverture en écriture avec effacement du fichier ouvert
    ofstream outFile("C:\\Users\\Edern Haumont\\Documents\\test3.out", ios::out | ios::trunc);  // ouverture en écriture avec effacement du fichier ouvert

    if(!inFile || !outFile)
    {
        cout << "erreur d'ouverture de fichier" << endl;
        return FILE_ERROR;
    }

    else
    {
        for (int id=0; id<50; id++) {
            for (int month=7; month <8; month++)
            {
                for (int day=0; day <30; day++)
                {
                    int relativeMonth = 7 - month;
                    int day7 = (relativeMonth*30+day)%7+1;
                    for (int hour=0; hour <24; hour++)
                    {
                        for (int min=0; min <60; min++)
                        {
                            inFile << "ADD " << id << " " << 2015 << " " << month << " " << day << " " << hour << " " <<
                            min << " " << day7 << " ";
                            switch(day7)
                            {
                                case 1:
                                    inFile <<'V';
                                    break;
                                case 2:
                                    inFile <<'J';
                                    break;
                                case 3:
                                    inFile <<'R';
                                    break;
                                case 4:
                                    inFile <<'N';
                                    break;
                                case 5:
                                    if(hour<12)
                                        inFile <<'V';
                                    else
                                        inFile <<'N';
                                    break;
                                case 6:
                                    if(hour<12)
                                        inFile <<'R';
                                    else
                                        inFile <<'J';
                                    break;
                                case 7:
                                    if(hour<6)
                                        inFile <<'V';
                                    else if(hour<12)
                                        inFile <<'J';
                                    else if(hour<18)
                                        inFile <<'R';
                                    else
                                        inFile <<'N';
                                    break;
                            }
                            inFile <<"\r\n";
                        }
                    }
                }
            }
        }
        inFile << "STATS_D7 " << 1<<"\r\n";
        outFile << "V 100%\r\n";
        outFile << "J 0%\r\n";
        outFile << "R 0%\r\n";
        outFile << "N 0%\r\n";
        inFile << "STATS_D7 " << 2<<"\r\n";
        outFile << "V 0%\r\n";
        outFile << "J 100%\r\n";
        outFile << "R 0%\r\n";
        outFile << "N 0%\r\n";
        inFile << "STATS_D7 " << 3<<"\r\n";
        outFile << "V 0%\r\n";
        outFile << "J 0%\r\n";
        outFile << "R 100%\r\n";
        outFile << "N 0%\r\n";
        inFile << "STATS_D7 " << 4<<"\r\n";
        outFile << "V 0%\r\n";
        outFile << "J 0%\r\n";
        outFile << "R 0%\r\n";
        outFile << "N 100%\r\n";
        inFile << "STATS_D7 " << 5<<"\r\n";
        outFile << "V 50%\r\n";
        outFile << "J 0%\r\n";
        outFile << "R 0%\r\n";
        outFile << "N 50%\r\n";
        inFile << "STATS_D7 " << 6<<"\r\n";
        outFile << "V 0%\r\n";
        outFile << "J 50%\r\n";
        outFile << "R 50%\r\n";
        outFile << "N 0%\r\n";
        inFile << "STATS_D7 " << 7<<"\r\n";
        outFile << "V 25%\r\n";
        outFile << "J 25%\r\n";
        outFile << "R 25%\r\n";
        outFile << "N 25%\r\n";

        inFile << "JAM_DH " << 1 <<"\r\n";
        for (int i=0; i<24; i++)
        {
            outFile << "1 " << i << " 0%\r\n";
        }
        inFile << "JAM_DH " <<5<<"\r\n";
        for (int i=0; i<12; i++)
        {
            outFile << "5 " << i << " 0%\r\n";
        }
        for (int i=12; i<24; i++)
        {
            outFile << "5 " << i << " 100%\r\n";
        }
        inFile << "JAM_DH " <<7<<"\r\n";
        for (int i=0; i<12; i++)
        {
            outFile << "7 " << i << " 0%\r\n";
        }
        for (int i=12; i<24; i++)
        {
            outFile << "7 " << i << " 100%\r\n";
        }

        inFile << "STATS_C 1\r\n";
        outFile << "V 26%\r\n";
        outFile << "J 26%\r\n";
        outFile << "R 23%\r\n";
        outFile << "N 23%\r\n";
        inFile << "STATS_C 6\r\n";
        outFile << "V 26%\r\n";
        outFile << "J 26%\r\n";
        outFile << "R 23%\r\n";
        outFile << "N 23%\r\n";
        inFile << "STATS_C 7\r\n";
        outFile << "V 26%\r\n";
        outFile << "J 26%\r\n";
        outFile << "R 23%\r\n";
        outFile << "N 23%\r\n";

        inFile << "OPT 6 11 13 5 20 40 41 42 43\r\n";
        outFile << "6 12 0 10\r\n";
        inFile << "OPT 5 22 23 8 1 2 3 4 5 6 7 8\r\n";
        outFile << "5 23 0 62\r\n";

        inFile << "EXIT\r\n";

    }
    cout << "end of test generation" << endl;
    return 0;
}

int generateTest4()
{
    ofstream inFile("C:\\Users\\Edern Haumont\\Documents\\test4.in", ios::out | ios::trunc);  // ouverture en écriture avec effacement du fichier ouvert
    ofstream outFile("C:\\Users\\Edern Haumont\\Documents\\test4.out", ios::out | ios::trunc);  // ouverture en écriture avec effacement du fichier ouvert

    if(!inFile || !outFile)
    {
        cout << "erreur d'ouverture de fichier" << endl;
        return FILE_ERROR;
    }

    else
    {
        inFile << "ADD " << 0 << " " << 2015 << " " << 11 << " " << 24 << " " << 8 << " " <<
        30 << " " << 1 << " " << 'R';
        inFile << "ADD " << 0 << " " << 2015 << " " << 11 << " " << 24 << " " << 8 << " " <<
        31 << " " << 1 << " " << 'J';
        inFile << "ADD " << 0 << " " << 2015 << " " << 6 << " " << 28 << " " << 8 << " " <<
        32 << " " << 1 << " " << 'N';

        inFile << "ADD " << 99 << " " << 2015 << " " << 11 << " " << 24 << " " << 8 << " " <<
        33 << " " << 1 << " " << 'J';
        inFile << "ADD " << 99 << " " << 2015 << " " << 11 << " " << 24 << " " << 8 << " " <<
        34 << " " << 1 << " " << 'J';

        inFile << "ADD " << 1450 << " " << 2015 << " " << 11 << " " << 24 << " " << 8 << " " <<
        35 << " " << 1 << " " << 'N';
        inFile << "ADD " << 1450 << " " << 2015 << " " << 6 << " " << 28 << " " << 8 << " " <<
        35 << " " << 1 << " " << 'R';
        inFile << "ADD " << 1450 << " " << 2015 << " " << 11 << " " << 24 << " " << 8 << " " <<
        36 << " " << 1 << " " << 'N';
        inFile << "ADD " << 1450 << " " << 2015 << " " << 11 << " " << 24 << " " << 8 << " " <<
        43 << " " << 1 << " " << 'R';

        inFile << "ADD " << 948 << " " << 2015 << " " << 11 << " " << 24 << " " << 8 << " " <<
        39 << " " << 1 << " " << 'J';
        inFile << "ADD " << 948 << " " << 2015 << " " << 11 << " " << 24 << " " << 8 << " " <<
        46 << " " << 1 << " " << 'J';
        inFile << "ADD " << 948 << " " << 2015 << " " << 11 << " " << 24 << " " << 8 << " " <<
        47 << " " << 1 << " " << 'V';

        inFile << "ADD " << 169 << " " << 2015 << " " << 11 << " " << 24 << " " << 12 << " " <<
        30 << " " << 1 << " " << 'N';
        inFile << "ADD " << 169 << " " << 2015 << " " << 11 << " " << 24 << " " << 8 << " " <<
        42 << " " << 1 << " " << 'R';

        inFile << "OPT 1 8 20 5 0 99 1450 948 169\r\n";

        outFile << "1 8 00 5\r\n";

        inFile << "EXIT\r\n";
    }
    return 0;
}

int generateTest5()
{
    ofstream inFile("C:\\Users\\Edern Haumont\\Documents\\test5.in", ios::out | ios::trunc);  // ouverture en écriture avec effacement du fichier ouvert
    if(!inFile)
    {
        cout << "erreur d'ouverture de fichier" << endl;
        return FILE_ERROR;
    }

    else
    {
        srand ( time(NULL) );
        unsigned int sensors[1500];
        randSensList(sensors, 1500);
        for(int sensorIndex =0; sensorIndex<1500; sensorIndex++)
        {
            for(int day=0; day<30; day++)
            {
                for(int month=0; month<444; month++)
                {
                    char color = randState();
                    int day7 = randDay7();
                    int min = randMin();
                    int hour = randHour();
                    inFile << "ADD " << sensors[sensorIndex] << " " << 2015 << " " << month << " " << day << " " << hour << " " <<
                    min << " " << day7 << " " << color <<"\r\n";
                }
            }
        }
        for(int i=0;i<1500;i++)
        {
            inFile << "STATS_C "<< sensors[i] <<"\r\n";
        }
        inFile << "JAM_DH 1\r\n";
        inFile << "JAM_DH 2\r\n";
        inFile << "JAM_DH 3\r\n";
        inFile << "JAM_DH 4\r\n";
        inFile << "JAM_DH 5\r\n";
        inFile << "JAM_DH 6\r\n";
        inFile << "JAM_DH 7\r\n";
        inFile << "STATS_D7 1\r\n";
        inFile << "STATS_D7 2\r\n";
        inFile << "STATS_D7 3\r\n";
        inFile << "STATS_D7 4\r\n";
        inFile << "STATS_D7 5\r\n";
        inFile << "STATS_D7 6\r\n";
        inFile << "STATS_D7 7\r\n";
        inFile << "OPT 1 0 11 10";
        for(int i=0; i<10; i++)
        {
            inFile << " " << sensors[i];
        }
        inFile << "\r\n";
        inFile << "OPT 1 12 23 10";
        for(int i=10; i<20; i++)
        {
            inFile << " " << sensors[i];
        }
        inFile << "\r\n";
        inFile << "EXIT\r\n";
        cout << "generated 5!" <<endl;
        }
}

int randSensList(unsigned int* sensors, int size)
{
    for (int t=0;t<size;t++)
    {
        unsigned int random;
        bool newNumber=false;
        while (newNumber==false)
        {
            random = (rand()*rand())+1;
            newNumber=true;
            for(int j=0; j<t;j++)
            {
                if (sensors[j]== random)
                    newNumber=false;
            }
        }
        sensors[t]=random;
    }
    return 0;
}
int randDay7()
{
    return (rand()%7)+1;
    return 0;
}
int randState()
{
    char num = rand()%4;
    switch(num)
    {
        case 0:
            return 'V';
        case 1:
            return 'J';
        case 2:
            return 'R';
        case 3:
            return 'N';
    }
    return 0;
}
int randHour()
{
    return rand()%24;
    return 0;
}
int randMin()
{
    return rand()%60;
    return 0;
}
