#include <iostream>
#include <fstream>
#include <string>

using namespace::std;

class IPAdress {
public:
    unsigned char f,t,s,o;
    void setData(unsigned char ff,unsigned char tt,unsigned char ss,unsigned char oo){
        f=ff;t=tt;s=ss;o=oo;
    }
/*    void setData(string inp){
        string stmp,inpu=inp;
        stmp=inpu.find_first_not_of("0123456789");
        f=stoi(inpu.substr(0,stmp));
        inpu=inpu.substr(stmp+1,inpu.length());
        stmp=inpu.find_first_not_of("0123456789");
        t=stoi(inpu.substr(0,stmp));
        inpu=inpu.substr(stmp+1,inpu.length());
        stmp=inpu.find_first_not_of("0123456789");
        s=stoi(inpu.substr(0,stmp));
        inpu=inpu.substr(stmp+1,inpu.length());
        stmp=inpu.find_first_not_of("0123456789");
        o=stoi(inpu.substr(0,stmp));
    }*/
    void prent(){
        if(f<100){cout<<" ";}if(f<10){cout<<" ";}cout<<int(f)<<".";
        if(t<100){cout<<" ";}if(t<10){cout<<" ";}cout<<int(t)<<".";
        if(s<100){cout<<" ";}if(s<10){cout<<" ";}cout<<int(s)<<".";
        if(o<100){cout<<" ";}if(o<10){cout<<" ";}cout<<int(o)<<"\n";
        //cout<<int(f)<<"."<<int(t)<<"."<<int(s)<<"."<<int(o)<<"\n";
    }
    IPAdress operator + (IPAdress const &obj) {
         IPAdress res;
         res.f = f + obj.f;
         res.t = t + obj.t;
         res.s = s + obj.s;
         res.o = o + obj.o;
         return res;
    }
    IPAdress operator - (IPAdress const &obj) {
         IPAdress res;
         res.f = f - obj.f;
         res.t = t - obj.t;
         res.s = s - obj.s;
         res.o = o - obj.o;
         return res;
    }
    bool operator > (IPAdress const &obj) {
         IPAdress res;
         if(f>obj.f){return true;}
         if(f<obj.f){return false;}
         if(t>obj.t){return true;}
         if(t<obj.t){return false;}
         if(s>obj.s){return true;}
         if(s<obj.s){return false;}
         if(o>obj.o){return true;}
         if(o<obj.o){return false;}
         return false;
    }
    bool operator >= (IPAdress const &obj) {
         IPAdress res;
         if(f>obj.f){return true;}
         if(f<obj.f){return false;}
         if(t>obj.t){return true;}
         if(t<obj.t){return false;}
         if(s>obj.s){return true;}
         if(s<obj.s){return false;}
         if(o>obj.o){return true;}
         if(o<obj.o){return false;}
         return true;
    }
    bool operator < (IPAdress const &obj) {
         IPAdress res;
         if(f<obj.f){return true;}
         if(f>obj.f){return false;}
         if(t<obj.t){return true;}
         if(t>obj.t){return false;}
         if(s<obj.s){return true;}
         if(s>obj.s){return false;}
         if(o<obj.o){return true;}
         if(o>obj.o){return false;}
         return false;
    }
    bool operator <= (IPAdress const &obj) {
         IPAdress res;
         if(f<obj.f){return true;}
         if(f>obj.f){return false;}
         if(t<obj.t){return true;}
         if(t>obj.t){return false;}
         if(s<obj.s){return true;}
         if(s>obj.s){return false;}
         if(o<obj.o){return true;}
         if(o<obj.o){return false;}
         return true;
    }
};
bool belongToNet(IPAdress net,IPAdress maks,IPAdress ip){
    return ((net.f==(maks.f&ip.f))&&(net.t==(maks.t&ip.t))&&(net.s==(maks.s&ip.s))&&(net.o==(maks.o&ip.o)));
}
/*    std::istream &operator>>(std::istream &is, IPAdress &rez)
    {
        string stmp,inpu;
        int t1,t2,t3,t4;
        is >> inpu;
        stmp=inpu.find_first_not_of("0123456789");
        t1=stoi(inpu.substr(0,stmp));
        inpu=inpu.substr(stmp+1,inpu.length());
        stmp=inpu.find_first_not_of("0123456789");
        t2=stoi(inpu.substr(0,stmp));
        inpu=inpu.substr(stmp+1,inpu.length());
        stmp=inpu.find_first_not_of("0123456789");
        t3=stoi(inpu.substr(0,stmp));
        inpu=inpu.substr(stmp+1,inpu.length());
        stmp=inpu.find_first_not_of("0123456789");
        t4=stoi(inpu.substr(0,stmp));
        rez.setData(t1,t2,t3,t4);
        return is;
    }*/
