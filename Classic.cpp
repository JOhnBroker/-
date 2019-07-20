
#include "Classic.h"

Classic::Classic(std::string s1, char * s2, char * s3, int n, double x) :Cd((char *)s2,(char *)s3,n,x) {
    describe=s1;
}
Classic::Classic(std::string s1, Cd & cd) :Cd(cd) {
    describe=s1;
}
void Classic::Report() const {
    Cd::Report();
    std::cout<<"describe:"<<describe<<std::endl;
}

Classic & Classic::operator =(Classic & classic){
    Cd::operator=(classic);
    describe=classic.describe;
    return *this;
}