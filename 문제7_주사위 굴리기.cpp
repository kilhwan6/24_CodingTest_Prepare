#include <iostream>
#define endl "\n"
#define MAX 20
using namespace std;

int map[MAX][MAX];
int N, M, x, y, K;
int move_order[1000];
int dice[6]; //초기에는 전부 0

int Judgement(int d)
{
	if (d == 1)
	{
		if (y == M - 1) return 0;
	}
	if (d == 2)
	{
		if (y == 0) return 0;
	}
	if (d == 3)
	{
		if (x == 0) return 0;
	}
	if (d == 4)
	{
		if (x == N - 1) return 0;
	}
	return 1;
}
//dice - 위, 아래, 동, 서, 남, 북
void Move(int d)
{
	int temp = dice[0];
	if (d == 1)//동
	{
		y++;
		dice[0] = dice[3];
		dice[3] = dice[1];
		dice[1] = dice[2];
		dice[2] = temp;
	}
	if (d == 2)//서
	{
		y--;
		dice[0] = dice[2];
		dice[2] = dice[1];
		dice[1] = dice[3];
		dice[3] = temp;
	}
	if (d == 3)//북
	{
		x--;
		dice[0] = dice[4];
		dice[4] = dice[1];
		dice[1] = dice[5];
		dice[5] = temp;
	}
	if (d == 4)//남
	{
		x++;
		dice[0] = dice[5];
		dice[5] = dice[1];
		dice[1] = dice[4];
		dice[4] = temp;
	}
}

void Play()
{
	for (int i = 0; i < K; i++)
	{
		if (!Judgement(move_order[i])) continue;

		Move(move_order[i]);
		if (map[x][y] == 0) map[x][y] = dice[1];
		else {
			dice[1] = map[x][y];
			map[x][y] = 0;
		}
		cout << dice[0] << endl;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M >> x >> y >> K;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < K; i++)
	{
		cin >> move_order[i];
	}
	Play();
}