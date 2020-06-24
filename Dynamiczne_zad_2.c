/*
2. Napisz program, który:
Bêdzie zawiera³ 3 funkcje lub procedury (zdecyduj co ma byæ funkcj¹ a co procedur¹):
- przypisuj¹c¹ do tablicy losowe wartoœci zmiennoprzecinkowe od 0 do 20 na przek¹tnej
- obliczy œlad
- wypisuj¹c¹ wszystkie elementy tablicy
W pêtli g³ównej:
- zaalokuje dynamiczn¹ tablicê 2D typu double o wymiarach podanych przez u¿ytkownika wype³niaj¹c j¹ zerami (calloc)
- wywo³a wszystkie funkcje
- zwolni tablicê
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void tworzonko(float **tab, int wiersze, int kolumny)
{
    srand(time(NULL));
    for(int i=0; i<kolumny; i++) {
        tab[i][i]=(float)((rand()%201)*0.1);
    }
    return;
}

void wypisywanko(float **tab, int wiersze, int kolumny)
{
    srand(time(NULL));
    for(int j=0; j<wiersze; j++) {
        for(int i=0; i<kolumny; i++) {
            printf("%.3f, ",tab[j][i]);
        }
        printf("\n");
    }
    return;
}

float slad(float **tab, int wiersze, int kolumny)
{
    float slad=0;
    for(int i=0; i<kolumny; i++) {
        slad+=tab[i][i];
    }
    printf("Slad jest rowny: %.3f", slad);
    return slad;
}

int main()
{
    int w,k;
    printf("Podaj liczbe wierszy i kolumn twojej tablicy: ");
    scanf("%d %d", &w, &k);
    if(w==k) {
        float **tab;
        tab=(float**)calloc(w, sizeof(float*));
        for(int i=0; i<w; i++)
            tab[i]=(float*)calloc(k, sizeof(float));
        tworzonko(tab, w, k);
        wypisywanko(tab, w, k);
        slad(tab, w, k);
        for(int i=0; i<w; i++)
            free(tab[i]);
        free(tab);
    } else
        printf("Liczba wierszy nie jest rowna liczbie kolumn (niezbedne dla powstania przekatnej i sladu)!!");
    return 0;
}













