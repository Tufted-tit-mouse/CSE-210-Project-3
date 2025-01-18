/*
 * Calculator.cpp
 *
 *  Date: [7/5/23]
 *  Author: [Caleb Ewer]
 */
/*
#include <iostream>

using namespace std;

void main()
{
	//char statment[100] never gets used so ereased it   
	double op1, op2; //Cahnged from int to double for better accuracy
	char operation;
	char answer = 'Y';	//Mising semicolon and needs to use single quotes for char
		while ((answer == 'Y') || (answer == 'y')) //Used y and not Y to fix used or operator
		{
			cout << "Enter expression" << endl;
			cin >> op1 >> operation >> op2;   //Swapped position of op1 and op2 to correct positions
			if (operation == '+') { //Used double quotes instead of single also semicolon after expression
				cout << op1 << " + " << op2 << " = " << op1 + op2 << endl; //Used >> instead of <<
			}
			else if (operation == '-') {	//Semicolon after expression
				cout << op1 << " - " << op2 << " = " << op1 - op2 << endl; //Used >> instead of <<
			}
			else if (operation == '*') {
				cout << op1 << " * " << op2 << " = " << op1 * op2 << endl; //Missing semicolon also printing out / instead of *
			}
			else if (operation == '/') {
				cout << op1 << " / " << op2 << " = " << op1 / op2 << endl; //Printing * instead of /
			}
			cout << "Do you wish to evaluate another expression? " << endl;
			cin >> answer;
		}			//Personal Design flaw: All if statements missing curly braces and seperate if statements instead of else ifs
}*/