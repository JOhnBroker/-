
#include "Cd.h"
Cd::Cd() {
    performers[0]='\0';
    label[0]='\0';
    selections=0;
    playtime=0.0;
}
Cd::Cd(const Cd & d) {
    strncpy(performers,d.performers,50);
    strncpy(label,d.label,20);
    selections=d.selections;
    playtime=d.playtime;
}
Cd::Cd(char const *s1, char const *s2, int n, double x) {
    strncpy(performers,s1,50);
    strncpy(label,s2,20);
    selections=n;
    playtime=x;
}
Cd& Cd::operator=(const Cd &d) {
    if(this==&d)return *this;
    strncpy(performers,d.performers,50);
    strncpy(label,d.label,20);
    selections=d.selections;
    playtime=d.playtime;
    return *this;
}
void Cd::Report() const {
    std::cout<<"Cd's performers:"<<performers<<std::endl;
    std::cout<<"Cd's label:"<<label<<std::endl;
    std::cout<<"Cd's selections:"<<selections<<std::endl;
    std::cout<<"Cd's playtime:"<<playtime<<std::endl;
}