/*
* 4 3 2 1 1 2 3 4
* input���� ���� �޾ƿ�
* 
*/

#include <algorithm>
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int n;
vector <int> v;
int result;

void input() {
	cin >> n;
	int a;
	for (int i = 0; i < n; i++) {
		cin >> a;
		v.push_back(a);
	}
}

void func() {
	//1���� ���� ũ�� n���� �ݺ�
	//
	int cur_max = v[0];
	result = v[0];
	for (int i = 1; i < n; i++) {
		cur_max = max(v[i], cur_max + v[i]);
		result = max(result, cur_max);
	}
}

void output() {
	cout << result << endl;
}

int main() {
	input();
	func();
	output();
}