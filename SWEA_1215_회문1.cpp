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
	//�ʱ�ȭ
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			map[j][i] = 0;
		}
	}
	int input = 0;
	length = 0;
	//�Է�
	cin >> length;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			cin >> input;
			map[j][i] = input;
		}
	}
}

void func() {
	//������, ���� ��
	//������ ++, ���� --
	//1. �������� �������� Ŀ���� ����(result ++)
	//2. ���� ���� ������ ����
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