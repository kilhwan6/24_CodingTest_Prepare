#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#define endl "\n"

using namespace std;

vector <int>v;
vector <int>add;
string result;

void input() {
	v.clear();
	add.clear();

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

	string a;
	int x, y, s;
	for (int i = 0; i < length; i++) {
		add.clear();

		cin >> a;
		cin >> x >> y;

		for (int j = 0; j < y; j++) {//add 에 추가
			cin >> s;
			add.push_back(s);
		}
		for (int j = 0; j < y; j++) {//맨 뒤 add부터 추가하기
			s = add.back();
			v.emplace(v.begin()+x, s);
			add.pop_back();
		}
		for (int j = 0; j < y; j++) {
			v.pop_back();
		}
	}
	//10개만 남기기
	for (int i = 0; i < 10; i++) {
		a = v[i];
		result.append(a);
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