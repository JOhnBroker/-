
#include "Classic.h"
Classic::Classic(){
    describe[0]='\0';
}
Classic::Classic(char const * s1, char const * s2, char const * s3, int n, double x) :Cd((char *)s2,(char *)s3,n,x) {
    strcpy(describe,s1);
}
Classic::Classic(char const * s1, Cd & cd) :Cd(cd) {
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
    strcpy(describe,classic.describe);
    return *this;
}