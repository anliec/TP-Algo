//
// Created by Edern Haumont on 19/10/2015.
//
#include <fstream>
#include <iostream>

#ifndef TP_ALGO_TEST_H
#define TP_ALGO_TEST_H

const int FILE_ERROR = 99;

using namespace std;

int generateTest2()
{
    ofstream file("test.txt", ios::out | ios::trunc);  // ouverture en écriture avec effacement du fichier ouvert
    if(!file)
    {
        cout << "erreur d'ouverture de fichier" << endl;
        return FILE_ERROR;
    }

    else
    {
        for (int id=0; id<1500; id++) {
            for (int month=6; month <10; month++)
            {
                for (int day=0; day <30; day++)
                {
                    int relativeMonth = 6 - month;
                    int day7 = (relativeMonth*30+day)^7;
                    for (int hour=0; hour <24; hour++)
                    {
                        for (int min=0; min <60; min++)
                        {

                        }
                    }
                }
            }
        }
    }
};

















#endif //TP_ALGO_TEST_H

/*
 * #include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
        ofstream fichier("test.txt", ios::out | ios::trunc);  // ouverture en écriture avec effacement du fichier ouvert

        if(fichier)
        {
                string nom = "Xav57";
                int age = 19;
                fichier << "Date de naissance : " << 24 << '/' << 3 << '/' << 1988 << endl;
                fichier << "Bonjour, " << nom << ". Vous avez " << age << " ans.";

                fichier.close();
        }
        else
                cerr << "Impossible d'ouvrir le fichier !" << endl;

        return 0;
}

 */