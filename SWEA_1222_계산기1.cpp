#include <iostream>
#include <cstring>
#include <string>
#define endl "\n"
using namespace std;

int table_len;
string table;
int result;

void input() {
	result = 0;
	table_len = 0;
	table.clear();

	cin >> table_len;
	cin >> table;
}

void func() {
	for (int i = 0; i < table.size(); i += 2) {
		if (isdigit(table[i])) {
			result += table[i] - '0';
		}
	}
}

void output(int testcase_num) {
	cout << "#" << testcase_num << " " << result << endl;
}

int main() {
	for (int i = 1; i < 11; i++) {
		input();
		func();
		output(i);
	}
	return 0;
}