#include <stdio.h>
#include <cstring>
#include <iostream>
#define endl "\n"

using namespace std;

char map[100][100] = { 0, };
int testcase_num;
int result;

void input() {
	//�ʱ�ȭ
	memset(map, 0, sizeof(map));
	result = 0;
	//�Է�

	cin >> testcase_num;
	char input;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
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
	int len = 100;
	bool flag = false;
	while (!flag) {
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j <= 100 - len; j++) {
				if (isPalindrome(i, j, len, true)) {
					flag = true;
					result = len;
				}
			}
		}

		//����
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j <= 100 - len; j++) {
				if (isPalindrome(j, i, len, false)) {
					flag = true;
					result = len;
				}
			}
		}
		len--;
	}
}

void output() {
	cout << "#" << testcase_num << " " << result << endl;
}

int main() {
	for (int i = 1; i <= 10; i++) {
		input();
		func();
		output();
	}
	return 0;
}