#include <iostream>
#include <string>
using namespace std;

// Klasa bazowa dla komputera
class Computer {
public:
    // Inicjalizacja pól publicznych dla klasy
    string brand;
    string model;

    // Konstruktor
    Computer(string brand = "", string model = "") : brand(brand), model(model) {}

    // Wirtualna metoda do wyświetlania danych
    virtual void displayInfo() const {
        cout << "Brand: " << brand << "\nModel: " << model << endl;
    }
};

// Klasa pochodna dla komputerów stacjonarnych
class Desktop : public Computer {
public:
    // Inicjalizacja pól publicznych dla klasy
    string casingType; // Typ obudowy

    // Konstruktor
    Desktop(string brand = "", string model = "", string casingType = "")
        : Computer(brand, model), casingType(casingType) {}

    // Nadpisanie metody wyświetlania danych
    void displayInfo() const override {
        Computer::displayInfo();
        cout << "Casing Type: " << casingType << endl;
    }
};

// Klasa pochodna dla laptopów
class Laptop : public Computer {
public:
    // Inicjalizacja pól publicznych dla klasy
    double screenDiagonal; // Długość przekątnej ekranu
    string color; // Kolor obudowy

    // Konstruktor
    Laptop(string brand = "", string model = "", double screenDiagonal = 0.0, string color = "")
        : Computer(brand, model), screenDiagonal(screenDiagonal), color(color) {}

    // Nadpisanie metody wyświetlania danych
    void displayInfo() const override {
        Computer::displayInfo();
        cout << "Screen Diagonal: " << screenDiagonal << " inches\nColor: " << color << endl;
    }
};

// Funkcja główna
int main() {
    // Dane wprowadzane przez użytkownika dla laptopa
    Laptop userLaptop;
    cout << "Enter laptop details:\n";
    cout << "Brand: ";
    cin >> userLaptop.brand;

    cout << "Model: ";
    cin >> userLaptop.model;

    cout << "Screen Diagonal (inches): ";
    cin >> userLaptop.screenDiagonal;

    cout << "Color: ";
    cin >> userLaptop.color;

    // Wyświetlenie wprowadzonych danych
    cout << "\nEntered Laptop Info:" << endl;
    userLaptop.displayInfo();

    return 0;
}
