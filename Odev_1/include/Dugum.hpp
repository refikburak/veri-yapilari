#ifndef DUGUM_HPP
#define DUGUM_HPP
#include <string>

class Dugum
{
public:
    Dugum(std::string veri);
    ~Dugum();
    std::string veri;
    Dugum *onceki;
    Dugum *sonraki;
};
#endif