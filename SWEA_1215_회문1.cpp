#include <stdio.h>
#include <cstring>
#include <iostream>
#define endl "\n"

using namespace std;

char map[8][8] = { 0, };
int length = 5;
int result;

void input() {
	//초기화
	memset(map, 0, sizeof(map));
	result = 0;
	//입력

	length = 0;
	cin >> length;
	char input;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			cin >> input;
			map[j][i] = input;
		}
	}
}

bool isPalindrome(int row, int col, int len, bool isHorizontal) {
	int start = 0, end = len - 1;
	while (start < end) {
		if (isHorizontal) {
			if (map[row][col + start] != map[row][col + end]) {
				return false;
			}
		}
		else {
			if (map[row + start][col] != map[row + end][col]) {
				return false;
			}
		}
		start++;
		end--;
	}
	return true;
}

void func() {
	//시작점, 끝점 비교
	//시작점 ++, 끝점 --
	//1. 시작점이 끝점보다 커지면 종료(result ++)
	//2. 값이 같지 않으면 종료
	//가로
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j <= 8 - length; j++) {
			if (isPalindrome(i, j, length, true)) {
				result++;
			}
		}
	}

	//세로
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j <= 8 - length; j++) {
			if (isPalindrome(j, i, length, false)) {
				result++;
			}
		}
	}
}

void output(int testcase_num) {
	cout << "#" << testcase_num << " " << result << endl;
}

int main() {
	for (int i = 1; i <= 10; i++) {
		input();
		func();
		output(i);
	}
	return 0; 
}