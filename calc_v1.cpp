//Author: Bartlomiej Osiak 
//Copyright: WIEiT AGH 
//Name: calc

#include <iostream>

using namespace std;

//funkcje przeliczajace input
double przelicznikmasa1(double wart1, int wbr1){

    switch (wbr1){
        case 1: wart1/=1000000; break; 
        case 2: wart1/=1000; break;
        case 3: wart1*=1; break;
        case 4: wart1*=1000; break;
        case 5: wart1*=1000000; break;
        case 6: wart1*=453.59237; break;
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
    }
    return (wart2);
}

double przeliczniktemperatura1(double wart1, int wbr1){

    switch (wbr1){
        case 1: wart1-=274.15; break;
        case 2: wart1*=1; break;
    }
    return (wart1);
}

double przeliczniktemperatura2(double wart2, int wbr2){

    switch (wbr2){
        case 1: wart2+=274.15; break;
        case 2: wart2*=1; break;
        }
    return (wart2);
}

double przeliczniknatezenie1(double wart1, int wbr1){

    switch(wbr1){
        case 1: wart1/=1000000; break; 
        case 2: wart1/=1000; break;
        case 3: wart1*=1; break;
        case 4: wart1*=1000; break;
        case 5: wart1*=1000000; break;
        case 6: wart1*=1000000000; break;
    }
    return (wart1);
}

double przeliczniknatezenie2(double wart2, int wbr2){

    switch(wbr2){
        case 1: wart2*=1000000; break;
        case 2: wart2*=1000; break;
        case 3: wart2*=1; break; 
        case 4: wart2/=1000; break;
        case 5: wart2/=1000000; break;
        case 6: wart2/=1000000000; break;
    }
    return (wart2);
}

double przeliczniknapiecie1(double wart1, int wbr1){

    switch(wbr1){
        case 1: wart1/=1000000; break; 
        case 2: wart1/=1000; break;
        case 3: wart1*=1; break;
        case 4: wart1*=1000; break;
        case 5: wart1*=1000000; break;
        case 6: wart1*=1000000000; break;
    }
    return (wart1);
}

double przeliczniknapiecie2(double wart2, int wbr2){

    switch(wbr2){
        case 1: wart2*=1000000; break;
        case 2: wart2*=1000; break;
        case 3: wart2*=1; break; 
        case 4: wart2/=1000; break;
        case 5: wart2/=1000000; break;
        case 6: wart2/=1000000000; break;
    }
    return (wart2);
}
//funkcje przeliczajace output
double przelicznik1(int ww, int wart1, double wbr1){

    switch(ww){
        case 1: return przelicznikdlugosc1(wart1, wbr1); break;
        case 2: return przelicznikmasa1(wart1, wbr1); break;
        case 3: return przelicznikczas1(wart1, wbr1); break;
        case 4: return przeliczniktemperatura1(wart1, wbr1); break;
        case 5: return przeliczniknatezenie1(wart1, wbr1); break;
        case 6: return przeliczniknapiecie1(wart1, wbr1); break;
    }
    return (wart1);
}

double przelicznik2(int ww, int wart2, double wbr2){

    switch(ww){
        case 1: return przelicznikdlugosc2(wart2, wbr2); break;
        case 2: return przelicznikmasa2(wart2, wbr2); break;
        case 3: return przelicznikczas2(wart2, wbr2); break;
        case 4: return przeliczniktemperatura2(wart2, wbr2); break;
        case 5: return przeliczniknatezenie2(wart2, wbr2); break;
        case 6: return przeliczniknapiecie2(wart2, wbr2); break;
    }
    return (wart2);
}

 void WYNIK(string przedrostki[], int ilosc_przedrostkow, int ww){//interfejs, wypisywanie tablic

    for (int i=0; i<ilosc_przedrostkow; i++){
            cout<<przedrostki[i]<<endl;
        }
        cout<<"Podaj przedrostek poczatkowy twojej wielkosci"<<endl;
        int wbr1;
        cin>>wbr1;
        cout<<"Wprowadz wartosc poczatkowa"<<endl;
        double wart1;
        cin>> wart1;
        double wartosc_poczatkowa=przelicznik1(ww, wart1, wbr1);
        for (int i=0; i<ilosc_przedrostkow; i++){
            cout<<przedrostki[i]<<endl;
        }
        cout<<"Podaj na jaki przedrostek chcesz zamienic twoja wielkosc"<<endl;
        int wbr2;
        cin>>wbr2;
        double wynik=przelicznik2(ww, wartosc_poczatkowa, wbr2);
        for (int i=0; i<ilosc_przedrostkow; i++){
            przedrostki[i].erase(0,3);//usuwam 3 pierwsze znaki z kazdego wyrazu z tablicy 
        }
        cout<<"WYNIK: "<<wynik<<" "<<przedrostki[wbr2-1]<<endl;
}
int main(){

//tablice jednostek i wielkosci
string wielkosci[6]={"1. dlugosc","2. masa","3. czas","4. temperatura", "5. natezenie pradu","6. napiecie"};
string przedrostkidlugosc[6]={"1. u[m]","2. m[m]","3. [m]","4. k[m]", "5. M[m]","6. yd"};
string przedrostkimasa[6]={"1. u[g]","2. m[g]","3. [g]", "4. k[g]","5. M[g]","6. lbs"};
string przedrostkiczas[6]={"1. u[s]","2. m[s]","3. [s]","4. [min]","5. [h]", "6. [dni]"};
string temperatura[2]={"1. [K]", "2. [C]"};
string natezenie[6]={"1. u[A]","2. m[A]","3. [A]","4. k[A]","5. M[A]","6. G[A]"};
string napiecie[6]={"1. u[V]","2. m[V]","3. [V]","4. k[V]","5. M[V]","6. G[V]"};

//kod kalkulatora
cout<<"Witaj w kalkulatorze jednostek ukladu SI!"<<endl;
cout<<"Wybierz jaka wielkosc chcesz zamieniac:"<<endl;
cout<<"Prosze wybierac tylko wyszczegolnione opcje!"<<endl;
for (int i=0; i<(sizeof(wielkosci)/sizeof(wielkosci[0])); i++){
    cout<<wielkosci[i]<<endl;
}
int ww;
cin>>ww;
if (ww==1){//droga 
    WYNIK(przedrostkidlugosc, sizeof(przedrostkidlugosc)/sizeof(przedrostkidlugosc[0]), ww);//wielkosc tablicy 
}
else if (ww==2){//masa 
    WYNIK(przedrostkimasa, sizeof(przedrostkimasa)/sizeof(przedrostkimasa[0]), ww);
}
else if (ww==3){//czas
    WYNIK(przedrostkiczas, sizeof(przedrostkiczas)/sizeof(przedrostkiczas[0]), ww);
}
else if (ww==4){//temperatura 
    WYNIK(temperatura, sizeof(temperatura)/sizeof(temperatura[0]), ww);
}
else if (ww==5){
    WYNIK(natezenie, sizeof(natezenie)/sizeof(natezenie[0]), ww);
}
else if (ww==6){
    WYNIK(napiecie, sizeof(napiecie)/sizeof(napiecie[0]), ww);
}
else{
    cout<<"Blad!"<<endl;
}
return (0);
}