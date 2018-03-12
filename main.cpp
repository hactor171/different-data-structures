#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <fstream>
#include <time.h>
#include <chrono>
#include <windows.h>

#include "Lista.h"
#include "DynTab.h"
#include "Kopiec.h"
#include "Testowanie.h"
#include "Generator.h"

#include "DrzewoRB.h"

using namespace std;



int main()
{
    char w;
	bool a,b,c,d,e,f,g,z;
	a=b=c=d=e=f=g=z=true;
    Testowanie *st = new Testowanie();
	Generator *gen = new Generator();
	
	
	

    while (a) {
        b=c=d=e=f=g=z=true;
        cout << "\n== Menu Glowne ==\n"<<endl;
        cout << "Wybierz:"<<endl;
		cout<<"-1- Testowanie list"<<endl;
		cout<<"-2- Testowanie tablicy"<<endl;
		cout<<"-3- Testowanie kopcu"<<endl;
		cout<<"-4- Testowanie drzewa 'REDBLACK'"<<endl;
		cout<<"-5- Zgeneruj plik z liczbami"<<endl;
		cout<<"-6- Zakonc program"<<endl;
        cout << "\n>>>: ";
        cin >> w;
        system("cls");
        switch(w) {
        case '1' : {
            while(b) {
                cout << "\n<<Praca z lista>>\n" << endl;
                cout << "Wybierz opcje:"<<endl;
                cout<<"-1- Wczytanie wartosci z pliku:"<<endl;
				cout<<"-2- Dodawanie na poczatek listy:"<<endl;
				cout<<"-3- Dodawanie do listy w wybranym miejscu:"<<endl;
				cout<<"-4- Dodawanie na koniec listy:"<<endl;
				cout<<"-5- Wyszukaj wartosc w liscie:"<<endl;
				cout<<"-6- Usuwanie elementu z poczatku listy:"<<endl;
				cout<<"-7- Usuwanie elementu z wybranego miejsca w liscie:"<<endl;
				cout<<"-8- Usuwanie elementu z konca listy:"<<endl;
				cout<<"-9- Pokaz liste:"<<endl;
				cout<<"\n-a- Powrot do ==Menu Glowne==\n"<<endl;
				cout << "\n>>>: ";
				
				cin >> w;
                system("cls");
                switch(w) {
                case '1' : {
                    string file;
                    cout << "Wpisz nazwe pliku: "<<endl;
					cout<<">>>:";
                    cin.ignore();
                    getline(cin, file);
                    st->OdczytajWartosciZPliku(file);
                    st->pokazListe();
                    break;
                } case '2' : {
                    int value;
                    cout << "Wpisz wartosc: "<<endl;
					cout<<">>>:";
                    cin.ignore();
                    cin >> value;
                    st->DodajDoListyP(value);
                    break;
                } case '3' : {
                    int value, index;
                    cout << "Wpisz wartosc: "<<endl;
					cout<<">>>:";
                    cin.ignore();
                    cin >> value;
                    cin.ignore();
                    cout << "Wpisz index: "<<endl;
					cout<<">>>:";
                    cin >> index;
                    st->DodajDoListyM(value, index);
                    break;
                } case '4' : {
                    int value;
                    cout << "Wpisz wartosc: "<<endl;
					cout<<">>>:";
                    cin.ignore();
                    cin >> value;
                    st->DodajDoListyK(value);
                    break;
                } case '5' : {
                    int value;
                    cout << "Wpisz wartosc: "<<endl;
					cout<<">>>:";
                    cin.ignore();
                    cin >> value;
                    st->ZnajdzWLiscie(value);
                    break;
                } case '6' : {
                    st->UsunPierwszyELemListy();
                    break;
                } case '7' : {
                    int value;
                    cout << "Wpisz index: "<<endl;
					cout<<">>>:";
                    cin.ignore();
                    cin >> value;
                    st->UsunWMiejscuListy(value);
                    break;
                } case '8' : {
                    st->UsunOstatniElemListy();
                    break;
                } case '9' : {
                    st->pokazListe();
                    break;
                } case 'a' : {
                    b = false;
                    break;
                }
                }
            } 
            break;
        } 
        case '2' : {
            while(c) {
                cout << "\n<<Praca z tablica>>\n" << endl;
                cout << "Wybierz opcje:"<<endl;
                cout<<"-1- Wczytanie wartosci z pliku:"<<endl;
				cout<<"-2- Dodawanie na poczatek tablicy:"<<endl;
				cout<<"-3- Dodawanie do tablicy w wybranym miejscu:"<<endl;
				cout<<"-4- Dodawanie na koniec tablicy:"<<endl;
				cout<<"-5- Wyszukaj wartosc w tablice:"<<endl;
				cout<<"-6- Usuwanie elementu z poczatku tablicy:"<<endl;
				cout<<"-7- Usuwanie elementu z wybranego miejsca w tablice:"<<endl;
				cout<<"-8- Usuwanie elementu z konca tablicy:"<<endl;
				cout<<"-9- Pokaz tablice:"<<endl;
				cout<<"\n-a- Powrot do ==Menu Glowne==\n"<<endl;
				cout << "\n>>>: ";

				cin>>w;
                system("cls");
                switch(w) {
                case '1' : {
                    string file;
                    cout << "Wpisz nazwe pliku: "<<endl;
					cout<<">>>:";
                    cin.ignore();
                    getline(cin, file);
                    st->OdczytajWartosciZPliku(file);
                    st->pokazTablice();
                    break;
                } case '2' : {
                    int value;
                    cout << "Wpisz wartosc: "<<endl;
					cout<<">>>:";
                    cin.ignore();
                    cin >> value;
                    st->DodajDoTablicyP(value);
                    break;
                } case '3' : {
                    int value, index;
                    cout << "Wpisz wartosc: "<<endl;
					cout<<">>>:";
                    cin.ignore();
                    cin >> value;
                    cin.ignore();
                    cout << "Wpisz index: "<<endl;
					cout<<">>>:";
                    cin >> index;
                    st->DodajDoTablicyM(value, index);

                    break;
                } case '4' : {
                    int value;
                    cout << "Wpisz wartosc: "<<endl;
					cout<<">>>:";
                    cin.ignore();
                    cin >> value;
                    st->DodajDoTablicyK(value);
                    break;
                } case '5' : {
                    int value;
                    cout << "Wpisz wartosc: "<<endl;
					cout<<">>>:";
                    cin.ignore();
                    cin >> value;
                    st->ZnajdzWTabblice(value);
                    break;
                } case '6' : {
                    st->UsunPierwszyELemTablicy();
                    break;
                } case '7' : {
                    int value;
                    cout << "Wpisz index: "<<endl;
					cout<<">>>:";
                    cin.ignore();
                    cin >> value;
                    st->UsunWMiejscuTablicy(value);
                    break;
                } case '8' : {
                    st->UsunOstatniElemTablicy();
                    break;
                } case '9' : {
                    st->pokazTablice();
                    break;
                } case 'a' : {
                    c = false;
                    break;
                }
                }
            }
            break;
        }
        case '3' : {
            while(d) {
                
			    cout << "\n<<Praca z kopcem>>\n" << endl;
                cout << "Wybierz opcje:"<<endl;
                cout<<"-1- Wczytanie wartosci z pliku:"<<endl;
				cout<<"-2- Dodawanie do element do kopcu:"<<endl;
				cout<<"-3- Wyszukaj wartosc w kopcu:"<<endl;
				cout<<"-4- Usuwanie elementu z kopcu:"<<endl;
				cout<<"-5- Pokaz kopiec:"<<endl;
				cout<<"\n-a- Powrot do ==Menu Glowne==\n"<<endl;
				cout << "\n>>>: ";

				cin>>w;
                system("cls");

                switch(w) {
                case '1' : {
                    string file;
                    cout << "Wpisz nazwe pliku: "<<endl;
					cout<<">>>:";
                    cin.ignore();
                    getline(cin, file);
                    st->OdczytajWartosciZPliku(file);
                    st->pokazKopiec();
                    break;
                } case '2' : {
                    int value;
                    cout << "Wpisz wartosc: "<<endl;
					cout<<">>>:";
                    cin.ignore();
                    cin >> value;
                    st->DodajDoKopcu(value);
                    break;
                } case '3' : {
                    int value;
                    cout << "Wpisz wartosc: "<<endl;
					cout<<">>>:";
                    cin.ignore();
                    cin >> value;
                    st->ZnajdzWKopcu(value);
                    break;
                } case '4' : {
                    st-> UsunZKopcu();
                    break;
                }  case '5' : {
                    st->pokazKopiec();
                    break;
                } case 'a' : {
                    d = false;
                    break;
                }
                }
            }
            break;
        }
        case '4' : {
            while(e) {
                cout << "\n<<Praca z drzewem>>\n" << endl;
                cout << "Wybierz opcje:"<<endl;
                cout<<"-1- Wczytanie wartosci z pliku:"<<endl;
				cout<<"-2- Dodawanie do element do drzewa:"<<endl;
				cout<<"-3- Wyszukaj wartosc w drzewie:"<<endl;
				cout<<"-4- Usuwanie elementu z drzewa:"<<endl;
				cout<<"-5- Pokaz drzewo:"<<endl;
				cout<<"\n-a- Powrot do ==Menu Glowne==\n"<<endl;
				cout << "\n>>>: ";

				cin>>w;
                system("cls");
                switch(w) {
                case '1' : {
                    string file;
                    cout << "Wpisz nazwe pliku: "<<endl;
					cout<<">>>:";
                    cin.ignore();
                    getline(cin, file);
                    st->OdczytajWartosciZPliku(file);
                    st->pokazDrzewo();
                    break;
                } case '2' : {
                    int value;
                    cout << "Wpisz wartosc: "<<endl;
					cout<<">>>:";
                    cin.ignore();
                    cin >> value;
                    st->DodajDoDrzewa(value);
                    break;
                } case '3' : {
                    int value;
                    cout << "Wpisz wartosc: "<<endl;
					cout<<">>>:";
                    cin.ignore();
                    cin >> value;
                    st-> ZnajdzWDrzewie(value);
                    break;
                } case '4' : {
                    st->UsunZDrzewa();
                    break;
                }  case '5' : {
                    st->pokazDrzewo();
                    break;
                } case 'a' : {
                    e = false;
                    break;
                }
                }
            }
            break;
        }
        
        case '5' : {
			int n;
			string filename;
			cout<<"Wpisz liczbe:"<<endl;
			cout<<">>>:";
        	cin>>n;
	 		cout<<"Wpisz nazwe pliku:"<<endl;
			cout<<">>>:";
			cin>>filename;
			gen->generate(n, filename);
			cout<<"Plik zostaw stworzony"<<endl;
			break;
			}
     
		case '6' :{
		    a=false;
            break;
			}
        }

    }

}


