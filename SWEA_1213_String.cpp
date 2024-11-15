#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#define endl "\n"

using namespace std;
int result;
string str;
string find_str;

void input() {
	cin >> find_str;
	cin >> str;
}

void func() {
	int a = str.size() - find_str.size();
	int b = find_str.size();
	result = 0;

	for (int i = 0; i < a; i++) {
		//만약 첫 글자가 같으면 비교 수행
		if (str[i] == find_str[0]) {
			for (int j = 0; j < b; j++) {
				if (!(str[i + j] == find_str[j])) {
					break;//글자 하나씩 비교하다가 아니면 for문 탈출
				}
				else result++;
			}
		}
		else;
	}
}

void output(int testcase_num) {
	testcase_num += 1;
	cout << "#" << testcase_num << " " << result << endl;
}

int main() {
	for (int i = 0; i < 10; i++) {
		input();
		func();
		output(i);
	}
	return 0;
}