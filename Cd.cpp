
#include "Cd.h"
Cd::Cd() {
    performers=new char[1];
    performers[0]='\0';
    label=new char[1];
    label[0]='\0';
    selections=0;
    playtime=0.0;
}
Cd::Cd(const Cd & d) {
    performers=new char[strlen(d.performers)+1];
    strcpy(performers,d.performers);
    label=new char[strlen(d.label)+1];
    strcpy(label,d.label);
    selections=d.selections;
    playtime=d.playtime;
}
Cd::Cd(char const *s1, char const *s2, int n, double x) {
    performers=new char[strlen(s1)+1];
    strcpy(performers,s1);
    label=new char[strlen(s2)+1];
    strcpy(label,s2);
    selections=n;
    playtime=x;
}
Cd& Cd::operator=(const Cd &d) {
    if(this==&d)return *this;
    delete[] performers;
    delete[] label;
    performers=new char[strlen(d.performers)+1];
    strcpy(performers,d.performers);
    label=new char[strlen(d.label)+1];
    strcpy(label,d.label);
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