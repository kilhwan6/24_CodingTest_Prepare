#include <iostream>
#include <stdio.h>
#include <algorithm>
#define endl "\n"

using namespace std;

int map[100][100] = { {0,}, };
int result;

/*
* �� column���� 0�ʿ� ����� 1, ū �ʿ� ����� 2 ������ ������
* result�� 1 �߰�
* 
* �� ��Ģ�� ������ ����.
* 1. if������ 1 2 �������� ���� ī��Ʈ
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
	int b;

	for (int x = 0; x < 100; x++) {//x 0���� 100����
		for (int y = 0; y < 100 - 1; y++) {// y 0 ���� 100���� ����
			a = map[y][x];
			b = map[y + 1][x];
			if (a == 1 && b == 2) {
				result++;
			}
		}

	}
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