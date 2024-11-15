#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define endl "\n"
using namespace std;

char order;
int N, M, x, y, s;
vector <int>list;
string result;

void input() {
	list.clear(); // ���� �׽�Ʈ ������ �ʱ�ȭ
	result.clear(); //��� ���ڿ� �ʱ�ȭ

	cin >> N;
	int a;
	for (int i = 0; i < N; i++) {
		cin >> a;
		list.push_back(a);
	}
}

void func() {
	
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> order;

		if (order == 'I') {//1. ����
			cin >> x >> y;
			for (int j = 0; j < y; j++) {
				cin >> s;
				list.insert(list.begin() + x, s);
			}
		}

		else if (order == 'D') {//2. ����
			cin >> x >> y;
			/*for (int j = 0; j < y; j++) {
				list.erase(list.begin() + x);
			}*/
			list.erase(list.begin() + x, list.begin() + x + y);
		}

		else if (order == 'A') {//3. �߰�
			cin >> y;
			for (int j = 0; j < y; j++) {
				cin >> s;
				list.push_back(s);
			}
		}
	}
	for (int i = 0; i < 10; i++) {
		//result += list[i];
		result += to_string(list[i]);
		result += " ";
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
}