#ifndef INC_15_1_TV_H
#define INC_15_1_TV_H
#include <iostream>

class Remote;

class Tv {
private:
    int state;
    int volume;
    int maxchanel;
    int channel;
    int mode;
    int input;
public:
    friend class Remote;
    enum State{Off,On};
    enum{MinVal,MaxVal=20};
    enum{Antenna,Cable};
    enum {TV,DVD};
    Tv(int s =Off,int mc=125):state(s),volume(5),maxchanel(mc),
            channel(2),mode(Cable),input(TV){}
    void onoff(){state^=On;}
    bool ison()const{return state==On;}
    bool volup();
    bool voldown();
    void chanup();
    void chandown();
    void set_mode(){mode^=Cable;}
    void set_input(){input^=DVD;}
    void setting()const;
    void set_remote(Remote & r);
};

class Remote{
private:
    int mode;
    int state;

public:
    friend class Tv;
    enum {Routine,Interaction};
    Remote(int m=Tv::TV,int s=Routine):mode(m),state(s){}
    bool volup(Tv & t){return t.volup();};
    bool voldown(Tv & t){return t.voldown();};
    void onoff(Tv & t){t.onoff();};
    void chanup(Tv & t){t.chanup();};
    void chandown(Tv & t){t.chandown();};
    void set_mode(Tv & t){t.set_mode();};
    void set_input(Tv & t){t.set_input();};
    void set_chan(Tv & t,int c){t.channel=c;};
    void show (Tv & t){t.setting();
        if(t.ison())std::cout<<"Remote's state = "<<(state==Routine?"Routine":"Interaction")<<std::endl;}
};

#endif //INC_15_1_TV_H
