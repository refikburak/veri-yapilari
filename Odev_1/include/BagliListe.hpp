#ifndef BAGLILISTE_HPP
#define BAGLILISTE_HPP

#include "Dugum.hpp"
class BagliListe
{
private:
    Dugum *ilk;
    int uzunluk;

public:
    BagliListe();
    ~BagliListe();
    void Ekle(int indis, std::string veri);
    void Sil(int indis);
    void Yazdir();
};

#endif