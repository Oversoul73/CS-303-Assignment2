
//   3/5/2023

// Mohammadreza Akbari Lor

// CS-303 Assignment 2 part 1

// this file contians the main function

#include<iostream>
#include<string>

#include"Single_linked_list.h"

using namespace std;

char MainMenu();
// pre:   loads menu and give option to give an input
// post:  returns input to main

int main() {

    Single_Linked_List<string> a;

	char menuInput;

	// first call of the menu
	menuInput = MainMenu();

	// loop for remaining in menu until Q is selected and executing other commands
	while (menuInput != 'Q') {

        string item;
        int index;

		// selecting command based on user input
		switch (menuInput)
		{
		case '1':
            cout << "Please enter what you wish to be pushed onto the back of the list: ";
            cin >> item;
            a.push_back(item);
			break;
		case '2':
            cout << "Please enter what you wish to be pushed onto the front of the list: ";
            cin >> item;
            a.push_front(item);
			break;
		case '3':
            a.pop_back();
			break;
        case '4':
            a.pop_front();
            break;
        case '5':
            cout << a.back() << endl << endl;
            break;
        case '6':
            cout << a.front() << endl << endl;
            break;
		case '7':
            cout << "Please enter what you wish to insert to the list: ";
            cin >> item;
            cout << "Please enter where you wish to insert in the list: ";
            cin >> index;
            a.insert(index, item);
			break;
		case '8':
            cout << "Please enter what index you wish to be deleted in the list: ";
            cin >> index;
            cout << a.remove(index) << endl << endl;
            break;
		case '9':
            cout << "Please enter what you wish to be found in the list: ";
            cin >> item;
            cout << a.find(item) << endl << endl;
			break;
        case '0':
            cout << a.empty() << endl << endl;
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
    cout << "Wellcome to the Single_linked_list testing station" << endl;
    cout << endl;
    cout << "     MENU CHOICES" << endl;
    cout << "1 - Push Back" << endl;
    cout << "2 - Push Front" << endl;
    cout << "3 - Pop Back" << endl;
    cout << "4 - Pop Front" << endl;
    cout << "5 - Back" << endl;
    cout << "6 - Front" << endl;
    cout << "7 - Insert" << endl;
    cout << "8 - Remove" << endl;
    cout << "9 - Find" << endl;
    cout << "0 - Empty" << endl;
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
    case '7':
        return '7';
        break;
    case '8':
        return '8';
        break;
    case '9':
        return '9';
        break;
    case '0':
        return '0';
        break;
    case 'Q':
        return 'Q';
        break;
    default:
        return 'E';
        break;
    }

}