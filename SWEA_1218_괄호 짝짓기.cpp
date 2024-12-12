//자료구조 적절히 활용
//이런 비교하는 판별 프로그램 작성 시, 맞으면 테트리스처럼 없애는 것도 좋을 듯

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#define endl '\n'

using namespace std;

int T_len;
string str;
vector <char> v;
int result;

void input() {
	str.clear();
	v.clear();
	cin >> T_len >> str;
}

void func() {
	for (int i = 0; i < str.size(); i++) {
		if ((!v.empty() && v.back() == '{' && str[i] == '}')
			|| (!v.empty() && v.back() == '[' && str[i] == ']')
			|| (!v.empty() && v.back() == '(' && str[i] == ')')
			|| (!v.empty() && v.back() == '<' && str[i] == '>')) {
			v.pop_back();
		}
		else {
			v.push_back(str[i]);
		}
	}
	if (v.empty()) {
		result = 1;
	}
	else
	{
		result = 0;
	}
}

void output(int testcase_num) {
	cout << "#" << testcase_num << " " << result << endl;
}

int main() {
	for (int i = 1; i < 11; i++) {
		input();
		func();
		output(i);
	}
	return 0;
}