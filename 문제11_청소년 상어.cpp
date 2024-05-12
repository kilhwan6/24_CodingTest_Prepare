#include <iostream>
#include <algorithm>
#include <queue>

#define endl "\n"
#define MAX 4

using namespace std;

//1. input 받기 그리기
//2. 물고기 관리 / 상어 관리

struct FISH
{
	int x;
	int y;
	int Dir;
	bool Live;
};

int Answer;
int MAP[MAX][MAX];
FISH Fish[20];

int dx[] = { 0, -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[] = { 0, 0, -1, -1, -1, 0, 1, 1, 1 };

int Max(int A, int B) { if (A > B) return A; return B; }

void Input()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			int a, b; cin >> a >> b;
			MAP[i][j] = a;
			Fish[a] = { i, j, b, true };
		}
	}
}

void Copy_State(int A[][4], int B[][4], FISH C[], FISH D[])
{
	for (int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			A[i][j] = B[i][j];
		}
	}
	for (int i = 1; i <= 16; i++) C[i] = D[i];
}

void Swap_Fish(int Idx, int IIdx)
{
	FISH Temp = Fish[Idx];
	Fish[Idx].x = Fish[IIdx].x;
	Fish[Idx].y = Fish[IIdx].y;
	Fish[IIdx].x = Temp.x;
	Fish[IIdx].y = Temp.y;
}

void Move_Fish()
{
	for (int i = 1; i <= 16; i++)
	{
		if (Fish[i].Live == false) continue;

		int x = Fish[i].x;
		int y = Fish[i].y;
		int Dir = Fish[i].Dir;

		int nx = x + dx[Dir];
		int ny = y + dy[Dir];
		bool Flag = false;
		if (nx >= 0 && ny >= 0 && nx < 4 && ny < 4)
		{
			if (MAP[nx][ny] == 0)
			{
				Flag = true;
				Fish[i].x = nx;
				Fish[i].y = ny;
				MAP[nx][ny] = i;
				MAP[x][y] = 0;
			}
			else if (MAP[nx][ny] != -1)
			{
				Flag = true;
				Swap_Fish(i, MAP[nx][ny]);
				swap(MAP[x][y], MAP[nx][ny]);
			}
		}

		if (Flag == false)
		{
			int nDir = Dir + 1;
			if (nDir == 9) nDir = 1;
			int nx = x + dx[nDir];
			int ny = y + dy[nDir];

			while (nDir != Dir)
			{
				if (nx >= 0 && ny >= 0 && nx < 4 && ny < 4)
				{
					if (MAP[nx][ny] == 0)
					{
						Fish[i].x = nx;
						Fish[i].y = ny;
						MAP[nx][ny] = i;
						MAP[x][y] = 0;
						Fish[i].Dir = nDir;
						break;
					}
					else if (MAP[nx][ny] != -1)
					{
						Swap_Fish(i, MAP[nx][ny]);
						swap(MAP[x][y], MAP[nx][ny]);
						Fish[i].Dir = nDir;
						break;
					}
				}
				nDir++;
				if (nDir = 9) nDir = 1;
				nx = x + dx[nDir];
				ny = y + dy[nDir];
			}
		}
	}
}

//상태 바꾸기, 되돌리기
void Make_State(int x, int y, int nx, int ny, int Fish_Num, bool T)
{
	if (T == true)
	{
		MAP[x][y] = 0;
		MAP[nx][ny] = -1;
		Fish[Fish_Num].Live = false;
	}
	else
	{
		MAP[x][y] = -1;
		MAP[nx][ny] = Fish_Num;
		Fish[Fish_Num].Live = true;
	}
}

//물고기 움직임, 상어의 움직임
void DFS(int x, int y, int Dir, int Sum)
{
	Answer = Max(Answer, Sum);
	int C_MAP[4][4];
	FISH C_Fish[20];
	Copy_State(C_MAP, MAP, C_Fish, Fish);// 현재 상태 저장
	Move_Fish();

	for (int i = 1; i <= 3; i++)
	{
		int nx = x + dx[Dir] * i;
		int ny = y + dy[Dir] * i;
		if (nx >= 0 && ny >= 0 && nx < 4 && ny < 4)
		{
			if (MAP[nx][ny] == 0) continue;

			int Fish_Num = MAP[nx][ny];
			int nDir = Fish[Fish_Num].Dir;

			Make_State(x, y, nx, ny, Fish_Num, true);
			DFS(nx, ny, nDir, Sum + Fish_Num);
			Make_State(x, y, nx, ny, Fish_Num, false);//DFS위한 상어, 물고기 되돌림
		}
		else break;
	}
	Copy_State(MAP, C_MAP, Fish, C_Fish); //DFS위한 되돌림

}

//초기 세팅, 상어가 0,0 물고기 먹음
void Solution()
{
	int F_Num = MAP[0][0];
	int Dir = Fish[F_Num].Dir;
	Fish[F_Num].Live = false;
	MAP[0][0] = -1;

	DFS(0, 0, Dir, F_Num);
	cout << Answer << endl;
}

void Solve()
{
	Input();
	Solution();
}

int main(void)
{
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	//freopen("Input.txt", "r", stdin);
	Solve();

	return 0;
}