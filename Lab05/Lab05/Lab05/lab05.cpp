#include <iostream>
#include <stack>
using namespace std;

bool isCorrectBrackets(string s) {
	stack<char> stk;
	for (char symbol : s) {
		switch (symbol) {
		case '(': stk.push(')'); break;
		case '[': stk.push(']'); break;
		case '{': stk.push('}'); break;
		case '<': stk.push('>'); break;


		case ')':
		case ']':
		case '}':
		case '>':
			if (stk.empty() || stk.top() != symbol) {
				return false;
			}
			stk.pop();
			break;
		default:
			break;
		}
	}
	return stk.empty();
}

bool checkIsThereBrackets(string s) {
	int len = s.length();
	for (int i = 0; i < len; i++) {
		if (s[i] == '(' or s[i] == ')'
			or s[i] == '[' or s[i] == ']'
			or s[i] == '{' or s[i] == '}'
			or s[i] == '<' or s[i] == '>')
			return true;
	}
	return false;
}

void main() {
	string string_to_check;
	cout << "Enter the sting to check: ";
	cin >> string_to_check;
	if (checkIsThereBrackets(string_to_check)) {
		if (isCorrectBrackets(string_to_check))
			cout << endl << "Brackets are palced correctly" << endl;
		else
			cout << endl << "Brackets are placed INCORRECTLY!!!" << endl;
	}
	else
		cout << endl << "There is no any brackets in the string" << endl;
}