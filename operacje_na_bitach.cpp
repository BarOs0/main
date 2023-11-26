#include <iostream>

using namespace std;

string opcje[5]={"1. negacja ~", "2. alternatywa |","3. koniunkcja &","4. przesunecie w prawo >>","5. przesuniecie w lewo <<"};

int wypisywanie_operacji(int wybor, unsigned int wynik){
    unsigned int a;
    cout<<"Prosze podac liczbe naturalna dodatnia (zmienna a)"<<endl;
    cin>>a;
    cout<<"Twoje a = "<<a<<endl;
    unsigned int b;
    cout<<"Prosze podac liczbe naturalna dodatnia (zmienna b)"<<endl;
    cin>>b;
    cout<<"Twoje b = "<<b<<endl;
    switch(wybor){
        case 1: cout<<"Twoje zmienne sa postaci unsigned int, zatem reprezentuja taka postac binarna: xxxx . xxxx (2^7,2^6,2^5,2^4 . 2^3,2^2,2^1,2^0)"<<endl; cout<<"np: a = 5 = 0000 . 0101 ; b = np: 6 = 0000 . 0110"<<endl; cout<<"zatem: "<<"~ 0000 . 0101 = 1111 . 1010 ; ~ 0000 . 0110 = 1111 . 1001"<<endl; wynik=(~a); cout<<"Wynik dziesietnie = "<<wynik<<endl; break;
        case 2: cout<<"Twoje zmienne sa postaci unsigned int, zatem reprezentuja taka postac binarna: xxxx . xxxx (2^7,2^6,2^5,2^4 . 2^3,2^2,2^1,2^0)"<<endl; cout<<"np: a =  5 = 0000 . 0101 ; np: b = 6 = 0000 . 0110"<<endl; cout<<"zatem: "<<"0000 0101 + 0000 0110 = 0000 0111"<<endl; wynik=(a|b); cout<<"Wynik dziesietnie = "<<wynik<<endl; break;
        case 3: cout<<"Twoje zmienne sa postaci unsigned int, zatem reprezentuja taka postac binarna: xxxx . xxxx (2^7,2^6,2^5,2^4 . 2^3,2^2,2^1,2^0)"<<endl; cout<<"np: a = 5 = 0000 . 0101 ; np: b = 6 = 0000 . 0110"<<endl; cout<<"zatem: "<<"0000 0101 & 0000 0110 = 0000 0100"<<endl; wynik=(a&b); cout<<"Wynik dziesietnie = "<<wynik<<endl; break;
        case 4: cout<<"Twoje zmienne sa postaci unsigned int, zatem reprezentuja taka postac binarna: xxxx . xxxx (2^7,2^6,2^5,2^4 . 2^3,2^2,2^1,2^0)"<<endl; cout<<"np: a = 5 = 0000 . 0101 ; np: b = 6 = 0000 . 0110"<<endl; cout<<"zatem: "<<"0000 . 0101>>6 = "<<"0000 . 0000"<<endl; wynik=a >> b; cout<<"Wynik dziesietnie = "<<wynik<<endl; cout<<"liczba (binarna) a przesunieta o (dziesietnie) b miejsc w prawo"<<endl; break;
        case 5: cout<<"Twoje zmienne sa postaci unsigned int, zatem reprezentuja taka postac binarna: xxxx . xxxx (2^7,2^6,2^5,2^4 . 2^3,2^2,2^1,2^0)"<<endl; cout<<"np: a = 5 = 0000 . 0101 ; b = np: 6 = 0000 . 0110"<<endl; cout<<"zatem: "<<"0000 . 0101<<6 = "<<"0101 . 0000 . 0000"<<endl; wynik=a << b; cout<<"Wynik dziesietnie = "<<wynik<<endl; cout<<"liczba (binarna) a przesunieta o (dziesietnie) b miejsc w lewo"<<endl; break;
        default: cout<<"Blad!"<<endl; break;
    }
    return (wynik);
}

int main(){

    cout<<"Wybierz opcje z ktorej chcesz skorzystac"<<endl;
    for (int i=0; i<(sizeof(opcje)/sizeof(opcje[0])); i++){
        cout<<opcje[i]<<endl;
    }
    int wybor;
    cin>>wybor;
    if (wybor==1){
        int wynik;
        wypisywanie_operacji(wybor, wynik);
    }
    else if (wybor==2){
        int wynik;
        wypisywanie_operacji(wybor, wynik);
    }
    else if (wybor==3){
        int wynik;
        wypisywanie_operacji(wybor, wynik);
    }
    else if (wybor==4){
        int wynik;
        wypisywanie_operacji(wybor, wynik);
    }
    else if (wybor==5){
        int wynik;
        wypisywanie_operacji(wybor, wynik);
    }
    else{
        cout<<"Blad!"<<endl;
    }
}