/*
1. Napisz program, który:
- wczyta z klawiatury imię użytkownika i przywita się z nim używając jego imienia
- poprosi o dowolny łańcuch znaków (ustal jego długość i uprzedź o tym użytkownika)
- wywoła funkcję/procedurę (zdecyduj), która w podanym łańcuchu zamieni wszystkie
wielkie litery na małe, a małe na wielkie i wyświetli nowy łańcuch. np. ab3C − > AB3c
- wywoła funkcję/procedurę (zdecyduj), która w podanym łańcuchu zliczy i wypisze ilość
cyfr
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


void zamiana(char zdanie[])
{
    printf("Tekst po zamianie: ");
    for(int i=0; i<20; i++) {
        if (zdanie[i]>='A'&&zdanie[i]<='Z') {
            zdanie[i]=zdanie[i]+32;
        }
        else if(zdanie[i]>='a'&&zdanie[i]<='z') {
            zdanie[i]=zdanie[i]-32;
        }
        }
    printf("%s", zdanie);
    return;
}

int liczenie(char zdanie[])
{
    int suma=0;
    for(int i=0;i<30;i++){
    if(zdanie[i]>='0'&&zdanie[i]<='9')
        suma=suma+1;
    }
    printf("\nW zdaniu znajduje sie %d cyfr", suma);
    return suma;

}

int main()
{
    char napis[31];
    int ile=0;
    printf("Podaj z ilu liter sklada sie twoje imie: ");
    scanf("%d", &ile);
    char imie[ile];                                       // nie moglem przypisac wartosci '\0' gdyz wyskakiwal mi blad kompilatora "Variable-sized object may not be initialized"
    printf("Podaj swoje imie: ");
    scanf("%s", imie);
    printf("Witaj %s\n", imie);
    printf("Podaj napis (max 30 znakow, nie uzywaj spacji)\n");   //program czyta spacji nawet po zastapieniu f-cji scanf f-cja scanf("%[^\n]s",napis) czy gets(napis)
    scanf("%s", &napis);
    zamiana(napis);
    liczenie(napis);
    return 0;
}
