#include <stdio.h>
#include <iostream>
#include <algorithm>
#define endl '\n'
using namespace std;

int test_case;
int result;
int dump_num;
int map[100] = { 0, };


void Init() {
	result = 0;
	dump_num = 0;
	for (int i = 0; i < 100; i++) {
		map[i] = 0;
	}
}


//input
void Input() {
	int input;
	cin >> dump_num;
	for (int i = 0; i < 100; i++) {
		cin >> input;
		map[i] = input;
	}
}

void Output(int test_case_num) {
	cout << "#" << test_case_num << " " << result << endl;
}

void Func(){
	for (int i = 0; i < 10; i++) {
		Init();
		Input();
		//����
		sort(map, map + 100);
		for (int j = 0; j < dump_num; j++) {
			//map�� ���� ū �� -1, ���� �� +1
			map[100] =- 1;
			map[0] =+ 1;
			//������
			sort(map, map + 100);
			//��źȭ �Ϸ� �� ���� �� ��ȯ
			if (map[0] == map[100] || map[0] + 1 == map[100]) {
				result = map[100] - map[0];
				break;
			}
			else result = map[100] - map[0];
		}
		Output(i + 1);
	}
}

int main() {
	Func();
	return 0;
}