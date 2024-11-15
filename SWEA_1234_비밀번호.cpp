#include <stdio.h>
#include <iostream>
#include <vector>
#include <string.h>
#define endl "\n"

using namespace std;

int N;
string str;
vector <int>v;
string result;


void input() {
	cin >> N >> str;
}

void func() {
	//str안의 숫자를 벡터로 넣기
	for (int i = 0; i < N; i++)
	{
		v[i] = str[i];
	}

	int a, b;
	bool flag = true;
	while (flag) {
		//탈출조건 -> flag가 한번도 안켜지면 탈출
		flag = false;
		for (int i = 0; i < N - 1; i++) {
			a = v[i];
			b = v[i + 1];
			if (a == b) {
				v.erase(v.begin() + i);
				v.erase(v.begin() + i + 1);
				flag = true;
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		v[i] = str[i];
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