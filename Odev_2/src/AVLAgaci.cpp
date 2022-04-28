/**
* @file AVLAgaci.cpp
* @description AVL ağacının ekleme, silme, postorder gezme ve ham veriyi istenen formata çevirme fonksiyonları
* @course 2-B
* @assignment 2
* @date 22.12.2021
* @author Refik Burak Akbaş refikburakakbas@gmail.com
*/
#include "AVLAgaci.hpp"
#include <cmath>
#include <iostream>
#include <sstream>
#include <string.h>
using namespace std;
AVLAgaci::AVLAgaci()
{
    kok = 0;
}
AVLAgaci::~AVLAgaci()
{
    Sil(kok);
}
//Koordinat sayısını satırdan bulan fonksiyon
int AVLAgaci::koordinatSayisi(string satir)
{
    stringstream ss(satir);
    int sayac = 0;
    string temp = "";
    while (ss >> temp)
        sayac++;
    return sayac;
}
//Satırdaki veriyi işleyen fonksiyon
void AVLAgaci::ekle(string satir)
{
    DogruKuyrugu *kuyruk = new DogruKuyrugu();
    string xcord;
    string ycord;
    string zcord;
    stringstream ss(satir);

    for (int i = 0; i < koordinatSayisi(satir); i++)
    {
        if (i % 3 == 0)
            ss >> xcord;
        else if (i % 3 == 1)
            ss >> ycord;
        else
        {
            ss >> zcord;
            kuyruk->NoktaEkle(stoi(xcord), stoi(ycord), stoi(zcord));
        }
    }
    kok = ekle(kuyruk, kok);
}
int AVLAgaci::yukseklik()
{
    return yukseklik(kok);
}
void AVLAgaci::postOrder()
{
    postOrder(kok);
}
//Postorder gezme ve yazdırmayı sağlayan fonksiyon
void AVLAgaci::postOrder(DogruKuyrugu *aktif)
{
    if (aktif)
    {
        postOrder(aktif->sol);
        postOrder(aktif->sag);
        aktif->OrijineUzaklikYazdir();
    }
}
//AVL'deki yüksekliği bulan fonksiyon
int AVLAgaci::yukseklik(DogruKuyrugu *aktifKuyruk)
{
    if (aktifKuyruk)
    {
        return 1 + max(yukseklik(aktifKuyruk->sol),
                       yukseklik(aktifKuyruk->sag));
    }
    return -1;
}
//Ekleme ve dengelemeyi yapan fonksiyon
DogruKuyrugu *AVLAgaci::ekle(DogruKuyrugu *eklenecek, DogruKuyrugu *aktifKuyruk)
{

    if (aktifKuyruk == 0)
        return eklenecek;

    else if (aktifKuyruk->toplamUzunlukBul() < eklenecek->toplamUzunlukBul())
    {
        aktifKuyruk->sag = ekle(eklenecek, aktifKuyruk->sag);
        if (yukseklik(aktifKuyruk->sag) - yukseklik(aktifKuyruk->sol) > 1)
        {
            if (eklenecek->toplamUzunlukBul() > aktifKuyruk->sag->toplamUzunlukBul())
                aktifKuyruk = solaDondur(aktifKuyruk);

            else
            {
                aktifKuyruk->sag = sagaDondur(aktifKuyruk->sag);
                aktifKuyruk = solaDondur(aktifKuyruk);
            }
        }
    }
    else if (aktifKuyruk->toplamUzunlukBul() >= eklenecek->toplamUzunlukBul())
    {
        aktifKuyruk->sol = ekle(eklenecek, aktifKuyruk->sol);
        if (yukseklik(aktifKuyruk->sol) - yukseklik(aktifKuyruk->sag) > 1)
        {

            if (eklenecek->toplamUzunlukBul() < aktifKuyruk->sol->toplamUzunlukBul())
                aktifKuyruk = sagaDondur(aktifKuyruk);
            else
            {
                aktifKuyruk->sol = solaDondur(aktifKuyruk->sol);
                aktifKuyruk = sagaDondur(aktifKuyruk);
            }
        }
    }
    return aktifKuyruk;
}

DogruKuyrugu *AVLAgaci::solaDondur(DogruKuyrugu *buyukEbeveyn)
{
    DogruKuyrugu *sagCocuk = buyukEbeveyn->sag;
    buyukEbeveyn->sag = sagCocuk->sol;
    sagCocuk->sol = buyukEbeveyn;
    return sagCocuk;
}

DogruKuyrugu *AVLAgaci::sagaDondur(DogruKuyrugu *buyukEbeveyn)
{
    DogruKuyrugu *solCocuk = buyukEbeveyn->sol;
    buyukEbeveyn->sol = solCocuk->sag;
    solCocuk->sag = buyukEbeveyn;
    return solCocuk;
}
//Silmeyi yapan fonksiyon
void AVLAgaci::Sil(DogruKuyrugu *silinecek)
{
    if (silinecek)
    {
        Sil(silinecek->sol);
        Sil(silinecek->sag);
        delete silinecek;
    }
}