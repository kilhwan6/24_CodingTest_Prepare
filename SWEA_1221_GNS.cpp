#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#define endl "\n"

using namespace std;

int Testcase;
string Tc_num;
int Num_size;
int Num_list[10000] = { 0, };
string Num_list_str[10000] = { 0, };

void input() {
	string a;
	Num_size = 0;

	for (int i = 0; i < 10000; i++) {
		Num_list[i] = 0;
		Num_list_str[i] = 0;
	}

	cin >> Tc_num >> Num_size;
	for (int i = 0; i < Num_size; i++) {
		cin >> a;
		if (a == "ZRO") Num_list[i] = 0;
		else if (a == "ONE") Num_list[i] = 1;
		else if (a == "TWO") Num_list[i] = 2;
		else if (a == "THR") Num_list[i] = 3;
		else if (a == "FOR") Num_list[i] = 4;
		else if (a == "FIV") Num_list[i] = 5;
		else if (a == "SIX") Num_list[i] = 6;
		else if (a == "SVN") Num_list[i] = 7;
		else if (a == "EGT") Num_list[i] = 8;
		else if (a == "NIN") Num_list[i] = 9;
	}

}

void func() {
	sort(Num_list, Num_list + Num_size);
	for (int i = 0; i < Num_size; i++) {
		if (Num_list[i] == 0) Num_list_str[i] = "ZRO";
		else if (Num_list[i] == 1) Num_list_str[i] = "ONE";
		else if (Num_list[i] == 2) Num_list_str[i] = "TWO";
		else if (Num_list[i] == 3) Num_list_str[i] = "THR";
		else if (Num_list[i] == 4) Num_list_str[i] = "FOR";
		else if (Num_list[i] == 5) Num_list_str[i] = "FIV";
		else if (Num_list[i] == 6) Num_list_str[i] = "SIX";
		else if (Num_list[i] == 7) Num_list_str[i] = "SVN";
		else if (Num_list[i] == 8) Num_list_str[i] = "EGT";
		else if (Num_list[i] == 9) Num_list_str[i] = "NIN";
	}
}

void output() {
	string a;

	cout << Tc_num << endl;
	for (int i = 0; i < Num_size; i++) {
		if (i < Num_size - 1) {
			a = Num_list_str[i];
			cout << a << " ";
		}
		else { //마지막 줄에서 건너뛰기
			a = Num_list_str[i];
			cout << a << endl;
		}
	}
}

int main() {
	Testcase = 0;
	cin >> Testcase;

	for (int i = 0; i < Testcase; i++) {
		input();
		func();
		output();
	}
	
	return 0;
}