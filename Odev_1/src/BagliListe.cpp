/**
* @file BagliListe.cpp
* @description Bağlı listeye düğümleri ekleme, silme ve düğümleri yazdırma
* @course 2-B
* @assignment 1
* @date 28.10.2021
* @author Refik Burak Akbaş refikburakakbas@gmail.com
*/
#include "BagliListe.hpp"
#include <iostream>
#include <iomanip>
using namespace std;

BagliListe::BagliListe()
{
    ilk = 0;
    uzunluk = 0;
}
void BagliListe::Ekle(int indis, std::string veri)
{
    Dugum *yeni = new Dugum(veri);
    Dugum *gecici = ilk;
    int sayac = uzunluk;

    //Hiç eleman yoksa eleman ekleme
    if (ilk == 0)
    {
        ilk = yeni;
        uzunluk++;
        return;
    }

    ////Verilen indis yoksa veya indis son elemanı gösteriyorsa sona eleman ekleme
    if (indis >= uzunluk || indis < 0)
    {
        while (gecici->sonraki != 0)
        {
            gecici = gecici->sonraki;
        }
        gecici->sonraki = yeni;
        yeni->onceki = gecici;
        uzunluk++;
        return;
    }

    //Araya eleman ekleme
    while (gecici->sonraki != 0)
    {
        gecici = gecici->sonraki;
    }
    gecici->sonraki = yeni;
    yeni->onceki = gecici;
    gecici = gecici->sonraki;

    while (sayac-- != indis)
    {
        gecici = gecici->onceki;
        gecici->sonraki->veri = gecici->veri;
    }
    gecici->veri = veri;
    uzunluk++;
}
void BagliListe::Sil(int indis)
{
    Dugum *gecici = ilk;
    //Eleman yoksa silmeme
    if (ilk == 0)
        return;

    //Tek elemanlıysa o elemanı silme
    if (ilk->sonraki == 0)
    {
        delete ilk;
        uzunluk--;
        ilk = 0;
        return;
    }
    //Verilen indis yoksa veya indis son elemanı gösteriyorsa sondaki elemanı silme
    if (indis >= uzunluk || indis < 0)
    {
        while (gecici->sonraki->sonraki != 0)
        {
            gecici = gecici->sonraki;
        }
        Dugum *silinecek = gecici->sonraki;
        gecici->sonraki = NULL;
        uzunluk--;
        delete silinecek;
        return;
    }
    //Aradaki elemanı silme
    for (int i = 0; i < indis; i++)
    {
        gecici = gecici->sonraki;
    }
    while (gecici->sonraki != 0)
    {
        gecici = gecici->sonraki;
        gecici->onceki->veri = gecici->veri;
    }
    Dugum *silinecek = gecici;
    gecici = gecici->onceki;
    gecici->sonraki = NULL;
    uzunluk--;
    delete silinecek;
}
void BagliListe::Yazdir()
{
    Dugum *gecici = ilk;
    while (gecici->sonraki != NULL)
    {
        cout << gecici->veri << "<-->";
        gecici = gecici->sonraki;
    }
    cout << gecici->veri << "\n";
}
BagliListe::~BagliListe()
{
    Dugum *gecici = ilk;
    while (gecici != 0)
    {
        Dugum *silinecek = gecici;
        gecici = gecici->sonraki;
        delete silinecek;
    }
    cout << "Bagli liste silindi." << endl;
}