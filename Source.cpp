#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include "Program.h"
#include "BinarniStrom.h"
#include <vld.h>
using namespace std;

void Rozhrani(BinarniStrom & s);

int main()
{
  
	BinarniStrom ALG;
	string nazev;
	cout<<"Zadejte nazev souboru: ";
	cin>>nazev;

	ALG.NacteniSouboru(nazev);
	ALG.RozdeleniNaSlova();
	ALG.VlozeniSlovdoStromu();
	Rozhrani(ALG);
	
	
	return 0;
}

void Rozhrani(BinarniStrom & s)
{
	cout<<"Slovo"<<setw(15)<<"Cetnost"<<setw(15)<<"Entropie"<<endl;
	cout<<"------------------------------------"<<endl;
	s.Print();
	cout<<"------------------------------------"<<endl;
	cout<<"Celkova entropie: "<<s.EntropieCelkem()<<endl;
}
