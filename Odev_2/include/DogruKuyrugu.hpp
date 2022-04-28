#ifndef DOGRUKUYRUGU_HPP
#define DOGRUKUYRUGU_HPP
#include "Nokta.hpp"
#include <string>
class DogruKuyrugu
{
public:
    DogruKuyrugu();
    ~DogruKuyrugu();
    DogruKuyrugu *sol;
    DogruKuyrugu *sag;
    void NoktaEkle(int x, int y, int z);
    Nokta *enYakinOncekiNokta();
    void enYakiniCikar();
    Nokta *enYakiniGetir();
    int uzunlukBul(Nokta nokta1, Nokta nokta2);
    int toplamUzunlukBul();
    void OrijineUzaklikYazdir();
    int count;

private:
    Nokta *ilk;
    Nokta *son;
};
#endif