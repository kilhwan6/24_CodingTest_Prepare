#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#define endl "\n"

using namespace std;
int N, M;
vector <int>v;
vector <int>add;
string result;

void input() {
	v.clear();
	add.clear();
	result.clear();

	int a;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a;
		v.push_back(a);
	}
}

void func() {

	int x, y, s;
	string a;
	cin >> M;
	for (int i = 0; i < M; i++) {
		add.clear();

		cin >> a;

		if (a == "I") {//추가 시
			cin >> x >> y;
			for (int j = 0; j < y; j++) {
				cin >> s;
				add.push_back(s);
			}
			for (int j = 0; j < y; j++) {
				s = add.back();
				v.emplace(v.begin() + x, s);
				add.pop_back();
			}
			for (int j = 0; j < y; j++) {
				v.pop_back();
			}
		}

		else {//삭제 시
			cin >> x >> y;
			for (int j = 0; j < y; j++) {
				v.erase(v.begin() + x);
			}
		}
	}

	//10개만 남기기
	for (int i = 0; i < 10; i++) {
		a = to_string(v[i]);
		result.append(a);
		result.append(" ");
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
}