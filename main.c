/*
1. Napisaæ program, który wczyta plik P0001 attr.rec z mojej strony i utworzy 3 tablice
dynamiczne floatów, do których zaczyta wartoœci X, Y i RHO. Zostanie policzona i wyœwietlona œrednia, mediana i odchylenie standardowe dla X, Y i RHO. Wyniki statystyk
zostan¹ dopisane do pierwotnego pliku. W modu³ach maj¹ znaleŸæ siê tylko funkcje/procedury dla statystyk.
*/
#include <stdio.h>
#include <stdlib.h>
#include "statystyka.h"
int main()
{
    float arrx[51];
    float arry[51];
    float arrrho[51];
    FILE *plik;
    float *x;
    x=(float*)malloc(50*sizeof(float));
    float *y;
    y=(float*)malloc(50*sizeof(float));
    float *rho;
    rho=(float*)malloc(50*sizeof(float));
    char c;
    float *a;
    a=(float*)malloc(50*sizeof(float));
    plik=fopen("P0001_attr.rec","r");
    if(plik==NULL) {
        printf("Nie mozna otworzyc pliku");
        exit(-1);
    } else {
        while (!feof(plik)) {
            do {
                c = fgetc(plik);
            } while (c != '\n');
            for(int i = 0; i < 50; i++) {
                fscanf(plik,"%f %f %f %f",a,x,y,rho);
                printf("%.3f %.3f %.3f %.3f",*a,*x,*y,*rho);
                arrx[i]=*x;
                arry[i]=*y;
                arrrho[i]=*rho;
                a++;
                x++;
                y++;
                rho++;
                printf("\n");
            }
        }
    }
    meanandsd(arrx,arry,arrrho);
    median(arrx,arry,arrrho);
    fclose(plik);

    return 0;
}
