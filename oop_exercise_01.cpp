// Written by VSNelyubin, m80-206b-19, Original Code, do not steal!
/*
Создать класс IPAddress для работы с адресом в интернет. Класс состоит из четырех чисел unsigned char (a,b,c,d).
Реализовать арифметические операции сложения, вычитания, а также операции сравнения (для сравнение на больше/меньше считать что левые байты главнее т.е. вначале сравниваются первые байты, потом вторые и т.д.).
Так же реализовать функцию, которая будет определять принадлежность адреса к подсети по адресу подсети (a1,b1,c1,d1) и битовой маске подсети (a2,b2,c2,d2).
Например, адрес 192.168.1.30 принадлежит подсети 192.168.0.0 с маской 255.255.0.0.
*/

#include <iostream>
#include <fstream>
#include <string>
#pragma once

using namespace::std;

class IPAdress {
public:
    unsigned char f,t,s,o;

    void setData2(unsigned char ff,unsigned char tt,unsigned char ss,unsigned char oo){
        f=ff;t=tt;s=ss;o=oo;
    }
    int setdata(string inp){
	int stmp;
    string inpu=inp;
    //stmp=inpu.find_first_not_of("0123456789");
    stmp=inpu.find(".");
	if(stmp<0){return 1;}
    f=stoi(inpu.substr(0,stmp));
    inpu=inpu.substr(stmp+1,inpu.length());
    //stmp=inpu.find_first_not_of("0123456789");
    stmp=inpu.find(".");
	if(stmp<0){return 1;}
    t=stoi(inpu.substr(0,stmp));
    inpu=inpu.substr(stmp+1,inpu.length());
    //stmp=inpu.find_first_not_of("0123456789");
    stmp=inpu.find(".");
	if(stmp<0){return 1;}
    s=stoi(inpu.substr(0,stmp));
    inpu=inpu.substr(stmp+1,inpu.length());
    stmp=inpu.find_first_not_of("0123456789");
	if(stmp>=0){return 1;}
    o=stoi(inpu.substr(0,stmp));
	return 0;
    }

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
    ifstream fin;
    string filename;
    cin>>filename;
    fin.open (filename.c_str());
    string inpu;
    size_t stmp;
    IPAdress one,two,mask,net,tmp;
    fin>>inpu;
    if(one.setdata(inpu)){
        cout<<"Bad input. Exiting\n";
        return 0;
    }
    fin>>inpu;
    if(two.setdata(inpu)){
        cout<<"Bad input. Exiting\n";
        return 0;
    }
    fin>>inpu;
    if(mask.setdata(inpu)){
        cout<<"Bad input. Exiting\n";
        return 0;
    }
    fin>>inpu;
    if(net.setdata(inpu)){
	cout<<"Bad input. Exiting\n";
	return 0;
    }
    cout<<"\n";
    cout<<"IP1:   ";
    one.prent();
    cout<<"IP2:   ";
    two.prent();
    tmp=one+two;
    cout<<"Sum:   ";
    tmp.prent();
    tmp=one-two;
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
