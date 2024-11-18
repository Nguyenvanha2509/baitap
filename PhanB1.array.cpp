#include <iostream>
#include <string>
using namespace std;
#define MAX 10000 
class Stack {
private:
    string st[MAX]; // Mang chua cac phan tu cua stack
    int n;          // Bien luu tru so luong phan tu trong stack
public:
    // Constructor
    Stack() : n(0) {}
    // Ham push de them phan tu vao stack
    void push(const string& x) {
        if (n >= MAX) {
            cout << "STACK FULL! Khong the them phan tu.\n";
        } else {
            st[n] = x;
            ++n;
        }
    }
    // Ham pop de loai bo phan tu khoi stack
    void pop() {
        if (n == 0) {
            cout << "STACK EMPTY! Khong the pop.\n";
        } else {
            --n;
            cout << "Pop thanh cong.\n";
        }
    }

    // Ham top de lay phan tu o dinh stack
    string top() {
        if (n == 0) {
            cout << "STACK EMPTY! Khong co phan tu o dinh.\n";
            return ""; // Tra ve chuoi rong neu stack rong
        } else {
            return st[n - 1];
        }
    }
    // Ham size de tra ve so luong phan tu trong stack
    int size() {
        return n;
    }
    // Ham nhap cac phan tu vao stack
    void inputStack() {
        int initSize;
        do {
            cout << "Nhap so luong phan tu ban dau cua stack: ";
            cin >> initSize;
            if (initSize <= 0) {
                cout << "So luong phan tu phai lon hon 0. Vui long nhap lai.\n";
            }
            if (initSize > MAX) {
                cout << "So luong vuot qua kich thuoc toi da (" << MAX << "). Chi nhan toi da " << MAX << " phan tu.\n";
                initSize = MAX;
            }
        } while (initSize <= 0);
        cin.ignore(); // Bo qua ky tu xuong dong truoc khi nhap chuoi
        for (int i = 0; i < initSize; ++i) {
            cout << "Nhap chuoi thu " << i + 1 << ": ";
            string x;
            getline(cin, x); // Nhap chuoi co khoang trang
            push(x);
        }
        cout << "Stack da duoc khoi tao voi " << initSize << " chuoi.\n";
    }
    // Ham xuat cac phan tu trong stack
    void outputStack() {
        if (n == 0) {
            cout << "STACK EMPTY! Khong co phan tu de xuat.\n";
        } else {
            cout << "Cac chuoi trong stack (tu dinh xuong day):\n";
            for (int i = n - 1; i >= 0; --i) {
                cout << st[i] << " ";
            }
            cout << endl;
        }
    }
};
// Ham menu
void menu(Stack& stack) {
    int lc;
    while (true) {
        cout << "-------------------------------\n";
        cout << "1. push\n";
        cout << "2. pop\n";
        cout << "3. top\n";
        cout << "4. size\n";
        cout << "5. xuat stack\n";
        cout << "0. Thoat\n";
        cout << "-------------------------------\n";
        cout << "Nhap lua chon: ";
        cin >> lc;
        if (lc == 1) {
            cin.ignore(); // Bo qua ky tu xuong dong truoc khi nhap chuoi
            string x;
            cout << "Nhap chuoi: ";
            getline(cin, x); // Nhap chuoi co khoang trang
            stack.push(x);
        } else if (lc == 2) {
            stack.pop();
        } else if (lc == 3) {
            string t = stack.top();
            if (!t.empty()) {
                cout << "Chuoi o dinh: " << t << endl;
            }
        } else if (lc == 4) {
            cout << "So luong chuoi trong stack: " << stack.size() << endl;
        } else if (lc == 5) {
            stack.outputStack();
        } else if (lc == 0) {
            break;
        } else {
            cout << "Lua chon khong hop le. Vui long nhap lai.\n";
        }
    }
}
int main() {
    Stack stack; // Khoi tao stack
    stack.inputStack(); // Khoi tao stack ban dau
    menu(stack);       // Goi menu de nguoi dung thao tac
    return 0;
}

