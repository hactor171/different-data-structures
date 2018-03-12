#ifndef TESTOWANIE_H
#define TESTOWANIE_H

#include "DrzewoRB.h"
#include "Kopiec.h"
#include "Lista.h"
#include "DynTab.h"

#include <string>

class Testowanie
{
    public:
        Testowanie();
        Testowanie(Lista*, DynTab*, Kopiec*, DrzewoRB*);
	//lista
        void DodajDoListyP(int);  //dodawanie elementu na poczatek listy
		void DodajDoListyM(int, unsigned int); //dodawanie elementu w wybranym miejscu listy
        void DodajDoListyK(int); // dodawanie elementu na koniec listy
        void ZnajdzWLiscie(int);// szukaj element w liscie
		void UsunPierwszyELemListy(); // usuwanie elementu z poczatku listy
		void UsunWMiejscuListy(unsigned int);// usuwanie elementu w wybranym miejscu listy
        void UsunOstatniElemListy();// usuwanie elementu z konca listy
		void pokazListe(); // pokaz liste
		void wyczyscListe(); //czyszczenie listy
    ///////

   //kopiec
        void DodajDoKopcu(int);  // dodawanie elementu do kopcu
        void UsunZKopcu();  // usuwanie elementu z kopcu
		void ZnajdzWKopcu(int);  // szukanie wartosci w kopcu
		void pokazKopiec();  // pokaz kopiec
		void wyczyscKopiec();  // czyszczenie kopcu
   ///////

   //tablica
		void DodajDoTablicyP(int);  //dodawanie elementu na poczatek tablicy
		void DodajDoTablicyM(int, unsigned int); //dodawanie elementu w wybranym miejscu tablicy
        void DodajDoTablicyK(int); // dodawanie elementu na koniec tablicy
		void ZnajdzWTabblice(int); // szukaj element w tablice
		void UsunPierwszyELemTablicy();// usuwanie elementu z poczatku tablicy
		void UsunWMiejscuTablicy(unsigned int);// usuwanie elementu w wybranym miejscu tablicy
        void UsunOstatniElemTablicy();//usuwanie elementu z konca tablicy
        void pokazTablice(); //pokaz tablice
		void wyczyscTablice(); //czyszczenie tablicy
   ///////
   
   //drzewo
        void DodajDoDrzewa(int);  //dodawanie elementu do drzewa
        void UsunZDrzewa();// usuwanie elementu z drzewa
        void ZnajdzWDrzewie(int);// szukanie wartosci w drzewie
		void pokazDrzewo();// pokaz dzrewo
        void wyczyscDrzewo();// czyszczenie drzewa
   ///////
        
        void setList(Lista*);
        void setHeap(Kopiec*);
        void setDtab(DynTab*);
        void setRbtr(DrzewoRB*);

        void wyczscWszystko(); //czyszczenie struktur 
		void OdczytajWartosciZPliku(std::string);/*inicializacja danych z pliku*/
       
        
        void ZapiszDoPlikuiEndTimer(double,std::string);
        void CzasPlik(std::string,std::string,double);
        
		virtual ~Testowanie();

    private:
        Lista* lista;
        Kopiec* kopiec;
        DynTab* dtab;
        DrzewoRB* drzeworb;

		template<typename T>//zapisanie do pliku przed operacja(lista,tablica,kopiec)
		void przedOperacja(T*, std::string, std::string, int, unsigned int, unsigned int, unsigned int);
		template<typename T>//zapisanie do pliku po operacji(lista,tablica,kopiec)
		void poOperacji(T*, std::string, unsigned int, unsigned int);
        
		void PrzedZnajdowaniem(std::string, int);//przed znajdowaniem
        void PoZnajdowaniu(std::string, int);//po znajdowaniu
        
		void przedOperacjaDrzewo(std::string);//zapisanie do pliku drzewa  przed operacja
        void poOperacjiDrzewo(std::string);//zapisanie do pliku drzewa  po operacji

		

};

#endif 