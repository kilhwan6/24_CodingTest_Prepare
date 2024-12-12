#include <iostream>
#include <vector>
#include <queue>
#define endl '\n'

using namespace std;

vector<vector<int>> adj; // 인접 리스트
vector<bool> visited;
int testcase_num;
int road_size;
int result;

void input() {
    adj.assign(100, vector<int>()); // 인접 리스트 초기화
    visited.assign(100, false);    // 방문 배열 초기화
    result = 0;

    cin >> testcase_num >> road_size;

    int a, b;
    for (int i = 0; i < road_size; i++) {
        cin >> a >> b;
        adj[a].push_back(b); // 간선 저장
    }
}

void func() {
    queue<int> q;
    q.push(0);          // 시작점 0 삽입
    visited[0] = true;  // 방문 처리

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        if (current == 99) { // 도착점에 도달하면 성공
            result = 1;
            return;
        }

        for (int next : adj[current]) { // 현재 노드에서 이동 가능한 모든 노드 탐색
            if (!visited[next]) {
                visited[next] = true;
                q.push(next);
            }
        }
    }
    result = 0; // 도달하지 못하면 실패
}

void output(int testcase_num) {
    cout << "#" << testcase_num << " " << result << endl;
}

int main() {
    for (int i = 1; i <= 10; i++) { // 테스트 케이스 10개 처리
        input();
        func();
        output(i); // 테스트 케이스 번호 출력
    }
    return 0;
}
