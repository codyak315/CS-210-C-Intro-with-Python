#include <iostream>
#include <string>
#include <stdexcept> // invalid_argument
#include <cstdlib> // exit() pause()
#include <fstream> // files
#include <Windows.h> // color
#include "Menu.h"
#include "Translator.h"


using namespace std;


// Constructor for Menu Object.
Menu::Menu() {
	this->validInput = 0;
	this->itemQuantity = 0;
	this->histogramIcon = '*';
	this->histogramNum = 0;
	this->fileString = "";
}


// Initial prompt generated to get user input.
void Menu::initialPrompt() {
	cout << "\t***Corner Grocer***" << endl;
	cout << "1. List of all items purchanced" << endl;
	cout << "2. Amount of 'x' item purchased" << endl;
	cout << "3. Total daily sales" << endl;
	cout << "4. Exit Program" << endl;
}


// Follow up prompt that is called in each instance user input is needed after the first.
void Menu::followUpPrompt() {
	cout << "\nEnter another selection:" << endl;
	cout << "1. List of all items purchanced" << endl;
	cout << "2. Amount of 'x' item purchased" << endl;
	cout << "3. Total daily sales" << endl;
	cout << "4. Exit Program" << endl;
}


/*
Reads the file frequency.dat and outputs to the console a text-based histogram that shows each item sold and its quantity represented
by the histogramIcon, default set to '*'.
*/
void Menu::writeHistogram() {
	ifstream reader;

	cout << "Opening file frequency.dat\n" << endl;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14); // Changes text color
	cout << "Item\t" << "Quantity '*'" << endl;

	reader.open("frequency.dat");
	if (!reader.is_open()) { // If file cannot be opened warns user.
		cout << "Could not open file frequency.dat." << endl;
	}

	reader >> fileString;
	while (!reader.fail()) {

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11); // Changes text color

		cout << fileString; // Outputs item name
		reader >> fileString;

		try { // If input is off and histogramNum is not a number clears error flags and closes file stream then re-prompts user.
			histogramNum = stoi(fileString);

		}
		catch (invalid_argument e) {
			cout << "Error reading file." << endl;
			reader.clear();
			reader.close();
			followUpPrompt();
			handleInput();
		}

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13); // Changes text color
		cout << " " << string(histogramNum, histogramIcon) << endl; // Outputs icon as visual representation for amount sold that was read from file.

		reader >> fileString;
	}

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 07); // Changes text color back to white

	reader.close();

}


/*
Takes user input, validates that is an integer of valid range, else prompts user for correct input. 
Then displays the desired output.
1. Lists all items and quantity purchased.
2. Lists the amount of a specific item purchased.
3. Total amount of items sold.
4. Exit Program.
*/
void Menu::handleInput() {
	cin >> input;

	try {
		validInput = stoi(input);
	}
	catch (invalid_argument e) { // If user input is not an integer.
		cout << "Invalid input, please enter your selection as 1, 2, 3, or 4 to exit." << endl;
		handleInput();
	}

	switch (validInput) {
		case 1:
			cout << "\n#--------Item" << endl;
			Translator::Translator().CallProcedure("itemsPurchased");
			system("pause");
			followUpPrompt();
			handleInput();
			break;
		case 2:
			cout << "\nEnter an item to see quantity purchased." << endl;
			cin >> input2;
			itemQuantity = Translator::Translator().callIntFunc("quantityPurchased", input2);
			cout << itemQuantity << " " << input2 << " purchased." << endl;
			system("pause");
			followUpPrompt();
			handleInput();
			break;
		case 3:
			Translator::Translator().CallProcedure("histogram");
			writeHistogram();
			system("pause");
			followUpPrompt();
			handleInput();
			break;
		case 4:
			cout << "\nProgram exited." << endl;
			exit(0); // Exits program
		default:
			cout << "\nInvalid input, please enter your selection as 1, 2, 3, or 4 to exit." << endl; // Input out of range
			handleInput();
	}
}