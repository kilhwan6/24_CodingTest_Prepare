#include <iostream>
#include <queue>
#define ARR 100
using namespace std;

int T, mincol, minm, row, col, cnt;
int ladder[ARR][ARR] = { 0, };
queue <int> q;
int res;

int map(int x, int size);

bool isIn(int x) { //범위 확인 함수
    return (0 <= x && x < ARR);
}

void input() {
    cin >> T;
    for (int i = 0; i < ARR; i++) {
        for (int j = 0; j < ARR; j++) {
            cin >> ladder[i][j];
            if (i == 0 && ladder[i][j] == 1) {
                q.push(j);
            }
        }
    }//input end
}

void func() {
    minm = 20000000;
    cnt = 1;
    while (!q.empty()) {
        int move = 0;
        cnt++;
        row = 0;
        col = q.front();

        while (row < ARR && isIn(col)) {
            //cout<<"cnt "<<cnt<<" row "<<row<<" col "<<col<<"\n";
            if ((ladder[row][col + 1] > 0 && isIn(col + 1)) && ladder[row][col + 1] < cnt)
            {
                ladder[row][col] = cnt;
                col++;
                move++;
            }
            else if (ladder[row][col - 1] < cnt && (ladder[row][col - 1] > 0 && isIn(col - 1)))
            {
                ladder[row][col] = cnt;
                col--;
                move++;

            }
            else
            {
                ladder[row][col] = cnt;
                row++;  //양옆에 길이 없음
                move++;
            }
        }//end one ladder

        if (move <= minm) {
            minm = move;
            mincol = q.front();
        }
        q.pop();

    }//queue end
}

void output() {
    cout << "#" << T << " " << mincol << endl;
}

int main()
{
    for (int i = 0; i < 10; i++) {
        input();
        func();
        output();
    }
    return 0;
}