#ifndef NOKTA_HPP
#define NOKTA_HPP
class Nokta
{
public:
    Nokta(int x, int y, int z);
    int x;
    int y;
    int z;
    int orijineUzaklikBul();
    Nokta *sonraki;
};
#endif