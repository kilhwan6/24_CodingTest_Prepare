//DFS 사용

#include <iostream>
#include <cstring>
#define endl '\n'
using namespace std;

int testcase_num;
int map[100][100] = { {0, }, };
bool visited[100][100] = { {false,}, };
int result = 0;
int y_dir[4] = { 1, -1 , 0, 0 };
int x_dir[4] = { 0, 0 , 1, -1 };

void init() {
	testcase_num = 0;
	memset(map, 0, sizeof(map));
	memset(visited, false, sizeof(visited));
	result = 0;
}

void input() {
	cin >> testcase_num;

	for (int y = 0; y < 100; y++) {
		string input;
		cin >> input;
		for (int x = 0; x < 100; x++) {
			map[y][x] = input[x] - '0';
		}
	}
}

void dfs(int y, int x) {
	//백트래킹
	//기록해야 할 것 : x,y 좌표 / visited 여부
	//visited 기록
	visited[y][x] = true;
	if (map[y][x] == 3) {
		result = 1;
	}
	else {
		for (int i = 0; i < 4; i++) {
			int ny = y + y_dir[i];
			int nx = x + x_dir[i];
			if (ny >= 0 && ny < 100 && nx >= 0 && nx < 100
				&& visited[ny][nx] == false
				&& (map[ny][nx] == 0 || map[ny][nx] == 3)) {
				dfs(ny, nx);
			}
		}
	}
	
}

void func() {
	int x = 1; int y = 1;
	dfs(y, x);
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