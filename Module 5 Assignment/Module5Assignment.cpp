#include <iostream>
#include <fstream>
#include <iomanip> 
using namespace std;

double ConvertTemp(int fahren) {
	double cels;
		cels = (fahren - 32) * (5.0 / 9.0);
	return cels;
}
int main() {
	ifstream input;
	ofstream output;
	string city;
	int temp = 0;

	cout << "Opening file FahrenheitTemperature.txt." << endl;
	input.open("FahrenheitTemperature.txt");

	if (!input.is_open()) {
		cout << "Could not open file FahrenheitTemperature.txt." << endl;
		return 1;
	}

	cout << "Opening file CelsiusTemperature.txt." << endl;

	output.open("CelsiusTemperature.txt");

	while (!input.eof()) {
		input >> city;
		input >> temp;

		output << city << " ";
		output << fixed << setprecision(2) << ConvertTemp(temp) << endl;

	}

	cout << "File FahrenheitTemperature.txt successfully read from and closing file." << endl;
	cout << "File CelsiusTemperature.txt successfully wrote to and closing file." << endl;
	input.close();
	output.close();

}