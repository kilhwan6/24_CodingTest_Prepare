#include <math.h>
#include <iostream>
#include <vector>

#define endl '\n'

using namespace std;
// �Է� �ޱ�

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

// ���̾�� ���� �ܰ�
// 1. ���� ������ + ȸ��
// 3. ���� �� ���̱� (������ ĭ Ȯ��)


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



// ��� solve -> �����ִ� ������ ��, ���� ū ��� �����ϴ� ����(DFS, BFS)
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