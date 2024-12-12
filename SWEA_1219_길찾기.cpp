#include <iostream>
#include <vector>
#include <queue>
#define endl '\n'

using namespace std;

vector<vector<int>> adj; // ���� ����Ʈ
vector<bool> visited;
int testcase_num;
int road_size;
int result;

void input() {
    adj.assign(100, vector<int>()); // ���� ����Ʈ �ʱ�ȭ
    visited.assign(100, false);    // �湮 �迭 �ʱ�ȭ
    result = 0;

    cin >> testcase_num >> road_size;

    int a, b;
    for (int i = 0; i < road_size; i++) {
        cin >> a >> b;
        adj[a].push_back(b); // ���� ����
    }
}

void func() {
    queue<int> q;
    q.push(0);          // ������ 0 ����
    visited[0] = true;  // �湮 ó��

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        if (current == 99) { // �������� �����ϸ� ����
            result = 1;
            return;
        }

        for (int next : adj[current]) { // ���� ��忡�� �̵� ������ ��� ��� Ž��
            if (!visited[next]) {
                visited[next] = true;
                q.push(next);
            }
        }
    }
    result = 0; // �������� ���ϸ� ����
}

void output(int testcase_num) {
    cout << "#" << testcase_num << " " << result << endl;
}

int main() {
    for (int i = 1; i <= 10; i++) { // �׽�Ʈ ���̽� 10�� ó��
        input();
        func();
        output(i); // �׽�Ʈ ���̽� ��ȣ ���
    }
    return 0;
}
