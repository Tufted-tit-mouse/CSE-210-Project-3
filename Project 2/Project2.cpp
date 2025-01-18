#include <iostream>
#include <string>
#include <iomanip>
#include <ios>
using namespace std;
#include "BankAccount.h"

int main() {
	BankAccount user1;
	double initialAmountInvested;
	double monthlyDeposit;
	double annualInterest;
	int numOfYears;
	char cont = 'y';
	int months;
	//double total;
	//double interest;

	while ((cont == 'y' || cont == 'Y') && (cont != 'n' || cont != 'N')) {
		cout << "=======================================" << endl;
		cout << "========== Data Input Menu ============" << endl;
		cout << "Inital ammount invested: $";
		cin >> initialAmountInvested;
		user1.SetInitialAmount(initialAmountInvested);
		cout << "Monthly Deposit amount: $";
		cin >> monthlyDeposit;
		user1.SetMonthlyDeposit(monthlyDeposit);
		cout << "Annual Interest amount: ";
		cin >> annualInterest;
		user1.SetRate(annualInterest);
		cout << "Number of Years: ";
		cin >> numOfYears;
		user1.SetNumYears(numOfYears);
		months = user1.GetNumYears() * 12;
		cout << "Press any key to continue or the n key to exit: ";
		cin >> cont;
		if (cont == 'n' || cont == 'N') {
			break;
		}
		cout << endl;
		user1.SetTotal(monthlyDeposit, initialAmountInvested);
		user1.SetInterest(user1.GetTotal(), annualInterest);

		if (user1.GetMonthlyDeposit() > 0) {
			cout << "Month		Opening Amount  Deposited Amount	$Total		$Interest	Closing Balance" << endl;
			for (int i = 0; i < months; i++) {
				cout << i + 1 << "		";
				cout << fixed << setprecision(2) << user1.GetInitialAmount() << "		";
				cout << fixed << setprecision(2) << user1.GetMonthlyDeposit() << "			";
				cout << fixed << setprecision(2) << user1.GetTotal() << "		";
				cout << fixed << setprecision(2) << user1.GetInterest() << "		";
				user1.SetInitialAmount(user1.GetTotal() + user1.GetInterest());
				cout << fixed << setprecision(2) << user1.GetInitialAmount() << endl;

				user1.SetTotal(monthlyDeposit, user1.GetInitialAmount());
				user1.SetInterest(user1.GetTotal(), annualInterest);
			}
		}
		else {
			cout << "Month		Opening Amount  $Total		$Interest	Closing Balance" << endl;
			for (int i = 0; i < months; i++) {
				cout << i + 1 << "		";
				cout << fixed << setprecision(2) << user1.GetInitialAmount() << "		";
				cout << fixed << setprecision(2) << user1.GetTotal() << "		";
				cout << fixed << setprecision(2) << user1.GetInterest() << "		";
				user1.SetInitialAmount(user1.GetTotal() + user1.GetInterest());
				cout << fixed << setprecision(2) << user1.GetInitialAmount() << endl;

				user1.SetTotal(monthlyDeposit, user1.GetInitialAmount());
				user1.SetInterest(user1.GetTotal(), annualInterest);
			}
		}
		cout << "Do you wish to change the values? (Enter y to continue or n to exit): ";
		cin >> cont;
	}

	return 0;
}
