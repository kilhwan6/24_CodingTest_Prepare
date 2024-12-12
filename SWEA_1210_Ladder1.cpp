#include <iostream>
#include <cstring>
#define endl '\n'
using namespace std;

int map[100][100] = { {0, }, };
bool visited[100][100] = { {0, }, };
int testcase_num;
int X;

void input() {
	memset(map, 0, sizeof(map));
	memset(visited, false, sizeof(visited));

	cin >> testcase_num;

	int a;
	for (int y = 0; y < 100; y++) {
		for (int x = 0; x < 100; x++) {
			cin >> a;
			map[y][x] = a;
		}
	}
}

void func() {
	int cur_x, cur_y;
	for (int x = 0; x < 100; x++) {
		if (map[99][x] == 2) {
			cur_x = x;
			cur_y = 99;
		}
	}

	visited[cur_y][cur_x] = true;

	while (cur_y > 0) {
		bool flag = 0;
		if (cur_x>0
			&& map[cur_y][cur_x - 1] == 1
			&& !visited[cur_y][cur_x - 1]) {//аб
			cur_x--;
		}
		else if (cur_x < 99
			& map[cur_y][cur_x + 1] == 1
			&& !visited[cur_y][cur_x + 1]) {//©Л
			cur_x++;
		}
		else if (cur_y > 0
			& map[cur_y - 1][cur_x] == 1
			&& !visited[cur_y - 1][cur_x]) {
			cur_y--;
		}

		visited[cur_y][cur_x] = true;
	}

	X = cur_x;
}

void output() {
	cout << "#" << testcase_num << " " << X << endl;
}

int main() {
	for (int i = 0; i < 10; i++) {
		input();
		func();
		output();
	}
	return 0;
}