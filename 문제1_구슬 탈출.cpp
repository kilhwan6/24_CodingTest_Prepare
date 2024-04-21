#include <stdio.h>
#include <queue>
#include <algorithm>
using namespace std;

//1. ���� ��//
//INFO ����ü�� �Ķ� ����, ���� ������ ��ġ �� �̵� Ƚ���� ����
struct INFO {
    int ry, rx, by, bx, count;
    //ry, rx�� ���� ���� ��ġ
    //by, bx�� �Ķ� ���� ��ġ
    //count�� �̵� Ƚ��
};

INFO start;//����ü ����
char map[10][11];//�迭 ����, 10*11����

//2. bfs�˰����� �̿��� �Լ� ��//
int bfs() {
    //1)const int dy[]�� const int dx[] �迭�� �����¿� �������� �̵��ϱ� ���� ��Ÿ �迭�Դϴ�.
    const int dy[] = { -1, 1, 0, 0 }; //���Ϸ� �̵��ϱ� ���� �迭
    const int dx[] = { 0, 0, -1, 1 }; //�¿�� �̵��ϱ� ���� �迭

    //2)visited �迭�� 4���� �迭��, [10][10][10][10] ũ�⸦ ������ ���� ������ �Ķ� ������ ��ġ ������ �����ϴ� �迭�Դϴ�. �� �迭�� ����Ͽ� �̹� �湮�� ���¸� üũ�ϰ� �ߺ� �湮�� �����մϴ�.
    int visited[10][10][10][10] = { 0, }; //4���� �迭, ���� ������ �Ķ� ������ ��ġ ������ ����.
    //ù �ΰ��� ���� ����, ���� �ΰ��� �Ķ� ����, �ߺ� �湮�� ������

    //3)ť q�� start ����ü�� �ְ�, �ش� ��ġ�� �湮�� ������ ǥ���մϴ�.
    queue<INFO> q;//ť�� start ����ü�� �ְ� �ش� ��ġ�� �湮�� ������ ǥ��?
    q.push(start);
    visited[start.ry][start.rx][start.by][start.bx] = 1;//Visited�� ���� ���� ��ġ�� �־� ��

    //4)ret ������ ���� ������ ���ۿ� ������ ����� �ּ� �̵� Ƚ���� �����ϴ� ������, �ʱⰪ�� -1�� �����˴ϴ�. �� ���� -1�� ���� ���� ������ ���ۿ� �������� ���� ��츦 ��Ÿ���ϴ�.
    int ret = -1;//���� ������ �ּ� �̵� Ƚ���� ����, �������� ������ ��� -1�� ����ؾ� �ϹǷ� �ʱⰪ�� -1�� ����

    //5)while ������ ���� BFS�� �����մϴ�. ť�� ������� ���� ���� ������ ����˴ϴ�. ����, cur.count�� 10�� �ʰ��ϸ� ������ �����ϰ� -1�� ��ȯ�մϴ�.
    while (!q.empty()) {//ť�� ����ִ� ���°� �ƴ϶�� ����ؼ� ����.
        INFO cur = q.front();   q.pop();
        if (cur.count > 10)  break;//������ 10ȸ�̹Ƿ� 10ȸ�� �ʰ��ϸ� ������ ������. ���� ����� �ڿ������� ret = -1�� ��ȯ��.

        //6)���� ������ cur���� ���� ������ ���ۿ� ������ ���(map[cur.ry][cur.rx] == 'O') ret�� ��������� �̵� Ƚ��(cur.count)�� �����ϰ�, BFS ������ �����մϴ�.
        if (map[cur.ry][cur.rx] == 'O' && map[cur.by][cur.bx] != 'O') {//���� ������ ���ۿ� ������ ��� ����, �ٸ� �Ķ� ������ �������� �ʾҾ�� ��
            ret = cur.count;//���� �� �̵� Ƚ���� ����
            break;
        }

        //7)�����¿� ������ Ž���ϸ鼭 �� ������ ���� ��ġ(next_ry, next_rx, next_by, next_bx)�� ����մϴ�. �̶�, ��('#')�� ������ �̵��� ����ϴ�.
        for (int dir = 0; dir < 4; ++dir) {//dir�� 1�� ���ذ��鼭 ��� ����(4����) �׽�Ʈ
            int next_ry = cur.ry;//���� ��ġ�� ���� next_������ ���� ��ġ���� �ϴ� �޾ƿ�.
            int next_rx = cur.rx;
            int next_by = cur.by;
            int next_bx = cur.bx;

            while (1) {//���� ������ �ʰ�, ���ۿ��� �������� �ʾ��� ��� ���� ������ ��ǥ ��ȯ
                if (map[next_ry][next_rx] != '#' && map[next_ry][next_rx] != 'O') {
                    next_ry += dy[dir], next_rx += dx[dir];//�׷��� dx[n]�� ������? -> ����ܿ��� �迭 ���� 
                }
                else {//���� ������ ��
                    if (map[next_ry][next_rx] == '#') {
                        next_ry -= dy[dir], next_rx -= dx[dir];//�̵��� ������
                    }
                    break;//������ �ٲ�� �ϹǷ� ��������
                }
            }

            while (1) {//�Ķ� ������ ��쿡�� ���� ������ ���� ����
                if (map[next_by][next_bx] != '#' && map[next_by][next_bx] != 'O') {
                    next_by += dy[dir], next_bx += dx[dir];
                }
                else {
                    if (map[next_by][next_bx] == '#') {
                        next_by -= dy[dir], next_bx -= dx[dir];
                    }
                    break;
                }
            }

            //8)���� ������ �Ķ� ������ ���� ��ġ�� �����ϸ�, �̵� �Ÿ��� ���Ͽ� �� �� ������ �� ĭ �ڷ� �̵���ŵ�ϴ�. �̷��� �����ν� ���� ������ �Ķ� ������ ��ġ�� �ʵ��� �մϴ�.
            if (next_ry == next_by && next_rx == next_bx) {
                if (map[next_ry][next_rx] != 'O') {//���ۿ� ������ ���� �ƴϸ�
                    int red_dist = abs(next_ry - cur.ry) + abs(next_rx - cur.rx);//���� ������ ��￴�� �� �̵��Ÿ�
                    int blue_dist = abs(next_by - cur.by) + abs(next_bx - cur.bx);//�Ķ� ������ ��￴�� �� �̵��Ÿ�
                    if (red_dist > blue_dist) {//���� ������ �̵��Ÿ��� �� ���
                        next_ry -= dy[dir], next_rx -= dx[dir];//���� ������ �ʰ� �����ϹǷ� �� ĭ �ڷ� �̵�
                    }
                    else {//�Ķ� ������ �̵��Ÿ��� �� ���
                        next_by -= dy[dir], next_bx -= dx[dir];//�Ķ� ������ �ʰ� �����ϹǷ� �� ĭ �ڷ� �̵�
                    }
                }
            }

            //9)���� ���� ��ġ�� �湮���� ���� �����̸�, �ش� ��ġ�� �湮�� ������ ǥ���ϰ� cur.count + 1��ŭ �̵��� ���¸� next ����ü�� �����ϰ� ť�� �߰��մϴ�.
            if (visited[next_ry][next_rx][next_by][next_bx] == 0) {//�ش� ��ġ�� ��������, �Ķ����� ��ǥ
                visited[next_ry][next_rx][next_by][next_bx] = 1;//0�̸� 1�� �ٲ�
                INFO next;//���� ����, �Ķ� ������ ��ġ �� �̵�Ƚ�� ����
                next.ry = next_ry;
                next.rx = next_rx;
                next.by = next_by;
                next.bx = next_bx;
                next.count = cur.count + 1;
                q.push(next);//ť�� next ���� ����
            }
        }
    }
    return ret;//���� ������ ���ۿ� ������ �ּ� Ƚ�� ��ȯ
}

//3. ���� �Լ� ���� ��
int main()
{
    int n, m;//�̷��� x, y ũ�⸦ �޾ƿ� n, m ����
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%s", map[i]);//�� �Ʒ� �̷� �迭�� map�� ����
    }

    for (int y = 0; y < n; ++y) {//�̷� �� ��ġ�� Ȯ���ϸ�, ���� ������ �Ķ� ���� ������ġ Ȯ��
        for (int x = 0; x < m; ++x) {
            if (map[y][x] == 'R') {
                start.ry = y, start.rx = x;//����ü ��� ���� �����Ͽ� bfs���� �Ŀ� ����ϵ��� ��
            }
            if (map[y][x] == 'B') {
                start.by = y, start.bx = x;
            }
        }
    }
    start.count = 0;//�ʱ� �̵� Ƚ��, 0���� ����

    int ret = bfs();//����� ret�� ����
    printf("%d\n", ret);//ret���

    return 0;
}