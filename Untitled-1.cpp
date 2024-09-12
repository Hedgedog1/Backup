#include <iostream>
using namespace std;
bool isvalid(float value){
    float ocena[]{0.00,0.25,0.50,0.75,1.00,1.25,1.50,1.75,2.00,2.25,2.50,2.75,3.00,3.25,3.50,3.75,4.00,4.25,4.50,4.75,5.00,5.25,5.50,5.75,6.00};
    int size = sizeof(ocena) / sizeof(ocena[0]);
    for (int i = 0; i < 5; i++){
        if (value == ocena[i]){
            return true;
        }
        return false;
    }
    
}

float max(float tab[], int len){
    float tmp= tab[0];
    for(int i = 1; i < len; i++){
        if(tab[i] > tmp){
            tmp=tab[i];
        }
    }
    return tmp;
}
float min(float tab[], int len){
    float tmp= tab[0];
    for(int i = 1; i < len; i++){
        if(tab[i] < tmp){
            tmp=tab[i];
        }
    }
    return tmp;
}
float srednia(float tab[], int len){
    int tmp= 0;
    for(int i = 1; i < len; i++){
        tmp += tab[i];
    }
    return tmp/len;
}
int main(){
    int liczba_ocen;
    cout<<"Ile ocen chceszs > 4 :"<<endl;
    cin>>liczba_ocen;
    while (liczba_ocen < 4){
        cout<<"Ile ocen chceszs > 4";
        cin>>liczba_ocen;
    }
    float tab[10000];
    cout<<"Podaj wartość liczby\n";
    for(int i = 0; i < liczba_ocen; i++){
        cout<<"podaj liczbe "<< i + 1<<" : ";
        cin>>tab[i];
        while (isvalid(tab[i])){
            cout<<"wpisz jeszcze raz";
            cin>>tab[i];
        }
    }
    cout<<"Najmniejszy numer "<< min(tab,liczba_ocen)<<endl;
    cout<<"Średnia "<< srednia(tab,liczba_ocen)<<endl;
    cout<<"Największy numer "<< max(tab,liczba_ocen);
}