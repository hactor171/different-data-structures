#include "DrzewoRB.h"

#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <sstream>

using namespace std;

// Konstruktor drzewa
DrzewoRB::DrzewoRB()
{
  cr = cl = cp = "  ";
  cr[0] = 218; cr[1] = 196;
  cl[0] = 192; cl[1] = 196;
  cp[0] = 179;
  wezel.kolor = 'B';          // Inicjujemy stralnika
  wezel.gorny    = &wezel;
  wezel.lewy  = &wezel;
  wezel.prawy = &wezel;
  korzen    = &wezel;           // Korzen wskazuje stralnika
}

// Destruktor drzewa
DrzewoRB::~DrzewoRB()
{
  usunDrzewoRB(korzen);       //usuwamy wezly
}

// Usuwa rekurencyjnie drzewo czerwono-czarne
void DrzewoRB::usunDrzewoRB(DrzewoRBWezel * p)
{
  if(p != &wezel)
  {
    usunDrzewoRB(p->lewy);   // usuwamy lewe poddrzewo
    usunDrzewoRB(p->prawy);  // usuwamy prawe poddrzewo
    delete p;              // usuwamy sam wezel
  }
}

// Wypisuje zawartosc drzewa
void DrzewoRB::pokazDrzewoRB(string sp, string sn, DrzewoRBWezel * p)
{
  string t;

  if(p != &wezel)
  {
    t = sp;
    if(sn == cr) t[t.length() - 2] = ' ';
    pokazDrzewoRB(t+cp,cr,p->prawy);

    t = t.substr(0,sp.length()-2);
    cout << t << sn << p->kolor << ":" << p->klucz << endl;

    t = sp;
    if(sn == cl) t[t.length() - 2] = ' ';
    pokazDrzewoRB(t+cp,cl,p->lewy);
  }
}

void DrzewoRB::zapisDrzewoRBdoPliku(string sp, string sn, DrzewoRBWezel * p, ofstream &str)
{
  string t;

  if(p != &wezel)
  {
    t = sp;
	if(sn == cr) t[t.length() - 2] = ' ';
    zapisDrzewoRBdoPliku(t+cp,cr,p->prawy, str);

    t = t.substr(0,sp.length()-2);
    str << t << sn << p->kolor << ":" << p->klucz << endl;

    t = sp;
    if(sn == cl) t[t.length() - 2] = ' ';
    zapisDrzewoRBdoPliku(t+cp,cl,p->lewy, str);
  }
}

DrzewoRBWezel* DrzewoRB::getRoot() {return korzen;}

// Wypisuje zawartosc drzewa
void DrzewoRB::pokaz()
{
 
  pokazDrzewoRB("","",korzen);
}

void DrzewoRB::pokaz(ofstream &str) {
    zapisDrzewoRBdoPliku("","",korzen,str);
}

// Wyszukuje wezel o kluczu k
// Jesli wezel nie zostanie znaleziony, to zwraca
// wskazanie puste
int DrzewoRB::znajdzDrzewoRB(int k)
{
  DrzewoRBWezel * p;

  p = korzen;
  while((p != &wezel) && (p->klucz != k))
    if(k < p->klucz) p = p->lewy;
    else           p = p->prawy;
  if(p == &wezel) return NULL;
  return p->klucz;
}

// Wyszukuje najmniejszy wêze³ w poddrzewie
// o korzeniu p
DrzewoRBWezel * DrzewoRB::minRBT(DrzewoRBWezel * p)
{
  if(p != &wezel)
    while(p->lewy != &wezel) p = p->lewy;
  return p;
}

// Zwraca nastêpnik p
DrzewoRBWezel * DrzewoRB::nastRBT(DrzewoRBWezel * p)
{
  DrzewoRBWezel * r;

  if(p != &wezel)
  {
    if(p->prawy != &wezel) return minRBT(p->prawy);
    else
    {
      r = p->gorny;
      while((r != &wezel) && (p == r->prawy))
      {
        p = r;
        r = r->gorny;
      }
      return r;
    }
  }
  return &wezel;
}

// Wykonuje rotacje w lewo wzgledem A
void DrzewoRB::rot_L(DrzewoRBWezel * A)
{
  DrzewoRBWezel * B, * p;

  B = A->prawy;
  if(B != &wezel)
  {
    p = A->gorny;
    A->prawy = B->lewy;
    if(A->prawy != &wezel) A->prawy->gorny = A;

    B->lewy = A;
    B->gorny = p;
    A->gorny = B;

    if(p != &wezel)
    {
      if(p->lewy == A) p->lewy = B; else p->prawy = B;
    }
    else korzen = B;
  }
}

// Wykonuje rotacje w prawo wzgledem A
void DrzewoRB::rot_P(DrzewoRBWezel * A)
{
  DrzewoRBWezel * B, * p;

  B = A->lewy;
  if(B != &wezel)
  {
    p = A->gorny;
    A->lewy = B->prawy;
    if(A->lewy != &wezel) A->lewy->gorny = A;

    B->prawy = A;
    B->gorny = p;
    A->gorny = B;

    if(p != &wezel)
    {
      if(p->lewy == A) p->lewy = B; else p->prawy = B;
    }
    else korzen = B;
  }
}

