/**
* @file main.cpp
* @description Dosyadan okuma ve ham veriyi gönderme
* @course 2-B
* @assignment 2
* @date 22.12.2021
* @author Refik Burak Akbaş refikburakakbas@gmail.com
*/
#include <iostream>
#include <fstream>
#include "AVLAgaci.hpp"

using namespace std;

int main()
{
    ifstream dosyaOku(".\\doc\\Noktalar.txt");
    string satir = "";
    AVLAgaci *avlagaci = new AVLAgaci();
    if (dosyaOku.is_open())
    {
        while (getline(dosyaOku, satir))
        {
            avlagaci->ekle(satir);
        }
    }
    dosyaOku.close();
    avlagaci->postOrder();
    delete avlagaci;
    return 0;
}
