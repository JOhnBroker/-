#include <iostream>
#include "Classic.h"
void Bravo(const Cd & disk);
int main() {
////13.1
    Cd c1("Beatles","Capitol",14,35.5);
    Classic c2=Classic("Piano Sonata in B flat, Fantasia in-C",
                       "Alfred Brendel","Philips",2,57.17);
    Cd *pcd =&c1;
    std::cout<<"Using object directly."<<std::endl;
    c1.Report();
    c2.Report();
    std::cout<<std::endl;
    std::cout<<"Using tye cd* pointer to objects."<<std::endl;
    pcd->Report();
    pcd=&c2;
    pcd->Report();
    std::cout<<std::endl;
    std::cout<<"Calling a funtion with a Cd reference argument"<<std::endl;
    Bravo(c1);
    Bravo(c2);
    std::cout<<std::endl;
    std::cout<<"Testing assignment"<<std::endl;
    Classic copy;
    copy =c2;
    copy.Report();
    return 0;
}
void Bravo(const Cd & disk){
    disk.Report();
}