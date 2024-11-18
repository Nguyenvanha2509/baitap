#include <iostream>
#include <string>
using namespace std;
#define MAX 100000 
class Stack {
private:
    int stk[MAX];  
    int topIndex;

public:
    Stack() : topIndex(-1) {}
    // Ham push de day phan tu vao stack
    void push(int x) {
        stk[++topIndex] = x;  
    }
    // Ham pop de lay phan tu tu stack
    void pop() {
        --topIndex; 
    }
    // Ham top de lay phan tu o dinh stack
    int top() const {
        return stk[topIndex]; 
    }
    // Ham kiem tra stack rong hay khong
    bool isEmpty() const {
        return topIndex == -1;
    }
};
void processParentheses(const string& s) {
    Stack stack;

    // Duyet qua tung ki tu trong xau ngoac
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '(') {
            // Day chi so cua dau mo ngoac vao stack
            stack.push(i + 1);  
        } else if (s[i] == ')') {
            // Dau dong ngoac, lay chi so dau mo ngoac tu stack
            int u = stack.top(); 
            stack.pop(); 
            int v = i + 1;
            cout << u << " " << v << endl;
        }
    }
}

int main() {
    string s;
    cin >> s;
    processParentheses(s);  
    return 0;
}


