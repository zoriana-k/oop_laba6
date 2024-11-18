#include <iostream>
#include <fstream>
#include <stdexcept>
#include "manager.h"
#include "project.h"
#include "customer.h"
#include "employeer.h"
#include "team.h"
#include "resourceManager.h"
#include "teamLeader.h"
#include "projectController.h"
#include "MultiTypeContainer.h"
#include "resource.h"

using namespace std;

void processProject(const project& p) {
    cout << "Processing project: " << p.name << endl;
    cout << "Customer: " << p.customer << endl;
    cout << "Budget: " << p.budget << endl;
}

void processProject(const project* p) {
    if (p) {
        cout << "Processing project: " << p->name << endl;
        cout << "Customer: " << p->customer << endl;
        cout << "Budget: " << p->budget << endl;
    }
}

void processProjectPointer(const project* p) {
    cout << "Processing project by pointer: " << p->name << endl;
    cout << "Customer: " << p->customer << endl;
    cout << "Budget: " << p->budget << endl;
}
void displayInfo(const person& person) {
    person.printInfo(); // Поліморфний виклик
}

void xxxx(person* p) {
    p->xxx(); // Поліморфний виклик
}

int main() {
    employeer emp("Nadia Suska", 28, "Angel", "101 Pine St", "Developer", 3, 5000);
    emp.printInfo();
    ++emp;
    emp.printInfo();
    emp++;
    emp.printInfo();
    --emp;
    emp.printInfo();
    emp--;
    emp.printInfo();
    emp = emp + 2; // Додаємо досвід
    emp.printInfo();
    emp = emp - 1; // Зменшуємо досвід
    emp.printInfo();
    emp += 3; // Додати досвід
    emp.printInfo();
    emp -= 2; // Забрати досвід
    emp.printInfo();
    emp *= 1.2; // Збільшити бюджет
    emp.printInfo();

    manager mgr("Zavgorodnya Valeria", 37, "SuperManager", "119 Office St", "Manager", 3, 170000);
    mgr.printInfo();
    ++mgr;
    mgr.printInfo();
    mgr++;
    mgr.printInfo();
    --mgr;
    mgr.printInfo();
    mgr--;
    mgr.printInfo();
    mgr = mgr + 5000; // Збільшуємо бюджет
    mgr.printInfo();
    mgr = mgr - 10000; // Зменшуємо бюджет
    mgr.printInfo();
    mgr += 1; // Додати проєкт
    mgr.printInfo();
    mgr -= 2; // Забрати проєкти
    mgr.printInfo();
    mgr *= 1.3; // Збільшити бюджет
    mgr.printInfo();

    customer cust("Zotova Alina", 33, "KvaCommision", "789 Oak St", "Customer", 1, 50000);
    cust.printInfo();
    ++cust;
    cust.printInfo();
    cust++;
    cust.printInfo();
    --cust;
    cust.printInfo();
    cust--;
    cust.printInfo();
    cust = cust + 10000; // Збільшуємо платіж
    cust.printInfo();
    cust = cust - 20000; // Зменшуємо платіж
    cust.printInfo();
    customer newCustomer = cust;
    newCustomer.printInfo();
    cust += 2;
    cust.printInfo();
    cust -= 1;
    cust.printInfo();
    cust *= 1.5;
    cust.printInfo();

    // Демонстрація оператора []
    cout << "Customer projects ordered: " << cust[0] << endl;
    cout << "Employeer experience: " << emp[0] << endl;
    cout << "Manager projects count: " << mgr[0] << endl;

    try {
        // Створення контейнера з різними типами даних
        MultiTypeContainer<int, double, float, string, string> container(10, 20.5, 30.75, "Hello", "World");

        // Виведення всіх елементів
        container.displayElements();

        // Оновлення елементів
        container.updateElements(15, 25.5, 35.75, "Goodbye", "Everyone");
        container.displayElements();

        // Сума числових елементів
        double sum = container.sumNumericElements();
        cout << "Sum of numeric elements: " << sum << endl;

        // Конкатенація строкових елементів
        string concatenated = container.concatenateStrings();
        cout << "Concatenated strings: " << concatenated << endl;

        // Перевірка на рівність
        bool areEqual = container.areElementsEqual();
        cout << "Are some elements equal? " << (areEqual ? "Yes" : "No") << endl;

    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    // Створення контейнера з різними типами даних
    MultiTypeContainer<int, double, float, string, string> container(10, 20.5, 30.75, "Hello", "World");
    // Виведення всіх елементів
    container.displayElements();
    // Оновлення елементів
    container.updateElements(15, 25.5, 35.75, "Goodbye", "Everyone");
    container.displayElements();
    // Сума числових елементів
    double sum = container.sumNumericElements();
    cout << "Sum of numeric elements: " << sum << endl;
    // Конкатенація строкових елементів
    string concatenated = container.concatenateStrings();
    cout << "Concatenated strings: " << concatenated << endl;
    // Перевірка на рівність
    bool areEqual = container.areElementsEqual();
    cout << "Are some elements equal? " << (areEqual ? "Yes" : "No") << endl;

    // Створення об'єктів класів
    Resource laptop("Laptop", "Hardware", 1500.0);
    Resource software("Software License", "Software", 200.0);

    Team devTeam("Development Team", 5000.0);
    devTeam.addMember("Alice");
    devTeam.addMember("Bob");
    devTeam.allocateResource(laptop);
    devTeam.allocateResource(software);

    // Використання шаблонного класу
    MultiTypeContainer<Resource, Team, int, double, string> MyContainer(
        laptop, devTeam, 3, 1200.5, "Project Management"
    );

    cout << "Container elements:" << endl;
    container.displayElements();

    return 0;
}
