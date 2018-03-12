#include "Kopiec.h"
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <sstream>
 

Kopiec ::Kopiec (int wartosc) : kopiec((int*)malloc(sizeof(int))), rozmiar(1) // konstruktor kopcu
{
	kopiec[0] = wartosc;
}

// wyswietlanie kopcu
void Kopiec ::pokaz() 
{
	for (unsigned int i = 0; i < this->rozmiar; i++) 
	{
		std::cout << this->kopiec[i] << " ";
	}
	std::cout<<"\n---------------------------------------------"<<std::endl;
	rysuj("","",0);
}
void Kopiec ::rysuj(std::string sp, std::string sn, int v)	//rysowanie kopca 
{
	//wartosci jakie daja mozliwosc do rysowanie znakow w konsoli
	cr = cl = cp = "  ";
	cr[0] = 218; cr[1]=62; cr[2] = 196;	
	cl[0] = 192; cl[1]=62; cl[2] = 196;
	cp[0]= 179;
	std::string s;

	int test;

	if (v < rozmiar)
	{
		s = sp;
		if (sn == cr) s[s.length() - 2] = ' ';
		rysuj(s + cp, cr, 2 * v + 2);

		s = s.substr(0, sp.length() - 2);

		test = kopiec[v];

		std::cout << s << sn << test << std::endl;

		
			s = sp;
			if (sn == cl)
				s[s.length() - 2] = ' ';
			rysuj(s + cp, cl, 2 * v +1);
		


	}
}

Kopiec * Kopiec ::dodaj(int wartosc) // dodawanie elementu do kopcu 
{
	int *nowyKopiec ;
	if ((nowyKopiec = (int*)realloc(this->kopiec, (this->rozmiar + 1)*sizeof(int))) != NULL)
	{
		nowyKopiec[this->rozmiar] = wartosc; //dodanie elementu na koniec
		this->kopiec = nowyKopiec;
		this->rozmiar++;
		sortowaniezDolunaGore(this->kopiec, this->rozmiar);	//sortowanie kopcu
		return this;
	} 
	else 
	{
        return this;
	}
}

int Kopiec::otrzymaj(unsigned int index) 
{
    if(index >= this->rozmiar) 
	{
        return NULL;
    } 
	else 
	{
        return this->kopiec[index];
    }
}


int Kopiec::usunPierwszy(Kopiec** h) // usuwanie wezla
{
	int popwartosc = this->kopiec[0];
	int *nowyKopiec = (int*)malloc((this->rozmiar - 1)*sizeof(int)); //nowa pamiec

	nowyKopiec[0] = this->kopiec[this->rozmiar - 1];	//ostatnia wartosc jako nowy wezel
	for (unsigned int i = 1; i < this->rozmiar - 1; i++) 
	{	
		nowyKopiec[i] = this->kopiec[i];
	}

	free(this->kopiec);	//usun stary kopiec
	this->kopiec = nowyKopiec;	//nowy kopiec
	this->rozmiar--;	//zmina rozmiaru

	sortowaniezGorynaDol(this->kopiec);	
	return popwartosc;	//zwara stara wartosc
}


int Kopiec::znajdzWartosc(int war)// znajduje wartosc w kopcu
{
	for(unsigned int i = 0; i < rozmiar; i++) 
	{
        if(this->kopiec[i] == war) return i;
	}
	return -1;
}


void Kopiec::sortowaniezDolunaGore(int *kopiec, int rozmiar) // sortowanie z dolu na gore
{
	int rodzic = (rozmiar - 2) / 2;
	int dziecko = rozmiar-1;
	while (kopiec[rodzic] < kopiec[dziecko] && dziecko > 0) 
	{ 
		int tmp = kopiec[rodzic];	
		kopiec[rodzic] = kopiec[dziecko];
		kopiec[dziecko] = tmp;
		dziecko = rodzic;	//dziecko staje rodzicem
		rodzic = (dziecko - 1) / 2;	//shuka nowego rodzica
	}
}


void Kopiec::sortowaniezGorynaDol(int *kopiec) // sortowanie z gory na dol
{
	unsigned int wezel, lewy, prawy;
	wezel = 0;

	while ( (lewy=(2*wezel+1)) < this->zRozmiar() ) 
	{ 
		if ((prawy = lewy+1) < this->zRozmiar()) 
		{	
			if (kopiec[wezel] < kopiec[lewy] || kopiec[wezel] < kopiec[prawy]) 
			{	
				if (kopiec[lewy] >= kopiec[prawy]) 
				{ 
					int tmp = kopiec[wezel];	//wezel wymiana z lewym dzieckiem
					kopiec[wezel] = kopiec[lewy];	//lewe dziecko nowy wezel
					kopiec[lewy] = tmp;		//stary wezel staje sie nowym dzieckiem
					wezel = lewy;
				}
				else // jezeli prawe dziecko jest wieksze za wezel 
				{	
					int tmp = kopiec[wezel];	//wezel wymiana z prawym dzieckiem
					kopiec[wezel] = kopiec[prawy];	//prawe dziecko nowy wezel
					kopiec[prawy] = tmp;		//stary wezel staje sie nowym dzieckiem
					wezel = prawy;
				}
			}
			    else 
				{
				break;
			    }
		}
		        else// jezeli jest tylko jedno dziecko 
				{	
			      if (kopiec[lewy] > kopiec[wezel]) 
				  {	
				int tmp = kopiec[wezel];	//wezel wymiana z lewym dzieckiem
				kopiec[wezel] = kopiec[lewy];	//lewe dziecko nowy wezel
				kopiec[lewy] = tmp;		//stary wezel staje sie nowym dzieckiem
				wezel = lewy;
			      }
			    else 
				{
				break;
			    }
		}
	}
}


Kopiec::~Kopiec()
{
	free(kopiec);
}


