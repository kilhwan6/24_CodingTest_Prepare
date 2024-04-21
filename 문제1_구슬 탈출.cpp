#include <stdio.h>
#include <queue>
#include <algorithm>
using namespace std;

//1. 선언 단//
//INFO 구조체로 파란 구슬, 빨간 구슬의 위치 및 이동 횟수를 저장
struct INFO {
    int ry, rx, by, bx, count;
    //ry, rx는 빨간 구슬 위치
    //by, bx는 파란 구슬 위치
    //count는 이동 횟수
};

INFO start;//구조체 선언
char map[10][11];//배열 선언, 10*11차원

//2. bfs알고리즘을 이용한 함수 단//
int bfs() {
    //1)const int dy[]와 const int dx[] 배열은 상하좌우 방향으로 이동하기 위한 델타 배열입니다.
    const int dy[] = { -1, 1, 0, 0 }; //상하로 이동하기 위한 배열
    const int dx[] = { 0, 0, -1, 1 }; //좌우로 이동하기 위한 배열

    //2)visited 배열은 4차원 배열로, [10][10][10][10] 크기를 가지며 빨간 구슬과 파란 구슬의 위치 정보를 저장하는 배열입니다. 이 배열을 사용하여 이미 방문한 상태를 체크하고 중복 방문을 방지합니다.
    int visited[10][10][10][10] = { 0, }; //4차원 배열, 빨간 구슬과 파란 구슬의 위치 정보를 저장.
    //첫 두개가 빨간 구슬, 뒤의 두개가 파란 구슬, 중복 방문을 방지함

    //3)큐 q에 start 구조체를 넣고, 해당 위치를 방문한 것으로 표시합니다.
    queue<INFO> q;//큐에 start 구조체를 넣고 해당 위치를 방문한 것으로 표기?
    q.push(start);
    visited[start.ry][start.rx][start.by][start.bx] = 1;//Visited에 최초 구슬 위치를 넣어 줌

    //4)ret 변수는 빨간 구슬이 구멍에 도달한 경우의 최소 이동 횟수를 저장하는 변수로, 초기값은 -1로 설정됩니다. 이 값이 -1인 경우는 빨간 구슬이 구멍에 도달하지 못한 경우를 나타냅니다.
    int ret = -1;//빨간 구슬의 최소 이동 횟수를 저장, 도달하지 못했을 경우 -1을 출력해야 하므로 초기값을 -1로 설정

    //5)while 루프를 통해 BFS를 수행합니다. 큐가 비어있지 않은 동안 루프가 실행됩니다. 또한, cur.count가 10을 초과하면 루프를 종료하고 -1을 반환합니다.
    while (!q.empty()) {//큐가 비어있는 상태가 아니라면 계속해서 시행.
        INFO cur = q.front();   q.pop();
        if (cur.count > 10)  break;//제한이 10회이므로 10회를 초과하면 루프를 종료함. 루프 종료시 자연스럽게 ret = -1이 반환됨.

        //6)현재 상태인 cur에서 빨간 구슬이 구멍에 도달한 경우(map[cur.ry][cur.rx] == 'O') ret에 현재까지의 이동 횟수(cur.count)를 저장하고, BFS 루프를 종료합니다.
        if (map[cur.ry][cur.rx] == 'O' && map[cur.by][cur.bx] != 'O') {//빨간 구슬이 구멍에 도달한 경우 종료, 다만 파란 구슬은 도달하지 않았어야 함
            ret = cur.count;//종료 시 이동 횟수를 저장
            break;
        }

        //7)상하좌우 방향을 탐색하면서 각 구슬의 다음 위치(next_ry, next_rx, next_by, next_bx)를 계산합니다. 이때, 벽('#')을 만나면 이동을 멈춥니다.
        for (int dir = 0; dir < 4; ++dir) {//dir을 1씩 더해가면서 모든 방향(4방향) 테스트
            int next_ry = cur.ry;//다음 위치를 위한 next_변수를 현재 위치에서 일단 받아옴.
            int next_rx = cur.rx;
            int next_by = cur.by;
            int next_bx = cur.bx;

            while (1) {//벽을 만나지 않고, 구멍에도 도달하지 않았을 경우 붉은 구슬의 좌표 변환
                if (map[next_ry][next_rx] != '#' && map[next_ry][next_rx] != 'O') {
                    next_ry += dy[dir], next_rx += dx[dir];//그런데 dx[n]는 무슨뜻? -> 선언단에서 배열 참조 
                }
                else {//벽을 만났을 때
                    if (map[next_ry][next_rx] == '#') {
                        next_ry -= dy[dir], next_rx -= dx[dir];//이동을 복구함
                    }
                    break;//방향을 바꿔야 하므로 빠져나옴
                }
            }

            while (1) {//파란 구슬의 경우에도 빨간 구슬과 같이 적용
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

            //8)빨간 구슬과 파란 구슬이 같은 위치에 도달하면, 이동 거리를 비교하여 더 먼 구슬을 한 칸 뒤로 이동시킵니다. 이렇게 함으로써 빨간 구슬과 파란 구슬이 겹치지 않도록 합니다.
            if (next_ry == next_by && next_rx == next_bx) {
                if (map[next_ry][next_rx] != 'O') {//구멍에 도달한 것이 아니면
                    int red_dist = abs(next_ry - cur.ry) + abs(next_rx - cur.rx);//빨간 구슬의 기울였을 시 이동거리
                    int blue_dist = abs(next_by - cur.by) + abs(next_bx - cur.bx);//파란 구슬의 기울였을 시 이동거리
                    if (red_dist > blue_dist) {//빨간 구슬의 이동거리가 더 길면
                        next_ry -= dy[dir], next_rx -= dx[dir];//빨간 구슬이 늦게 도달하므로 한 칸 뒤로 이동
                    }
                    else {//파란 구슬의 이동거리가 더 길면
                        next_by -= dy[dir], next_bx -= dx[dir];//파란 구슬이 늦게 도달하므로 한 칸 뒤로 이동
                    }
                }
            }

            //9)만약 다음 위치가 방문하지 않은 상태이면, 해당 위치를 방문한 것으로 표시하고 cur.count + 1만큼 이동한 상태를 next 구조체에 저장하고 큐에 추가합니다.
            if (visited[next_ry][next_rx][next_by][next_bx] == 0) {//해당 위치의 빨간구슬, 파란구슬 좌표
                visited[next_ry][next_rx][next_by][next_bx] = 1;//0이면 1로 바꿈
                INFO next;//빨간 구슬, 파란 구슬의 위치 및 이동횟수 저장
                next.ry = next_ry;
                next.rx = next_rx;
                next.by = next_by;
                next.bx = next_bx;
                next.count = cur.count + 1;
                q.push(next);//큐에 next 정보 저장
            }
        }
    }
    return ret;//빨간 구슬이 구멍에 도달한 최소 횟수 반환
}

//3. 메인 함수 실행 단
int main()
{
    int n, m;//미로의 x, y 크기를 받아올 n, m 선언
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%s", map[i]);//그 아래 미로 배열을 map에 저장
    }

    for (int y = 0; y < n; ++y) {//미로 각 위치를 확인하며, 빨간 구슬과 파란 구슬 시작위치 확인
        for (int x = 0; x < m; ++x) {
            if (map[y][x] == 'R') {
                start.ry = y, start.rx = x;//구조체 멤버 변수 갱신하여 bfs에서 후에 사용하도록 함
            }
            if (map[y][x] == 'B') {
                start.by = y, start.bx = x;
            }
        }
    }
    start.count = 0;//초기 이동 횟수, 0으로 설정

    int ret = bfs();//결과를 ret에 저장
    printf("%d\n", ret);//ret출력

    return 0;
}