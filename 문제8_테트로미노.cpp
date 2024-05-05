#include<iostream>
#define MAX 500
using namespace std;
int N, M, ans;
int map[MAX][MAX];
int visited[MAX][MAX];
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };

void dfs(int y, int x, int d, int sum);
void T(int y, int x);

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);	cout.tie(NULL);
	cin >> N >> M;
	
	for (int i = 0; i < N; i++)
		for (int j; j < M; j++)
			cin >> map[i][j]; // N이 세로 M가 가로
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++) 
		{
			dfs(i, j, 1, 0);
			T(i, j);
		}
	}
	cout << ans;

}

void dfs(int y, int x, int d, int sum)
{
	sum += map[y][x];
	visited[y][x] = 1;
	if (d == 4)
	{
		if (sum > ans) ans = sum;
		visited[y][x] = 0;
		return;
	}
	for (int dir = 0; dir < 4; dir++)
	{
		int ny = y + dy[dir];
		int nx = x + dx[dir];
		if (ny >= 0 && ny < N && nx >= 0 && nx < M)
			if (!visited[ny][nx])
				dfs(ny, nx, d + 1, sum);
	}
	visited[y][x] = 0;
}

void T(int y, int x)// 상하좌우에서 한 칸 골라 제외
{
	int sum, dir, ny, nx;
	for (int i = 0; i < 4; i++)
	{
		sum = map[y][x];
		for (dir = 0; dir < 4; dir++)
		{
			if (dir == i) continue;
			ny = y + dy[dir];
			nx = x + dx[dir];
			if (ny >= 0 && ny < N && nx >= 0 && nx < M)
				sum += map[ny][nx];
		}
		if (sum > ans)
			ans = sum;
	}
}