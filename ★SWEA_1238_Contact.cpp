#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, start;
vector <vector<int>> map;
vector <int> visited;
int res;

void input() {
	cin >> N >> start;

	map.assign(101, vector<int>()); // 연락 가능한 사람의 번호는 1~100으로 가정
	visited.assign(101, 0);
	res = 0;

	for (int i = 0; i < N / 2; i++) {
		int send, receive;
		cin >> send >> receive;
		map[send].push_back(receive);
	}
}

void func() {
	queue <int> q;
	q.push(start);
	visited[start] = 1;

	while (!q.empty()){
		//한 번 연락을 받은 상태는 예외처리
		//끝까지 탐색했을 때, 끝에서 연락한 사람 중 큰 것을 반환
		int size = q.size();
		int max_num = 0;

		for (int i = 0; i < size; i++)
		{
			int cur = q.front();
			q.pop();
			max_num = max(max_num, cur);

			for (int next_point : map[cur]) {
				if (!visited[next_point]) {
					q.push(next_point);
					visited[next_point] = 1;
				}
			}
		}
		res = max_num;
	}
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