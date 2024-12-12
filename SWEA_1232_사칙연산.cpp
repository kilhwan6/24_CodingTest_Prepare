//���� ���κ��� ��ȸ
//���� ���� ��� ����?
//�Ʒ��� �������� ���Ŀ� 2�� �ִ� ���
//���� ������ 1���� �Ǿ� �մ� ���
//�׷��ٸ� ���δ� ��� ��ȸ?
//BFS�� �ݴ�� ��ȸ�ؾ� �ϳ�?
//

#include <iostream>
#include <vector>
using namespace std;

int N;
vector <char> list;
vector <pair<int, int>> map;
float res;

void input() {
	cin >> N;

	list.resize(N + 1);
	map.resize(N + 1, { 0, 0 });

	char calc;
	int node;
	int left, right;
	for (int i = 0; i < N; i++) {
		//1.���� �Է�
		//2.���� �Է��̸� left right �Է�
		//���� �Է��̸� list�� �Է�
		cin >> node;
		cin >> calc;
		list[node] = calc;
		if (calc == '-' || calc == '+'
			|| calc == '*' || calc == '/') {
			cin >> left >> right;
			map[node].first = left;
			map[node].second = right;
		}
	}
}

float calc(int node) {
	//�ش� ��忡�� ���
	//vector[node]�� ���ڷ� ����, ������ ��� ���
	float num;
	if (list[node] == '-') {
		num = calc(map[node].first) - calc(map[node].second);
	}
	else if (list[node] == '+') {
		num = calc(map[node].first) + calc(map[node].second);
	}
	else if (list[node] == '*') {
		num = calc(map[node].first) * calc(map[node].second);
	}
	else if (list[node] == '/') {
		num = calc(map[node].first) / calc(map[node].second);
	}
	else {
		num = list[node] - '0';
	}
	return num;
}

void func() {
	res = calc(1);
}

void output(int testcase_num) {
	cout << "#" << testcase_num << " " << res << endl;
}

int main() {
	for (int i = 1; i <= 10; i++) {
		input();
		func();
		output(i);
	}
	return 0;
}