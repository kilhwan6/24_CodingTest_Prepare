#include <iostream>
#include <stack>
#include <string>
#define endl "\n"
using namespace std;

// 연산자 우선순위를 반환
int precedence(char op) {
    if (op == '*') return 2; // 곱셈 우선순위
    if (op == '+') return 1; // 덧셈 우선순위
    return 0; // 기타
}

// 중위 표기식을 후위 표기식으로 변환
string infixToPostfix(const string& infix) {
    stack<char> opStack;
    string postfix = "";

    for (char c : infix) {
        if (isdigit(c)) {
            // 숫자는 바로 결과에 추가
            postfix += c;
        }
        else if (c == '+' || c == '*') {
            // 연산자 처리
            while (!opStack.empty() && precedence(opStack.top()) >= precedence(c)) {
                postfix += opStack.top();
                opStack.pop();
            }
            opStack.push(c);
        }
    }

    // 스택에 남아 있는 연산자를 결과에 추가
    while (!opStack.empty()) {
        postfix += opStack.top();
        opStack.pop();
    }

    return postfix;
}

// 후위 표기식을 계산
int evaluatePostfix(const string& postfix) {
    stack<int> valueStack;

    for (char c : postfix) {
        if (isdigit(c)) {
            valueStack.push(c - '0'); // 숫자를 스택에 저장
        }
        else if (c == '+' || c == '*') {
            int b = valueStack.top(); valueStack.pop();
            int a = valueStack.top(); valueStack.pop();

            if (c == '+') valueStack.push(a + b);
            if (c == '*') valueStack.push(a * b);
        }
    }

    return valueStack.top(); // 최종 결과
}

int main() {
    for (int testCase = 1; testCase <= 10; testCase++) {
        int length;
        string expression;

        cin >> length >> expression;

        // 후위 표기식 변환
        string postfix = infixToPostfix(expression);

        // 후위 표기식 계산
        int result = evaluatePostfix(postfix);

        // 결과 출력
        cout << "#" << testCase << " " << result << endl;
    }

    return 0;
}