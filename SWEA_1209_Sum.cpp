#include <stdio.h>
#include <iostream>
#include <algorithm>
#define endl "\n"
using namespace std;

int map[100][100] = { {0,}, };
int result;

void init() {
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			map[i][j] = 0;
		}
	}
}

void input() {
	//�ʱ�ȭ
	init();
	int input;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			cin >> input;
			map[j][i] = input;// x, y�� ����
		}
	}
}

int max(int a, int b){
	if (a > b) return a;
	else if (b > a) return b;
	else return a;
}

void func() {
	//�� ���� ��, ���� ��, �밢���� �� ����
	int sum_table[202] = { 0, };
	int sum = 0;
	for (int i = 0; i < 100; i++){
		sum = 0;
		for (int j = 0; j < 100; j++) {//���� ��
			sum += map[i][j];
		}
		sum_table[i] = sum;
	}
	for (int i = 100; i < 200; i++){
		sum = 0;
		for (int j = 0; j < 100; j++) {//���� ��
			sum += map[j][i-100];//i-100ó��
		}
		sum_table[i] = sum;
	}
	sum = 0;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {//�밢�� ��
			sum += map[j][j];
		}
	}
	sum_table[201] = sum;
	sum = 0;
	for (int i = 0; i < 100; i++) {
		for (int j = 99; j < 0; j--) {//�밢�� ��
			sum += map[j][i];//i-200ó��
		}
	}
	sum_table[202] = sum;

	//��
	result = 0;
	for (int i = 0; i < 202; i++) {
		max(result, sum_table[i]);
	}
}

void output(int testcase_num) {
	testcase_num += 1;
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