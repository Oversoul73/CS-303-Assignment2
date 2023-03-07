#pragma once

#include <iostream>
#include <string>

using namespace std;

// the main class which is abstract defined as the assignment detailed 
class Employee {
protected:
    string name;
    int age;
    double hourlyRate;
    double healthInsurance;
public:
    Employee(string n, int a, double hr, double hi) {
        name = n;
        age = a;
        hourlyRate = hr;
        healthInsurance = hi;
    }

    //the main functions of the class; to be defined in the derived classes
    virtual double calcWeeklySalary(double hoursWorked) = 0;

    virtual double calcHealthCareContributions() = 0;

    virtual int calcVacationDays(double hoursWorked) = 0;
};


// the derived class with defined functions and extra data
class Professional : public Employee {
private:
    int monthlySalary;
    int vacationDays;
public:
    Professional(string n, int a, int ms, int vd, double hi)
        : Employee(n, a, 0, hi) {
        monthlySalary = ms;
        vacationDays = vd;
    }

    double calcWeeklySalary(double hoursWorked) {
        return monthlySalary / 4.0;
    }

    double calcHealthCareContributions() {
        return healthInsurance * 0.2;
    }

    int calcVacationDays(double hoursWorked) {
        return vacationDays;
    }
};


// the derived class with defined functions and extra data
class Nonprofessional : public Employee {
private:
    double vacationHours;
public:
    Nonprofessional(string n, int a, double hr, double hi)
        : Employee(n, a, hr, hi) {
        vacationHours = 0;
    }

    double calcWeeklySalary(double hoursWorked) {
        return hoursWorked * hourlyRate;
    }

    double calcHealthCareContributions() {
        return healthInsurance * 0.1;
    }

    int calcVacationDays(double hoursWorked) {
        vacationHours = hoursWorked / 4;
        return vacationHours / 8;
    }
};
