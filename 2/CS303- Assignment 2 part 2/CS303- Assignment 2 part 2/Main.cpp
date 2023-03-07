
//   3/5/2023

// Mohammadreza Akbari Lor

// CS-303 Assignment 2 part 2

// this file contians the main function

#include <iostream>
#include <string>

#include "Employee.h"

using namespace std;

char MainMenu();
// pre:   loads menu and give option to give an input
// post:  returns input to main

int main() {

    string name;
    int age, monthlySalary, vacationDays;
    double hourlyRate, healthInsurance;

    // prompts for inputing the information of the professional employee
    cout << "Please enter the details of the professional employee." << endl;
    cout << "Name: ";
    cin >> name;
    cout << "Age: ";
    cin >> age;
    cout << "Montly Salary: ";
    cin >> monthlySalary;
    cout << "Vacation Days: ";
    cin >> vacationDays;
    cout << "Health Insurance: ";
    cin >> healthInsurance;

    Professional a(name, age, monthlySalary, vacationDays, healthInsurance);

    // prompts for inputing the information of the non-professional employee
    cout << "Please enter the details of the non-professional employee." << endl;
    cout << "Name: ";
    cin >> name;
    cout << "Age: ";
    cin >> age;
    cout << "Hourly Rate: ";
    cin >> hourlyRate;
    cout << "Health Insurance: ";
    cin >> healthInsurance;

    Nonprofessional b(name, age, hourlyRate, healthInsurance);

    char menuInput;

    // first call of the menu
    menuInput = MainMenu();

    // loop for remaining in menu until Q is selected and executing other commands
    while (menuInput != 'Q') {

        int hoursWorked;

        // selecting command based on user input
        switch (menuInput)
        {
        case '1':
            cout << "Weekly Salary of the Professional Employee is: " << a.calcWeeklySalary(0) << endl;
            cout << endl;
            break;
        case '2':
            cout << "Health Care Contributions of the Professional Employee is: " << a.calcHealthCareContributions() << endl;
            cout << endl;
            break;
        case '3':
            cout << "Vacation Days of the Professional Employee is: " << a.calcVacationDays(0) << endl;
            cout << endl;
            break;
        case '4':
            cout << "How many hours has the Employee worked during the week? ";
            cin >> hoursWorked;
            cout << "Weekly Salary of the Non-Professional Employee is: " << b.calcWeeklySalary(hoursWorked) << endl;
            cout << endl;
            break;
        case '5':
            cout << "Health Care Contributions of the Non-Professional Employee is: " << b.calcHealthCareContributions() << endl;
            cout << endl;
            break;
        case '6':
            cout << "How many hours has the Employee worked during the week? ";
            cin >> hoursWorked;
            cout << "Vacation Days of the Non-Professional Employee is: " << b.calcVacationDays(hoursWorked) << endl;
            cout << endl;
            break;
        default:
            cout << endl;
            cout << "Error: Wrong input! Try again!" << endl;
            cout << endl;
            cout << endl;
            break;
        }

        // succesive calls to menu
        menuInput = MainMenu();

    }

}

char MainMenu() {

    char menuInput;

    // printing the menu header and options
    cout << "Wellcome to the Employee class testing station" << endl;
    cout << endl;
    cout << "     MENU CHOICES" << endl;
    cout << "1 - Calculating the Weekly Salary of the Professional Employee" << endl;
    cout << "2 - Calculating the Health Care Contributions of the Professional Employee" << endl;
    cout << "3 - Calculating the Vacation Days of the Professional Employee" << endl;
    cout << "4 - Calculating the Weekly Salary of the Non-Professional Employee" << endl;
    cout << "5 - Calculating the Health Care Contributions of the Non-Professional Employee" << endl;
    cout << "6 - Calculating the Vacation Days of the Non-Professional Employee" << endl;
    cout << "Q - Quit" << endl;
    cout << endl;
    cout << endl;
    cout << "Enter your choice: ";

    // getting user input for menu
    cin >> menuInput;
    menuInput = toupper(menuInput);

    // returning the upper case of inputed letter to main
    switch (menuInput) {
    case '1':
        return '1';
        break;
    case '2':
        return '2';
        break;
    case '3':
        return '3';
        break;
    case '4':
        return '4';
        break;
    case '5':
        return '5';
        break;
    case '6':
        return '6';
        break;
    case 'Q':
        return 'Q';
        break;
    default:
        return 'E';
        break;
    }

}