#include <iostream>
using namespace std;


bool isvalid(float value){
    float ocena[]{0.00,0.25,0.50,0.75,1.00,1.25,1.50,1.75,2.00,2.25,2.50,2.75,3.00,3.25,3.50,3.75,4.00,4.25,4.50,4.75,5.00,5.25,5.50,5.75,6.00};
    int size = sizeof(ocena) / sizeof(ocena[0]);
    for (int i = 0; i < size; i++){
        if (value == ocena[i]){
            return false; 
        }
    }
    return true;
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
    float tmp= 0;
    for(int i = 0; i < len; i++){
        tmp += tab[i];
    }
    return tmp/len;
}

int main(){
    int liczba_ocen;
    cout << "Ile ocen chcesz podać (więcej niż 4):" << endl;
    cin >> liczba_ocen;
    while (liczba_ocen < 4){
        cout << "Liczba ocen musi być większa niż 4. Wprowadź ponownie:" << endl;
        cin >> liczba_ocen;
    }

    float tab[10000];
    float ocena[]{0.00,0.25,0.50,0.75,1.00,1.25,1.50,1.75,2.00,2.25,2.50,2.75,3.00,3.25,3.50,3.75,4.00,4.25,4.50,4.75,5.00,5.25,5.50,5.75,6.00};
    int size = sizeof(ocena) / sizeof(ocena[0]);
    float freq[sizeof(ocena) / sizeof(ocena[0])] = {0};

    cout << "Podaj wartości ocen:" << endl;
    for(int i = 0; i < liczba_ocen; i++){
        cout << "Podaj ocenę " << i + 1 << " : ";
        cin >> tab[i];
        if(tab[i] == 0){
            i--;
            liczba_ocen--;
            continue;
        }
        while (isvalid(tab[i])){
            cout << "Wpisz wartość jeszcze raz (ocena musi być z listy): ";
            cin >> tab[i];
        }
        for (int j = 0; j < size; j++){
            if (tab[i] == ocena[j]){
                freq[j]++;
                break;
            }
        }
    }

    cout << "Najmniejsza ocena: " << min(tab, liczba_ocen) << endl;
    cout << "Średnia: " << srednia(tab, liczba_ocen) << endl;
    cout << "Największa ocena: " << max(tab, liczba_ocen) << endl;

    cout << "Częstotliwość ocen:" << endl;
    for (int i = 0; i < size; i++){
        if (freq[i] > 0){
            cout << ocena[i] << ": " << freq[i] << " razy" << endl;
        }
    }

    return 0;
}
