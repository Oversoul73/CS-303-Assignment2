
#include <iostream>
using namespace std;

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

    virtual double calcWeeklySalary(double hoursWorked) = 0;

    virtual double calcHealthCareContributions() = 0;

    virtual int calcVacationDays(double hoursWorked) = 0;
};

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

int main() {
    Professional emp1("John Smith", 30, 5000, 20, 1000);
    Nonprofessional emp2("Jane Doe", 25, 20, 500);

    cout << "Employee " << emp1.name << " has a weekly salary of " << emp1.calcWeeklySalary(0) << endl;
    cout << "Employee " << emp1.name << " has healthcare contributions of " << emp1.calcHealthCareContributions() << endl;
    cout << "Employee " << emp1.name << " has " << emp1.calcVacationDays() << " vacation days" << endl;

    cout << "Employee " << emp2.name << " has a weekly salary of " << emp2.calcWeeklySalary(40) << endl;
    cout << "Employee " << emp2.name << " has healthcare contributions of " << emp2.calcHealthCareContributions() << endl;
    cout << "Employee " << emp2.name << " has " << emp2.calcVacationDays() << " vacation days" << endl;

    return 0;
}