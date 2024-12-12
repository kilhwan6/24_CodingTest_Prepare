#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string num;
int max_cnt, answer;

void input() {
    num.clear();
    answer = 0;

    cin >> num >> max_cnt;
}

void func(int idx, int cnt) {
    //Ż�� ����
    if (cnt == max_cnt) {
        answer = max(answer, stoi(num));
        return;
    }
    //�ݺ���
    for (int i = idx; i < num.length() - 1; i++) {
        for (int j = i + 1; j < num.length(); j++) {//ù �ڸ��� ��°�ڸ� ��ȯ
            if (num[i] <= num[j]) {
                swap(num[i], num[j]);
                func(i, cnt + 1);
                swap(num[i], num[j]);
            }
            //������ �ٲپ�� �ϴ� ���
            if (i == num.length() - 2 && j == num.length() - 1) {
                swap(num[i], num[j]);
                func(i, cnt + 1);
                swap(num[i], num[j]);
            }
        }
    }
}


void output(int test_case_num) {
    cout << "#" << test_case_num << " " << answer << endl;
}

int main() {
    int T;

    cin >> T;

    for (int test_case_num = 1; test_case_num <= T; test_case_num++) {
        input();
        func(0, 0);
        output(test_case_num);
    }
    return 0;
}