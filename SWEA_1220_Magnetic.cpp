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
	bool flag = false;
	//flag �� N(1) �߰� �� true, �� ���¿��� S(2) �߰��ϸ�
	// result ++, flag != flag;
	//1�� N��, 2�� S��
	//�������� N�� 
	for (int x = 0; x < 100; x++) {//x 0���� 100����
		flag = false;
		for (int y = 0; y < 100; y++) {// y 0 ���� 100���� ����
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