#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include "person.h"

class employeer : public person {
private:
    int experience;
    int taskBudget;
    bool isActive;
    vector<string> assignedTasks;

public:
    // Конструктор
    employeer(const char* name, int age, const char* ID, const std::string& address, const std::string& position, int experience, int taskBudget)
        : person(name, age, ID, address, position), experience(experience), taskBudget(taskBudget), isActive(true) {}

    // Префіксна форма оператора ++: збільшує досвід
    employeer& operator++() {
        ++experience;
        cout << "Prefix ++: Experience increased to " << experience << endl;
        return *this;
    }

    // Постфіксна форма оператора ++: збільшує бюджет
    employeer operator++(int) {
        employeer temp = *this;
        ++taskBudget;
        cout << "Postfix ++: Task budget increased to " << taskBudget << endl;
        return temp;
    }

    // Префіксна форма оператора --: зменшує досвід
    employeer& operator--() {
        if (experience > 0) --experience;
        cout << "Prefix --: Experience decreased to " << experience << endl;
        return *this;
    }

    // Постфіксна форма оператора --: зменшує бюджет
    employeer operator--(int) {
        employeer temp = *this;
        if (taskBudget > 0) --taskBudget;
        cout << "Postfix --: Task budget decreased to " << taskBudget << endl;
        return temp;
    }
    employeer operator+(int experienceGain) const {
        return employeer(name.c_str(), age, ID.c_str(), address, position, experience + experienceGain, taskBudget);
    }

    employeer operator-(int experienceLoss) const {
        int newExperience = experience - experienceLoss > 0 ? experience - experienceLoss : 0;
        return employeer(name.c_str(), age, ID.c_str(), address, position, newExperience, taskBudget);
    }
    employeer& operator=(const employeer& other) {
        if (this == &other) return *this;
        name = other.name;
        age = other.age;
        ID = other.ID;
        address = other.address;
        position = other.position;
        experience = other.experience;
        taskBudget = other.taskBudget;
        return *this;
    }

    employeer& operator+=(int experienceGain) {
        experience += experienceGain;
        return *this;
    }

    employeer& operator-=(int experienceLoss) {
        experience = experience > experienceLoss ? experience - experienceLoss : 0;
        return *this;
    }

    employeer& operator*=(double multiplier) {
        taskBudget = static_cast<int>(taskBudget * multiplier);
        return *this;
    }

    int operator[](int index) const {
        if (index == 0) return experience;
        if (index == 1) return taskBudget;
        throw std::out_of_range("Invalid index for employeer!");
    }

    // Метод для виведення інформації про об'єкт
    void printInfo() const override {
        person::printInfo();
        cout << "Experience: " << experience << " years\nTask Budget: $" << taskBudget << endl;
    }

    void xxx() const override {
        cout << "i wanna sleep" << endl;
    }
};
