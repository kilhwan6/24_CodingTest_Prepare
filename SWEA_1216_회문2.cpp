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

//100개부터 1개씩 줄여가며 검사
void func() {
	for (int i = 100; i < 1; i--) {
		//가로 함수
		row(i);
		//세로 함수
		column(i);
		if (find_case) {
			result = i;
			break;
		}
	}
}
