#include <iostream>
using namespace std;

#define MAX 100000 

class Stack {
private:
    int st[MAX];  
    int topIndex;
public:
    Stack() : topIndex(-1) {}

    // Ham day phan tu vao ngan xep
    void push(int x) {
        if (topIndex < MAX - 1) {
            st[++topIndex] = x;  // Day phan tu vao vi tri dinh va tang topIndex
        }
    }

    // Ham loai bo phan tu khoi ngan xep
    void pop() {
        if (topIndex != -1) {  // Kiem tra neu ngan xep rong thi khong lam gi
            --topIndex;        
        }
    }

    // Ham in phan tu o dinh ngan xep
    void top() {
        if (topIndex == -1) {
            cout << "Empty!\n";  
        } else {
            cout << st[topIndex] << endl;  
        }
    }
};

int main() {
    int T; 
    cin >> T;

    Stack stack; 
    while (T--) {
        int query;
        cin >> query;

        if (query == 1) { 
            int n;
            cin >> n;
            stack.push(n);
        }
        else if (query == 2) { 
            stack.pop();
        }
        else if (query == 3) {  
            stack.top();
        }
    }

    return 0;
}


