#include <iostream>
#define MAX 15
#define endl '\n'

using namespace std;

int N;
int Ti[MAX] = { 0, };
int Pi[MAX] = { 0, };
int res[MAX] = { 0, };

int Max(int a, int b)
{
	return a > b ? a : b;
}

void Input()
{
	cin >> N;
	for (int i = 1; i < N; i++)
	{
		cin >> Ti[i] >> Pi[i];
	}
}

void DP()
{
	int deadline;
	for (int i = N; i > 0; i--)
	{
		deadline = i + Ti[i];
		if (deadline > N + 1)//상담 불가
			res[i] = res[i + 1];
		else
			res[i] = Max(res[i + 1], res[deadline] + Pi[i]);
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	Input();
	DP();

	cout << res[1] << endl;
	return 0;
}