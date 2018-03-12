#ifndef KOPIEC_H
#define KOPIEC_H

#include <string>

class Kopiec 
{
public:
	Kopiec () : kopiec(nullptr), rozmiar(0) {}  // konstruktor
	Kopiec (int);      //iniciakizacja wartosci

	std::string cr, cl, cp;
	void rysuj(std::string, std::string, int);
	void pokaz();	//pokaz kopiec

	Kopiec * dodaj(int); //dodanie wartosci do kopcu

	int usunPierwszy(Kopiec ** = nullptr);      //usun element z kopca
	int otrzymaj(unsigned int);

	unsigned int zRozmiar() { return rozmiar; }		//zwraca rozmiar
	int znajdzWartosc(int);    //poszukiwanie po indeksu

	virtual ~Kopiec ();

private:
	int *kopiec;
	unsigned int rozmiar;

	void sortowaniezGorynaDol(int *);   
	void sortowaniezDolunaGore(int *, int);   
};

#endif 
