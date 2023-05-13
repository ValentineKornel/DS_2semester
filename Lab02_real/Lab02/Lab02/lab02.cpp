#include <iostream>
#include <cmath> 
using namespace std;

int main()
{
	setlocale(LC_ALL, "RUS");
	int N, choice = 0, left = 1, right, mid;
	int right2, left2 = left;
	bool check = false;
	cout << "������� �������� ����� (�� 1 �� N) "; cin >> right;
	right2 = right;
	cout << "������� ���������� ����� ";	cin >> N;
	mid = right / 2;
	do {
		if (choice == 1) {
			left = mid;
			mid = (right + left) / 2;
		}
		if (choice == 2) {
			right = mid;
			mid = (right + left) / 2;
		}
		if (choice == 3 || mid == N)
			check = true;
		system("cls");
		cout << mid << endl;
		cout << "1)������ " << endl;
		cout << "2)������" << endl;
		cout << "3)������" << endl;
		cin >> choice;
	} while (check != true);
	system("cls");
	cout << "��������� �����: " << N << endl;
	cout << "������������ ���������� ����� = " << round(log2(right2)) << endl;

	for (int m = 1, n = right2; n > 1; m++)
	{
		mid = (left2 + right2) / 2;
		cout << "��� " << m << " ����� " << mid << endl;
		right2 = mid;
		n = mid;
	}
	return 0;
}