#include "Testowanie.h"

#include "Lista.h"
#include "Kopiec.h"
#include "DynTab.h"
#include "DrzewoRB.h"
#include "Timer.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <stdlib.h>
#include <ctime>
#include <time.h>
#include <windows.h>
#include <stack>
#include <time.h>
#include <conio.h>
#include <string>
#include <sstream>


Timer*czas = new Timer(); 


// tworzymy struktury
Testowanie::Testowanie() :
    lista(new Lista()), dtab(new DynTab()),kopiec(new Kopiec()), drzeworb(new DrzewoRB()) { }

// struktury dla testowania
Testowanie::Testowanie(Lista* l, DynTab* dt,Kopiec* k, DrzewoRB* rb) :
    lista(l), dtab(dt),kopiec(k), drzeworb(rb) { }



void Testowanie::DodajDoListyP(int wartosc) 
{
	czas->startTimer();
    if(lista->zRozmiar() <= 10) 
	{	   
	    przedOperacja(lista, "listAddTests.txt", "dodawania na poczatku", wartosc, 0, 0, lista->zRozmiar());
        lista = lista->dodaj(wartosc);
        poOperacji(lista, "listAddTests.txt",0, lista->zRozmiar());
		
    } 
	else
	{
        przedOperacja(lista, "listAddTests.txt", "dodawania na poczatku", wartosc, 0, 0, 5);
        lista = lista->dodaj(wartosc);
		poOperacji(lista, "listAddTests.txt", 0, 5);
    }
	ZapiszDoPlikuiEndTimer(0,"Dodawanie na poczatek Listy:");
}

void Testowanie::DodajDoKopcu(int wartosc) {
	        
	czas->startTimer();
    if(kopiec->zRozmiar() <= 10) 
	{
	
        przedOperacja(kopiec,"heapAddTests.txt", "dodawania", wartosc, 0, 0, kopiec->zRozmiar());
        kopiec->dodaj(wartosc);
        poOperacji(kopiec, "heapAddTests.txt", 0, kopiec->zRozmiar());
    } 
	else
	{
        przedOperacja(kopiec,"heapAddTests.txt", "dodawania", wartosc, 0, 0, 5);
        kopiec->dodaj(wartosc);
        poOperacji(kopiec, "heapAddTests.txt", 0, 5);
    }
	ZapiszDoPlikuiEndTimer(0,"Dodawanie do kopcu:");
}

void Testowanie::DodajDoDrzewa(int wartosc) {
	czas->startTimer();
    przedOperacjaDrzewo("RBTaddTests.txt");
	drzeworb->dodajDrzewoRB(wartosc);
    poOperacjiDrzewo("RBTaddTests.txt");
	ZapiszDoPlikuiEndTimer(0,"Dodawanie do drzewa:");
}

void Testowanie::DodajDoTablicyP(int wartosc) 
{
	czas->startTimer();
    if(dtab->otzrmajRozmiar() <= 10)
	{
        przedOperacja(dtab, "DTabAddTests.txt", "dodawania na poczatku", wartosc, 0, 0, dtab->otzrmajRozmiar());
        dtab->dodajP(wartosc);
        poOperacji(dtab, "DTabAddTests.txt", 0, dtab->otzrmajRozmiar());
    }
	else
	{
        przedOperacja(dtab, "DTabAddTests.txt", "dodawania na poczatku", wartosc, 0, 0, 5);
        dtab->dodajP(wartosc);
        poOperacji(dtab, "DTabAddTests.txt", 0, 5);
    }
	ZapiszDoPlikuiEndTimer(0,"Dodawanie do tablicy na poczatek:");
}

