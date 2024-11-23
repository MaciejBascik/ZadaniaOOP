#include <iostream>
#include <string>
using namespace std;

// Klasa bazowa Pojazd z enkapsulacją
class Pojazd {
private:
    string marka;
    string model;
    int rokProdukcji;

public:
    Pojazd(string m, string mo, int r) : marka(m), model(mo), rokProdukcji(r) {}

    // Gettery i Settery
    string getMarka() const { return marka; }
    string getModel() const { return model; }
    int getRokProdukcji() const { return rokProdukcji; }

    void setMarka(const string &m) { marka = m; }
    void setModel(const string &mo) { model = mo; }
    void setRokProdukcji(int r) { rokProdukcji = r; }

    virtual void wyswietl() {
        cout << "Marka: " << marka << ", Model: " << model << ", Rok produkcji: " << rokProdukcji << endl;
    }
};

// Klasa pochodna SamochodCiezarowy z enkapsulacją
class SamochodCiezarowy : public Pojazd {
private:
    string przeznaczenie;

public:
    SamochodCiezarowy(string m, string mo, int r, string p) : Pojazd(m, mo, r), przeznaczenie(p) {}

    void wyswietl() {
        cout << "Samochód ciężarowy - ";
        Pojazd::wyswietl();
        cout << "Przeznaczenie: " << przeznaczenie << endl;
    }
};

// Klasa pochodna Autobus z enkapsulacją
class Autobus : public Pojazd {
private:
    int miejscaSiedzace;
    int miejscaStojace;

public:
    Autobus(string m, string mo, int r, int ms, int mt) : Pojazd(m, mo, r), miejscaSiedzace(ms), miejscaStojace(mt) {}

    void wyswietl() {
        cout << "Autobus - ";
        Pojazd::wyswietl();
        cout << "Miejsca siedzące: " << miejscaSiedzace << ", Miejsca stojące: " << miejscaStojace << endl;
    }
};

int main() {
    // Tworzenie obiektów za pomocą danych od użytkownika
    string marka, model, przeznaczenie;
    int rokProdukcji, miejscaSiedzace, miejscaStojace;

    // Dane dla autobusu
    cout << "Podaj dane autobusu:\n";
    cout << "Marka: ";
    cin >> marka;
    cout << "Model: ";
    cin >> model;
    cout << "Rok produkcji: ";
    cin >> rokProdukcji;
    cout << "Liczba miejsc siedzących: ";
    cin >> miejscaSiedzace;
    cout << "Liczba miejsc stojących: ";
    cin >> miejscaStojace;

    Autobus autobus(marka, model, rokProdukcji, miejscaSiedzace, miejscaStojace);
    SamochodCiezarowy ciezarowka("MAN", "TGA", 2021, "transport materiałów");
    ciezarowka.wyswietl();
    autobus.wyswietl();

    // Zmiana danych przez settery
    ciezarowka.setMarka("DAF");
    ciezarowka.setModel("XF");
    ciezarowka.setRokProdukcji(2022);
    ciezarowka.wyswietl();

    return 0;
}
