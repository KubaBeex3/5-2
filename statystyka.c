#include "statystyka.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void meanandsd(float x[],float y[], float rho[])
{
    FILE *plik;
    float sdx=0.0;
    float sdy=0.0;
    float sdrho=0.0;
    float sumx=0.0;
    float sumy=0.0;
    float sumrho=0.0;
    for(int i=0; i<50; i++) {
        sumx+=x[i];
        sumy+=y[i];
        sumrho+=rho[i];
    }
    printf("Srednie dla:\nX=%f\nY=%f\nRHO=%f\n\n",sumx/50,sumy/50,sumrho/50);
    for (int i = 0; i < 50; i++) {
        sdx += pow(x[i]-sumx/50, 2);
        sdy += pow(y[i]-sumy/50, 2);
        sdrho += pow(rho[i]-sumrho/50, 2);
    }
    printf("Odchylenie standardowe dla:\nX=%f\nY=%f\nRHO=%f\n\n",sqrt(sdx/50),sqrt(sdy/50),sqrt(sdrho/50));
    plik=fopen("P0001_attr.rec", "a");
    fprintf(plik,"\nSrednia\n\t%.5f\t\t%.5f\t%.3f",sumx/50,sumy/50,sumrho/50);
    fprintf(plik,"\nOdchylenie standardowe\n\t%.5f\t\t%.5f\t%.3f", sqrt(sdx/50),sqrt(sdy/50),sqrt(sdrho/50));
    fclose(plik);
    return;
}

void median(float x[],float y[],float rho[])
{

    FILE *plik;
    float pom;
    int j;
    for(int i=1; i<50; i++) {

        pom = x[i];
        j = i-1;
        while(j>=0 && x[j]>pom) {
            x[j+1] = x[j];
            --j;
        }
        x[j+1] = pom;

    }
    for(int i=1; i<50; i++) {
        pom = y[i];
        j = i-1;
        while(j>=0 && y[j]>pom) {
            y[j+1] = y[j];
            --j;
        }
        y[j+1] = pom;
    }
    for(int i=1; i<50; i++) {
        pom = rho[i];
        j = i-1;
        while(j>=0 && rho[j]>pom) {
            rho[j+1] = rho[j];
            --j;
        }
        rho[j+1] = pom;
    }
    printf("Mediany dla:\nX=%f\nY=%f\nRHO=%f\n", (x[25]+x[26])/2,(y[25]+y[26])/2,(rho[25]+rho[26])/2);
    plik=fopen("P0001_attr.rec", "a");
    fprintf(plik,"\nMediana\n\t%.5f\t\t%.5f\t%.3f",(x[25]+x[26])/2,(y[25]+y[26])/2,(rho[25]+rho[26])/2);
    fclose(plik);
    return;
}