void Testowanie::DodajDoListyK(int wartosc) 
{
	czas->startTimer();
    if(lista->zRozmiar() <= 10)
	{
        przedOperacja(lista, "listAddAtEndTests.txt", "dodawania na koncu", wartosc, NULL, 0, lista->zRozmiar());
        lista = lista->dodajNaKoniec(wartosc);
        poOperacji(lista, "listAddAtEndTests.txt", 0, lista->zRozmiar());
    } 
	else 
	{
        przedOperacja(lista, "listAddAtEndTests.txt", "dodawania na koncu", wartosc, NULL, lista->zRozmiar()-6 , lista->zRozmiar());
        lista = lista->dodajNaKoniec(wartosc);
        poOperacji(lista, "listAddAtEndTests.txt", lista->zRozmiar() -6, lista->zRozmiar());
    }
	ZapiszDoPlikuiEndTimer(0,"Dodawanie do listy na koniec:");
}

void Testowanie::DodajDoListyM(int wartosc, unsigned int indeks) 
{   
	czas->startTimer();
    if(lista->zRozmiar() <= 10) 
	{
        przedOperacja(lista, "listAddAtIndexTests.txt", "dodawania w okreslonym miejscu", wartosc, indeks, 0, lista->zRozmiar());
        lista = lista->dodajPoIndeksie(wartosc, indeks);
        poOperacji(lista, "listAddAtIndexTests.txt", 0, lista->zRozmiar());
    }
	
	else 
	{
        przedOperacja(lista, "listAddAtIndexTests.txt", "dodawania w okreslonym miejscu", wartosc, indeks, indeks-3, indeks+3);
        lista = lista->dodajPoIndeksie(wartosc, indeks);
        poOperacji(lista, "listAddAtIndexTests.txt", indeks-3, indeks+4);
    }
	ZapiszDoPlikuiEndTimer(0,"Dodawanie Po indeksie do Listy:");
}

void Testowanie::DodajDoTablicyM(int wartosc, unsigned int indeks) {
	czas->startTimer();
    if(dtab->otzrmajRozmiar() <= 10) 
	{
        przedOperacja(dtab, "DTabAddAtIndexTests.txt", "dodawania w okreslonym miejscu", wartosc, indeks, 0, dtab->otzrmajRozmiar());
        dtab->dodajPoIndeksie(wartosc, indeks);
        poOperacji(dtab, "DTabAddAtIndexTests.txt", 0, dtab->otzrmajRozmiar());
    } 
	else 
	{
        przedOperacja(dtab, "DTabAddAtIndexTests.txt", "dodawania w okreslonym miejscu", wartosc, indeks, indeks-3, indeks+3);
        dtab->dodajPoIndeksie(wartosc, indeks);
		poOperacji(dtab, "DTabAddAtIndexTests.txt", indeks-3, indeks+4);
    }
	ZapiszDoPlikuiEndTimer(0,"Dodawanie Po indeksie do Tablicy:");
}

void Testowanie::DodajDoTablicyK(int indeks) 
{
	czas->startTimer();
    if(dtab->otzrmajRozmiar() <= 10) 
	{
        przedOperacja(dtab, "DTabAddAtEndTests.txt", "dodawania na koncu", indeks, NULL, 0, dtab->otzrmajRozmiar());
        dtab->dodajK(indeks);
		poOperacji(dtab, "DTabAddAtEndTests.txt", 0, dtab->otzrmajRozmiar());
    } 
	else 
	{
        przedOperacja(dtab, "DTabAddAtEndTests.txt", "dodawania na koncu", indeks, NULL, dtab->otzrmajRozmiar() -6, dtab->otzrmajRozmiar());
        dtab->dodajK(indeks);
		poOperacji(dtab, "DTabAddAtEndTests.txt", dtab->otzrmajRozmiar() -6, dtab->otzrmajRozmiar());
    }
	ZapiszDoPlikuiEndTimer(0,"Dodawanie do Tablicy na koniec :");
}



