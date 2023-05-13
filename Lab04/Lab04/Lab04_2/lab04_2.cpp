#include <iostream>
using namespace std;

void bubbleSort(int* arr, int N)
{
	int num;
	for (int i = 1; i < N; i++)
		for (int j = i; j > 0 && arr[j - 1] > arr[j]; j--) {
			num = arr[j - 1];
			arr[j - 1] = arr[j];
			arr[j] = num;
		}
}

void main() {
	int N, diploma = 0, cnt = 0, maxPoint = 100;
	int* results;
	string check;
	cout << "Enter the number of members: ";
	cin >> N;
	if (N >= 10000) {
		cout << "Incorrect input! Do it correctly (<10000)";
		exit(0);
	}
	results = new int[N];

	srand(time(NULL));
	for (int i = 0; i < N; i++) {
		results[i] = rand() % 100 + 1;
		cout << "Medalist " << i + 1 << " = " << results[i] << endl;
	}

	bubbleSort(results, N);

	for (int i = 0; i < N; i++) {
		cout << results[i] << ' ';
	}
	cout << endl;

	for (int i = N - 1; i > 0; i--) {
		if (diploma == 3) {
			break;
		}
		else {
			cnt++;
			if (i == 1 && results[i] == results[0])
				cnt++;
		}
		if (results[i] != results[i - 1]) {
			diploma++;
		}
	}
	cout << "Number of medalists: " << cnt << endl;

	delete[] results;
}