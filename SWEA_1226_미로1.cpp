/*
* BFS, DFS활용하는 문제
* 두 방법 전부 활용해서 풀기!
* 1. BFS 방법
* Queue 활용
* While 문으로 bfs함수 돌림
* 갈 수 없거나, 도착지점을 찾으면 종료
* 이동 함수
* 1)현재위치 visit 
* 2)Queue에 현재 위치에서 갈수있는길 넣음
* 3)Queue에서 갈 위치 front() 받고 pop()
* 4)이동 후 반복
* 
* 2. DFS 방법
* 재귀 활용
* DFS문으로  
*/

#include <queue>
#include <iostream>
#include <cstring>
#define endl '\n'
using namespace std;

int testcase_num = 0;
int map[16][16] = { {0, }, };
int visited[16][16] = { {0, }, };
int result = 0;

int y_dir[4] = { 0, 0, -1, 1 };//동서남북
int x_dir[4] = { 1, -1, 0, 0 };//

void init() {
	memset(map, 0, sizeof(map));
	memset(visited, 0, sizeof(visited));
	result = 0;
	testcase_num = 0;
}

void input() {
	cin >> testcase_num;

	for (int y = 0; y < 16; y++) {
		int a = 0;
		string input;
		cin >> input;

		for (int x = 0; x < 16; x++) {
			map[y][x] = input[a] - '0';
			a ++ ;
		}
	}
}

void func() {
	queue <pair<int,int>> q;
	q.push({ 1, 1 });

	int x = 1; int y = 1;
	while (!q.empty()) {
		y = q.front().first;
		x = q.front().second;
		q.pop();
		if (map[y][x] == 3) {
			result = 1;
			break;
		}

		for (int i = 0; i < 4; i++) {
			int ny = y + y_dir[i];
			int nx = x + x_dir[i];
			if (ny >= 0 && ny < 16 && nx >= 0 && nx < 16
				&& visited[ny][nx] == 0
				&& (map[ny][nx] == 0 || map[ny][nx] == 3)) {
				//큐에 푸시 : 조건에 맞다면 이동
				visited[ny][nx] = 1;
				q.push({ny, nx});
			}
		}
	}
}

void output() {
	cout << "#" << testcase_num << " " << result << endl;
}


int main() {
	for (int i = 0; i < 10; i++) {
		init();
		input();
		func();
		output();
	}
	return 0;
}