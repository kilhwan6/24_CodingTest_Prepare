//�ڷᱸ�� ������ Ȱ��
//�̷� ���ϴ� �Ǻ� ���α׷� �ۼ� ��, ������ ��Ʈ����ó�� ���ִ� �͵� ���� ��

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