#include "Series.h"
#include <math.h>
#include <string>
#include <stack> 

using namespace std;

void Series::geometricSeries() {
	int command;
	cout << "Enter 1 or 2. Option 1 is entering the first term and r. Option 2 is entering a series of numbers and finding r." << endl;
	cin >> command;
	if (command == 1) {
		double r = 0;
		double a = 0;
		double sum = 0;
		double denominator;
		double numerator;
		cout << "Please enter the first term(a): ";
		cin >> a;
		cout << "Please enter numerator for r: ";
		cin >> numerator;
		cout << "Please enter denominator for r: ";
		cin >> denominator;
		r = (numerator / denominator);
		cout << "r = " << r << endl;
		if (r > -1 && r < 1) {
			cout << "The series is convergent. " << endl;
			sum = (a / (1 - r));
			cout << "The sum is: " << sum << endl;
		}
		else {
			cout << "The series is divergent. " << endl;
		}
	}
	else {
		Stack hold(1000);
		Stack hold2(1000);
		int counter = 0;
		double number = 0;
		double r = 0;
		double p = 0;
		double a = 0;
		double value = 0;
		double first = 0;
		double second = 0;
		double sum = 0;
		bool done = false;
		cout << "Enter numbers: " << endl;
		cin >> value;
		while (value != 0) {
			hold.push(value);
			counter++;
			cin >> value;
		}
		while (!hold.empty()) {
			hold2.push(hold.pop());
		}
		first = hold2.pop();
		a = first;
		second = hold2.pop();
		hold2.push(second);
		r = second / first;
		number = r;
		p = r;
		while ((!(done)) && counter > 2) {
			first = hold2.pop();
			second = hold2.pop();
			hold2.push(second);
			p = second / first;
			counter--;
			if (p != number) {
				done = true;
			}
			else if (p == number) {
				done = false;
			}
		}
		if (done == false && r > -1 && r < 1) {
			cout << "The series is convergent." << endl;
			cout << "r = " << r << endl;
			cout << "The first term is " << a << endl;
			sum = (a / (1 - r));
			cout << "The sum is " << sum << endl;
		}
		else {
			cout << "The series is divergent." << endl;
		}
		cout << endl;
	}
}

bool Series::wholeNumber(double num) {
	if (num == (int)num) {
		return true;
	}
	else {
		return false;
	}
}

int reduce_fraction(int &numerator, int &denominator)
{
	for (int i = denominator * numerator; i > 1; i--) {
		if ((denominator % i == 0) && (numerator % i == 0)) {
			denominator /= i;
			numerator /= i;
		}

	}
	return denominator;
}

void Series::p_Series() {
	cout << "A p-series must be in the form (1/(n)^p)" << endl;
	int command;
	cout << "Enter 1 or 2. Option 1 is entering p. Option 2 is entering a series of numbers and finding p." << endl;
	cin >> command;
	if (command == 1) {
		double p = 0;
		double n = 0;
		double total = 0;
		double sum = 0;
		double numerator = 0;
		long denominator = 0;
		double divisor = 0;
		cout << "Enter numerator: ";
		cin >> numerator;
		cout << "Enter p: ";
		cin >> p;
		if (numerator != 1) {
			cout << "The series is not a p-series because numerator is not 1. " << endl;
		}
		else if (p > 1 && numerator == 1) {
			cout << "The series is: (" << numerator << "/" << "(" << "n" << ")" << "^" << p << ") " << endl;
			cout << "The series is convergent. " << endl;
			cout << "Find the sum of the series from 1 to ";
			cin >> n;
			for (int i = 1; i <= n; i++) {
				divisor = 1.0 / i;
				sum = pow(divisor, p);
				total = total + sum;
				if (i < n) {
					cout << total << " + ";
				}
				else {
					cout << " = " << total << endl;
				}
			}
			cout << "The sum is " << total << endl;
		}
		else if (p < 1 && numerator == 1) {
			cout << "The series is divergent. " << endl;
		}
	}
	else {
		//Stack hold(1000);
		//Stack hold2(1000);
		int counter = 0;
		double number = 1;
		double j = 2.0;
		double p = 0;
		double exponent = 0;
		//double value = 0;
		double first = 0;
		double sum = 0;
		bool done = false;
		bool done2 = false;
		bool whole = false;
		//double num = 1;
		//double origNum = 1;
		//double rem = 1;
		//int den = 1;
		//int count = 0;
		//int gcd = 1;


		int numer = 0;
		int denom = 0;
		Stack den(10000);
		Stack origDen(10000);
		cout << "Enter numerator and denominator of first term: " << endl;
		cout << "Numerator: ";
		cin >> numer;
		cout << "Denominator: ";
		cin >> denom;
		denom = reduce_fraction(numer, denom);
		while (numer == 1  && denom != 0) {
			cout << numer << "/" << denom << endl;
			den.push(denom);
			counter++;
			cout << "Next term: " << endl;
			cout << "Numerator: ";
			cin >> numer;
			cout << "Denominator: ";
			cin >> denom;
			denom = reduce_fraction(numer, denom);
		}
		if (numer != 1) {
			cout << "Not a p-series" << endl;
			return;
		}

		while (!den.empty()) {
			origDen.push(den.pop());
		}
		origDen.pop();
		first = origDen.pop();
		counter -= 2;
		while (!done && j < 10) {
			exponent = 1.0 / j;
			number = pow(first, exponent);
			whole = wholeNumber(number);
			if (whole == true) {
				p = j;
				done = true;
			}
			j++;
		}
		if (done == false) {
			cout << "Not a p-series. P could not be found." << endl;
			return;
		}
		while ((!(done2)) && counter > 0) {
			first = origDen.pop();
			p = 1 / p;
			first = pow(first, p);
			whole = wholeNumber(first);
			counter--;
			if (whole == true) {
				done2 = false;
			}
			else {
				done2 = true;
			}
		}
		if (done2 == false && p < 1) {
			cout << "The series is convergent. p = " << j << endl;
		}
		else if (done2 == true) {
			cout << "The series id divergent." << endl;
		}
	}
}
