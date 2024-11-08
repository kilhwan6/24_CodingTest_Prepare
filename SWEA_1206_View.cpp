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
	for (int i = 2; i < (T - 2); i++) {//0,1��° �ǹ� ������ ����, ������ 2���� ����
		//�¿� 2�� ���ؼ�, ������ ū �� ������ ����
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
�迭�� �� �ʿ䰡 ������? ������ �ִ���

1. �Է¹ޱ�
��2 ��2 �迭 �Է¹ޱ�
2. if ������ ��

	Ȯ���� �� �ڸ� ����ŭ �߰�
*/

int main()
{
	int test_case;
	for (test_case = 1; test_case <= 10; ++test_case)
	{
		//�ʱ�ȭ
		reset();
		//�Է�
		input();
		//�˰���
		compare(T);
		output();
	}
	return 0;
}

