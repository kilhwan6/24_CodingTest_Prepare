#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#define endl "\n"

using namespace std;

int map[100][100] = { {0, }, };
bool find_case;
int result;


void row(int a) {

}

void column(int a) {

}

//100������ 1���� �ٿ����� �˻�
void func() {
	for (int i = 100; i < 1; i--) {
		//���� �Լ�
		row(i);
		//���� �Լ�
		column(i);
		if (find_case) {
			result = i;
			break;
		}
	}
}
