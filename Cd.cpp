
#include "Cd.h"
Cd::Cd(const Cd & d) {
    strcpy_s(performers,d.performers);
    strcpy_s(label,d.label);
    selections=d.selections;
    playtime=d.playtime;
}
Cd::Cd(char const *s1, char const *s2, int n, double x) {
    if(strlen(s1)>50){
        char *temp=new char[strlen(s1)+1];
        strcpy(temp,s1);
        temp[49]='\0';
        strcpy_s(performers,temp);
        delete [] temp;
    }
    else{
        strcpy_s(performers,s1);
    }
    if(strlen(s2)>20){
        char *temp=new char[strlen(s2)+1];
        strcpy(temp,s2);
        temp[19]='\0';
        strcpy_s(label,temp);
        delete [] temp;
    }
    else{
        strcpy_s(label,20,s2);
    }
    selections=n;
    playtime=x;
}
Cd& Cd::operator=(const Cd &d) {
    if(this==&d)return *this;
    strcpy(performers,d.performers);
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