void Testowanie::UsunPierwszyELemListy() 
{ 
	czas->startTimer();
    if(lista->zRozmiar() <= 10) 
	{
        przedOperacja(lista, "listDeleteFTests.txt", "usuwania z poczatku", 0, 0, 0, lista->zRozmiar());
        int wartosc = lista->usunPierwszy(&lista);
        poOperacji(lista, "listDeleteFTests.txt", 0, lista->zRozmiar());
        cout << "Usunieta wartosc: " << wartosc << "\n....\n\n";
    } else 
	{
        przedOperacja(lista, "listDeleteFTests.txt", "usuwania z poczatku", 0, 0, 0, 5);
        int wartosc = lista->usunPierwszy(&lista);
        poOperacji(lista, "listDeleteFTests.txt", 0, 5);
        cout << "Usunieta wartosc: " << wartosc << "\n....\n\n";
    }
	ZapiszDoPlikuiEndTimer(0,"Usuwanie z poczatku Listy:");
}

void Testowanie:: UsunZKopcu() 
{
	czas->startTimer();
    if(kopiec->zRozmiar() <= 10) 
	{
        przedOperacja(kopiec,"heapDeleteFTests.txt", "usuwania z poczatku", 0, 0, 0, kopiec->zRozmiar());
        int wartosc = kopiec->usunPierwszy();
        poOperacji(kopiec, "heapDeleteFTests.txt", 0, kopiec->zRozmiar());
        cout << "Usunieta wartosc: " << wartosc << "\n####\n\n";
    } else 
	{
        przedOperacja(kopiec,"heapDeleteFTests.txt", "usuwania z poczatku", 0, 0, 0, 5);
        int wartosc = kopiec->usunPierwszy();
        poOperacji(kopiec, "heapDeleteFTests.txt", 0, 5);
        cout << "Usunieta wartosc: " << wartosc << "\n####\n\n";
    }
	ZapiszDoPlikuiEndTimer(0,"Usuwanie z kopcu:");
}

void Testowanie::UsunZDrzewa() 
{
	czas->startTimer();
    przedOperacjaDrzewo("RBTdeleteTests.txt");
	drzeworb->usunW(drzeworb->getRoot());
    poOperacjiDrzewo("RBTdeleteTests.txt");
	ZapiszDoPlikuiEndTimer(0,"Usuwanie z drzewa:");
}

void Testowanie::UsunPierwszyELemTablicy() 
{   czas->startTimer();
    if(dtab->otzrmajRozmiar() <= 10) 
	{
        przedOperacja(dtab, "DTabDeleteFTests.txt", "usuwania z poczatku", 0, 0, 0, dtab->otzrmajRozmiar());
        int wartosc = dtab->usunP();
        poOperacji(dtab, "DTabDeleteFTests.txt", 0, dtab->otzrmajRozmiar());
        cout << "Usunieta wartosc: " << wartosc << "\n####\n\n";
    } else 
	{
        przedOperacja(dtab, "DTabDeleteFTests.txt", "usuwania z poczatku", 0, 0, 0, 5);
        int wartosc = dtab->usunP();
        poOperacji(dtab, "DTabDeleteFTests.txt", 0, 5);
        cout << "Usunieta wartosc: " << wartosc << "\n####\n\n";
    }
	ZapiszDoPlikuiEndTimer(0,"Usuwanie z poczatku Tablicy:");
}

void Testowanie::UsunOstatniElemListy() 
{
	czas->startTimer();
    if(lista->zRozmiar() <= 10)
	{
        przedOperacja(lista, "listDeleteLTests.txt", "usuwania z konca", 0, 0, 0, lista->zRozmiar());
        int wartosc = lista->usunOstatni();
        poOperacji(lista, "listDeleteLTests.txt", 0, lista->zRozmiar());
        cout << "Usunieta wartosc: " << wartosc << "\n####\n\n";
    } else 
	{
        przedOperacja(lista, "listDeleteLTests.txt", "usuwania z konca", 0, 0, 0, 5);
        int wartosc = lista->usunOstatni();
        poOperacji(lista, "listDeleteLTests.txt", 0, 5);
        cout << "Usunieta wartosc: " << wartosc << "\n####\n\n";
    }
	ZapiszDoPlikuiEndTimer(0,"Usuwanie z konca Listy:");
}

