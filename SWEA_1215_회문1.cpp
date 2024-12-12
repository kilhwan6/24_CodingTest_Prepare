#include <stdio.h>
#include <cstring>
#include <iostream>
#define endl "\n"

using namespace std;

char map[8][8] = { 0, };
int length = 5;
int result;

void input() {
	//�ʱ�ȭ
	memset(map, 0, sizeof(map));
	result = 0;
	//�Է�

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
	//������, ���� ��
	//������ ++, ���� --
	//1. �������� �������� Ŀ���� ����(result ++)
	//2. ���� ���� ������ ����
	//����
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j <= 8 - length; j++) {
			if (isPalindrome(i, j, length, true)) {
				result++;
			}
		}
	}

	//����
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