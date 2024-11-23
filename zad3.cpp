#include <iostream>
#include <string>
using namespace std;

// Klasa bazowa PracownikSzkoly z enkapsulacją
class PracownikSzkoly {
private:
    // Pola prywatne
    string imie;
    string nazwisko;
    int wiek;

public:
    // Konstruktor parametryczny
    PracownikSzkoly(string i, string n, int w) : imie(i), nazwisko(n), wiek(w) {}

    // Gettery
    string getImie() const { return imie; }
    string getNazwisko() const { return nazwisko; }
    int getWiek() const { return wiek; }

    // Settery
    void setImie(const string& i) { imie = i; }
    void setNazwisko(const string& n) { nazwisko = n; }
    void setWiek(int w) { wiek = w; }

    // Wirtualna metoda do wyświetlania danych  (virtual pozwala na nadpisanie metody przez klasy dziedziczace)
    virtual void wyswietl() const {     //  użycie const, co oznacza, że metoda nie modyfikuje stanu obiektu 
        cout << "Imię: " << imie << ", Nazwisko: " << nazwisko << ", Wiek: " << wiek << endl;
    }
};

// Klasa pochodna Dyrektor
class Dyrektor : public PracownikSzkoly {
public:
    Dyrektor(string i, string n, int w) : PracownikSzkoly(i, n, w) {}

    void wyswietl() const override {    // dopisanie override -> nadpisanie metody "wyswietl" dziedziczonej
        cout << "Dyrektor - ";
        PracownikSzkoly::wyswietl();
    }
};

// Klasa pochodna Nauczyciel
class Nauczyciel : public PracownikSzkoly {
public:
    Nauczyciel(string i, string n, int w) : PracownikSzkoly(i, n, w) {}

    void wyswietl() const override {
        cout << "Nauczyciel - ";
        PracownikSzkoly::wyswietl();
    }
};

// Klasa pochodna Wychowawca
class Wychowawca : public PracownikSzkoly {
public:
    Wychowawca(string i, string n, int w) : PracownikSzkoly(i, n, w) {}

    void wyswietl() const override {
        cout << "Wychowawca - ";
        PracownikSzkoly::wyswietl();
    }
};

// Klasa pochodna Sekretarka
class Sekretarka : public PracownikSzkoly {
public:
    Sekretarka(string i, string n, int w) : PracownikSzkoly(i, n, w) {}

    void wyswietl() const override {
        cout << "Sekretarka - ";
        PracownikSzkoly::wyswietl();
    }
};

int main() {
    // Wprowadzenie danych wychowawcy z klawiatury
    string imie, nazwisko;
    int wiek;

    cout << "Wprowadz imię wychowawcy: ";
    cin >> imie;
    cout << "Wprowadz nazwisko wychowawcy: ";
    cin >> nazwisko;
    cout << "Wprowadz wiek wychowawcy: ";
    cin >> wiek;

    // Tworzenie obiektów różnych pracowników
    Dyrektor dyrektor("Jan", "Kowalski", 50);
    Nauczyciel nauczyciel("Anna", "Nowak", 35);
    Wychowawca wychowawca(imie, nazwisko, wiek);
    Sekretarka sekretarka("Maria", "Jankowska", 30);

    // Wyświetlanie danych
    dyrektor.wyswietl();
    nauczyciel.wyswietl();
    wychowawca.wyswietl();
    sekretarka.wyswietl();

    // Modyfikacja danych sekretarki za pomocą setterów
    sekretarka.setImie("Ewa");
    sekretarka.setNazwisko("Kowalska");
    sekretarka.setWiek(42);

    cout << "\nPo zmianie danych sekretarki:\n";
    sekretarka.wyswietl();

    return 0;
}
