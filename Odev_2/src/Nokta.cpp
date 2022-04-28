/**
* @file Nokta.cpp
* @description Nokta sınıfının yapıcı fonksiyonu ve orijin formülü
* @course 2-B
* @assignment 2
* @date 22.12.2021
* @author Refik Burak Akbaş refikburakakbas@gmail.com
*/
#include "Nokta.hpp"
#include <math.h>
using namespace std;

Nokta::Nokta(int x, int y, int z)
{
    this->x = x;
    this->y = y;
    this->z = z;
    sonraki = 0;
}
//Noktanın orijine olan uzaklığını bulan fonksiyon
int Nokta::orijineUzaklikBul()
{
    return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
}