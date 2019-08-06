#ifndef INC_14_2_WINEC_H
#define INC_14_2_WINEC_H
#include <iostream>
#include <string.h>
#include <valarray>
typedef std::valarray<int> ArrayInt;
typedef std::pair<ArrayInt,ArrayInt> PairArray;

class Wine : private std::string ,private PairArray{
private:
    int yrs;
public:
    Wine(std::string l,int y,const int yr[],const int bot[]);
    Wine(const char* l,int y);
    void Show();
    void GetBottles();
    int sum();
    std::string & babel();
};


#endif //INC_14_2_WINEC_H
