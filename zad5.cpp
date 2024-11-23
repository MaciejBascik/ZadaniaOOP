#include <iostream>
#include <string>
using namespace std;

// Klasa bazowa Pojazd
class Pojazd {
protected:
    string marka;
    string model;
    int rokProdukcji;

public:
    Pojazd(string m, string mo, int r) : marka(m), model(mo), rokProdukcji(r) {}

    virtual void wyswietl() const { // dopisanie virtual -> pozwala na nadpisanie działania metody przez inne klasy
    //  użycie const, co oznacza, że metoda nie modyfikuje stanu obiektu 
        cout << "Marka: " << marka << ", Model: " << model << ", Rok produkcji: " << rokProdukcji << endl;
    }
};

// Klasa pochodna SamochodCiezarowy
class SamochodCiezarowy : public Pojazd {
private:
    string przeznaczenie;

public:
    SamochodCiezarowy(string m, string mo, int r, string p) : Pojazd(m, mo, r), przeznaczenie(p) {} // lista inicjalizacjyjna -> ma za zadanie inicjalizacje pól w klasie bazowej (ponieważ dziedziczymy inicjalizowane pole, a klasa dziedzicząca nie posiada tych pól.)

    void wyswietl() const override {    // dopisanie override -> nadpisanie działania metody z klasy bazowej
        cout << "Samochód ciężarowy - ";
        Pojazd::wyswietl();
        cout << "Przeznaczenie: " << przeznaczenie << endl;
    }
};

// Klasa pochodna Autobus
class Autobus : public Pojazd {
private:
    int miejscaSiedzace;
    int miejscaStojace;

public:
    Autobus(string m, string mo, int r, int ms, int mt) : Pojazd(m, mo, r), miejscaSiedzace(ms), miejscaStojace(mt) {}

    void wyswietl() const override {
        cout << "Autobus - ";
        Pojazd::wyswietl();
        cout << "Miejsca siedzące: " << miejscaSiedzace << ", Miejsca stojące: " << miejscaStojace << endl;
    }
};

int main() {
    // utworzenie obiektów
    string nazwa, marka;
    int rocznik, mst, ms;
    cout << "Podaj nazwe autobusu: ";
    cin >> nazwa;
    cout << "Podaj marka autobusu: ";
    cin >> marka;
    cout << "Podaj rocznik autobusu: ";
    cin >> rocznik;
    cout << "Podaj ilość miejsc siedzących: ";
    cin >> ms;
    cout << "Podaj ilość miejsc stojących: ";
    cin >> mst;
    Autobus autobus(nazwa, marka, rocznik, ms, mst);
    SamochodCiezarowy ciezarowka("Volvo", "FH16", 2020, "wywrotka");

    ciezarowka.wyswietl();
    autobus.wyswietl();

    return 0;
}
