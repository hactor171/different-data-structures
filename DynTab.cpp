#include "DynTab.h"

#include <stdlib.h>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;
// tworzenie pustej tablicy 
DynTab::DynTab() : rozmiar(0), tab() {}

//tworzenie tablicy z dynamicznym rozmiarem(wypelniona zerami)
DynTab::DynTab(unsigned int s) : rozmiar(s), tab((int *)calloc(s,sizeof(int))) {}

// dodawanie po indeksie
DynTab* DynTab::dodajPoIndeksie(int wartosc, unsigned int indeks) {
    if(indeks >= this->rozmiar) 
	{
		try{
			throw exception("Error, nie ma elementow do wyrzucenia");  // sprawdzanie indeksu
		   }
		catch (exception &e)
		{
			cout<<e.what()<<endl;
		}

    } else {
        if(indeks == 0) 
		{

            return this->dodajP(wartosc); // dodawanie na pocztek
        } else if(indeks == this->rozmiar) 
		{
            return this->dodajK(wartosc);   //dodawanie na koniec 
        } else {
            DynTab *dt = this;  // operacje ze wskaznikami
            int *nowaTablica = (int*)malloc((dt->rozmiar+1)*sizeof(int));   // w tym momencie rezerwujemy nowa pamiec
            for(unsigned int i = 0; i < dt->rozmiar+1; i++) 
			{   // kopjujemy stara date
                if(i < indeks)
				{ // pierwsza czesc tablicy 
                    nowaTablica[i] = dt->tab[i];
                } else if(i > indeks) 
				{  //druga czesc tablicy
                    nowaTablica[i] = dt->tab[i-1];
                } else {
                    nowaTablica[i] = wartosc;  // dodawanie znacznie w specyficznym indeksie
                }
            }
            free(dt->tab); // zwolnienie starej tablicy 
            dt->tab = nowaTablica;   // ustawienie nowej tablicy 
            dt->rozmiar++;     // zwiekszenie tablicy  
			
            return dt;
        }
    }
}
// dodawanie na pocztek 
DynTab* DynTab::dodajP(int wartosc) {
    DynTab *dt = this;  // operacje ze wskaznikami
    int *nowaTablica = (int*)malloc((dt->rozmiar+1)*sizeof(int));   // w tym momencie rezerwujemy nowy blok pamieci
    nowaTablica[0] = wartosc;  // dodawanie znacznia na zerowy index
    for(unsigned int i = 1; i < dt->rozmiar+1; i++) { //kopjujemy stara date
        nowaTablica[i] = dt->tab[i-1];
    }
    free(dt->tab);  // zwolnienie starej tablicy 
    dt->tab = nowaTablica;  // ustawienie nowej tablicy 
    dt->rozmiar++;      // zwiekszenie tablicy  
    return dt;
}

// dodawanie na koniec 
DynTab* DynTab::dodajK(int wartosc) 
{
    DynTab *dt = this;  //operacje ze wskaznikami
    void *tmp;
    // prznoszamy ponownie pamiec
    if( (tmp = realloc(dt->tab, (dt->rozmiar+1)*sizeof(int))) != NULL ) 
	{
        dt->tab = (int*)tmp;    // ustawianie skopiowanych i powiększonych bloków pamięci
        dt->tab[dt->rozmiar] = wartosc;  // dodawanie na koniec
        dt->rozmiar++; // zwikszenie tablicy
        return dt;
    } else 
	{    // jesli wystenpie blad
		
        throw std::string("Wystąpił błąd podczas ponownego podziału pamięci.");
		
    }
}
// wyswietlanie tablicy w konsoli
void DynTab::pokaz() 
{
    for(unsigned int i = 0; i < this->rozmiar; i++) 
	{
		std::cout <<"["<<this->tab[i]<<"]"<< " ";
    }
}

// zwraca wartosc po indeksie(nie usuwa wartosci)
int DynTab::otrzymaj(unsigned int indeks) 
{
    if(indeks >= this->rozmiar) 
	{
        throw std::string("Index nie znajduje sie w tablice");
    } else 
	{
        return tab[indeks];
    }
}
// usuwamy po indeksie
int DynTab::usunPoIndeksie(unsigned int indeks, DynTab** d) 
{
    if(indeks >= this->rozmiar)
	{
		try{
			throw exception("Error, nie ma elementow do wyrzucenia");
		   }
		catch (std::exception &e)
		{
			cout<<e.what()<<endl;
		}
    }
    int value;// wartosc
    int *tb = (int*)malloc((this->rozmiar - 1)*sizeof(int));// w tym momencie rezerwujemy nowy blok pamieci
    for(unsigned int i = 0; i < indeks; i++) 
	{
        tb[i] = this->tab[i];
    }
    for(unsigned int i = indeks+1; i < this->rozmiar; i++) 
	{
        tb[i-1] = this->tab[i];
    }
    value = this->tab[indeks];
    free(this->tab);// zwolnienie starej tablicy 
    this->tab = tb;
    this->rozmiar--;// zmniejszmy rozmiar tablicy 
    return value;// zwracamy wartosc
}

// usuwanie pirwszego elementu
int DynTab::usunP(DynTab** d) 
{
    DynTab *dt = this;  //      operacje ze wskaznikami
    int wartosc = dt->tab[0];     // otrzmanie wartosc do zwrotu
    int *nowaTablica = (int*)malloc((dt->rozmiar-1)*sizeof(int));     // w tym momencie rezerwujemy nowy blok pamieci

    // kopia daty be pierwszej wartosci
    for(unsigned int i = 1; i < dt->rozmiar; i++)
	{
        nowaTablica[i-1] = dt->tab[i];
    }
    dt->rozmiar--;
    free(dt->tab);  //zwolnienie starej tablicy 
    dt->tab = nowaTablica;   // umieszczenie nowego bloku pamieci do tablicy
    return wartosc;   //zwracamy wartosc
}

// usuwamy ostatni element
int DynTab::usunOstatni() 
{
    DynTab *dt = this;
    if(dt->rozmiar >= 1) 
	{//spawdzamy czy tablica jest pusta 
        int wartosc = dt->tab[--dt->rozmiar];  //znajdowanie ostatniej wartosci, zmniejszenie rozmiaru tablicy 
        void *nowaTablica;

        if(dt->rozmiar == 0)
		{ // jezeli ostatni element to zwracamy wartosc i zwolniamy pamiec
            free(dt->tab);//zwolnienie starej tablicy 
            dt->tab = (int *)malloc(0*sizeof(int));
            return wartosc; //zwracamy wartosc
        } else 
		{        // przdzielenie pamieci bez ostatniego elementu
            if((nowaTablica = realloc(dt->tab, dt->rozmiar*sizeof(int)))!= NULL) 
			{
                dt->tab = (int*)nowaTablica;
                return wartosc;
            } else 
			{    // jesli blad
				try
				{
					throw exception("Wystąpił błąd podczas ponownego podziału pamięci.");
			    }
				catch(exception &e)
				{
					cout<<e.what()<<endl;
				}
            }
        }
    } else 
	{ // wyjatek jesli tablica pusta
		try
		{
			throw exception("Nie mamy elementow do usuwania");
		}
		catch(std::exception&e)
		{
			cout<<e.what()<<endl;
		}
    }
}

// znajdowanie wartosci
int DynTab::znajdzWartosc(int wartosc) 
{
    for(unsigned int i = 0; i < this->rozmiar; i++) 
	{
        if(this->tab[i] == wartosc) return i;
    }
    return -1;
}

DynTab::~DynTab()
{
    free(tab);
}

