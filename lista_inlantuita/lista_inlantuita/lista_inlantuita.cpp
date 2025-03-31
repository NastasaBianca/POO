#include<iostream>
#include<fstream>
using namespace std;

struct Nod 
{
	int valoare;// variabila pentru stocarea valorii nodului
	Nod* urmator;//pointer care ne trimite la urmatorul nod
};

void adaugaNod_inceput(Nod*& cap, int valoare) //adaugam un nou nod la inceputul listei
{
	Nod* nouNod = new Nod;//cream noul nod pe care il adaugam la lista 
	nouNod->valoare = valoare;// ii dam o valoare
	nouNod->urmator = cap;//legatura va duce catre primul nod exist.
	cap = valoare; // actualizam capul listei pentru a trece la urmatorul nod

}
Nod* cap = NULL;

void adaugaNod_final(Nod*& cap, int valoare) 
{
	Nod* nouNod = new Nod;//cream noul nod pe care il adaugam la lista 
	nouNod->valoare = valoare;// ii dam o valoare
	nouNod->urmator = NULL;//legatura este null,fiind ultimul nos din lista  
	
	if (cap == NULL) //daca lista este goala , at oul nod devine primul nod,adica capul listei
	{
		cap = nouNod;
	}
	else
	{
	// daca lista nu este goala, caut ultimul nod si il leg la noul nod
	Nod* temp = cap;            // cream un pointer pentru a naviga prin lista
	while (temp->urmator != NULL)
	{
		temp = temp->urmator;    // Mmerge la urmatorul nod
	}
	temp->urmator = nouNod;     // legam ultimul nod la noul nod
	}
}
void Parcurgere(Nod* cap)
{
	Nod* p = cap;  // incepe de la primul nod
	if (p == NULL)
	{
		cout << "Lista este goala!" << endl;
		return;
	}
	while (p != NULL) 
	{
		cout << p->valoare << " ";  // afisam valoarea nodului curent
		p = p->urmator;  // trecem la urmatorul nod
	}
	cout << endl;
}