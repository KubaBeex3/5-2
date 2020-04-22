/*
1. Napisz program, który pobierze od u¿ytkownika ci¹g znaków i utworzy 5 plików o nazwie wg wzoru P000[1-5] [pobrana nazwa].rec. Np.:
P0001 attr after denoise.rec, P0002 attr after denoise.rec itd. Nastêpnie wygeneruje i zapisze do nich treœæ. Zawartoœæ plików powinna wygl¹daæ nastêpuj¹co:
LP X Y RHO
1. 0.00234 10.23493 2.784
2. 3.24135 37.48272 2.828
...
50. 9.32849 48.23839 2.723
LP: liczby od 1 do 50
X: liczby typu float wylosowane z zakresu <0.0 - 10.0> z 5 miejscami po przecinku
Y: liczby typu float wylosowane z zakresu <10.0 - 50.0> z 5 miejscami po przecinku
RHO: liczby typu float wylosowane z zakresu <2.7 - 2.84 > z 3 miejscami po przecinku
Program powinien mieæ funkcje/procedury.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <time.h>

void losujx(float arrx[])
{
    srand(time(NULL));
    for(int i=0; i<50; i++) {
        arrx[i]=((double)rand()/(double)RAND_MAX) * 10.0;
        printf("%.5f, ", arrx[i]);
    }
    return;
}

void losujy(float arry[])
{
    for(int i=0; i<50; i++) {
        arry[i]=10+((double)rand()/(double)RAND_MAX) * 40.0;
        printf("%.5f, ", arry[i]);
    }
    return;
}

void losujrho(float arrrho[])
{
    for(int i=0; i<50; i++) {
        arrrho[i]=2.7+((double)rand()/(double)RAND_MAX) * 0.14;
        printf("%.5f, ", arrrho[i]);
    }
    return;
}


int main()
{
    float arrx[51]= {0.0};
    float arry[51]= {0.0};
    float arrrho[51]= {0.0};
    FILE *plik;
    printf("IKSY\n");
    losujx(arrx);
    printf("\nIGREKI\n");
    losujy(arry);
    printf("\nRGOKI\n");
    losujrho(arrrho);
    //nazwa=(char *)malloc((21)*sizeof(char));
    plik=fopen("P0001_nazwa_.txt", "w");
    for(int i=0; i<50; i++)
        fprintf(plik, "%d. %.5f %.5f %.5f \n", i+1, arrx[i], arry[i], arrrho[i]);
    plik=fopen("P0002_nazwa_.txt", "w");
    for(int i=0; i<50; i++)
        fprintf(plik, "%d. %.5f %.5f %.5f \n", i+1, arrx[i], arry[i], arrrho[i]);
    plik=fopen("P0003_nazwa_.txt", "w");
    for(int i=0; i<50; i++)
        fprintf(plik, "%d. %.5f %.5f %.5f \n", i+1, arrx[i], arry[i], arrrho[i]);
    plik=fopen("P0004_nazwa_.txt", "w");
    for(int i=0; i<50; i++)
        fprintf(plik, "%d. %.5f %.5f %.5f \n", i+1, arrx[i], arry[i], arrrho[i]);
    plik=fopen("P0005_nazwa_.txt", "w");
    for(int i=0; i<50; i++)
        fprintf(plik, "%d. %.5f %.5f %.5f \n", i+1, arrx[i], arry[i], arrrho[i]);
    //free(nazwa);
    fclose(plik);
    return 0;
}
