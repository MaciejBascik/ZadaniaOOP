#include <iostream>
#include <string>
using namespace std;

// Klasa bazowa PracownikSzkoly z enkapsulacją (pola prywatne)
class PracownikSzkoly {
private:    
    string imie;
    string nazwisko;
    int wiek;

public:
    PracownikSzkoly(string i, string n, int w) : imie(i), nazwisko(n), wiek(w) {} // lista inicjalizacjyjna -> ma za zadanie inicjalizacje pól w klasie bazowej (ponieważ dziedziczymy inicjalizowane pole, a klasa dziedzicząca nie posiada tych pól.)

    // Gettery
    string getImie() const { return imie; }
    string getNazwisko() const { return nazwisko; }
    int getWiek() const { return wiek; }

    // Settery
    void setImie(const string &i) { imie = i; }
    void setNazwisko(const string &n) { nazwisko = n; }
    void setWiek(int w) { wiek = w; }

    virtual void wyswietl() const {     // dopisanie virtual -> pozwala na nadpisanie działania metody przez inne klasy
    //  użycie const, co oznacza, że metoda nie modyfikuje stanu obiektu 
        cout << "Imię: " << imie << ", Nazwisko: " << nazwisko << ", Wiek: " << wiek << endl;
    }
};

// Klasa pochodna Nauczyciel z dziedziczeniem i enkapsulacją
class Nauczyciel : public PracownikSzkoly {
public:
    Nauczyciel(string i, string n, int w) : PracownikSzkoly(i, n, w) {}

    void wyswietl() const override {    // dopisanie override -> nadpisanie metody "wyswietl" dziedziczonej
        cout << "Nauczyciel - ";
        PracownikSzkoly::wyswietl();
    }
};

int main() {
    Nauczyciel nauczyciel("Anna", "Nowak", 35);
    nauczyciel.wyswietl();

    // Użycie setterów
    nauczyciel.setImie("Ewa");
    nauczyciel.setNazwisko("Kowalska");
    nauczyciel.setWiek(42);
    nauczyciel.wyswietl();

    return 0;
}
