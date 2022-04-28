#ifndef AVLAGACI_HPP
#define AVLAGACI_HPP
#include <iostream>
#include "DogruKuyrugu.hpp"
using namespace std;

class AVLAgaci
{
public:
    AVLAgaci();
    ~AVLAgaci();
    void ekle(string veri);
    int yukseklik();
    void postOrder();

private:
    DogruKuyrugu *solaDondur(DogruKuyrugu *kuyruk);
    DogruKuyrugu *sagaDondur(DogruKuyrugu *kuyruk);
    void postOrder(DogruKuyrugu *index);
    int yukseklik(DogruKuyrugu *aktifKuyruk);
    DogruKuyrugu *ekle(DogruKuyrugu *eklenecek, DogruKuyrugu *aktifKuyruk);
    DogruKuyrugu *kok;
    int koordinatSayisi(string satir);
    void Sil(DogruKuyrugu *silinecek);
};
#endif