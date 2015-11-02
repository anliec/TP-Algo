//
// Created by Edern Haumont on 19/10/2015.
//
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
        outFile << "V 100%\r\n";
        outFile << "J 0%\r\n";
        outFile << "R 0%\r\n";
        outFile << "N 0%\r\n";
        inFile << "STATS_C 6\r\n";
        outFile << "V 0%\r\n";
        outFile << "J 50%\r\n";
        outFile << "R 50%\r\n";
        outFile << "N 0%\r\n";
        inFile << "STATS_C 7\r\n";
        outFile << "V 25%\r\n";
        outFile << "J 25%\r\n";
        outFile << "R 25%\r\n";
        outFile << "N 25%\r\n";

    }
    inFile << "EXIT\r\n";
    cout << "end of test generation" << endl;
    return 0;
}