#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Aceasta este calasa de baza din care vom face mostenirea
class Animal {
protected: //in interiorul aceleași clase
           //in clasele care deriva din aceasta(clasele care mostenesc clasa respectiva)
           // nu vor fi accesibile din afara clasei sau din obiectele externe
    string nume;//stocarea numelui
    int varsta;// stocarea varstei
    string habitat;// stocarea locului in care traieste
    float greutate;// stocarea greutatii

public://pot fi accesate si din afara clasei
    // Constructorul este o functie care este apelata automat atunci cand este creat un oboect al acestei clasei
    Animal(string n, int v, string h, float g) : nume(n), varsta(v), habitat(h), greutate(g) {}
    
    // Destructorul este o funcție care se apelează automat atunci când un obiect este distrus sau dispare
    virtual ~Animal() {}
    
    // Funcție virtuala pentru afisarea detaliilor (va fi suprascrisa în clasele derivate)
    virtual void afisare() const {
        cout << "Nume: " << nume << "Varsta: " << varsta << "Habitat: " << habitat << "Greutate: " << greutate << " kg";
    }
};

// Clasa derivata - Pasare mostenita de la clasa Animal
class Pasare : public Animal {
private:
    float lungime_aripi;//stocheaza lungimea aripilor
    bool poate_zbura;  // indica daca pasarea poate zbura (true = da, false = nu)

public:
    // Constructorul clasei Pasare care intializeaza atributele
    // Folosim lista de initializare pentru a apela constructorul clasei parinte Animal
    Pasare(string n, int v, string h, float g, float a, bool p) : Animal(n, v, h, g), lungime_aripi(a), poate_zbura(p) {}
    // Constructorul clasei Pasare init. atat atributele mostenite de la Animal,cat si atributele specifice acestei clase 

    // Functia de afisare a informatiilor despre pasare
    void afisare() const  {
        cout << " Pasare ";
        Animal::afisare();
        cout << "Lungime aripi: " << lungime_aripi << " m\nPoate zbura: " << (poate_zbura ? "Da" : "Nu") << "\n";
    }
};

// Clasa derivată - Caine
class Caine : public Animal {
private:
    string rasa;
    string abilitate_speciala;

public:
    Caine(string n, int v, string h, float g, string r, string a) : Animal(n, v, h, g), rasa(r), abilitate_speciala(a) {}
    
    void afisare() const {
        cout << " Caine ";
        Animal::afisare();
        cout << "Rasa: " << rasa << "\nAbilitate speciala: " << abilitate_speciala << "\n";
    }
};

// Funcție pentru afișarea meniului
void meniu() {
    cout << "Adauga pasare\n";
    cout << "Adauga caine\n";
    cout << "Afiseaza toate animalele\n";
    cout << "Iesire\n";
}

int main() {
    vector<Animal*> gradina_zoologica; // Vector de pointeri la obiecte de tip Animal
    int optiune;

    while (true) {  // bucla infinita, controlata cu "break"
        meniu();
        cout << "Alege o optiune: ";
        cin >> optiune;

        if (optiune == 1) {  // Adăugare pasăre
            string nume, habitat;
            int varsta;
            float greutate, lungime_aripi;
            bool poate_zbura;

            cout << "Nume pasare: ";
            cin >> nume;
            cout << "Varsta: ";
            cin >> varsta;
            cout << "Habitat: ";
            cin >> habitat;
            cout << "Greutate (kg): ";
            cin >> greutate;
            cout << "Anvergura aripilor (m): ";
            cin >> lungime_aripi;
            cout << "Poate zbura? (1=Da, 0=Nu): ";
            cin >> poate_zbura;

            gradina_zoologica.push_back(new Pasare(nume, varsta, habitat, greutate, lungime_aripi, poate_zbura));
        }
        else if (optiune == 2) {  // Adaugare caine
            string nume, habitat, rasa, abilitate_speciala;
            int varsta;
            float greutate;

            cout << "Nume caine: ";
            cin >> nume;
            cout << "Varsta: ";
            cin >> varsta;
            cout << "Habitat: ";
            cin >> habitat;
            cout << "Greutate (kg): ";
            cin >> greutate;
            cout << "Rasa: ";
            cin >> rasa;
            cout << "Abilitate speciala: ";
            cin >> abilitate_speciala;

            gradina_zoologica.push_back(new Caine(nume, varsta, habitat, greutate, rasa, abilitate_speciala));
        }
        else if (optiune == 3) {  // Afisare animale
            if (gradina_zoologica.empty()) {
                cout << "Nu sunt animale in gradina zoologica!\n";
            } else {
                cout << "\n=== Animalele din gradina zoologica ===\n";
                for (Animal* animal : gradina_zoologica) {
                    animal->afisare();
                }
            }
        }
        else if (optiune == 4) {  // Iesire din program
            cout << "Iesire din program.\n";
            break; // Iesire din bucla
        }
        else {
            cout << "Optiune invalida!";
        }
    }

    // Eliberare memorie (stergem obiectele create )
    for (Animal* animal : gradina_zoologica) {
        delete animal;
    }
    
    return 0;
}
