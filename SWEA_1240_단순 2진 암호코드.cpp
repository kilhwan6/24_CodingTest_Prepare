#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#define endl "\n"

using namespace std;

int T, N, M;
int map[51][101] = { {0, }, }; // y, x��ǥ
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
	memset(map, 0, sizeof(map)); // �迭 �ʱ�ȭ

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
	* ��ĳ��
	* 1. ��� �࿡ ���Ͽ�, �ڿ������� �� �о���ٰ� 1�߰��ϱ�
	* 2. 1 �߰��ϸ� 7���ھ� ����
	* 3. ���� ���� 8�� ����
	* 4. ó��(����)
	* 5. ���� ���� �Ǵ�, �ʱ�ȭ
	*/
	int value;
	int x, y;
	x = M;
	y = N;

	//Ż������
	//1. 1�� ã���� ��
	while (true) {
		value = map[y][x];
		if (value == 1) {
			break;
		}
		//1. x���� 0���� ������ y -- 
		if (x < 0) {
			x = M;	
			y--;
		}
		else x--;
	}

	//��ȣ�� �ص�
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
	
	//����� �Ǻ���
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
