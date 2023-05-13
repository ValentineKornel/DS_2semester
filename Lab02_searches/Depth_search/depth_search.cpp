#include <iostream>
#include <stack>
using namespace std;

void main() {
	stack<int> q;
	int mas[10][10] = {
  {0, 1, 0, 0, 1, 0, 0, 0, 0, 0},
  {1, 0, 0, 0, 0, 0, 1, 1, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
  {0, 0, 0, 0, 0, 1, 0, 0, 1, 0},
  {1, 0, 0, 0, 0, 1, 0, 0, 0, 0},
  {0, 0, 0, 1, 1, 0, 0, 0, 1, 0},
  {0, 1, 0, 0, 0, 0, 0, 1, 0, 0},
  {0, 1, 1, 0, 0, 0, 1, 0, 0, 0},
  {0, 0, 0, 1, 0, 1, 0, 0, 0, 1},
  {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
	};

	int nodes[10];
	for (int i = 0; i < 10; i++)
		nodes[i] = 0;
	q.push(0);
	while (!q.empty()) {
		int node = q.top();
		q.pop();
		if (nodes[node] == 2) continue;
		nodes[node] = 2;
		for (int j = 9; j >= 0; j--) {
			if (mas[node][j] == 1 && nodes[j] != 2) {
				q.push(j);
				nodes[j] = 1;
			}
		}
		cout << node + 1 << endl;
	}
}