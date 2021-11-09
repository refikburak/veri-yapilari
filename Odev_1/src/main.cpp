/**
* @file main.cpp
* @description Text dosyasını okuyup ekleme ve silme işlemleri yapma
* @course 2-B
* @assignment 1
* @date 28.10.2021
* @author Refik Burak Akbaş refikburakakbas@gmail.com
*/

#include <iostream>
#include <fstream>
#include "Dugum.hpp"
#include "BagliListe.hpp"
using namespace std;

int main()
{
    ifstream dosyaOku(".\\doc\\Veri.txt");
    string satir = "";
    int indis = 0;
    string veri = "";
    BagliListe *b = new BagliListe();
    if (dosyaOku.is_open())
    {
        while (getline(dosyaOku, satir))
        {
            for (int i = 0; i < satir.length(); i++)
            {
                string temp = "";

                if (satir[i] == '(')
                {
                    i++;
                    if (satir[0] == 'E')
                    {
                        while (satir[i] != '#')
                        {
                            temp += satir[i];
                            i++;
                        }
                        indis = stoi(temp);
                        temp = "";
                        i++;
                        while (satir[i] != ')')
                        {
                            temp += satir[i];
                            i++;
                        }
                        veri = temp;
                        b->Ekle(indis, veri);
                    }
                    else
                    {
                        while (satir[i] != ')')
                        {
                            temp += satir[i];
                            i++;
                        }
                        indis = stoi(temp);
                        b->Sil(indis);
                    }
                }
            }
        }
        dosyaOku.close();
    }
    b->Yazdir();
    delete b;
    return 0;
}