#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <queue>
#define endl "\n"

using namespace std;

int testcase_num;
queue<int> num_list;
string output_str;

void input() {
	testcase_num = 0;
	for (int i = 0; i < 8; i++) {
		num_list.pop();
	}

	int a;

	cin >> testcase_num;
	for (int i = 0; i < 8; i++) {
		cin >> a;
		num_list.push(a);
	}
}
void func() {
	int minus_num = 1;
	int key = 0;
	int a = 0;
	int b = 0;
	while (true) {
		//탈출조건
		key = num_list.back();
		if (key == 0) break;
		//map에서 1 감소하고 보내기
		a = num_list.front();
		num_list.pop();
		a -= minus_num;
		num_list.push(a);
		minus_num++;
	}
	for (int i = 0; i < 8; i++) {
		b = num_list.front();
		num_list.pop();

		output_str.push_back(b);
		output_str.append(" ");
	}
}
void output() {
	cout << "#" << testcase_num << " " << output_str <<endl;
	//이후 결과 출력
}
int main() {

	for (int i = 0; i < 10; i++) {
		input();
		func();
		output();
	}

	return 0;
}