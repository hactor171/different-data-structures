#ifndef DRZEWORB_H
#define DRZEWORB_H

#include <string>
#include <fstream>

using namespace std;
struct DrzewoRBWezel
{
  DrzewoRBWezel * gorny;
  DrzewoRBWezel * lewy;
  DrzewoRBWezel * prawy;
  int klucz;
  char kolor;
};
class DrzewoRB
{
    private:
        DrzewoRBWezel wezel;             // Wezel stralnika
        DrzewoRBWezel * korzen;        // Korzen drzewa czerwono-czarnego
        string cr,cl,cp;       // lancuchy do znakow ramek

        void pokazDrzewoRB(string sp, string sn, DrzewoRBWezel * p); // Wypisuje drzewo

    public:
        DrzewoRB();             // Konstruktor klasy
        ~DrzewoRB();            // Destruktor klasy
        void usunDrzewoRB(DrzewoRBWezel * p); // Usuwa rekurencyjnie drzewo
        void pokaz();          // Wypisuje drzewo
        int znajdzDrzewoRB(int k); // Wyszukuje wezel o kluczu k
        DrzewoRBWezel * minRBT(DrzewoRBWezel * p); // Wyszukuje najmniejszywezel w p
        DrzewoRBWezel * nastRBT(DrzewoRBWezel * p);// Wyszukuje nastepnik p
        void rot_L(DrzewoRBWezel * A); // Rotacja w lewo wzgledem A
        void rot_P(DrzewoRBWezel * A); // Rotacja w prawo wzgledem A
        void dodajDrzewoRB(int k);   // Wstawia wezel o kluczu k
        void usunW(DrzewoRBWezel * X); // Usuwa wezel X
        DrzewoRBWezel* getRoot();
        void pokaz(ofstream&);
        void zapisDrzewoRBdoPliku(string, string, DrzewoRBWezel*, ofstream&);
};


#endif