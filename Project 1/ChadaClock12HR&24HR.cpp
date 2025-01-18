/*
 * ChadaClock12HR&24HR.cpp
 *
 *  Date: [7/14/23]
 *  Author: [Caleb Ewer]
 */

#include <iostream>
#include <iomanip>
using namespace std;


int EnterHour(int hour) {	// Function to add the beginning hour
	cout << "Please enter hour: ";	
	cin >> hour;
	cout << endl;
	return hour;
}

int EnterMinute(int minute) {	// Function to add the beginning minute 
	cout << "Please enter minute: ";
	cin >> minute;
	cout << endl;
	return minute;
}

int EnterSecond(int second) {	// Function to add the beginning second
	cout << "Please enter second: ";
	cin >> second;
	cout << endl;
	return second;
}
void ShowTime(int hour, int minute, int second) {	//Function to display the time
	int temp;
	bool pm;
	if (hour > 11) {
		pm = true;
	}
	else {
		pm = false;
	}
	if (hour > 12) {
		temp = hour % 12;
	}
	else {
		temp = hour;
	}
	cout << "**************************		**************************" << endl;
	cout << "*      12-Hour Clock     *		*      24-Hour Clock     *" << endl;
	cout << "*        ";
	if ((hour < 10) || (temp < 10)) {
		cout << "0" << temp;
	}
	else {
		cout << temp;
	}
	cout << ":";
	if (minute < 10) {
		cout << "0" << minute;
	}
	else {
		cout << minute;
	}
	cout << ":";
	if (second < 10) {
		cout << "0" << second;
	}
	else {
		cout << second;
	}
	if (pm == true) {
		cout << " P M";
	}
	else {
		cout << " A M";
	}
	cout << "     *";
	cout << "		";
	cout << "*        ";
	if (hour < 10) {
		cout << "0" << hour;
	}
	else {
		cout << hour;
	}
	cout << ":";
	if (minute < 10) {
		cout << "0" << minute;
	}
	else {
		cout << minute;
	}
	cout << ":";
	if (second < 10) {
		cout << "0" << second;
	}
	else {
		cout << second;
	}
	cout << "        *" << endl;
	cout << "**************************		**************************" << endl;
}

void Menu() {	// Function to show the menu and options
	cout << endl;
	cout << "                    **************************" << endl;
	cout << "                    * 1 - Add One Hour       *" << endl;
	cout << "                    * 2 - Add One Minute     *" << endl;
	cout << "                    * 3 - Add One Second     *" << endl;
	cout << "                    * 4 - Exit Program       *" << endl;
	cout << "                    **************************" << endl;
}

void Error() {	// Function for invalid option
	cout << "The number you entered is invalid!" << endl;
	cout << " Please enter a different number." << endl;
}

int AddTime(int time) { // Function to add an hour, minute, or second
	time += 1;
	return time;
}

int main() {	// Main 
	int hour = 00;
	int minute = 00;
	int second = 00;
	int selection = 0;

	hour = EnterHour(hour); // Assgining the time amounts with the function calls
	minute = EnterMinute(minute);
	second = EnterSecond(second);
	ShowTime(hour, minute, second); // Calling the display

	while (selection != 4) { // While loop to loop for the menu
		Menu();	// Function call to display the menu
		cin >> selection;	// Taking user input for selection
		if (selection == 1) {	// Adding a hour
			hour = AddTime(hour);
		}
		else if (selection == 2) {	// Adding a minute
			minute = AddTime(minute);
		}
		else if (selection == 3) {	// Adding a second
			second = AddTime(second);
		}
		else if (selection == 4) {	// Exit condition
			exit;
		}
		else {	// Invalid selection condition
			Error();	
		}
		if (second > 59) {	// Rounding up from a second
			second = second % 60;
			minute = AddTime(minute);
		}
		if (minute > 59) {	// Rounding up from a minute
			minute = minute % 60;
			hour = AddTime(hour);
		}
		if (hour > 23) {	// Going past 24
			hour = hour % 24;
		}

		ShowTime(hour, minute, second); // Display the time
	}
	return 0;
} 