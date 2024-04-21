/*
����
1. ���� �ν�
2. ���� �ν� �� �̵� ��, �浹 ��� ������
    1)�̹� �浹�� ��� ����
        -�̹� �浹�� ����� �������� ����
        -������ ������ ������ �Ÿ� ���
            -���� �� ���̸�, �浹���� �� 1ĭ �ڷ� ����
            -���带 ȸ����Ų�ٸ�?
            ������ �������� �������� �迭�� ������ �ʿ�� ����
            ���� �񱳸� �ʿ��� ��
            ���� ȸ�����ѵ� ����� ����.
3. ���忡�� ���� ū ���ڸ� ã�� ��ȯ�ϱ�

*/
#include <stdio.h>

int n, ret;

//1. ���� ���带 ��Ÿ���� ����ü
struct BOARD {
    int map[20][20]; //���� �ִ�ũ��� ����

    void rotate() {//���� ȸ�� �Լ�
        int temp[20][20];

        for (int y = 0; y < n; ++y) {
            for (int x = 0; x < n; ++x) {
                temp[y][x] = map[n - x - 1][y];
            }
        }//���� ȸ�� ��ǥ temp�� ����

        for (int y = 0; y < n; ++y) {
            for (int x = 0; x < n; ++x) {
                map[y][x] = temp[y][x];//map x,y�� �ݴ��� ������ �迭����
                //y�� ��, x�� �� �����̱� ������ map[2][1]�� xy��ǥ���� (1,2)�̱� ����
            }
        }//temp�� ����� ��ǥ�� map�� ��ȯ
    }

    int get_max() {//���� �� ��� �� �� ���� ū �� �񱳹�ȯ
        int ret = 0;
        for (int y = 0; y < n; ++y) {
            for (int x = 0; x < n; ++x) {
                if (ret < map[y][x]) {
                    ret = map[y][x];
                }
            }
        }
        return ret;
    }

    void up() {//��½����� ��� �Լ�
        int temp[20][20];

        for (int x = 0; x < n; ++x) {//��� x ��ġ�� ���ؼ� ������ ����
            int flag = 0, target = -1;
            for (int y = 0; y < n; ++y) {
                if (map[y][x] == 0) {//�ش� ĭ�� 0�� ��� �׳� �Ѿ
                    continue;
                }
                if (flag == 1 && map[y][x] == temp[target][x]) {//?? ���� ��ġ�� ���� ��
                    temp[target][x] *= 2, flag = 0;//2��, �÷��� 0
                }
                else {
                    temp[++target][x] = map[y][x], flag = 1;//�׷��� ���� ��� ++target��ġ�� �̵� �� flag 1�� ����
                }
            }
            for (++target; target < n; ++target) {//target�� 1���ϰ� ����, n���� �۾��� ������ ����
                temp[target][x] = 0;//���� ���� 0
            }
        }
        for (int y = 0; y < n; ++y) {
            for (int x = 0; x < n; ++x) {
                map[y][x] = temp[y][x];//���� �迭 ������Ʈ
            }
        }
    }
};

void dfs(BOARD cur, int count) {
    if (count == 5) {//Count�� 5�϶� �ִ밪�� ����
        int candi = cur.get_max();
        if (ret < candi) {
            ret = candi;
        }
        return;
    }

    for (int dir = 0; dir < 4; ++dir) {//��� �̵� ���⿡ ���Ͽ� �ݿ�
        BOARD next = cur;
        next.up();
        dfs(next, count + 1);//����Լ��� ��� ���⿡ ���� �����ϵ��� ��.
        //��, ���� ��� �̵� �������� �����ϴ� ���� ��� ��쿡 ���� �����.
        //dfs�� �ǹ̿� �°� �� ��带 ��� ��쿡 ���� ���簡 ������ ����� �ڵ�
        cur.rotate();//���� ������
    }
}

int main()
{
    BOARD board;
    scanf("%d", &n);
    for (int y = 0; y < n; ++y) {
        for (int x = 0; x < n; ++x) {
            scanf("%d", &board.map[y][x]);
        }
    }

    ret = 0;
    dfs(board, 0);
    printf("%d\n", ret);

    return 0;
}