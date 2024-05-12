#include <iostream>
#include <string.h>
#define SMAX 410
using namespace std;

int N, M, K;

struct Shark {
	int x, y;
	int d;
	bool dead = false;
};

struct Map_info {
	int sn;
	int smell;
};

struct Prior {
	int map[5][4];
};

Shark shark[SMAX];
Map_info Map[30][30];
Prior prior[SMAX];

int alive_shark;

int dx[] = { 0,-1,1,0,0 };
int dy[] = { 0,0,0,-1,1 };

void update_shark_n_map(int sn, int nx, int ny, int nd, int time) {
	//상어 존재 O
	if (Map[nx][ny].sn > 0 && Map[nx][ny].sn < sn) { //자신 쫓겨남
		shark[sn].dead = true;
	}
	else if (Map[nx][ny].sn > 0 && Map[nx][ny].sn > sn) { //남 쫓겨남
		int other_sn = Map[nx][ny].sn;
		shark[other_sn].dead = true;

		Map[nx][ny].sn = sn;
		Map[nx][ny].smell = time + K;

		shark[sn].x = nx;
		shark[sn].y = ny;
		shark[sn].d = nd;
	}
	//상어 존재 X
	else {
		Map[nx][ny].sn = sn;
		Map[nx][ny].smell = time + K;

		shark[sn].x = nx;
		shark[sn].y = ny;
		shark[sn].d = nd;
	}

}

void move_shark(int time) {

	Map_info C_Map[30][30];
	memcpy(C_Map, Map, sizeof(Map));

	int x, y, d;
	for (int i = 1; i <= M; i++) {
		if (shark[i].dead) continue;
		x = shark[i].x;
		y = shark[i].y;
		d = shark[i].d;

		int blank = 0;
		int self = 0;

		int nx, ny;
		int blank_d, self_d;
		for (int k = 1; k <= 4; k++) {
			nx = x + dx[k];
			ny = y + dy[k];
			if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
			if (C_Map[nx][ny].sn == 0) {
				blank++;
				blank_d = k;
			}
			if (C_Map[nx][ny].sn == i) {
				self++;
				self_d = k;
			}
		}

		if (blank == 1) {
			nx = x + dx[blank_d];
			ny = y + dy[blank_d];
			update_shark_n_map(i, nx, ny, blank_d, time);
		}
		else if ((blank == 0 && self == 1)) {
			nx = x + dx[self_d];
			ny = y + dy[self_d];
			update_shark_n_map(i, nx, ny, self_d, time);
		}
		else {
			int dir[4];
			for (int k = 0; k < 4; k++) dir[k] = prior[i].map[d][k];

			if (blank > 0) {
				for (int k = 0; k < 4; k++) {
					nx = x + dx[dir[k]];
					ny = y + dy[dir[k]];
					if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
					if (C_Map[nx][ny].sn == 0)
					{
						update_shark_n_map(i, nx, ny, dir[k], time);
						break;
					}
				}
			}
			else {
				for (int k = 0; k < 4; k++) {
					nx = x + dx[dir[k]];
					ny = y + dy[dir[k]];
					if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
					if (C_Map[nx][ny].sn == i)
					{
						update_shark_n_map(i, nx, ny, dir[k], time);
						break;
					}
				}
			}
		}

	}
}

void remove_smell(int time) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (Map[i][j].smell == time) {
				Map[i][j].smell = 0;
				Map[i][j].sn = 0;
			}
		}
	}
}

bool check_shark() {

	for (int i = 2; i <= M; i++) {
		if (shark[i].dead) continue;
		return false;
	}
	return true;
}


void Solve() {
	int time = 0;
	while (1) {
		time++;
		if (time > 1000) {
			cout << -1 << endl;
			return;
		}
		move_shark(time);
		remove_smell(time);
		if (check_shark()) break;
	}

	cout << time << endl;
}

int main() {
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> Map[i][j].sn;
			if (Map[i][j].sn > 0) {
				Map[i][j].smell = K;

				shark[Map[i][j].sn].x = i;
				shark[Map[i][j].sn].y = j;
			}
		}
	}

	for (int i = 1; i <= M; i++) cin >> shark[i].d;

	for (int i = 1; i <= M; i++) {
		for (int k = 1; k <= 4; k++) {
			cin >> prior[i].map[k][0] >> prior[i].map[k][1] >> prior[i].map[k][2] >> prior[i].map[k][3];
		}
	}

	Solve();

	return 0;
}