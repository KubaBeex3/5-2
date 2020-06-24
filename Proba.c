#include<stdio.h>
#include<stdlib.h>


int main()
{
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
    }
    else {
        while (!feof(plik)) {
            do {
                c = fgetc(plik);
            } while (c != '\n');
            for(int i = 0; i < 50; i++) {
                    fscanf(plik,"%f %f %f %f",a,x,y,rho);
                    printf("%.3f %.3f %.3f %.3f",*a,*x,*y,*rho);
                a++;x++;y++;rho++;
                printf("\n");
            }
        }
    }
    fclose(plik);
    return 0;
}