void Testowanie::UsunOstatniElemTablicy() 
{
	czas->startTimer();
    if(dtab->otzrmajRozmiar() <= 10) 
	{
        przedOperacja(dtab, "DTabDeleteLTests.txt", "usuwania z konca", 0, 0, 0, dtab->otzrmajRozmiar());
        int wartosc = dtab->usunOstatni();
        poOperacji(dtab, "DTabDeleteLTests.txt", 0, dtab->otzrmajRozmiar());
        cout << "Usunieta wartosc: " << wartosc << "\n####\n\n";
    } else 
	{
        przedOperacja(dtab, "DTabDeleteLTests.txt", "usuwania z konca", 0, 0, 0, 5);
        int wartosc = dtab->usunOstatni();
        poOperacji(dtab, "DTabDeleteLTests.txt", 0, 5);
        cout << "Usunieta wartosc: " << wartosc << "\n####\n\n";
    }
	ZapiszDoPlikuiEndTimer(0,"Usuwanie z konca Tablicy:");
}

void Testowanie::UsunWMiejscuListy(unsigned int indeks) 
{
	czas->startTimer();
    if(lista->zRozmiar() <= 10) 
	{
        przedOperacja(lista, "listDeleteAITests.txt", "usuwania z podanego miejsca", 0, 0, 0, lista->zRozmiar());
        int wartosc = lista->usunPoIndeksu(indeks, &lista);
        poOperacji(lista, "listDeleteAITests.txt", 0, lista->zRozmiar());
        cout << "Usunieta wartosc: " << wartosc << "\n####\n\n";
    } else 
	{
        przedOperacja(lista, "listDeleteAITests.txt", "usuwania z podanego miejsca", 0, 0, 0, 5);
        int wartosc = lista->usunPoIndeksu(indeks, &lista);
        poOperacji(lista, "listDeleteAITests.txt", 0, 5);
        cout << "Usunieta wartosc: " << wartosc << "\n####\n\n";
    }
	ZapiszDoPlikuiEndTimer(0,"Usuwanie z Listy po indeksie :");
}

void Testowanie::UsunWMiejscuTablicy(unsigned int indeks) 
{
	czas->startTimer();
    if(dtab->otzrmajRozmiar() <= 10) 
	{
        przedOperacja(dtab, "DTabDeleteAITests.txt", "usuwania z podanego miejsca", 0, 0, 0, dtab->otzrmajRozmiar());
        int wartosc = dtab->usunPoIndeksie(indeks);
        poOperacji(dtab, "DTabDeleteAITests.txt", 0, dtab->otzrmajRozmiar());
        cout << "Usunieta wartosc: " << wartosc << "\n####\n\n";
    } else 
	{
        przedOperacja(dtab, "DTabDeleteAITests.txt", "usuwania z podanego miejsca", 0, 0, 0, 5);
        int wartosc = dtab->usunPoIndeksie(indeks);
        poOperacji(dtab, "DTabDeleteAITests.txt", 0, 5);
        cout << "Usunieta wartosc: " << wartosc << "\n####\n\n";
    }
	ZapiszDoPlikuiEndTimer(0,"Usuwanie z Tablicy po indeksie :");
}

/////Inicjalizacja struktur z wartościami z pliku/////
void Testowanie::OdczytajWartosciZPliku(string filePath) {
    wyczscWszystko();
    string line;
    ifstream dataFile(filePath);
    if(dataFile.is_open()) {
        cout << "==Odczytujemy wartosci z pliku==";
        while (getline(dataFile, line)) {
            int wartosc;
            istringstream iss(line);   
            iss >> wartosc;
            lista->dodajNaKoniec(wartosc);  
            kopiec->dodaj(wartosc);
            dtab->dodajK(wartosc);
			drzeworb->dodajDrzewoRB(wartosc);
        }
        cout << "\nWszystkie wartosci wczytane z pliku:\n\t--->>>" << endl;
        dataFile.close();
    } else {
        cout << "Bled, sprobuj ponownie" << endl;
    }
}

void Testowanie::ZnajdzWLiscie(int wartosc) 
{
	czas->startTimer();
    PrzedZnajdowaniem("listFindTests.txt", wartosc);
    int indeks = lista->znajdzWartosc(wartosc);
    PoZnajdowaniu("listFindTests.txt", indeks);
	ZapiszDoPlikuiEndTimer(0,"Sukanie w liscie:");
}

