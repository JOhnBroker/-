
#ifndef CLIONPROJECT_CD_H
#define CLIONPROJECT_CD_H
#include <string.h>
#include <iostream>

class Cd {
private:
    char performers[50];
    char label[20];
    int selections;
    double playtime;
public:
    Cd(char const * s1,char const * s2,int n,double x);
    Cd(const Cd &d);
    Cd(){};
    virtual ~Cd(){};
    virtual void Report()const;
    virtual Cd& operator=(const Cd& d);

};


#endif //CLIONPROJECT_CD_H
