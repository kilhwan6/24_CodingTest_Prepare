#include <iostream>
#include <vector>
#include <string>
using namespace std;

int N;
int res;

void input() {
	int node, left, right;
	string calc;
	res = 1;

	cin >> N;		
	if (N % 2 == 0) {
		//NÀÌ Â¦¼ö
		for (int i = 1; i < N / 2; i++) {
			cin >> node >> calc >> left >> right;
			if (calc != "*" 
				|| calc != "/"
				|| calc != "-"
				|| calc != "+") {
				res = 0;
			}
		}
		cin >> node >> calc >> left;
		if (calc != "*"
			&& calc != "/"
			&& calc != "-"
			&& calc != "+") {
			res = 0;
		}
		for (int i = N / 2 + 1; i <= N; i++) {
			cin >> node >> calc;
			if (calc == "*"
				|| calc == "/"
				|| calc == "-"
				|| calc == "+") {
				res = 0;
			}
		}
	}
	else {
		//NÀÌ È¦¼ö
		for (int i = 1; i <= N / 2; i++) {
			cin >> node >> calc >> left >> right;
			if (calc != "*"
				&& calc != "/"
				&& calc != "-"
				&& calc != "+") {
				res = 0;
			}
		}
		for (int i = N / 2 + 1; i <= N; i++) {
			cin >> node >> calc;
			if (calc == "*"
				|| calc == "/"
				|| calc == "-"
				|| calc == "+") {
				res = 0;
			}
		}
	}


}

void output(int testcase_num) {
	cout << "#" << testcase_num << " " << res << endl;
}

int main() {
	for(int i = 1; i <= 10; i++) {
		input();
		output(i);
	}
	return 0;
}