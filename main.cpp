#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

string wyraz;

int ilosc_znakow;

string sortuj(string &linia)
{
    for(int i=0; i<ilosc_znakow-1; i++)
    {
        for(int j=0; j<ilosc_znakow-1; j++)
        {
            if(linia[j]>linia[j+1])
            {
	            char x = linia[j];
	            linia[j] = linia[j+1];
	            linia[j+1] = x;
            }
        }
    }
    return linia;

}
int main()
{
    string linia;
    int nr_linii=1;

    fstream plik;
    plik.open("plik.txt", ios::in);

    if(plik.good()==false) cout<<"Nie mozna otworzyc pliku!";

    while (getline(plik, linia))
    {
        switch (nr_linii)
        {
            case 1: wyraz=linia; break;
        }
        nr_linii++;
    }
    cout<<"wyraz: "<<wyraz<<endl;
    
    ilosc_znakow = wyraz.length();
    
    string &ANAGRAM = wyraz;
    sortuj(ANAGRAM);
	cout<<endl<<wyraz;

    plik.close();

    return 0;
}