int main(){
    ifstream infile;
    string filename;
    cin>>filename;
    infile.open (filename);
    int t1,t2,t3,t4;
    string inpu;
    size_t stmp;
    IPAdress one,two,mask,net,tmp;
    /*cout<<"Enter 4 IP addresses. First two will be used in arithmetic, and the last two are Mask and Net IP. Fist 2 IPs will be used as the IP within the net \n";
    cin>>t1;cin>>t2;cin>>t3;cin>>t4;one.setData(t1,t2,t3,t4);
    cin>>t1;cin>>t2;cin>>t3;cin>>t4;two.setData(t1,t2,t3,t4);
    cin>>t1;cin>>t2;cin>>t3;cin>>t4;mask.setData(t1,t2,t3,t4);
    cin>>t1;cin>>t2;cin>>t3;cin>>t4;net.setData(t1,t2,t3,t4);*/
    infile>>inpu;
    stmp=inpu.find_first_not_of("0123456789");
    t1=stoi(inpu.substr(0,stmp));
    inpu=inpu.substr(stmp+1,inpu.length());
    stmp=inpu.find_first_not_of("0123456789");
    t2=stoi(inpu.substr(0,stmp));
    inpu=inpu.substr(stmp+1,inpu.length());
    stmp=inpu.find_first_not_of("0123456789");
    t3=stoi(inpu.substr(0,stmp));
    inpu=inpu.substr(stmp+1,inpu.length());
    stmp=inpu.find_first_not_of("0123456789");
    t4=stoi(inpu.substr(0,stmp));
    one.setData(t1,t2,t3,t4);
    infile>>inpu;
    stmp=inpu.find_first_not_of("0123456789");
    t1=stoi(inpu.substr(0,stmp));
    inpu=inpu.substr(stmp+1,inpu.length());
    stmp=inpu.find_first_not_of("0123456789");
    t2=stoi(inpu.substr(0,stmp));
    inpu=inpu.substr(stmp+1,inpu.length());
    stmp=inpu.find_first_not_of("0123456789");
    t3=stoi(inpu.substr(0,stmp));
    inpu=inpu.substr(stmp+1,inpu.length());
    stmp=inpu.find_first_not_of("0123456789");
    t4=stoi(inpu.substr(0,stmp));
    two.setData(t1,t2,t3,t4);
    infile>>inpu;
    stmp=inpu.find_first_not_of("0123456789");
    t1=stoi(inpu.substr(0,stmp));
    inpu=inpu.substr(stmp+1,inpu.length());
    stmp=inpu.find_first_not_of("0123456789");
    t2=stoi(inpu.substr(0,stmp));
    inpu=inpu.substr(stmp+1,inpu.length());
    stmp=inpu.find_first_not_of("0123456789");
    t3=stoi(inpu.substr(0,stmp));
    inpu=inpu.substr(stmp+1,inpu.length());
    stmp=inpu.find_first_not_of("0123456789");
    t4=stoi(inpu.substr(0,stmp));
    mask.setData(t1,t2,t3,t4);
    infile>>inpu;
    stmp=inpu.find_first_not_of("0123456789");
    t1=stoi(inpu.substr(0,stmp));
    inpu=inpu.substr(stmp+1,inpu.length());
    stmp=inpu.find_first_not_of("0123456789");
    t2=stoi(inpu.substr(0,stmp));
    inpu=inpu.substr(stmp+1,inpu.length());
    stmp=inpu.find_first_not_of("0123456789");
    t3=stoi(inpu.substr(0,stmp));
    inpu=inpu.substr(stmp+1,inpu.length());
    stmp=inpu.find_first_not_of("0123456789");
    t4=stoi(inpu.substr(0,stmp));
    net.setData(t1,t2,t3,t4);
    cout<<"\n";
    cout<<"IP1:   ";
    one.prent();
    cout<<"IP2:   ";
    two.prent();
    tmp=one+two;//sumIP(one,two);
    cout<<"Sum:   ";
    tmp.prent();
    tmp=one-two;//difIP(one,two);
    cout<<"Dif:   ";
    tmp.prent();
    if(one>two){
        cout<<"IP1 > IP2\n";
    }
    else{
        cout<<"IP1 <= IP2\n";
    }
    if(one>=two){
        cout<<"IP1 >= IP2\n";
    }
    else{
        cout<<"IP1 < IP2\n";
    }
    if(belongToNet(net,mask,one)){
        cout<<"IP1 belongs to the net\n";
    }
    else{
        cout<<"IP1 does not belong to the net\n";
    }
    if(belongToNet(net,mask,two)){
        cout<<"IP2 belongs to the net\n";
    }
    else{
        cout<<"IP2 does not belong to the net\n";
    }
    return 0;
}
