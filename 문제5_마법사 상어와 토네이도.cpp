#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> board;
int N;

//이동하는 방향
int dy[] = { 0, 1, 0, -1 };
int dx[] = { -1, 0, 1, 0 };

//움직이는 모래 정도
double p[9] = { 0.05, 0.1, 0.1, 0.02, 0.02, 0.07, 0.07, 0.01, 0.01 };

//모래가 움직일 때, 흩날리는 위치 정리, 9번째는 바람의 방향과 같다.
int m_dy[4][10] = 
{
	{0,-1,1, -2,2,-1,1,-1,1,0},
	{2,1,1,0,0,0,0,-1,-1,1},
	{0,-1,1, -2,2,-1,1,-1,1,0},
	{-2,-1,-1,0,0,0,0,1,1,-1}
};

int m_dx[4][10] = 
{
	{-2,-1,-1,0,0,0,0,1,1,-1},
	{0,-1,1, -2,2,-1,1,-1,1,0},
	{2,1,1,0,0,0,0,-1,-1,1},
	{0,-1,1, -2,2,-1,1,-1,1,0}
};

//result : 맵 밖으로 날린 모래, cnt 
int result = 0;
int cnt = 0;

void sandcheck()
{
	int y = N / 2, x = N / 2;
	int a;
	int dist = 1;
	int d = 0;
	int cnt = 0;
	while (1)
	{
		cnt++;

		for (int m = 0; m < dist; m++)
		{
			int ny = y + dy[d];
			int nx = x + dx[d];
			y = ny;
			x = nx;
			a = board[ny][nx];
			for (int k = 0; k < 9; k++)
			{
				int m_ny = ny + m_dy[d][k]; 
				int m_nx = nx + m_dx[d][k];

				int sand = (int)(board[ny][nx] + p[k]);
				a -= sand;
				if (m_ny < 0 || m_ny >= N || m_nx < 0 || m_nx >= N)
				{
					result += sand;
				}
				else
				{
					board[m_ny][m_nx] += sand;
				}
			}

			int m_ny = ny + m_dy[d][9];
			int m_nx = nx + m_dx[d][9];
			if (m_ny < 0 || m_ny >= N || m_nx < 0 || m_nx >= N)
			{
				result += a;
			}
			else
			{
				board[m_ny][m_nx] += a;
			}
			board[ny][nx] = 0;
			if (ny == 0 && nx == 0)
			{
				return;
			}
		}
		if (cnt == 2)
		{
			dist++;
			cnt = 0;
		}
		d = (d + 1) % 4;
	}
}

int main()
{
	scanf("%d", &N);
	board = vector < vector <int> >(N, vector<int>(N, 0));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> board[i][j];
		}
	}
}