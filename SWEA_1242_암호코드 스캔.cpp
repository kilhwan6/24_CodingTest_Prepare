#include <iostream>
#include <algorithm>
#include <string>
#define endl "\n"
#define MAX 2000
using namespace std;

int T, N, M, Line;
int res;
int Code[5][5][5];
int Map[MAX][MAX];

int HexaToBinary[16][4] = {
	{0, 0, 0, 0}, //0
	{0, 0, 0, 1}, //1
	{0, 0, 1, 0}, //2
	{0, 0, 1, 1}, //3
	{0, 1, 0, 0}, //4
	{0, 1, 0, 1}, //5
	{0, 1, 1, 0}, //6
	{0, 1, 1, 1}, //7
	{1, 0, 0, 0}, //8
	{1, 0, 0, 1}, //9
	{1, 0, 1, 0}, //A
	{1, 0, 1, 1}, //B
	{1, 1, 0, 0}, //C
	{1, 1, 0, 1}, //D
	{1, 1, 1, 0}, //E
	{1, 1, 1, 1}, //F
};



void Input() {
	memset(Map, 0, sizeof(Map));
	res = 0;

	cin >> N >> M;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			char C;
			cin >> C;
			if (C <= '9') C = C - '0';
			else C = C - 'A' + 10;

			for (int i = 0; i < 4; i++) {
				Map[y][x * 4 + i] = HexaToBinary[C][i];
			}
		}
	}
}

void Setting_Code() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			for (int k = 0; k < 5; k++) {
				Code[i][j][k] = -1;
			}
		}
	}
	Code
}

//int Decode(string code) {
//	for (int i = 0; i < 10; i++) {
//		if (code == patterns[i]) return i;
//	}
//	return -1;
//}

int Validate(int code[8]) {
	int odd_num = code[0] + code[2] + code[4] + code[6];
	int even_num = code[1] + code[3] + code[5];
	int valid_num = code[7];
	int valid = odd_num * 3 + even_num + valid_num;
	int result = odd_num + even_num + valid_num;
	if (valid % 10 == 0) return result;
	else return 0;
}

void Func() {

}

void Output(int testcase_num) {
	cout << "#" << testcase_num << " " << res << endl;
}

void Solve() {
	Setting_Code();
	int Tc; cin >> Tc;
	for (int T = 1; T <= Tc; T++) {
		Input();
		Func();
		Output();
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Solve();

	return 0;
}