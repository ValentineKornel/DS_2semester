#include <iostream>
#include <time.h>
using namespace std;


void main() {
	setlocale(LC_CTYPE, "Russian");
	double spent_time = 0.0;
	double spent_time_sec = 0.0;
	int spent_time_min = 0;


	int f1 = 0;
	int f2 = 1;
	int f3 = 0;
	int number = 0;
	cout << "Enter the nubmer in fibonachi sequence: ";
	cin >> number;

	clock_t start = clock();
	for (int i = 0; i < number - 2; i++) {
		f3 = f2 + f1;
		f1 = f2;
		f2 = f3;
	}
	cout << f3 << endl;

	clock_t end = clock();
	spent_time = (double)(end - start) / CLOCKS_PER_SEC;
	spent_time_min = (int)(spent_time / 60);
	spent_time_sec = (double)(end - start) / CLOCKS_PER_SEC; - (spent_time_min * 60);

	cout << "Расчетное время циклом " << spent_time_min << " минут " << spent_time_sec << " секунд";
}