#include "BinarniStrom.h"
#include <iomanip>

BinarniStrom::BinarniStrom()
{
  root=NULL;
}
BinarniStrom::~BinarniStrom()
{
	smazanistromu(root);
}
void BinarniStrom::insert(Uzel *&koren, string s)
{
	if(koren==NULL)
	{
		koren=new Uzel;
		koren->slovo=s;
		koren->cetnost=1;
		koren->pravy=NULL;
		koren->levy=NULL;
		return;
	}
	if(s < koren->slovo)
	{
		insert(koren->levy,s);
		return;
	}
	if(s > koren->slovo)
	{
		insert(koren->pravy,s);
		return;
	}
}
bool BinarniStrom::search(Uzel * koren, string s)
{
	if(koren==NULL)
	{
		return false;
	}
	if(koren->slovo==s)
	{
		koren->cetnost++;
		return true;
	}
	if(s < koren->slovo)
	{
		return search(koren->levy,s);
	}
	else
	{
		return search(koren->pravy,s);
	}
}
void BinarniStrom::Add(string s)
{
	insert(root,s);
}
bool BinarniStrom::Find(string s)
{
	return search(root,s);
}
void BinarniStrom::VlozeniSlovdoStromu()
{
	for(int i=0;i<this->celkovypocetslov;i++)
	{
		Find(pole[i]);
		Add(pole[i]);
	}
	
}
void BinarniStrom::Print()
{
	report(root);
}
void BinarniStrom::report(Uzel * koren)
{
	if(koren!=NULL)
	{
		report(koren->levy);
		PrintItem(koren);
		report(koren->pravy);
	}
}
void BinarniStrom::PrintItem(Uzel *p)
{
	if(p->slovo.length()==0)
	{
		return;
	}
	double entropie=0;
	entropie=-(log(p->cetnost/(double)celkovypocetslov)/log(2));
	celkovaentropie+=p->cetnost * entropie;
	cout<<p->slovo<<"\t\t"<<p->cetnost<<"\t\t"<<entropie<<endl;
}
void BinarniStrom::smazanistromu(Uzel *p)
{
	if(p!=NULL)
	{
		smazanistromu(p->pravy);
		smazanistromu(p->levy);
		delete p;
	}
}
