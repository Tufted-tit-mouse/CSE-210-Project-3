/*	Name:		Caleb Ewer
	ID:			2409827
	Program:	Project #3
	Purpose:	Read a text file of grocery items and condensing them into the item name and the count with a menu and options
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <map>
using namespace std;
#pragma once

class Grocery {
public:
	void PrintMenu();
	void SetItems(map<string, int> produce);
	void OpenFile(string fileName);
	void CloseFile();
	void Print(map<string, int> produce);
	void ItemOccurances(map<string, int> produce, string wordSearch);
	void Histgram(map<string, int> produce);
	map<string, int> ReadFile(map<string, int> produce);
	map<string, int> GetItems();


private:
	map<string, int> items;
	int count = 1;
	ifstream input;
};

void Grocery::PrintMenu() {	//Function to print menu prompts 
	cout << setfill('*') << setw(30) << '*' << endl;
	cout << "*         Main  Menu         *" << endl;
	cout << "* 1. Item to search for      *" << endl;
	cout << "* 2. Items and the amounts   *" << endl;
	cout << "* 3. Histogram of items      *" << endl;
	cout << "* 4. Exit                    *" << endl;
	cout << setfill('*') << setw(30) << '*' << endl;
	cout << endl;
	cout << "Please enter an option:";
	cout << setfill(' ');
}

void Grocery::SetItems(map<string, int> produce) {	//Function to set the map
	items = produce;
}

void Grocery::OpenFile(string fileName) {	//Function to open the file
	input.open(fileName);
}

void Grocery::CloseFile() {	//Function to close the file
	input.close();
}

void Grocery::Print(map<string, int> produce) {	//Function to print the map items and the names
	for (auto i = produce.begin(); i != produce.end(); i++) {
		cout << setw(15) << left << i->first << right << i->second << endl;
	}
}

void Grocery::ItemOccurances(map<string, int> produce, string wordSearch) {	//Function to print the select item
	if (produce.find(wordSearch) != produce.end()) {
		cout << setw(15) << left << wordSearch << right << produce[wordSearch] << endl;
	}
	else {
		cout << "Item does not exist in the list!" << endl;
	}
}

void Grocery::Histgram(map<string, int> produce) {	//Function to print the histogram
	for (auto i = produce.begin(); i != produce.end(); i++) {
		cout << setw(15) << left << i->first;
		for (int j = 0; j < i->second; j++) {
			cout << "+";
		}
		cout << endl;
	}
}

map<string, int> Grocery::GetItems() {	//Function to get the map
	return items;
}

map<string, int> Grocery::ReadFile(map<string, int> produce) {	//Function to load the map
	string inputWord;
	while (!input.eof()) {
		input >> inputWord;
		if (produce.count(inputWord)) {
			produce[inputWord] = produce[inputWord] + count;
		}
		else {
			produce[inputWord] = count;
		}
		count = 1;
	}
	return produce;
}
