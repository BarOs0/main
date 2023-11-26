#include <iostream>
#include <climits>

using namespace std;

/*        NAZWA                    |     WIELKOSC(BAJTY)    |                   ZAKRES                      |
1. short (calkowite)               |            2           | -2^15 -- 2^15 -1 (-32768, 32767)              |
2. unsigned short (calkowite)      |            2           | 0 -- 2^16 - 1 (0, 65535)                      |
3. int (calkowite)                 |            4           | -2^31 -- 2^31 - 1 (-2147483648, 2147483647)   |
4. unsigned int (calkowite)        |            4           | 0 -- 2^32 - 1 (0, 4294967295)                 |
4. long (calkowite)                |            4           | -2^31 -- 2^31 - 1 (-2147483648, 2147483647)   |
5. unsigned long (calkowite)       |            4           | 0 -- 2^32 -1 (0, 4294967295)                  |
6. long long (calkowite)           |            8           | -2^63 -- 2^63 - 1 (duzo)                      |
7. unsigned long long (calkowite)  |            8           | 0 -- 2^64 - 1 (duzo)                          |
8. float (rzeczywiste)             |            4           | precyzja: 6-7 cyfr po przecnku                |
9. double (rzeczywiste)            |            8           | precyzja: 15-16 cyfr po przecinku             |
10. long double                    |           12           | precyzja: 19-20 cyfr po przecinku             |
11. char (typ znakowy)             |            1           | -128 -- 127                                   |
12. unsigned char (typ znakowy)    |            1           | 0 -- 255                                      |
13. bool (typ logiczny)            |            1           | false (0), true (1)                           |

CLIMITS:
komendy: 
CHAR_BIT	
SCHAR_MIN	
SCHAR_MAX	
UCHAR_MAX	
CHAR_MIN	
CHAR_MAX	
MB_LEN_MAX	
SHRT_MIN	
SHRT_MAX	
USHRT_MAX	
INT_MIN	
INT_MAX	
UINT_MAX	
LONG_MIN	
LONG_MAX	
ULONG_MAX	
*/

string typy[8]={"1. char","2. unsigned char","3. short int","4. unsigned short int","5. int","6. unsigned int","7. long int", "8. unsigned long int"};

int main(){
    for (int i=0; i<sizeof(typy)/sizeof(typy[0]); i++){
        cout<<typy[i]<<endl;
    }
    int wybor;
    cout<<"Podaj z ktorej opcji chcesz skorzystac"<<endl;
    cin>>wybor;
    switch(wybor){
        case 1: cout<<"typ: char"<<endl; cout<<"wartosc: "<<CHAR_BIT<<endl; cout<<"wartosc MIN: "<<SCHAR_MIN<<endl; cout<<"wartosc MAX: "<<SCHAR_MAX<<endl; break;
        case 2: cout<<"typ: unsigned char"<<endl; cout<<"wartosc MAX: "<<UCHAR_MAX<<endl; break;
        case 3: cout<<"typ: short int"<<endl; cout<<"wartosc MIN: "<<SHRT_MIN<<endl; cout<<"wartosc MAX: "<<SHRT_MAX<<endl; break;
        case 4: cout<<"typ: unsigned short int"<<endl; cout<<"wartosc MAX: "<<USHRT_MAX<<endl; break;
        case 5: cout<<"typ: int"<<endl; cout<<"wartosc MIN: "<<INT_MIN<<endl; cout<<"wartosc MAX: "<<INT_MAX<<endl; break;
        case 6: cout<<"typ: unsigned int"<<endl; cout<<"wartosc MAX: "<<UINT_MAX<<endl; break;
        case 7: cout<<"typ: long int"<<endl; cout<<"wartosc MIN: "<<LONG_MIN<<endl; cout<<"wartosc MAX: "<<LONG_MAX<<endl; break;
        case 8: cout<<"typ: unsigned long int"<<endl; cout<<"wartosc MAX: "<<ULONG_MAX<<endl; break;
    }
cout<<"Przekroczenie zakresu:"<<endl;
unsigned int a=UINT_MAX;
unsigned long long int b=static_cast<unsigned long long int>(a)+1;//konwersja na typ unsigned long long int, skladnia: docelowy_typ zmienna_wyjsciowa=static_cast<docelowy_typ>(zmienna_ktora_zmieniamy)
cout<<"MAX unsigned int:"<<a<<" + 1 "<<" = "<<b<<endl;
}