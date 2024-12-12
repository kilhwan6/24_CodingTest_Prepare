#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#define endl "\n"

using namespace std;
int N, M;
vector <int>v;
string result;

void input() {
	v.clear();
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
	char a;
	cin >> N;
	for (int i = 0; i < N; i++) {
		vector <int> v2;
		cin >> a;
		if (a == 'I') {//추가 시
			cin >> x >> y;
			for (int j = 0; j < y; j++) {
				cin >> s;
				v2.push_back(s);
			}
			v.insert(v.begin() + x, v2.begin(), v2.end());
		}

		else if (a == 'D'){//삭제 시
			cin >> x >> y;
			for (int j = 0; j < y; j++) {
				v.erase(v.begin() + x);
			}
		}
	}

	//10개만 남기기
	for (int i = 0; i < 10; i++) {
		result += to_string(v[i]);
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