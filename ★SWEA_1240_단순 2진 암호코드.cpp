#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#define endl "\n"

using namespace std;

// ��ȣ ���ϰ� ���εǴ� ����
const string patterns[10] = {
    "0001101", "0011001", "0010011", "0111101", "0100011",
    "0110001", "0101111", "0111011", "0110111", "0001011"
};

int T, N, M;
vector <string> map;
int res;

// �迭 �ʱ�ȭ �� �Է� ó��
void input() {
    res = 0;
    cin >> N >> M;
    map.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> map[i];
    }

}

int decode(string code) {
    for (int i = 0; i < 10; i++) {
        if (code == patterns[i]) return i;
    }
    return -1;
}

int correct(vector<int> code) {
    int right, ans;
    right = ((code[1] + code[2] + code[3] + code[4]) * 3
        + (code[5] + code[6] + code[7] + code[8])) % 10;
    ans = code[1] + code[2] + code[3] + code[4] + code[5] + code[6] + code[7] + code[8];
    if (right == 0) return ans;
    else return 0;
}

void func() {
    int x_cor = 0; int y_cor = 0;
    string a;
    vector <int> code;
    bool onefind = false;
    //1. �� �ٺ��� ���������� 1 ã��
    // ã���� �� ��ġ���� ���� ���� (7���� 7��)
    for (int y = 0; y < N; y++) {
        for (int x = M - 1; x >= 0; x--) {
            if (map[y][x] == '1') {
                x_cor = x - 7*8 + 1; 
                y_cor = y;
                onefind = true;
                break;
            }
        }
        if (onefind) break;
    }

    for (int i = 1; i <= 8; i++) {
        a = map[y_cor].substr(x_cor,7);
        x_cor += 7;
        code.push_back(decode(a));
    }

    res = correct(code);
    //2. ������ string���� ���� 7��쿡 ����, �����Լ� ���� ¥����
    
    //3. ����� �ùٸ��� �Ǻ�, res ����
}

void output(int testcase_num) {
    cout << "#" << testcase_num << " " << res << endl;
}

int main() {
    cin >> T;
    for (int i = 1; i <= T; i++) {
        input();
        func();
        output(i);
    }
    return 0;
}
