#ifndef MENU_H
#define MENU_H

using namespace std;

class Menu {

public:
	Menu();
	void initialPrompt();
	void followUpPrompt();
	void handleInput();
	void writeHistogram();

private:
	string input; // handleInput() Switch Statement 
	string input2; // handleInput() Switch Statement Case 2
	string fileString; // writeHistogram() input from file reader
	int validInput; // handleInput() Switch Statement
	int itemQuantity; // handleInput Switch Statement Case 2
	char histogramIcon; // Symbol used to represent text-based histogram
	int histogramNum; // Quantity of grocery read from file

};

#endif