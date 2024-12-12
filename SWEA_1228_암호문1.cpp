#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#define endl "\n"

using namespace std;

vector <int> v;
string result;

void input() {
	v.clear();
	result.clear();

	int length;
	cin >> length;

	int a;
	for (int i = 0; i < length; i++) {
		cin >> a;
		v.push_back(a);
	}
}

void func() {
	int length;
	cin >> length;

	for (int i = 0; i < length; i++) {
		vector <int> v2;
		char a;
		int x, y;
		cin >> a;
		cin >> x >> y;

		for (int j = 0; j < y; j++) {//add 에 추가
			int b;
			cin >> b;
			v2.push_back(b);
		}
		v.insert(v.begin() + x, v2.begin(), v2.end());
	}
	//10개만 남기기
	for (int i = 0; i < 10; i++) {
		int a;
		a = v[i];
		result += to_string(a);
		result.append(" ");
	}
}

void output(int testcase_num) {
	cout << "#" << testcase_num << " " << result<<endl;
}

int main() {
	for (int i = 1; i < 11; i++) {
		input();
		func();
		output(i);
	}
}