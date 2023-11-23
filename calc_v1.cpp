//Author: Bartlomiej Osiak 
//Copyright: WIEiT AGH 
//Name: calc

#include <iostream>

using namespace std;

//funkcje przeliczajace 
double przelicznikmasa1(double wart1, int wbr1){
    switch (wbr1){
        case 1: wart1/=1000000; break; 
        case 2: wart1/=1000; break;
        case 3: wart1*=1; break;
        case 4: wart1*=1000; break;
        case 5: wart1*=1000000; break;
        case 6: wart1*=453.59237; break;
        default: cout<<"Blad!"<<endl;
    }
    return (wart1);
}
double przelicznikmasa2(double wart2, int wbr2){
    switch (wbr2){
        case 1: wart2*=1000000; break;
        case 2: wart2*=1000; break;
        case 3: wart2*=1; break; 
        case 4: wart2/=1000; break;
        case 5: wart2/=1000000; break;
        case 6: wart2/=453.59237; break;
        default: cout<<"Blad!"<<endl;
    }
    return (wart2);
}
double przelicznikdlugosc1(double wart1, int wbr1){
    switch (wbr1){
        case 1: wart1/=1000000; break;
        case 2: wart1/=1000; break;
        case 3: wart1*=1; break;
        case 4: wart1*=1000; break;
        case 5: wart1*=1000000; break;
        case 6: wart1*=0.9144; break;
        default: cout<<"Blad!"<<endl;
    }
    return (wart1);
}
double przelicznikdlugosc2(double wart2, int wbr2){
    switch (wbr2){
        case 1: wart2*=1000000; break;
        case 2: wart2*=1000; break;
        case 3: wart2*=1; break; 
        case 4: wart2/=1000; break;
        case 5: wart2/=1000000; break;
        case 6: wart2/=0.9144; break;
        default: cout<<"Blad!"<<endl;
    }
    return (wart2);
}
double przelicznikczas1(double wart1, int wbr1 ){
    switch (wbr1){
        case 1: wart1/=1000000; break;
        case 2: wart1/=1000; break;
        case 3: wart1*=1; break;
        case 4: wart1*=60; break;
        case 5: wart1*=3600; break;
        case 6: wart1*=86400; break;
        default: cout<<"Blad!"<<endl;
    }
    return (wart1);
}
double przelicznikczas2(double wart2, int wbr2){
    switch (wbr2){
        case 1: wart2*=1000000; break;
        case 2: wart2*=1000; break;
        case 3: wart2*=1; break;
        case 4: wart2/=60; break; 
        case 5: wart2/=3600; break;
        case 6: wart2/=86400; break;
        default: cout<<"Blad!"<<endl;
    }
    return (wart2);
}
double przeliczniktemperatura1(double wart1, int wbr1){
    switch (wbr1){
        case 1: wart1+=274.15; break;
        case 2: wart1*=1; break;
        default: cout<<"Blad!"<<endl;
    }
    return (wart1);
}
double przeliczniktemperatura2(double wart2, int wbr2){
    switch (wbr2){
        case 1: wart2-=274.15; break;
        case 2: wart2*=1; break;
        default: cout<<"Blad!"<<endl;
        }
    return (wart2);
}
void WYNIK(string przedrostki[6], int ilosc_przedrostkow){//jadro
    for (int i=0; i<ilosc_przedrostkow; i++){
            cout<<przedrostki[i]<<endl;
        }
        cout<<"Podaj przedrostek poczatkowy twojej wielkosci"<<endl;
        int wyborjednostkip;
        cin>>wyborjednostkip;
        cout<<"Wprowadz wartosc poczatkowa"<<endl;
        double wartosc;
        cin>> wartosc;
        double wartosc_poczatkowa=przelicznikmasa1(wartosc, wyborjednostkip);
            for (int i=0; i<ilosc_przedrostkow; i++){
                cout<<przedrostki[i]<<endl;
            }
        cout<<"Podaj na jaki przedrostek chcesz zamienic twoja wielkosc"<<endl;
        int wbr2;
        cin>>wbr2;
        double wynik=przelicznikmasa2(wartosc_poczatkowa, wbr2);
            for (int i=0; i<ilosc_przedrostkow; i++){
                przedrostki[i].erase(0,3);//usuwam 3 pierwsze znaki z kazdego wyrazu z tablicy 
            }
        wbr2-=1;
        cout<<"WYNIK: "<<wynik<<" "<<przedrostki[wbr2]<<endl;
}

int main(){

//tablice jednostek i wielkosci
string wielkosci[4]={"1. dlugosc","2. masa","3. czas","4. temperatura"};
string przedrostkidlugosc[6]={"1. u[m]","2. m[m]","3. [m]","4. k[m]", "5. M[m]","6. yd"};
string przedrostkimasa[6]={"1. u[g]","2. m[g]","3. [g]", "4. k[g]","5. M[g]","6. lbs"};
string przedrostkiczas[6]={"1. u[s]","2. m[s]","3. [s]","4. [min]","5. [h]", "6. [dni]"};
string temperatura[2]={"1. [K]", "2. [C]"};

//kod kalkulatora
cout<<"Witaj w kalkulatorze jednostek ukladu SI!"<<endl;
cout<<"Wybierz jaka wielkosc chcesz zamieniac:"<<endl;
    for (int i=0; i<4; i++){
        cout<<wielkosci[i]<<endl;
    }
int wyborwielkosci;
cin>>wyborwielkosci;
    if (wyborwielkosci==1){//droga 
       WYNIK(przedrostkidlugosc, sizeof(przedrostkidlugosc)/sizeof(przedrostkidlugosc[0]));
    }
    else if (wyborwielkosci==2){//masa 
        WYNIK(przedrostkimasa, sizeof(przedrostkimasa)/sizeof(przedrostkimasa[0]));//wyciaganie wielkosci tablicy
    }
    else if (wyborwielkosci==3){//czas
        WYNIK(przedrostkiczas, sizeof(przedrostkiczas)/sizeof(przedrostkiczas[0]));
    }
    else if (wyborwielkosci==4){//temperatura 
        WYNIK(temperatura, sizeof(temperatura)/sizeof(temperatura[0]));
    }
    else{
        cout<<"Blad!"<<endl;
    }
    return (0);
}