void Testowanie::ZnajdzWKopcu(int wartosc) 
{
	czas->startTimer();
    PrzedZnajdowaniem("heapFindTests.txt", wartosc);
    int indeks = kopiec->znajdzWartosc(wartosc);
    PoZnajdowaniu("heapFindTests.txt", indeks);
	ZapiszDoPlikuiEndTimer(0,"Sukanie w kopcu:");
}

void Testowanie::ZnajdzWTabblice(int wartosc)
{
	czas->startTimer();
    PrzedZnajdowaniem("DTabFindTests.txt", wartosc);
    int indeks = dtab->znajdzWartosc(wartosc);
    PoZnajdowaniu("DTabFindTests.txt", indeks);
	ZapiszDoPlikuiEndTimer(0,"Sukanie w tablice:");
}

void Testowanie:: ZnajdzWDrzewie(int wartosc) 
{
	czas->startTimer();
    PrzedZnajdowaniem("RBTreeFindTests.txt", wartosc);
	int indeks = drzeworb->znajdzDrzewoRB(wartosc);
    PoZnajdowaniu("RBTreeFindTests.txt", indeks);
	ZapiszDoPlikuiEndTimer(0,"Sukanie w drzewie:");
}

/////Wyswietlanie do konsoli/////
void Testowanie:: pokazListe() {
    lista->pokaz();
}

void Testowanie::pokazKopiec() {
    kopiec->pokaz();
}

void Testowanie::pokazTablice() {
    dtab->pokaz();
}

void Testowanie::pokazDrzewo() {
	drzeworb->pokaz();
}
////////////////////////////////

////////////////////////////////
void Testowanie::setList(Lista* li) {
    delete(lista);
    lista = (Lista*)li;
}

void Testowanie::setHeap(Kopiec* ko) {
    delete(kopiec);
    kopiec = (Kopiec*)ko;
}

void Testowanie::setDtab(DynTab* dt) {
    delete(dtab);
    dtab = (DynTab*)dt;
}

void Testowanie::setRbtr(DrzewoRB* rb) {
	drzeworb->usunDrzewoRB(drzeworb->getRoot());
	drzeworb = rb;
}
////////////////////////////////

////////wyczysc struktury///////
void Testowanie::wyczscWszystko() {
    delete(lista);
    lista = new Lista();
    delete(kopiec);
    kopiec = new Kopiec();
    delete(dtab);
    dtab = new DynTab();
	drzeworb->usunDrzewoRB(drzeworb->getRoot());
	drzeworb = new DrzewoRB();
}
////////////////////////////////

////////wyczyscznie struktur///////
void Testowanie::wyczyscListe() {
    delete(lista);
    lista = new Lista();
}

void Testowanie::wyczyscKopiec() {
    delete(kopiec);
    kopiec = new Kopiec();
}

void Testowanie::wyczyscTablice() {
    delete(dtab);
    dtab = new DynTab();
}

