#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#define endl "\n"

using namespace std;

int T, N, M;
int map[51][101] = { {0, }, }; // y, x좌표
string str;
int ans, result;

void input() {
	ans = 0;
	result = 0;
	//for (int i = 0; i < 51; i++) {
	//	for (int j = 0; j < 101; j++) {
	//		map[j][i] = 0;
	//	}
	//}
	memset(map, 0, sizeof(map)); // 배열 초기화

	cin >> N >> M;
	int a;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> a;
			map[i][j] = a;
		}
	}
}

void func() {
	/*
	* 스캐너
	* 1. 모든 행에 대하여, 뒤에서부터 값 읽어오다가 1발견하기
	* 2. 1 발견하면 7글자씩 묶기
	* 3. 묶은 글자 8개 저장
	* 4. 처리(연산)
	* 5. 연산 이후 판단, 초기화
	*/
	int value;
	int x, y;
	x = M;
	y = N;

	//탈출조건
	//1. 1을 찾았을 때
	while (true) {
		value = map[y][x];
		if (value == 1) {
			break;
		}
		//1. x값이 0보다 작으면 y -- 
		if (x < 0) {
			x = M;	
			y--;
		}
		else x--;
	}

	//암호문 해독
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 7; j++) {
			str += to_string(map[y][x]);
			x--;
		}
		if (str == "0001101") {//0
			;
		}
		else if (str == "0011001") {//1
			ans += 1;
			result += 1;
			result += 1 * (i % 2) * 2;
		}
		else if (str == "0010011") {//2
			ans += 2;
			result += 2;
			result += 2 * (i % 2) * 2;
		}
		else if (str == "0111101") {//3
			ans += 3;
			result += 3;
			result += 3 * (i % 2) * 2;
		}
		else if (str == "0100011") {//4
			ans += 4;
			result += 4;
			result += 4 * (i % 2) * 2;
		}
		else if (str == "0110001") {//5
			ans += 5;
			result += 5;
			result += 5 * (i % 2) * 2;
		}
		else if (str == "0101111") {//6
			ans += 6;
			result += 6;
			result += 6 * (i % 2) * 2;
		}
		else if (str == "0111011") {//7
			ans += 7;
			result += 7;
			result += 7 * (i % 2) * 2;
		}
		else if (str == "0110111") {//8
			ans += 8;
			result += 8;
			result += 8 * (i % 2) * 2;
		}
		else if (str == "0001011") {//9
			ans += 9;
			result += 9;
			result += 9 * (i % 2) * 2;
		}
		str.clear();
		y--;
	}
	
	//결과값 판별식
	if (result % 10 != 0)
	{
		ans = 0;
	}
}

void output(int testcase_num) {
	cout << "#" << testcase_num << " " << ans << endl;
}

int main() {
	cin >> T;
	for (int i = 1; i < T + 1; i++) {
		input();
		func();
		output(i);
	}
	return 0;
}
