/*	Name:		Caleb Ewer
	ID:			2409827
	Program:	Project #3
	Purpose:	Read a text file of grocery items and condensing them into the item name and the count with a menu and options
*/

#include "Grocery.h"


int main() {
	Grocery item;
	ifstream input;
	string file = "Groceries.txt";
	string searchWord;
	int selection = 0;

	item.OpenFile(file);	//Open the file
	item.SetItems(item.ReadFile(item.GetItems()));	//Set the map with the contents of the file 

	while (selection != 4) {
		item.PrintMenu();	//Print the menu options
		cin >> selection;
		if (selection == 1) {
			cout << endl;
			cout << "Enter an item to search for: ";
			cin >> searchWord;	//Word to search 
			cout << endl;
			item.ItemOccurances(item.GetItems(), searchWord);	//Calling the print option for the one item
			cout << endl;
		}
		else if (selection == 2) {
			item.Print(item.GetItems());	//Print the items of the map
			cout << endl;
		}
		else if (selection == 3) {
			item.Histgram(item.GetItems());	//Print the histogram 
			cout << endl;
		}
		else if (selection == 4) {
			break;	//Break the loop
		}
		else {
			cout << "ERROR! Please enter one of the options." << endl; //Error statement if number is not 1-4
			cout << endl;
		}
	}
	item.CloseFile();//Close the file
	cout << endl;
	cout << "Program Closed: Thank You!" << endl; //End program
	
	return 0;
}