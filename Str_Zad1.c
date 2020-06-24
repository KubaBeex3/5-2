/*
1. Napisz program, który bêdzie mia³ w sobie strukturê do przechowywania liczb zespolonych. Napisz funkcje/procedury odpowiedzialne za operacje na liczbach zespolonych:
wczytywanie ich, wyœwietlanie, przeliczanie ze wspó³rzêdnych kartezjañskich na biegunowe i odwrotnie.
*/
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<math.h>
#define PI 3.14159265
struct complex {
    float re;
    float im;
    float fi;
    float r;
};


void loading(struct complex *num, int ch)
{
    switch(ch) {
    case 1: {
        printf("Enter real part and imaginary part of your complex number: ");
        scanf("%f %f",&num->re, &num->im);
        break;
    }
    case 2: {
        printf("Enter ray beam and fi angle (in radians): ");
        scanf("%f %f", &num->r, &num->fi);
        break;
    }
    default: {
        printf("There is no such option");
        break;
    }
    }
    return;
}


void display(struct complex *num, int ch)
{
    switch(ch) {
    case 1: {
        printf("\nReZ=%.2f, ImZ=%.2f",num->re, num->im);
        break;
    }
    case 2: {
        printf("\nR=%.2f, FI=%.2f",num->r, num->fi);
        break;
    }
    }
    return;
}


void converting(struct complex *num, int ch)
{
    switch(ch) {
    case 1: {
        num->r=hypot(num->im,num->re);
        if(num->r==0) {
            printf("\nRay beam cannot be equal to 0");
            return;
        } else {
            num->fi=atan(num->im/num->re)*180/PI;
            printf("\nAfter converting to polar coordinate system: r=%.2f, fi=%.2f",num->r, num->fi);
        }
        break;
    }
    case 2: {
        if(num->r==0) {
            printf("\nRay beam cannot be equal to 0");
            return;
        } else {
            num->re=num->r*cos(num->fi*PI/180);
            num->im=num->r*sin(num->fi*PI/180);
            printf("\nAfter converting to Cartesian coordinate system ReZ=%.2f, ImZ=%.2f", num->re, num->im);
        }
        break;
    }
    }
    return;
}

int main()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
    int choice=0;
    printf("Press 1 if you want to use Cartesian coordinate system, 2 polar coordinate system: ");
    scanf("%d", &choice);
    struct complex num;
    loading(&num, choice);
    display(&num, choice);
    converting(&num, choice);
    return 0;
}

