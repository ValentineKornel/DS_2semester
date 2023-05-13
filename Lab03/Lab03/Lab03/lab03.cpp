#include <iostream>
#include <ctime>
#include <time.h>
#include <Windows.h>
using namespace std;

void sortBubble(int*, int);  // n^2
void sortInsert(int*, int);  // n^2
void sortSelection(int*, int); // n^2
void sortQuick(int* arr, int first, int last); // n * log n
void outArr(int*, int, int i = 0);


void main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int size;
	double time_bubble, time_insert, time_selection, time_quick;
	clock_t start, end;

	cout << "Enter amount of array elements: ";
	cin >> size;

	int* A = new int[size], * B = new int[size], * C = new int[size],
		* D = new int[size], * E = new int[size];

	cout << "Original array: " << endl;
	srand(time(NULL));
	for (int i = 0, num; i < size; i++) {
		num = rand() % 100;
		A[i] = B[i] = C[i] = D[i] = E[i] = num;
	}
	outArr(A, size);

	cout << endl;

	cout << "Array sorted by the bubble sort is: " << endl;
	start = clock();
	sortBubble(B, size);
	end = clock();
	outArr(B, size);
	time_bubble = (double)(end - start);

	cout << endl;

	cout << "Array sorted by the insert sort is: " << endl;
	start = clock();
	sortInsert(C, size);
	end = clock();
	outArr(C, size);
	time_insert = (double)(end - start) / CLOCKS_PER_SEC;

	cout << endl;

	cout << "Array sorted by the selection sort is: " << endl;
	start = clock();
	sortSelection(D, size);
	end = clock();
	outArr(D, size);
	time_selection = (double)(end - start) / CLOCKS_PER_SEC;

	cout << endl;

	cout << "Array sorted by quick sort is: " << endl;
	start = clock();
	sortQuick(E, 0, size - 1);
	end = clock();
	outArr(E, size);
	time_quick = (double)(end - start) / CLOCKS_PER_SEC;

	cout << endl;

	cout << "Bubble sort took " << time_bubble << " мс" << endl;
	cout << "Insert sort took " << time_insert << " мс" << endl;
	cout << "Selection sort took " << time_selection << " мс" << endl;
	cout << "Quick sort took " << time_quick << " мс" << endl;

	delete[] A;
	delete[] B;
	delete[] C;
	delete[] D;
	delete[] E;
}


void outArr(int* arr, int N, int i) {
	
	if (i == N)
		return;
	cout << arr[i++] << ";" << endl;
	outArr(arr, N, i);
}

void sortBubble(int* arr, int N) 
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

void sortInsert(int* arr, int N)
{
	int num;
	for (int i = 1; i < N; i++)
		for (int j = i; j > 0 && arr[j - 1] > arr[j]; j--) {//запомним обрабатываемый элемент arr[j]
			num = arr[j - 1];                               // и начнем перемещение элементов слева от него
	                                                       // пока запомненный не окажетс€ меньше чем перемещаемый
			arr[j - 1] = arr[j];
			arr[j] = num;
		}
}

void sortSelection(int* arr, int N)
{
	int min = 0;
	int buf = 0;
	for (int i = 0; i < N; i++)
	{
		min = i;  // запомним номер текущей €чейки, как €чейки с минимальным значением
		for (int j = i + 1; j < N; j++)  // в цикле найдем реальный номер €чейки с минимальным значением
			min = (arr[j] < arr[min]) ? j : min;
		if (i != min)
		{
			buf = arr[i];
			arr[i] = arr[min];
			arr[min] = buf;
		}
	}
}

void sortQuick(int* arr, int first, int last)
{
	int mid, count;
	int f = first, l = last;
	mid = arr[(f + l) / 2];
	do
	{
		while (arr[f] < mid)
			f++;
		while (arr[l] > mid)
			l--;
		if (f <= l)
		{
			count = arr[f];
			arr[f] = arr[l];
			arr[l] = count;
			f++;
			l--;
		}
	} while (f < l);
	if (first < l) sortQuick(arr, first, l);
	if (f < last) sortQuick(arr, f, last);
}