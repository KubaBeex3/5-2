/* 2. Stwórz strukturê przechowuj¹c¹ imiê, nazwisko, narodowoœæ i rekord czasowy dla zawodników wybranej przez Ciebie dyscypliny sportowej. Utwórz trzy zmienne strukturalne,
po jednej dla ka¿dego zawodnika. Nastêpnie utwórz plik i wpisz do niego dane trzech
zawodników i wczytaj do programu, przypisuj¹c je odpowiednio do pól trzech zmiennych strukturalnych. Wypisz dane zawodników. Daj u¿ytkownikowi mo¿liwoœæ wyboru
zawodnika i poprawienia jego rekordu czasowego. Zapisz nowe dane do pierwotnego pliku,
nadpisuj¹c go. Program powinien zawieraæ procedury/funkcje. */

#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
struct player {
    char name[20];
    char last_name[20];
    char nation[20];
    float time;
};

void data(struct player *one, struct player *two, struct player *three)
{
    strcpy(one->name, "Usain");
    strcpy(one->last_name, "Bolt");
    strcpy(one->nation, "Jamaica");
    one->time=9.58;
    strcpy(two->name, "Tyson");
    strcpy(two->last_name, "Gay");
    strcpy(two->nation, "US");
    two->time=9.69;
    strcpy(three->name, "Asafa");
    strcpy(three->last_name, "Powell");
    strcpy(three->nation, "Jamaica");
    three->time=9.72;
}

void loading(struct player *one, struct player *two, struct player *three)
{
    FILE *plik;
    plik=fopen("data.txt", "w");
    //  fprintf(plik,"O.N.\tName\tSurname\tNation\tBest time[s]\n");
    fprintf(plik,"%s\t%s\t%s\t%.2f\n%s\t%s\t%s\t%.2f\n%s\t%s\t%s\t%.2f\n",one->name,one->last_name,one->nation,one->time,two->name,two->last_name,two->nation,two->time,three->name,three->last_name,three->nation,three->time);
    fclose(plik);
    return;
}



int main()
{
    HANDLE hOut;
    hOut = GetStdHandle( STD_OUTPUT_HANDLE );
    SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY );
    FILE *plik;
    struct player one;//  = {"Usain", "Bolt", "Jamaica", 9.58};
    struct player two;// = {"Tyson","Gay","US",9.69};
    struct player three;// = {"Asafa","Powell","Jamaica",9.72};
    data(&one,&two,&three);
    loading(&one,&two,&three);
    int choice=0;
    int ch=0;
    printf("Pick your player:\n1.%s %s\n2.%s %s\n3.%s %s\n", one.name, one.last_name,two.name,two.last_name,three.name,three.last_name);
    scanf("%d",&choice);
    switch(choice) {
    case 1:
        printf("You picked %s %s\n", one.name, one.last_name);
        printf("Press 1 if you want to change his best time 2 if u want to end: \n");
        scanf("%d",&ch);
        switch(ch) {
        case 1:
            printf("Set new best time: ");
            scanf("%f", &one.time);
            break;
        default:
            break;
        }
        break;
    case 2:
        printf("You picked %s %s\n", two.name, two.last_name);
        printf("Press 1 if you want to change his best time 2 if u want to end: \n");
        scanf("%d",&ch);
        switch(ch) {
        case 1:
            printf("Set new best time: ");
            scanf("%f", &two.time);
            break;
        default:
            break;
        }
        break;
    case 3:
        printf("You picked %s %s\n", two.name, two.last_name);
        printf("Press 1 if you want to change his best time 2 if u want to end: \n");
        scanf("%d",&ch);
        switch(ch) {
        case 1:
            printf("Set new best time: ");
            scanf("%f",&two.time);
            break;
        default:
            break;
        }
        break;
    }
    plik=fopen("data.txt", "w");
    fprintf(plik,"%s\t%s\t%s\t%.2f\n%s\t%s\t%s\t%.2f\n%s\t%s\t%s\t%.2f\n",one.name,one.last_name,one.nation,one.time,two.name,two.last_name,two.nation,two.time,three.name,three.last_name,three.nation,three.time);
    fclose(plik);
    return 0;
}

