#include <iostream>
#include <string>
using namespace std;

// Klasa bazowa dla komputera
class Computer {
private:
    string brand;
    string model;

public:
    // Konstruktor
    Computer(string brand = "", string model = "") : brand(brand), model(model) {}

    // Settery
    void setBrand(const string& brand) { this->brand = brand; }     //  użycie const, co oznacza, że metoda nie modyfikuje stanu obiektu 
    void setModel(const string& model) { this->model = model; }

    // Gettery
    string getBrand() const { return brand; }
    string getModel() const { return model; }

    // Wirtualna metoda do wyświetlania danych  (virtual pozwala na nadpisanie metody przez klasy dziedziczace)
    virtual void displayInfo() const {
        cout << "Brand: " << brand << "\nModel: " << model << endl;
    }
};

// Klasa pochodna dla komputerów stacjonarnych
class Desktop : public Computer {
    // Inicjalizacja pól prywatnych dla klasy
private:
    string casingType; // Typ obudowy

public:
    // Konstruktor
    Desktop(string brand = "", string model = "", string casingType = "")
        : Computer(brand, model), casingType(casingType) {}

    // Setter i getter dla typu obudowy
    void setCasingType(const string& casingType) { this->casingType = casingType; }
    string getCasingType() const { return casingType; }

    // Nadpisanie metody wyświetlania danych (przez override)
    void displayInfo() const override {
        Computer::displayInfo();
        cout << "Casing Type: " << casingType << endl;
    }
};

// Klasa pochodna dla laptopów
class Laptop : public Computer {
private:
    double screenDiagonal; // Długość przekątnej ekranu
    string color; // Kolor obudowy

public:
    // Konstruktor
    Laptop(string brand = "", string model = "", double screenDiagonal = 0.0, string color = "")
        : Computer(brand, model), screenDiagonal(screenDiagonal), color(color) {}

    // Settery i gettery dla ekranu i koloru
    void setScreenDiagonal(double screenDiagonal) { this->screenDiagonal = screenDiagonal; }
    double getScreenDiagonal() const { return screenDiagonal; }     //  użycie const, co oznacza, że metoda nie modyfikuje stanu obiektu 

    void setColor(const string& color) { this->color = color; }
    string getColor() const { return color; }

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
    string brand, model, color;
    double screenDiagonal;

    cout << "Enter laptop details:\n";
    cout << "Brand: ";
    cin >> brand;
    userLaptop.setBrand(brand);

    cout << "Model: ";
    cin >> model;
    userLaptop.setModel(model);

    cout << "Screen Diagonal (inches): ";
    cin >> screenDiagonal;
    userLaptop.setScreenDiagonal(screenDiagonal);

    cout << "Color: ";
    cin >> color;
    userLaptop.setColor(color);

    // Wyświetlenie wprowadzonych danych
    cout << "\nEntered Laptop Info:" << endl;
    userLaptop.displayInfo();

    return 0;
}
