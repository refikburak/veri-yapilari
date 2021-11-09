/**
* @file Dugum.cpp
* @description Düğümleri oluşturma
* @course 2-B
* @assignment 1
* @date 28.10.2021
* @author Refik Burak Akbaş refikburakakbas@gmail.com
*/
#include "Dugum.hpp"
#include <iostream>
using namespace std;

Dugum::Dugum(string veri)
{
    this->veri = veri;
    this->onceki = NULL;
    this->sonraki = NULL;
}
Dugum::~Dugum()
{
    std::cout << veri << " dugumu silindi." << std::endl;
}