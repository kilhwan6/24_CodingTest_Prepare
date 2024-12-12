//in_order 형식으로 순회?
//

#include <iostream>
#include <vector>
#include <string>
#define endl '\n'
using namespace std;

int N;
vector <char> v;
vector <pair<int, int>> map;
string result;

void init() {
	v.clear();
	map.clear();
	result.clear();
}

void input() {
	cin >> N;
	v.resize(N + 1);           // 노드 번호가 1부터 시작하므로 N+1 크기로 벡터 생성
	map.resize(N + 1, { 0, 0 }); // 좌우 자식 정보도 N+1 크기로 생성하여 0으로 초기화
	
	int a, c, d;
	char b;
	//N이 짝수, 홀수냐에 따라 달라짐
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		v[a] = b;

		if (2 * a <= N) { // 자식이 있는 노드들만 처리 (정점이 2*a로 갈 수 있는지 확인)
			cin >> c;
			map[a].first = c;
			if (2 * a + 1 <= N) { // 오른쪽 자식도 있는 경우
				cin >> d;
				map[a].second = d;
			}
		}
	}
}

void search(int node) {
	if (node == 0) return; // 노드가 0인 경우 탐색 종료 (자식이 없다는 의미)
	// 좌측 트리 탐색
	search(map[node].first);
	// 현재 노드 탐색
	result += v[node];
	// 우측 트리 탐색
	search(map[node].second);
}

void func() {
	search(1);
}

void output(int testcase_num) {
	cout << "#" << testcase_num << " " << result << endl;
}

int main() {
	for (int i = 1; i < 11; i++) {
		init();
		input();
		func();
		output(i);
	}
	return 0;
}