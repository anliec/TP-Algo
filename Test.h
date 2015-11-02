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