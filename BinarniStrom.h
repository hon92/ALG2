#pragma once
#include "program.h"

struct Uzel
  {
	
	string slovo;
	int cetnost;
	Uzel * levy;
	Uzel * pravy;
	};

class BinarniStrom :public Program
{
public:
	BinarniStrom();
	~BinarniStrom();
	void Add(string);		//prida uzel do stromu
	bool Find(string);		//vyhleda uzel stromu
	void Print();			//vypise strom
	void VlozeniSlovdoStromu();	//vlozi slovo do stromu
	void PrintItem(Uzel *p);

private:
	void insert(Uzel *&koren, string);	//rekurzivni vkladani uzlu
	bool search(Uzel * koren, string);	//rekurzivni hledani uzlu
	void report(Uzel * koren);			//inorder - rekurzivni vypis
	void smazanistromu(Uzel *p);		//postorder - rekurzivni smazani uzlu
	Uzel * root;	//koren
};

