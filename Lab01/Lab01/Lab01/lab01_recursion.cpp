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
	double spent_time = 0.0;
	double spent_time_sec = 0.0;
	int spent_time_min = 0;


	int number = 0;
	cout << "Enter the nubmer in fibonachi sequence: ";
	cin >> number;
	clock_t start = clock();
	cout << fib(number - 1) << endl;

	clock_t end = clock();
	spent_time = (double)(end - start) / CLOCKS_PER_SEC;
	spent_time_min = (int)(spent_time / 60);
	spent_time_sec = spent_time - (spent_time_min * 60);

	cout << "–асчетное врем€ рекурсией " << spent_time_min <<" минут " << spent_time_sec << " секунд";
}