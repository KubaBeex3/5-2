#include<stdio.h>
#include <string.h>
#include<stdlib.h>
#include<ctype.h>


int dointa(char *znak)
{
    int len=strlen(znak);
    printf("Dlugosc to %d\n", len);
    for(int i=0; i<len; i++) {
        if(isdigit(znak[i]))
            printf( "znak nr.%d to %c\n",i+1, znak[i] );
        else {
            printf("znak nr.%d to %c, nie jest to cyfra",i+1, znak[i] );
                do{
                    printf("\nSprobuj ponownie: ");
                    scanf("%s", &znak[0]);}
                while(!isdigit(znak[0]));


        }

    }
    int liczba=atoi(znak);
    if(liczba>=10&&liczba<=50)
        ;

    else
        printf("Twoj ciag sklada sie z samych cyfr, ale twoja liczba jest poza przedzialem\n");
        while(liczba>50|| liczba<10)
        {
            printf("Sprobuj ponownie: ");
            scanf("%d", &liczba);
        }
        printf("Twoj ciag sklada sie z samych cyfr i miesci sie w przedziale\n");
        return liczba;
}

void silneczynie(char s[])
{
    int ile=strlen(s);
    int mala=0;
    int duza=0;
    int znak=0;
    int cyfra=0;
    for(int i=0; i<ile; i++) {
        if(s[i]>='a'&&s[i]<='z')
            mala=1;
        else if(s[i]>='A'&&s[i]<='Z')
            duza=1;
        else if(s[i]>='0'&&s[i]<='9')
            cyfra=1;
        else
            znak=1;
    }
    if(mala==1&&duza==1&&cyfra==1&&znak==1)
        printf("Haslo jest silne");
    else
        printf("Haslo jest slabe");
    return;
}
int main()
{
    char *znak;
    znak=(char *)malloc((2)*sizeof(char));
    printf("Podaj liczbe z zakresu <10,50>: ");
    scanf("%s",&znak[0]);
    int liczba=dointa(znak);
    free(znak);
    char h1[liczba];            //nie moglem zainicjalizowac gdyz otrzymywalem blad(varrible-sized boject may not be inicialized)
    char h2[liczba];
    printf("Podaj haslo: ");
    scanf("%s", h1);
    printf("Powtorz haslo: ");
    scanf("%s", h2);
    if(strcmp(h1,h2)==0)
        ;
    else {
        while(strcmp(h1,h2)!=0) {
            printf("Hasla nie sa jednakowe, sprobuj ponownie: ");
            scanf("%s", h2);
        }
    }
    printf("Hasla sa jednakowe\n");
    silneczynie(h1);
    return 0;
}
