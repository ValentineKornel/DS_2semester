#include <iostream>
#include <time.h>
using namespace std;

int fib(int n) {
	if (n == 1 or n == 2) {
		return 1;
	}
	if (n == 0) {
		return 0;
	}
	return fib(n - 1) + fib(n - 2);
}

void main() {
	setlocale(LC_CTYPE, "Russian");
	int n = 0;
	while (n != 3) {
		cout << "Choose the task number: 1 - recursion, 2 - linear, 3 - exit";
		cin >> n;
		switch (n) {
		case 1:
			double spen_time = 0.0;

			clock_t begin = clock();

			int numb = 0;
			cout << "Enter the nubmer in fibonachi sequence: ";
			cin >> numb;
			cout << fib(numb - 1) << endl;

			clock_t en = clock();
			spen_time = (double)(en - begin) / CLOCKS_PER_SEC;

			cout << "Runtime: " << spen_time << " seconds";
		case 2:
			double spent_time = 0.0;

			clock_t start = clock();

			int f1 = 0;
			int f2 = 1;
			int f3 = 0;
			int number = 0;
			cout << "Enter the nubmer in fibonachi sequence: ";
			cin >> number;

			for (int i = 0; i < number - 2; i++) {
				f3 = f2 + f1;
				f1 = f2;
				f2 = f3;
			}
			cout << f3 << endl;

			clock_t end = clock();
			spent_time = (double)(end - start) / CLOCKS_PER_SEC;

			cout << "Runtime: " << spent_time << " seconds";
		}
	}
}

