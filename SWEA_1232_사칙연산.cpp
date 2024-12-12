//말단 노드로부터 순회
//말단 노드는 어떻게 구분?
//아래로 내려가서 최후에 2개 있는 노드
//정점 연결이 1개만 되어 잇는 노드
//그렇다며 위로는 어떻게 순회?
//BFS의 반대로 순회해야 하나?
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
		//1.숫자 입력
		//2.문자 입력이면 left right 입력
		//숫자 입력이면 list에 입력
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
	//해당 노드에서 계산
	//vector[node]의 문자로 왼쪽, 오른쪽 노드 계산
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