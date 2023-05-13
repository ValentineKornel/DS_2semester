#include <iostream>
using namespace std;

void bubbleSort(int* arr, int N)
{
	int buff = 0;

	for (int i = 0; i < N - 1; i++)
	{
		for (int j = N - 1; j > i; j--)
		{
			if (arr[j] < arr[j - 1])
			{
				buff = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = buff;
			}
		}
	}
}

void main() {
	int num, sum = 0;

	cout << "Enter amount of array elements: ";
	cin >> num;
	if (num >= 10000) {
		cout << "Incorrect input! Do it correctly(<10000)";
		exit(0);
	}
	int* arr = new int[num];
	cout << "Prices: " << endl;
	srand(time(NULL));
	for (int i = 0; i < num; i++) {
		arr[i] = rand() % 100 + 1;
		cout << arr[i] << ';' << endl;
	}
	cout << endl;
	bubbleSort(arr, num);
	for (int i = 0; i < num; i++) {
		cout << arr[i] << ' ';
	}
	cout << endl;

	cout << "Bill after sort: " << endl;
	for (int i = 0, start = 0, end = num - 1; i < num; i++) {
		if ((i + 1) % 2 == 0) {
			cout << arr[start++] << ';' << endl;
		}
		else {
			sum += arr[end];
			cout << arr[end--] << ';' << endl;
		}
	}
	cout << endl << "The biggest  billâ summ: " << sum;
	delete[] arr;
}