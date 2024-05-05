#include <iostream>
#include <queue>

#define MAX 22
#define endl '\n'

using namespace std;

int N;
int map[MAX][MAX];
int dx[] = { 0, -1, 1, 0 }; //���¿��� (�켱����)
int dy[] = { -1, 0, 0, 1 };
int bx, by;
int result = 0;// �� �ɸ� �ð�
int count1 = 0;// ����� ���� Ƚ��
int sz = 2;// ��� ������
bool stop = false; // ���� ����� ���� ���
bool eat = false; // �� ������ ���� ���

void bfs(int a, int b, bool visit[][MAX], int shSize) //
{
	queue<pair<pair<int, int>, int>> q;
	q.push(make_pair(make_pair(a, b), 0));
	visit[b][a] = true;
	int temp; // �� ���� �Դ� �� �ɸ� �ð�
	while (!q.empty())
	{
		int x = q.front().first.first; // �� ��ǥ
		int y = q.front().first.second; // �� ��ǥ
		int cnt = q.front().second; // ���� �ð�
		//���� ������ ����, �� ���� ������ �켱������ �Ա�
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

			if (nx >= 0 && nx < N && ny >= 0 && ny < N && !visit[ny][nx]) {//�� ���̸鼭 ���� �湮�� �� �ƴ�
				if (map[ny][nx] <= shSize) {//�������ų� ���� �� �ִ� ������
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
			if (map[i][j] == 9)//��� ������ġ bx, by ���
			{
				by = i;
				bx = j;
				map[i][j] = 0;
			}
		}
	}

	while (!stop) {
		bool visit[MAX][MAX] = { 0 };
		bfs(bx, by, visit, sz);// �� ���� ���������� �̵�
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