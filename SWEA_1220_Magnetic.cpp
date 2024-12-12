#include <iostream>
#include <stdio.h>
#include <algorithm>
#define endl "\n"

using namespace std;

int map[100][100] = { {0,}, };
int result;

/*
* 각 column에서 0쪽에 가까운 1, 큰 쪽에 가까운 2 패턴이 나오면
* result에 1 추가
* 
* 즉 규칙은 다음과 같다.
* 1. if문으로 1 2 연속패턴 개수 카운트
*/

void input() {
	result = 0;
	int a = 0;
	int b = 0;

	cin >> a;

	for (int y = 0; y < 100; y++) {
		for (int x = 0; x < 100; x++) {
			cin >> b;
			map[y][x] = b;
		}
	}
}

void func() {
	int a;
	bool flag = false;
	//flag 는 N(1) 발견 시 true, 그 상태에서 S(2) 발견하면
	// result ++, flag != flag;
	//1은 N극, 2는 S극
	//작은쪽이 N극 
	for (int x = 0; x < 100; x++) {//x 0부터 100까지
		flag = false;
		for (int y = 0; y < 100; y++) {// y 0 부터 100까지 세기
			a = map[y][x];
			if (a == 1) {
				flag = true;
			}
			else if (a == 2 && flag == true){
				result++;
				flag = false;
			}
		}

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
	return 0;
}