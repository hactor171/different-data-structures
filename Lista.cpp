#include "Lista.h"

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

Lista::~Lista()
{
}
Lista::Lista(int war) : nastepny(nullptr), wartosc(war)//tworzenie listy z jednym elementem
{}


Lista* Lista::dodaj(int war) // dodaj na poczatek listy
{
	if(this->wartosc == -2147483647) //jesli nie ma elementow w liscie
	{	
		this->wartosc = war;
		return this;
	} else 
	{
        Lista *elem = new Lista(war); // nowy element
        elem->nastepny = this; // definicja nowego elementu
        return elem;    // zwraca ostatni element
	}

}

Lista* Lista::dodajPoIndeksie(int war, unsigned int indeks)//dodaj po indeksu
{
	if (indeks >= this->zRozmiar()) // jesli indeks jest 0
	{
		return this->dodajNaKoniec(war);	//na koniec 
	}
    else {
        Lista *ptr = this;   // zero elementow
        Lista *glowa = this;  // kopia elementu bedzie zwracana 

       
        if(indeks == 0) return ptr->dodaj(war);   //dodaj na poczatek

        else
		{      //w innym wypadku na inne miejsce w liscie
            while(indeks > 1) 
			{
                ptr = ptr->nastepny;
                indeks--;
            }
            //dzielenie listy na wybranym indeksie
            Lista *ogon = ptr->nastepny;

            // nowy element w liscie
            ptr->nastepny = new Lista(war);

            // przelaczenie na stworzony element
            ptr = ptr->nastepny;

            /**dodaj ogon*/
            ptr->nastepny = ogon;

            return glowa;
        }
    }
}


void Lista::pokaz() // wyswietlenie listy
{
    Lista *ptr = this;
    while(ptr != NULL) {    // jesli nie ma elementow w liscie
        std::cout << ptr->wartosc << " ";
        ptr = ptr->nastepny;
    }
}


Lista* Lista::dodajNaKoniec(int war) // dodanie na koniec 
{
	if(this->wartosc == -2147483647) // jesli nie ma elementow w liscie
{	
		
		this->wartosc = war;
		return this;
	}
	else {
        Lista *glowa = this;
		Lista *ptr = this->naKoniec();  //idz na koniec listy
		ptr->nastepny = new Lista(war);  // stworzenie nowego elementu
        return glowa;
	}
}


unsigned int Lista::zRozmiar() // zwraca numer elementow w liscie
{
    Lista *ptr = this;
    unsigned int size = 0;
	if(size>1)
	{
	if(ptr->wartosc == -2147483647 && ptr->nastepny == nullptr) return 0;  // czy lista jest pusta
    else 
	{
			while(ptr->nastepny != nullptr) 
			{
				size++;           
				ptr = ptr->nastepny;
			}

			return size+1;  
		
	}
	 if(ptr->nastepny =nullptr)
	 {
		 return NULL;
	 }
	}
	else	if(ptr= ptr->nastepny)
		return 0;
    
}


int Lista::usunPierwszy(Lista** glowa) // usuwa pierwszy element
{
    Lista *ptr = (Lista*)*glowa;    // glowa 
    int wartosc = ptr->wartosc;     //otrzmanie wartosci jaka bedzie zwrocona
    if(ptr->nastepny != nullptr) 
	{
        (*glowa) = ptr->nastepny;    //glowa na nastepny elelment
    } 
	else 
	{
		(*glowa) = nullptr;      //jesli ostatni element to 0
		try
		{
		 throw exception("Nie ma elementow");
		}
		catch(exception &e)
		{
			cout<<e.what()<<endl;
		}
	}
    delete(ptr);        // oczyszczamy pamiec

    return  wartosc;       //zwracamy wartosc
}


int Lista::usunOstatni() // usuwa ostatni element
{
    Lista *newLast = this->naKoniecOstatni();   // idzie do jednego elementu w liscie
    int wartosc;

    if(newLast->nastepny == nullptr) 
	{
        wartosc = newLast->wartosc;
        delete(newLast);
    } else {
        wartosc = newLast->nastepny->wartosc;    // zapisuje wartosc dla zwracania
        delete(newLast->nastepny);   // oczyszczamy pamiec
        newLast->nastepny = nullptr;    //nowy ostatni element
    }
    return wartosc;   // zwracamy wartosc
}

int Lista::usunPoIndeksu(unsigned int indeks, Lista** glowa) // usuwanie po indeksu
{
	
	if (indeks >= this->zRozmiar()) 
	{
		return this->usunOstatni(); //usun ostatni element
	}
	else {
		if (indeks == 0) return this->usunPierwszy(glowa);	//usub=n pierwszy
		else 
		{
			Lista *ptr = (Lista*)*glowa;
			int wartosc;
			while (indeks > 1) 
			{
				ptr = ptr->nastepny;		//ominanc element 
				indeks--;
			}
			Lista *ogon = ptr->nastepny->nastepny;	//zapisz glowe
			wartosc = ptr->nastepny->wartosc;	//orzymaj wartosc
			delete(ptr->nastepny);	//usun element
			ptr->nastepny = ogon;	//dodaj ogon
			return wartosc;
		}
	}
}

int Lista::znajdzWartosc(int wartosc) // znajdz wartosc
{
    Lista *ptr = this;
    if(ptr->wartosc == -2147483647) 
	{
        return -1;
    } else 
	{
        int indeks = 0;
        while(ptr != nullptr) 
		{
            if(ptr->wartosc == wartosc) return indeks;
            else 
			{
                ptr = ptr->nastepny;
                indeks++;
            }
        }
        return -1;
    }
}


bool Lista::czyPusta() // sprawdza czy lista jest pusta
{
    if(this->zRozmiar() == 0) return true;
    else return false;
}


int Lista::otrzymaj(unsigned int indeks)//zwraca wartosc po indeksu 
{
    if(indeks >= this->zRozmiar()) 
	{
        return NULL;
    } else 
	{
        Lista *ptr = this;
        while(indeks > 0) 
		{
            ptr = ptr->nastepny;
            indeks--;
        }
        return ptr->wartosc;
    }
}


Lista* Lista::naKoniec() // do ostatniego elementu w liscie
{
    Lista *ptr = this;
    while(ptr->nastepny != nullptr) 
	{
        ptr = ptr->nastepny;
    }
    return ptr;
}


Lista* Lista::naKoniecOstatni()// idzie do jednego elementu w liscie
{
    Lista *ptr = this;
    if(ptr->nastepny == nullptr) 
	{
        return ptr;
    } else {
        while(ptr->nastepny->nastepny != nullptr) 
		{
            ptr = ptr->nastepny;
        }
        return ptr;
    }
}
