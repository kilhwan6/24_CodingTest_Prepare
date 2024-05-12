#include <math.h>
#include <iostream>
#include <vector>

#define endl '\n'

using namespace std;
// 입력 받기

int N, Q;
int L;
int MAP[100][100];
vector<int> Magic_Sequence;

void Input()
{
	cin >> N >> Q;
	
	for (int i = 0; i < pow(2, N); i++)
	{
		for (int j = 0; j < pow(2, N); j++)
		{
			int a;
			cin >> a;
			MAP[j][i] = a;
		}
	}

	Magic_Sequence.clear();
	for (int i = 0; i < Q; i++)
	{
		int a;
		cin >> a;
		Magic_Sequence.push_back(a);
	}
}

// 파이어스톰 시전 단계
// 1. 격자 나누기 + 회전
// 3. 얼음 양 줄이기 (인접한 칸 확인)


void Tunning(int a, int b, int Len)
{

}

void Remake_Map()
{
	for (int i = 0; i < N; i += Len
}

void Melting()
{

}



// 결과 solve -> 남아있는 얼음의 합, 가장 큰 덩어리 차지하는 개수(DFS, BFS)
void Solve()
{
	BFS();
}
void BFS()
{

}

int main()
{
	ios::sync_with_stdio(false); cout.tie(NULL); cin tie(NULL);
	Input();

}