// Wstawia do drzewa wezel o kluczu k
void DrzewoRB::dodajDrzewoRB(int k)
{
  DrzewoRBWezel * X, * Y;

  X = new DrzewoRBWezel;        // Tworzymy nowy wezel
  X->lewy  = &wezel;          // Inicjujemy pola
  X->prawy = &wezel;
  X->gorny    = korzen;
  X->klucz   = k;
  if(X->gorny == &wezel) korzen = X; // X staje sie korzeniem
  else
  while(true)             // Szukamy zastopenia przez X
  {
    if(k < X->gorny->klucz)
    {
      if(X->gorny->lewy == &wezel)
      {
        X->gorny->lewy = X;  // X zastepuje lewy lisc
        break;
      }
      X->gorny = X->gorny->lewy;
    }
    else
    {
      if(X->gorny->prawy == &wezel)
      {
        X->gorny->prawy = X; // X zastepuje prawy lisc
        break;
      }
      X->gorny = X->gorny->prawy;
    }
  }
  X->kolor = 'R';         // Wezly kolorujemy na czerwono
  while((X != korzen) && (X->gorny->kolor == 'R'))
  {
    if(X->gorny == X->gorny->gorny->lewy)
    {
      Y = X->gorny->gorny->prawy; // Y -> wujek X

      if(Y->kolor == 'R')  // Przypadek 1
      {
        X->gorny->kolor = 'B';
        Y->kolor = 'B';
        X->gorny->gorny->kolor = 'R';
        X = X->gorny->gorny;
        continue;
      }

      if(X == X->gorny->prawy) // Przypadek 2
      {
        X = X->gorny;
        rot_L(X);
      }

      X->gorny->kolor = 'B'; // Przypadek 3
      X->gorny->gorny->kolor = 'R';
      rot_P(X->gorny->gorny);
      break;
    }
    else
    {                  // Przypadki lustrzane
      Y = X->gorny->gorny->lewy;

      if(Y->kolor == 'R') // Przypadek 1
      {
        X->gorny->kolor = 'B';
        Y->kolor = 'B';
        X->gorny->gorny->kolor = 'R';
        X = X->gorny->gorny;
        continue;
      }

      if(X == X->gorny->lewy) // Przypadek 2
      {
        X = X->gorny;
        rot_P(X);
      }

      X->gorny->kolor = 'B'; // Przypadek 3
      X->gorny->gorny->kolor = 'R';
      rot_L(X->gorny->gorny);
      break;
    }
  }
  korzen->kolor = 'B';
}

// Usuwa z drzewa wezel X
void DrzewoRB::usunW(DrzewoRBWezel * X)
{
  DrzewoRBWezel * W, * Y, * Z;

  if((X->lewy == &wezel) || (X->prawy == &wezel)) Y = X;
  else                                   
	  Y = nastRBT(X);

  if(Y->lewy != &wezel) Z = Y->lewy;
  else              Z = Y->prawy;

  Z->gorny = Y->gorny;

  if(Y->gorny == &wezel) korzen = Z;
  else if(Y == Y->gorny->lewy) Y->gorny->lewy  = Z;
  else                      Y->gorny->prawy = Z;

  if(Y != X) X->klucz = Y->klucz;

  if(Y->kolor == 'B')   // Naprawa struktury drzewa czerwono-czarnego
    while((Z != korzen) && (Z->kolor == 'B'))
      if(Z == Z->gorny->lewy)
      {
        W = Z->gorny->prawy;

        if(W->kolor == 'R')
        {              // Przypadek 1
          W->kolor = 'B';
          Z->gorny->kolor = 'R';
          rot_L(Z->gorny);
          W = Z->gorny->prawy;
        }

        if((W->lewy->kolor == 'B') && (W->prawy->kolor == 'B'))
        {              // Przypadek 2
          W->kolor = 'R';
          Z = Z->gorny;
          continue;
        }

        if(W->prawy->kolor == 'B')
        {              // Przypadek 3
          W->lewy->kolor = 'B';
          W->kolor = 'R';
          rot_P(W);
          W = Z->gorny->prawy;
        }

        W->kolor = Z->gorny->kolor; // Przypadek 4
        Z->gorny->kolor = 'B';
        W->prawy->kolor = 'B';
        rot_L(Z->gorny);
        Z = korzen;         // To spowoduje zakonczenie petli
      }
      else
      {                // Przypadki lustrzane
        W = Z->gorny->lewy;

        if(W->kolor == 'R')
        {              // Przypadek 1
          W->kolor = 'B';
          Z->gorny->kolor = 'R';
          rot_P(Z->gorny);
          W = Z->gorny->lewy;
        }

        if((W->lewy->kolor == 'B') && (W->prawy->kolor == 'B'))
        {              // Przypadek 2
          W->kolor = 'R';
          Z = Z->gorny;
          continue;
        }

        if(W->lewy->kolor == 'B')
        {              // Przypadek 3
          W->prawy->kolor = 'B';
          W->kolor = 'R';
          rot_L(W);
          W = Z->gorny->lewy;
        }

        W->kolor = Z->gorny->kolor;  // Przypadek 4
        Z->gorny->kolor = 'B';
        W->lewy->kolor = 'B';
        rot_P(Z->gorny);
        Z = korzen;         // To spowoduje zakonczenie petli
      }

  Z->kolor = 'B';

  delete Y;
}
