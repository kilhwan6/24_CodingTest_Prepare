#include <iostream>
#include <stdio.h>
#define endl "\n"

using namespace std;

//int main(int argc, char** argv)
int main()
{
	int test_case;
	int T;
	int num, sum;

	//freopen("input.txt", "r", stdin);

	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
		num = 0;
		sum = 0;
		for (int i = 0; i < 10; i++) {
			cin >> num;

			if (num % 2 == 1)
			{
				sum += num;
			}
		}
		cout << "#" << test_case << " " << sum << endl;
	}
	return 0;
}