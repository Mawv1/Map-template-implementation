#ifndef TABLICA_ASOSACYJNA_EMPLOYEE_H
#define TABLICA_ASOSACYJNA_EMPLOYEE_H

#include <string>
#include <cstring>
#include <iostream>

using namespace std;

class Employee{
public:
    string name;
    string position;
    int age;

    Employee(string name, string pos, int a): name(name), position(pos), age(a){}

    friend ostream& operator<<(ostream& os, const Employee& employee){
        os << "name: " << employee.name << ", position: " << employee.position << ", age: " << employee.age;
        return os;
    }
};

#endif //TABLICA_ASOSACYJNA_EMPLOYEE_H
