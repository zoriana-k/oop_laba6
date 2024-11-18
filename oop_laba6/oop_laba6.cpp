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
    person.printInfo(); // ���������� ������
}

void xxxx(person* p) {
    p->xxx(); // ���������� ������
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
    emp = emp + 2; // ������ �����
    emp.printInfo();
    emp = emp - 1; // �������� �����
    emp.printInfo();
    emp += 3; // ������ �����
    emp.printInfo();
    emp -= 2; // ������� �����
    emp.printInfo();
    emp *= 1.2; // �������� ������
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
    mgr = mgr + 5000; // �������� ������
    mgr.printInfo();
    mgr = mgr - 10000; // �������� ������
    mgr.printInfo();
    mgr += 1; // ������ �����
    mgr.printInfo();
    mgr -= 2; // ������� ������
    mgr.printInfo();
    mgr *= 1.3; // �������� ������
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
    cust = cust + 10000; // �������� �����
    cust.printInfo();
    cust = cust - 20000; // �������� �����
    cust.printInfo();
    customer newCustomer = cust;
    newCustomer.printInfo();
    cust += 2;
    cust.printInfo();
    cust -= 1;
    cust.printInfo();
    cust *= 1.5;
    cust.printInfo();

    // ������������ ��������� []
    cout << "Customer projects ordered: " << cust[0] << endl;
    cout << "Employeer experience: " << emp[0] << endl;
    cout << "Manager projects count: " << mgr[0] << endl;

    try {
        // ��������� ���������� � ������ ������ �����
        MultiTypeContainer<int, double, float, string, string> container(10, 20.5, 30.75, "Hello", "World");

        // ��������� ��� ��������
        container.displayElements();

        // ��������� ��������
        container.updateElements(15, 25.5, 35.75, "Goodbye", "Everyone");
        container.displayElements();

        // ���� �������� ��������
        double sum = container.sumNumericElements();
        cout << "Sum of numeric elements: " << sum << endl;

        // ������������ ��������� ��������
        string concatenated = container.concatenateStrings();
        cout << "Concatenated strings: " << concatenated << endl;

        // �������� �� ������
        bool areEqual = container.areElementsEqual();
        cout << "Are some elements equal? " << (areEqual ? "Yes" : "No") << endl;

    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    // ��������� ���������� � ������ ������ �����
    MultiTypeContainer<int, double, float, string, string> container(10, 20.5, 30.75, "Hello", "World");
    // ��������� ��� ��������
    container.displayElements();
    // ��������� ��������
    container.updateElements(15, 25.5, 35.75, "Goodbye", "Everyone");
    container.displayElements();
    // ���� �������� ��������
    double sum = container.sumNumericElements();
    cout << "Sum of numeric elements: " << sum << endl;
    // ������������ ��������� ��������
    string concatenated = container.concatenateStrings();
    cout << "Concatenated strings: " << concatenated << endl;
    // �������� �� ������
    bool areEqual = container.areElementsEqual();
    cout << "Are some elements equal? " << (areEqual ? "Yes" : "No") << endl;

    // ��������� ��'���� �����
    Resource laptop("Laptop", "Hardware", 1500.0);
    Resource software("Software License", "Software", 200.0);

    Team devTeam("Development Team", 5000.0);
    devTeam.addMember("Alice");
    devTeam.addMember("Bob");
    devTeam.allocateResource(laptop);
    devTeam.allocateResource(software);

    // ������������ ���������� �����
    MultiTypeContainer<Resource, Team, int, double, string> MyContainer(
        laptop, devTeam, 3, 1200.5, "Project Management"
    );

    cout << "Container elements:" << endl;
    container.displayElements();

    return 0;
}
