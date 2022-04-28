/**
* @file DogruKuyrugu.cpp
* @description Doğru kuyruğu sınıfının kuyruk ve öncelik fonksiyonları
* @course 2-B
* @assignment 2
* @date 22.12.2021
* @author Refik Burak Akbaş refikburakakbas@gmail.com
*/
#include "DogruKuyrugu.hpp"
#include <iostream>
#include <math.h>
DogruKuyrugu::DogruKuyrugu()
{
    ilk = 0, son = 0, sag = 0, sol = 0, count = 0;
}
//Noktaları silen fonksiyon
DogruKuyrugu::~DogruKuyrugu()
{
    Nokta *gecici = ilk;
    while (gecici != 0)
    {
        Nokta *silinecek = gecici;
        gecici = gecici->sonraki;
        delete silinecek;
    }
}
//Önceliğe göre en yakın noktanın bir önceki noktasını getiren yardımcı fonksiyon
Nokta *DogruKuyrugu::enYakinOncekiNokta()
{
    if (ilk == 0)
        return 0;
    Nokta *gec = ilk;
    Nokta *onceki = 0;
    Nokta *sonraki = 0;
    int enYakin = gec->orijineUzaklikBul();
    while (gec->sonraki != 0)
    {
        if (gec->sonraki->orijineUzaklikBul() < enYakin)
        {
            enYakin = gec->sonraki->orijineUzaklikBul();
            onceki = gec;
        }
        gec = gec->sonraki;
    }
    return onceki;
}
//En yakındaki noktayı kuyruktan çıkaran fonksiyon
void DogruKuyrugu::enYakiniCikar()
{
    Nokta *onceki = enYakinOncekiNokta();
    if (onceki)
    {
        if (onceki->sonraki == son)
            son = onceki;
        Nokta *sil = onceki->sonraki;
        onceki->sonraki = sil->sonraki;
        delete sil;
    }
    else
    {
        if (ilk == 0)
            return;
        Nokta *sil = ilk;
        ilk = ilk->sonraki;
        delete sil;
    }
}
//En yakındaki noktayı yardımcı fonksiyon aracılığıyla getiren fonksiyon
Nokta *DogruKuyrugu::enYakiniGetir()
{
    Nokta *onceki = enYakinOncekiNokta();
    if (onceki)
        return onceki->sonraki;
    if (ilk != 0)
        return ilk;

    throw std::out_of_range("Nokta yok");
}

//Nokta ekleme
void DogruKuyrugu::NoktaEkle(int x, int y, int z)
{

    Nokta *nokta = new Nokta(x, y, z);
    if (ilk == 0)
    {
        ilk = nokta;
        son = nokta;
    }
    else
    {
        Nokta *yeni = nokta;
        son->sonraki = yeni;
        son = yeni;
    }
    count++;
}

//İki nokta arasındaki uzunluğu bulma
int DogruKuyrugu::uzunlukBul(Nokta nokta1, Nokta nokta2)
{
    return sqrt(pow((nokta1.x - nokta2.x), 2) + pow((nokta1.y - nokta2.y), 2) + pow((nokta1.z - nokta2.z), 2));
}

//Yukarıdaki fonksiyonu kullanan ve kuyruktaki tüm noktaların arasındaki uzunluğu bulan fonksiyon.
int DogruKuyrugu::toplamUzunlukBul()
{
    int toplamMesafe = 0;
    Nokta *gecici = ilk;
    while (gecici->sonraki->sonraki != 0)
    {
        toplamMesafe += uzunlukBul(*gecici, *gecici->sonraki);
        gecici = gecici->sonraki;
    }
    toplamMesafe += uzunlukBul(*gecici, *gecici->sonraki);
    return toplamMesafe;
}
//Çıktıyı istenen formatta yazdıran fonksiyon
void DogruKuyrugu::OrijineUzaklikYazdir()
{
    for (int i = 0; i < count; i++)
    {
        std::cout << enYakiniGetir()->orijineUzaklikBul() << " ";
        enYakiniCikar();
    }
    std::cout << std::endl;
}