
#include "Classic.h"
Classic::Classic(){
    describe=new char[1];
    describe[0]='\0';
}
Classic::Classic(char const * s1, char const * s2, char const * s3, int n, double x) :Cd((char *)s2,(char *)s3,n,x) {
    describe=new char[strlen(s1)+1];
    strcpy(describe,s1);
}
Classic::Classic(char const * s1, Cd & cd) :Cd(cd) {
    describe=new char[strlen(s1)+1];
    strcpy(describe,s1);
}
void Classic::Report() const {
    Cd::Report();
    std::cout<<"describe:"<<describe<<std::endl;
    std::cout<<std::endl;
}

Classic & Classic::operator =(Classic & classic){
    if(this==&classic)return *this;
    Cd::operator=(classic);
    delete[] describe;
    describe=new char[strlen(classic.describe)+1];
    strcpy(describe,classic.describe);
    return *this;
}