#include <iostream>
#include "Tv.h"

int main() {
    using std::cout;
    using std::endl;

    Tv s1;
    cout << "Inital setting for Tv s1 \n";
    s1.setting();
    s1.chanup();
    s1.set_mode();
    s1.set_input();
    s1.onoff();

    cout<<"Turn on the Tv"<<endl;
    s1.setting();
    cout<<endl;

    cout << "change for Tv s1\n";
    Remote r1;
    r1.set_chan(s1, 50);

    cout << "Inital r1: " << endl;
    r1.show(s1);
    s1.set_remote(r1);

    cout << "\nChange for s1: " << endl;
    r1.show(s1);

    return 0;
}