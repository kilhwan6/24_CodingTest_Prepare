/*
설계
1. 보드 인식
2. 보드 인식 후 이동 시, 충돌 경우 나누기
    1)이미 충돌한 블록 구분
        -이미 충돌한 블록은 합쳐지지 않음
        -움직일 방향의 벽과의 거리 고려
            -벽과 먼 것이면, 충돌했을 때 1칸 뒤로 보냄
            -보드를 회전시킨다면?
            게임의 목적에서 마지막에 배열을 보여줄 필요는 없음
            값의 비교만 필요할 뿐
            따라서 회전시켜도 상관이 없다.
3. 보드에서 가장 큰 숫자를 찾아 반환하기

*/
#include <stdio.h>

int n, ret;

//1. 게임 보드를 나타내는 구조체
struct BOARD {
    int map[20][20]; //보드 최대크기로 만듬

    void rotate() {//보드 회전 함수
        int temp[20][20];

        for (int y = 0; y < n; ++y) {
            for (int x = 0; x < n; ++x) {
                temp[y][x] = map[n - x - 1][y];
            }
        }//보드 회전 좌표 temp에 저장

        for (int y = 0; y < n; ++y) {
            for (int x = 0; x < n; ++x) {
                map[y][x] = temp[y][x];//map x,y가 반대인 이유는 배열에서
                //y가 행, x가 열 정보이기 때문에 map[2][1]은 xy좌표에서 (1,2)이기 때문
            }
        }//temp에 저장된 좌표를 map에 반환
    }

    int get_max() {//보드 내 모든 값 중 가장 큰 값 비교반환
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

    void up() {//상승시켰을 경우 함수
        int temp[20][20];

        for (int x = 0; x < n; ++x) {//모든 x 위치에 대해서 열부터 수행
            int flag = 0, target = -1;
            for (int y = 0; y < n; ++y) {
                if (map[y][x] == 0) {//해당 칸이 0일 경우 그냥 넘어감
                    continue;
                }
                if (flag == 1 && map[y][x] == temp[target][x]) {//?? 이전 위치와 같을 때
                    temp[target][x] *= 2, flag = 0;//2배, 플래그 0
                }
                else {
                    temp[++target][x] = map[y][x], flag = 1;//그렇지 않은 경우 ++target위치에 이동 후 flag 1로 설정
                }
            }
            for (++target; target < n; ++target) {//target에 1더하고 시작, n보다 작아질 때까지 수행
                temp[target][x] = 0;//남은 공간 0
            }
        }
        for (int y = 0; y < n; ++y) {
            for (int x = 0; x < n; ++x) {
                map[y][x] = temp[y][x];//보드 배열 업데이트
            }
        }
    }
};

void dfs(BOARD cur, int count) {
    if (count == 5) {//Count가 5일때 최대값을 추출
        int candi = cur.get_max();
        if (ret < candi) {
            ret = candi;
        }
        return;
    }

    for (int dir = 0; dir < 4; ++dir) {//모든 이동 방향에 대하여 반영
        BOARD next = cur;
        next.up();
        dfs(next, count + 1);//재귀함수로 모든 방향에 대해 실행하도록 함.
        //즉, 위의 모든 이동 방향으로 적용하는 것이 모든 경우에 따라 수행됨.
        //dfs의 의미와 맞게 한 노드를 모든 경우에 따라 조사가 가능한 재귀의 코드
        cur.rotate();//보드 돌리기
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