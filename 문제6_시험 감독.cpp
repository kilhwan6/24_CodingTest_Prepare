#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, B, C;

	cin >> N;
	vector <int> v(N);
	for (int i = 0; i < N; i++)
		cin >> v[i];

	cin >> B >> C;
	ll result = N;
	
	for (int i = 0; i < N; i++)
	{
		v[i] -= B;
		if (v[i] <= 0)continue;
		result += v[i] / C;
		if (v[i] % C)result += 1;
	}
	cout << result;
}