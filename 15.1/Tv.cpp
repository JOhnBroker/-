#include "Tv.h"

void Tv::chandown() {
    if(channel<1)channel=maxchanel;
    channel--;
}
void Tv::chanup() {
    if(channel>maxchanel)channel=1;
    channel++;
}
bool Tv::volup() {
    if(volume<MaxVal){
        volume++;
        return true;
    }
    else{
        return false;
    }
}
bool Tv::voldown() {
    if(volume>MinVal){
        volume--;
        return true;
    }
    else{
        return false;
    }
}
void Tv::set_remote(Remote & r) {
    if(ison()){
        r.state^=r.Interaction;
    }
}
void Tv::setting() const {
    using std::cout;
    using std::endl;
    cout<<"TV is "<<(state==On ? "On":"Off")<<endl;
    if(state==On){
        cout<<"Volume setting = "<<volume<<endl;
        cout<<"Channel setting = "<<channel<<endl;
        cout<<"Mode = "
            <<(mode==Antenna?"Antenna":"Cable")<<endl;
        cout<<"Input = "
            <<(input==TV?"TV":"DVD")<<endl;
    }
}