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
		//���� ù ���ڰ� ������ �� ����
		if (str[i] == find_str[0]) {
			for (int j = 0; j < b; j++) {
				if (!(str[i + j] == find_str[j])) {
					break;//���� �ϳ��� ���ϴٰ� �ƴϸ� for�� Ż��
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