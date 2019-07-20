
#ifndef CLIONPROJECT_CLASSIC_H
#define CLIONPROJECT_CLASSIC_H
#include "Cd.h"
#include <string>

class Classic:public Cd {
private:
    std::string describe;
public:
    Classic(std::string,char *,char * ,int ,double);
    Classic(std::string,Cd&);
    void Report() const;
    Classic & operator =(Classic &);
    Classic(){};
    ~Classic(){};
};


#endif //CLIONPROJECT_CLASSIC_H
