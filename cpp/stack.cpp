#include <bits/stdc++.h>
using namespace std;

class Stack {
private:
    vector<int> data;  // 내부 저장용 벡터

public:
    // 스택이 비어있는지 확인
    bool empty() const {
        return data.empty();
    }

    // 스택 크기 반환
    int size() const {
        return data.size();
    }

    // 값 추가
    void push(int val) {
        data.push_back(val);
    }

    // top 값 반환
    int top() const {
        if (empty()) {
            throw runtime_error("Stack is empty");
        }
        return data.back();
    }

    // top 값 제거
    void pop() {
        if (empty()) {
            throw runtime_error("Stack is empty");
        }
        data.pop_back();
    }
};

// 테스트 예제
int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top: " << s.top() << "\n"; // 30
    s.pop();
    cout << "Top after pop: " << s.top() << "\n"; // 20

    cout << "Stack size: " << s.size() << "\n"; // 2

    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << "\n";

    return 0;
}
