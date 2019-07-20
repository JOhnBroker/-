
#ifndef CLIONPROJECT_CLASSIC_H
#define CLIONPROJECT_CLASSIC_H
#include "Cd.h"
#include <string>

class Classic:public Cd {
private:
    char * describe;
public:
    Classic(char const *,char const *,char const * ,int ,double);
    Classic(char const *,Cd&);
    void Report() const;
    virtual  Classic & operator =(Classic &);
    Classic();
    ~Classic(){delete[] describe;};
};


#endif //CLIONPROJECT_CLASSIC_H
