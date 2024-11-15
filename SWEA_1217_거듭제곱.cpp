#include <stdio.h>
#include <iostream>
#define endl "\n"

using namespace std;

int N, M;
int result;
int testcase_num;

void input() {
	N = 0;
	M = 0;
	testcase_num = 0;
	cin >> testcase_num;
	cin >> N >> M;
}

void func(int a, int b, int c) {
	//≈ª√‚¡∂∞«
	if (b = 1) {
		result = c;
	}
	else {
		c *= a;
		b--;
		func(a, b, c);
	}
}

void output() {
	cout << "#" << testcase_num << " " << result << endl;
}

int main() {
	for (int i = 0; i < 10; i++) {
		input();
		func(N, M, N);
		output();
	}
}