#include <iostream>
#include <stack>
#include <string>
#define endl "\n"
using namespace std;

// ������ �켱������ ��ȯ
int precedence(char op) {
    if (op == '*') return 2; // ���� �켱����
    if (op == '+') return 1; // ���� �켱����
    return 0; // ��Ÿ
}

// ���� ǥ����� ���� ǥ������� ��ȯ
string infixToPostfix(const string& infix) {
    stack<char> opStack;
    string postfix = "";

    for (char c : infix) {
        if (isdigit(c)) {
            // ���ڴ� �ٷ� ����� �߰�
            postfix += c;
        }
        else if (c == '+' || c == '*') {
            // ������ ó��
            while (!opStack.empty() && precedence(opStack.top()) >= precedence(c)) {
                postfix += opStack.top();
                opStack.pop();
            }
            opStack.push(c);
        }
    }

    // ���ÿ� ���� �ִ� �����ڸ� ����� �߰�
    while (!opStack.empty()) {
        postfix += opStack.top();
        opStack.pop();
    }

    return postfix;
}

// ���� ǥ����� ���
int evaluatePostfix(const string& postfix) {
    stack<int> valueStack;

    for (char c : postfix) {
        if (isdigit(c)) {
            valueStack.push(c - '0'); // ���ڸ� ���ÿ� ����
        }
        else if (c == '+' || c == '*') {
            int b = valueStack.top(); valueStack.pop();
            int a = valueStack.top(); valueStack.pop();

            if (c == '+') valueStack.push(a + b);
            if (c == '*') valueStack.push(a * b);
        }
    }

    return valueStack.top(); // ���� ���
}

int main() {
    for (int testCase = 1; testCase <= 10; testCase++) {
        int length;
        string expression;

        cin >> length >> expression;

        // ���� ǥ��� ��ȯ
        string postfix = infixToPostfix(expression);

        // ���� ǥ��� ���
        int result = evaluatePostfix(postfix);

        // ��� ���
        cout << "#" << testCase << " " << result << endl;
    }

    return 0;
}