void Testowanie::wyczyscDrzewo() {
	drzeworb->usunDrzewoRB(drzeworb->getRoot());
	drzeworb = new DrzewoRB();
}
////////////////////////////////
Testowanie::~Testowanie()
{
    delete(lista);
    delete(kopiec);
    delete(dtab);
	drzeworb->usunDrzewoRB(drzeworb->getRoot());
}
////////////////////////////////
//zapisanie do pliku przed operacja(lista,tablica,kopiec)//
template<typename T>
void Testowanie::przedOperacja(T* t, string filename, string where, int wartosc, unsigned int indeks, unsigned int begin, unsigned int end) {
    ofstream flist;
    flist.open(filename, ios::out | ios::app);
    if(flist.is_open()) {
        flist << "Testowanie " << where << " struktury.\nStan struktury:\n\n";
        cout << "Testowanie " << where << " struktury.\nStan struktury:\n\n";
        for(unsigned int i = begin; i < end; i++) {
            flist << t->otrzymaj(i) << " ";
            cout << t->otrzymaj(i) << " ";
        }
        flist << "\n\n";
        flist << "Wartosc: " << wartosc << "  indeks: " << indeks << "\n\nStan struktury po operacji:\n\n";
        cout << "\n\n";
        cout << "Wartosc: " << wartosc << "  indeks: " << indeks << "\n\nStan struktury po operacji:\n\n";
        flist.close();
    } else {
        cout << "Blad podczas otwierania pliku" << endl;
    }
}
////////////////////////////////
//zapisanie do pliku po operacji(lista,tablica,kopiec)//
template<typename T>
void Testowanie::poOperacji(T* t, string filename, unsigned int begin, unsigned int end) 
{
    ofstream flist;
    flist.open(filename, ios::out | ios::app);
    if(flist.is_open()) {
        for(unsigned int i = begin; i < end; i++) {
                flist << t->otrzymaj(i) << " ";
                cout << t->otrzymaj(i) << " ";
            }
            flist << "\n\n\n";
            cout << "\n\nWszystko zostalo zapisane do pliku\n";
            flist.close();
    } else {
        cout << "Blad podczas otwierania pliku!" << endl;
    }
}
////////////////////////////////
///////przed znajdowaniem///////
void Testowanie::PrzedZnajdowaniem(string filename, int wartosc) {
    ofstream file;
    file.open(filename, ios::out | ios::app);
    if(file.is_open()) {
        file << "Testowanie szukania wartosci w strukturze.\n";
        cout << "Testowanie szukania wartosci w strukturze.\n";
        file << "Szukana wartosc: " << wartosc << "\n\n";
        cout << "Szukana wartosc: " << wartosc << "\n\n";
        file << "Indeks szukanej wartosci: ";
        cout << "Indeks szukanej wartosci: ";
        file.close();
    } else {
        cout << "Blad podczas otwierania pliku!" << endl;
    }
}
////////////////////////////////
///////po znajdowaniu///////////
void Testowanie::PoZnajdowaniu(string filename, int indeks) {
    ofstream file;
    file.open(filename, ios::out | ios::app);
    if(file.is_open()) {
        file << indeks << "\n\n\n";
        cout << indeks << "\n\nPlik z ta wiadomoscia zostal utworzony w domyslnym katalogu.\n";
        file.close();
    } else {
        cout << "Blad podczas otwierania pliku!" << endl;
    }
}
////////////////////////////////
//zapisanie do pliku drzewa  przed operacja//
void Testowanie::przedOperacjaDrzewo(string filename) {
    ofstream file;
    file.open(filename, ios::out | ios::app);
    if(file.is_open()) {
        file << "\n\nPrzed operacja\n\n";
	//	drzeworb->print(file);
        cout << "\n\nPrzed operacja\n\n";
		drzeworb->pokaz();
        file.close();
    } else {
        cout << "Blad podczas otwierania pliku!" << endl;
    }
}
////////////////////////////////
//zapisanie do pliku drzewa  po operacji//
void Testowanie::poOperacjiDrzewo(string filename) {
    ofstream file;
    file.open(filename, ios::out | ios::app);
    if(file.is_open()) {
        file << "\n\nPo operacja\n\n";
	    drzeworb->pokaz(file);
        cout << "\n\nPo operacja\n\n";
		drzeworb->pokaz();
        file.close();
    } else {
        cout << "Blad podczas otwierania pliku!" << endl;
    }
}

void Testowanie::ZapiszDoPlikuiEndTimer(double Czas, string Text)
{
Czas =0;
Czas = czas->endTimer();
cout<<Text<<Czas<<endl;
CzasPlik("CzasPlik.txt",Text,Czas);
}
void Testowanie::CzasPlik(string filename,string Text, double Czas)
{
	ofstream file;
    file.open(filename, ios::out | ios::app);
    if(file.is_open()) 
	{
		file << Text << Czas << "\n\n";
	 } else {
        cout << "Blad podczas otwierania pliku!" << endl;
    }
}