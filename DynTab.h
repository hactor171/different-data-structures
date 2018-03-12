#pragma once
#ifndef DYNTAB_H
#define DYNTAB_H
#include <iostream>

class DynTab 
{
    public:
        DynTab();   //pusta tablica
        DynTab(unsigned int);  //tablica z specyficznym rozmiarem

        DynTab* dodajPoIndeksie(int, unsigned int);     //dodaje element do tablicy po indeksie
        DynTab* dodajP(int);     // dodaje na poczatek tablicy
        DynTab* dodajK(int);      //dodaje na koniec tablicy
        void pokaz();   //wyswietla tablice

        unsigned int otzrmajRozmiar() {return rozmiar;}// otrzmujemy rozmiar tablicy

        int otrzymaj(unsigned int);     // daje wartosc
		int usunPoIndeksie(unsigned int, DynTab** = nullptr);   //usunac po indeksie
        int usunP(DynTab** = nullptr);  //usuwa pierwszy element
        int usunOstatni();   //usuwa ostatni element tablicy

        int znajdzWartosc(int);    //szuka wartosc po indeksie w tablice

        virtual ~DynTab();

    private:
        unsigned int rozmiar;
        int *tab;
};

#endif 


