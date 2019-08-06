#ifndef INC_14_WINEC_H
#define INC_14_WINEC_H
#include <iostream>
#include <valarray>
#include <string.h>
typedef std::valarray<int> ArrayInt;
typedef std::pair<ArrayInt,ArrayInt> PairArray;

class Wine {
private:
    std::string name;
    int yrs;
    PairArray data;
public:
    Wine(const char* l,int y,const int yr[],const int bot[]);
    Wine(const char* l,int y);
    ~Wine();
    void Show();
    void GetBottles();
    std::string & babel();
    int sum();
};


#endif //INC_14_WINEC_H
