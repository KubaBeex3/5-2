CC=gcc
CFLAGS=−Wall // flaga umożliwiająca wyświetlenie ostrzeżeń
LIBS=−lm // jeśli chcemy używać math.h
Zad1: Zad1 . o mean . o // aby otrzymac Zad1 potrzeba: pliku Zad1.o i mean.o
$(CC)$(CFLAGS) −o Zad1 Zad1.o mean.o $( LIBS )
Zad1.o: Zad1.c fun.h // aby otrzymac plik Zad1.o potrzeba: pliku Zad1.c i fun.h
$(CC)$(CFLAGS) −c Zad1.c
mean.o: mean.c // aby otrzymac plik mean.o potrzeba pliku mean.c
$(CC)$(CFLAGS) −c mean.c
