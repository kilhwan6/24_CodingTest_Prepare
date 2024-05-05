#include <iostream>
#include <queue>

#define MAX 22
#define endl '\n'

using namespace std;

int N;
int map[MAX][MAX];
int dx[] = { 0, -1, 1, 0 }; //상좌우하 (우선순위)
int dy[] = { -1, 0, 0, 1 };
int bx, by;
int result = 0;// 총 걸린 시간
int count1 = 0;// 물고기 먹은 횟수
int sz = 2;// 상어 사이즈
bool stop = false; // 먹을 물고기 없는 경우
bool eat = false; // 한 마리를 먹은 경우

void bfs(int a, int b, bool visit[][MAX], int shSize) //
{
	queue<pair<pair<int, int>, int>> q;
	q.push(make_pair(make_pair(a, b), 0));
	visit[b][a] = true;
	int temp; // 한 마리 먹는 데 걸린 시간
	while (!q.empty())
	{
		int x = q.front().first.first; // 열 좌표
		int y = q.front().first.second; // 행 좌표
		int cnt = q.front().second; // 현재 시간
		//가장 위쪽을 먼저, 그 다음 왼쪽을 우선적으로 먹기
		if (map[y][x] > 0 && map[y][x] < shSize && temp == cnt) {
			if ((by > y) || (by == y && bx > x)) {
				by = y;
				bx = x;
			}
		}
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && nx < N && ny >= 0 && ny < N && !visit[ny][nx]) {//맵 안이면서 현재 방문한 곳 아님
				if (map[ny][nx] <= shSize) {//지나가거나 먹을 수 있는 사이즈
					if(map[ny][nx] > 0 && map[ny][nx] < shSize && !eat){
						eat = true;
						bx = nx;
						by = ny;
						temp = cnt + 1;
						result += temp;
					}
					else {
						q.push(make_pair(make_pair(nx, ny), cnt + 1));
						visit[ny][nx] = true;
					}
				}
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++) 
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 9)//상어 시작위치 bx, by 기록
			{
				by = i;
				bx = j;
				map[i][j] = 0;
			}
		}
	}

	while (!stop) {
		bool visit[MAX][MAX] = { 0 };
		bfs(bx, by, visit, sz);// 한 마리 먹을때까지 이동
		if (eat) {
			eat = false;
			count1 += 1;
			map[by][bx] = 0;
			if (count1 == sz) {
				sz += 1;
				count1 = 0;
			}
		}
		else {
			stop = true;
		}
	}
	cout << result << endl;
	return 0;
}