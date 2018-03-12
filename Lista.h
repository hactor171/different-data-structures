#ifndef LISTA_H
#define LISTA_H

#include <string>
class Lista
{
    public:
		Lista() : nastepny(nullptr), wartosc(-2147483647){} //konstruktor listy
        Lista(int); //konstruktor z wartoscia poczatkowa

        Lista* dodaj(int);   //dodaj na pocztek
        Lista* dodajPoIndeksie(int, unsigned int);     //dodaj po indeksie
        Lista* dodajNaKoniec(int);    //dodaj na koniec 

        void pokaz();   //pokaz liste

        unsigned int zRozmiar();     // zwraca rozmiar
        int usunPierwszy(Lista**);      //usuwa pierwszy element
        int usunOstatni();    //usuwa ostatni element
        int usunPoIndeksu(unsigned int, Lista**);    //usun po indeksie

        bool czyPusta();     //
        int znajdzWartosc(int);    //znajdz wartosc po indeksie
        int otrzymaj(unsigned int);

        virtual ~Lista();

    private:
        Lista *nastepny;
        int wartosc;

        Lista* naKoniec();  //w koniec listy
        Lista* naKoniecOstatni();   //idzie do ostatniego ale w tym wypadku gdy on jest ostatni
};

#endif 

