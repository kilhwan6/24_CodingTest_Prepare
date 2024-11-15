#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#define endl "\n"

using namespace std;

int map[8][8] = { {0,}, };
int length;
int result;

void input() {
	//초기화
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			map[j][i] = 0;
		}
	}
	int input = 0;
	length = 0;
	//입력
	cin >> length;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			cin >> input;
			map[j][i] = input;
		}
	}
}

void func() {
	//시작점, 끝점 비교
	//시작점 ++, 끝점 --
	//1. 시작점이 끝점보다 커지면 종료(result ++)
	//2. 값이 같지 않으면 종료
}

void output(int testcase_num) {
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