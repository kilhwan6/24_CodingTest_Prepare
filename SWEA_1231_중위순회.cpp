//in_order �������� ��ȸ?
//

#include <iostream>
#include <vector>
#include <string>
#define endl '\n'
using namespace std;

int N;
vector <char> v;
vector <pair<int, int>> map;
string result;

void init() {
	v.clear();
	map.clear();
	result.clear();
}

void input() {
	cin >> N;
	v.resize(N + 1);           // ��� ��ȣ�� 1���� �����ϹǷ� N+1 ũ��� ���� ����
	map.resize(N + 1, { 0, 0 }); // �¿� �ڽ� ������ N+1 ũ��� �����Ͽ� 0���� �ʱ�ȭ
	
	int a, c, d;
	char b;
	//N�� ¦��, Ȧ���Ŀ� ���� �޶���
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		v[a] = b;

		if (2 * a <= N) { // �ڽ��� �ִ� ���鸸 ó�� (������ 2*a�� �� �� �ִ��� Ȯ��)
			cin >> c;
			map[a].first = c;
			if (2 * a + 1 <= N) { // ������ �ڽĵ� �ִ� ���
				cin >> d;
				map[a].second = d;
			}
		}
	}
}

void search(int node) {
	if (node == 0) return; // ��尡 0�� ��� Ž�� ���� (�ڽ��� ���ٴ� �ǹ�)
	// ���� Ʈ�� Ž��
	search(map[node].first);
	// ���� ��� Ž��
	result += v[node];
	// ���� Ʈ�� Ž��
	search(map[node].second);
}

void func() {
	search(1);
}

void output(int testcase_num) {
	cout << "#" << testcase_num << " " << result << endl;
}

int main() {
	for (int i = 1; i < 11; i++) {
		init();
		input();
		func();
		output(i);
	}
	return 0;
}