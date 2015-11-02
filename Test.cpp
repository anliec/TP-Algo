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

        inFile << "JAM_DH " << 0;
        for (int i=0; i<24; i++)
        {
            outFile << "0 " << i << " 0%\r\n";
        }
    }
    cout << "end of test generation" << endl;
    return 0;
}