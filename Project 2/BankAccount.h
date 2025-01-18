#pragma once
#include <iostream>
#include <string>

class BankAccount {

public:	
	void SetInitialAmount(double amount);
	void SetMonthlyDeposit(double deposit);
	void SetRate(double annual);
	void SetNumYears(int years);
	void SetTotal(double deposit, double amount);
	void SetInterest(double total, double rate);

	double GetInitialAmount();
	double GetMonthlyDeposit();
	double GetRate();
	int GetNumYears();
	double GetTotal();
	double GetInterest();


private:
	double initialAmount;
	double monthlyDeposit;
	double rate;
	int numYears;
	double total;
	double updatedInterest;
};

void BankAccount::SetInitialAmount(double amount) {
	initialAmount = amount;
}
void BankAccount::SetMonthlyDeposit(double deposit) {
	monthlyDeposit = deposit;
}
void BankAccount::SetRate(double annual) {
	rate = annual;
}
void BankAccount::SetNumYears(int years) {
	numYears = years;
}
void BankAccount::SetTotal(double deposit, double amount) {
	total = deposit + amount;
}
void BankAccount::SetInterest(double total, double rate) {
	updatedInterest = (total) * ((rate / 100) / 12);
}
double BankAccount::GetInitialAmount() {
	return initialAmount;
}
double BankAccount::GetMonthlyDeposit() {
	return monthlyDeposit;
}
double BankAccount::GetRate() {
	return rate;
}
int BankAccount::GetNumYears() {
	return numYears;
}
double BankAccount::GetTotal() {
	return total;
}
double BankAccount::GetInterest() {
	return updatedInterest;
}
