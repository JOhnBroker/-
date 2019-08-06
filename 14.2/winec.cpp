#include "winec.h"

Wine::Wine(const char *l, int y):std::string(l),yrs(y) {
    ArrayInt year(y);
    ArrayInt bottles(y);
    (PairArray &)(*this)=std::make_pair(year,bottles);
}
Wine::Wine(std::string l, int y, const int *yr, const int *bot):std::string(l),yrs(y) {
    ArrayInt year(yr,y);
    ArrayInt bottles(bot,y);
    (PairArray &)(*this)=std::make_pair(year,bottles);
}
void Wine::Show() {
    std::cout<<"Wine: "<<(std::string &)(* this)<<std::endl;
    std::cout<<"\tYear"<<"\tBottles"<<std::endl;
    for(int i=0;i<yrs;i++){
        std::cout<<"\t"<<PairArray::first.operator[](i)<<"\t"<<PairArray::second.operator[](i)<<std::endl;
    }
}
void Wine::GetBottles() {
    std::cout<<"Enter "<<(std::string &)(* this)<<" data for "<<yrs<<" year(s)"<<std::endl;
    for(int i=0;i<yrs;i++){
        std::cout<<"Enter year: ";
        std::cin>>PairArray::first.operator[](i);
        std::cout<<"Enter bottles for that year: ";
        std::cin>>PairArray::second.operator[](i);
    }
}
int Wine::sum() {
    return PairArray::second.sum();
}
std::string& Wine::babel() {
    return (std::string &)(* this);
}