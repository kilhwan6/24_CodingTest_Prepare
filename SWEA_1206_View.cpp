#include <iostream>
#include <stdio.h>

using namespace std;

int map[1100] = { 0, };
int sum;

void input() {
	int T, map_input;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> map_input;
		map[i] = map_input;
	}
}

void reset() {
	for (int i = 0; i < 1100; i++) {
		map[i] = 0;
	}
	sum = 0;
}

void compare(int T) {
	int value = 0;
	int a, b, c, d;
	for (int i = 2; i < (T - 2); i++) {//0,1번째 건물 없으니 제외, 끝에서 2개도 제외
		//좌우 2개 비교해서, 나보다 큰 것 있으면 제외
		a = map[i] - map[i - 2];
		b = map[i] - map[i - 1];
		c = map[i] - map[i + 1];
		d = map[i] - map[i + 2];
		if (a > 0 && b > 0 && c > 0 && d > 0)
		{
			value = a;
			if (b > value) value = b;
			if (c > value) value = c;
			if (d > value) value = d;
		}
		sum += value;
	}
}

/*
배열을 쓸 필요가 있을까? 무조건 있더라

1. 입력받기
전2 후2 배열 입력받기
2. if 문으로 비교

	확보될 시 자른 수만큼 추가
*/

int main()
{
	int test_case;
	for (test_case = 1; test_case <= 10; ++test_case)
	{
		//초기화
		reset();
		//입력
		input();
		//알고리즘
		compare(T);
		output();
	}
	return 0;
}

