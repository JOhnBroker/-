#include "winec.h"

Wine::Wine(const char *l, int y) {
    name=l;
    yrs=y;
    ArrayInt year(y);
    ArrayInt bottles(y);
    data=std::make_pair(year,bottles);
}

Wine::Wine(const char* l, int y, const int yr[], const int bot[])  {
    ArrayInt year(yr,y);
    ArrayInt bottles(bot,y);
    data=std::make_pair(year,bottles);
    name=l;
    yrs=y;
}

Wine::~Wine() {

}
void Wine::Show() {
    std::cout<<"Wine: "<<name<<std::endl;
    std::cout<<"\tYear"<<"\tBottles"<<std::endl;
    for(int i=0;i<yrs;i++){
        std::cout<<"\t"<<data.first[i]<<"\t"<<data.second[i]<<std::endl;
    }
}
void Wine::GetBottles() {
    std::cout<<"Enter "<<name<<" data for "<<yrs<<" year(s)"<<std::endl;
    for(int i=0;i<yrs;i++){
        std::cout<<"Enter year: ";
        std::cin>>data.first[i];
        std::cout<<"Enter bottles for that year: ";
        std::cin>>data.second[i];
    }
}
int Wine::sum() {
    return data.second.sum();
}
std::string & Wine::babel() {
    return name;
}