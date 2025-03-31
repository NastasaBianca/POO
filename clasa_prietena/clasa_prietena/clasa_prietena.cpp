#include <iostream>
#include <string>
using namespace std;
//Clasa principala
class Persoana {
protected:
    string nume;
    int varsta;

public:
    Persoana(string nume, int varsta)
    {
#
        this->nume = nume;
        this->varsta = varsta;

    }
    void afiseazaInformatii()
    {
        cout << "Nume: " << nume << "Varsta: " << varsta << endl;
    }

    string Getnume()const {
        return nume;
    }

    int Getvarsta()const {
        return varsta;
    }
};
//clasa derivata student
class Student : public Persoana {
private:
    float medie;
    //clasa prietena
    friend class Admin;
public:
    Student(string nume, int varsta, float medie) : Persoana(nume, varsta)
    {
#
        this->medie = medie;

    }
    void afiseazaInformatii()
    {
        cout << "Nume: " << nume << "Varsta: " << varsta << "Medie: " << medie << endl;
    }
    //Suprascriere operatorului
    bool operator>(const Student& celalalt_obiect) const {
        return this->medie > celalalt_obiect.medie;
    }
};
//folosim "&" inseamna ca lucram cu o referinta adica un alias pentru o variabila existenta,NU E COPIE
class Admin {
public:
    void modificaMedie(Student& s, float nouaMedie)
    {
        cout << "Modific media pentru: " << s.nume << "de la" << s.medie << "la" << nouaMedie << endl;
        s.medie = nouaMedie;
    }
    void afiseazaDetaliiStudent(const Student& s) {
        cout << "Admin -> Student" << s.nume << ",Varsta: " << s.varsta << ",Medie: " << s.medie << endl;

    }
};
int main()
{
    //cream 2 obiecte
    Student s1("Gabi ", 18, 10);
    Student s2("Claudiu ", 24, 4);
    //Afisam informatii despre obiecte
    s1.afiseazaInformatii();
    s2.afiseazaInformatii();
    //adminul modifica media
    Admin admin;
    admin.modificaMedie(s2, 2);
    admin.afiseazaDetaliiStudent(s2);
    //Verificam 
    //*if (s1 > s2)
    {
        cout << s1.Getnume() << " are media mai mare decat" << s2.Getnume() << endl;
    }
    else
    {
        cout << s2.Getnume() << " are media mai mare decat" << s1.Getnume() << endl;
    }

}