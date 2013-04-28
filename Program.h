#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

class Program
{
public:
  Program();
	~Program();
	void NacteniSouboru(string nazev);	//nacte z txt souboru do retezce a rozdeli na slova
	void RozdeleniNaSlova();			//rozdeli retezec na slova
	int CelkemSlov();					//pocet slov v textu
	void VypisSlov();	////
	double EntropieCelkem();
protected:
	void Realokace();
	int size;			//velikost pole
	int maxsize;		//max velikost pole
	int j;				//index pole na ktery se ma vlozit nove slovo
	int celkovypocetslov;	//pocet slov v souboru
	string text;		//nacteny retezec textu ze souboru txt
	string * pole;		//pole jednotlivych slov
	static double celkovaentropie;
};

