#include <iostream>
#include <string>
using namespace std;

// clasa care reprezinta un loc de parcare
class LocParcare {
protected:
    int numar; // nr loc de parcare
    bool ocupat; // arata daca locul este ocupat
public:
    // folosim un constructor care ii seteaza locului de parcare un nr si il face liber
    LocParcare(int nr) : numar(nr), ocupat(false) {}

    // afis. informatii despre loc
    void afiseazaInformatii() {
        cout << "Loc " << numar << ": " << (ocupat ? "Ocupat" : "Liber") << endl;
    }

    // ocupa locul
    void ocupaLoc() { ocupat = true; }

    // elibereaza locul
    void elibereazaLoc() { ocupat = false; }

    // verifica daca locul este ocupat
    bool esteOcupat() { return ocupat; }

    // returneaza numarul locului de parcare
    int getNumar() { return numar; }
};

// clasa care reprezinta o masina
class Masina {
private:
    string nr_masina; 
    int ora_int, minut_int; 
    double tarif_ora; 
    LocParcare* loc; //pointerul este folosit pentru a indica locul de parcare ocupat de masina

public:
    // constructor
    Masina(string nr, double tarif, LocParcare* locParcare)
        : nr_masina(nr), tarif_ora(tarif), loc(locParcare) {
    }

    //  intrarea in parcare
    void intrare_parcare(int ora, int minut) {
        if (!loc->esteOcupat()) { // verifica daca locul e liber
            ora_int = ora;
            minut_int= minut;
            loc->ocupaLoc(); // ocupa locul
            cout << "Masina " << nr_masina << " a intrat la " << ora << ":" << minut
                << " pe locul " << loc->getNumar() << endl;
        }
        else {
            cout << "Locul " << loc->getNumar() << " este ocupat" << endl;
        }
    }

    //  iesirea din parcare
    void iesire_parcare(int ora, int minut) {
        if (loc->esteOcupat()) { // verifica daca locul e ocupat
            double ore = (ora - ora_int) + (minut - minut_int) / 60.0; // calculeaza cat timp a stat masina
            double cost = ore * tarif_ora; // calculeaza costul
            cout << "Masina " << nr_masina << " a iesit de pe locul " << loc->getNumar()
                << ".Cost: " << cost << " lei" << endl;
            loc->elibereazaLoc(); // elibereaza locul
        }
        else {
            cout << "Masina nu se afla pe locul " << loc->getNumar() << endl;
        }
    }

    // afiseaza informatiile locului ocupat de masina
    void afiseaza_stare_loc() {
        loc->afiseazaInformatii();
    }
};

int main() {
    // creare locuri de parcare
    LocParcare loc1(1), loc2(2);

    // creare masini si asociere cu locuri de parcare
    Masina masina1("BC-27-NSE", 10, &loc1);
    Masina masina2("BC-22-NSB", 15, &loc2);

    // afisare informatii initiale
    cout << "Stare initiala a locurilor de parcare:" << endl;
    loc1.afiseazaInformatii();
    loc2.afiseazaInformatii();

    // masinile intra in parcare
    masina1.intrare_parcare(10, 30);
    masina2.intrare_parcare(11, 00);

    // afisare dupa intrarea masinilor
    cout << "Dupa intrarea masinilor:" << endl;
    masina1.afiseaza_stare_loc();
    masina2.afiseaza_stare_loc();

    // masinile ies din parcare
    masina1.iesire_parcare(12, 45);
    masina2.iesire_parcare(13, 15);

    // afisare dupa iesirea masinilor
    cout << "Dupa iesirea masinilor:" << endl;
    masina1.afiseaza_stare_loc();
    masina2.afiseaza_stare_loc();

    return 0;
}
