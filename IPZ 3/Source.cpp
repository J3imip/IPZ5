#include <iostream>
#include <fstream>
using namespace std;

void cinValidate(string error) {
	if (cin.fail()) throw(error); //check if entered data is incorrect (like types mismatch or smth else).
}

//I've decided to make checkInputParameters() function based on overloads.
void checkInputParameters(double start, double end) {
	if (end < start) throw(string("End must be less than the start."));
}

void checkInputParameters(double start, double end, double step) {
	if (step > (end - start)) throw(string("Step is too large."));
	else if (step <= 0) throw(string("Step must be greater than 0.")); //causes infinite loop if less of equals 0.
}

void checkInputParameters(double n) {
	if (n != (int)n) throw(string("Parameter n must be an integer."));
}

void read(
	double &start, 
	double &end, 
	double &step, 
	double &n,
	bool &write
) {
	cout << "Enter the start and end of the interval: ";
	cin >> start >> end;
	cinValidate("Start or end variables is incorrect (must be a double)."); //instant check after user input to prevent from waiting for the end of the user input to check if something incorrect.
	checkInputParameters(start, end);

	cout << "Enter the step: ";
	cin >> step;
	cinValidate("Step is incorrect (must be a double).");
	checkInputParameters(start, end, step);

	cout << "Enter n: ";
	cin >> n;
	cinValidate("Parameter n is incorrect (must be a double).");
	checkInputParameters(n);


	cout << "Write results to file? (1 - yes, 0 - no) ";
	cin >> write;
	cinValidate("Write parameter is incorrect (must be only 1 or 0)");
}

int calculate(double n, double x) {
	int y = 0;
	if (x < 0) {
		for (int i = 1; i <= n; i++) {
			y += pow((i + x), 2);
		}
		return y;
	}
	else {
		for (int i = 0; i <= (n - 1); i++) {
			int temp = 1;
			for (int j = 1; j <= n; j++) {
				int divider = i - j;
				if (divider == 0) continue; //can not devide on 0 for obvious reasons)
				temp *= (x + i) / divider;
			}
			y += temp;
		}
		return y;
	}
}

int main() {
	double start, end, step, n, y = 0;
	ofstream results;
	bool write;
	try
	{
		read(start, end, step, n, write);
		if (write) results.open("results.txt", ios::out | ios::trunc);

		for (int x = start; x <= end; x += step) {
			cout << "x = " << x << "; y = " << calculate(n, x) << endl;
			if(write) results << "x = " << x << "; y = " << calculate(n, x) << endl; //write results in a file
		}

		if (write) results.close();
	}
	catch (const string exception)
	{
		cout << exception << endl; //output errors that described in checkInputParameters() or cinValidate()
		return -1;
	}
	catch (...) { //unexpected error handler
		cout << "Unknown error." << endl; 
		return -2;
	}
}
