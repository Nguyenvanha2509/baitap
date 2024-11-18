#include <iostream>
#include <string>
using namespace std;
struct Node {
    string data; 
    Node* next;    // Con tro toi phan tu tiep theo
};
class Stack {
private:
    Node* topNode; // Con tro toi phan tu dau (dinh stack)
    int n;         // So luong phan tu trong stack
public:
    // Ham khoi tao
    Stack() : topNode(nullptr), n(0) {}
    // Ham day phan tu vao stack
    void push(const string& x) {
        Node* newNode = new Node;
        newNode->data = x;
        newNode->next = topNode;
        topNode = newNode;
        ++n;
    }
    // Ham lay phan tu khoi stack
    void pop() {
        if (n == 0) {
            cout << "STACK EMPTY! Khong the pop.\n";
        } else {
            Node* temp = topNode;
            topNode = topNode->next;
            delete temp;
            --n;
            cout << "Pop thanh cong.\n";
        }
    }
    // Ham lay phan tu o dinh stack
    string top() {
        if (n == 0) {
            cout << "STACK EMPTY! Khong co phan tu o dinh.\n";
            return ""; // Tra ve chuoi rong neu stack rong
        } else {
            return topNode->data;
        }
    }
    // Ham tra ve so luong phan tu trong stack
    int size() {
        return n;
    }
    // Ham xuat cac phan tu trong stack
    void outputStack() {
        if (n == 0) {
            cout << "STACK EMPTY! Khong co phan tu de xuat.\n";
        } else {
            cout << "Cac phan tu trong stack (tu dinh xuong day):\n";
            Node* temp = topNode;
            while (temp != nullptr) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
    // Ham huy stack (giai phong bo nho)
    ~Stack() {
        while (topNode != nullptr) {
            Node* temp = topNode;
            topNode = topNode->next;
            delete temp;
        }
    }
};
// Ham nhap cac phan tu vao stack
void inputStack(Stack& stack) {
    cout << "Nhap so luong phan tu ban dau cua stack: ";
    int initSize;
    cin >> initSize;
    // Kiem tra so luong phan tu
    while (initSize <= 0) {
        cout << "So luong phan tu phai lon hon 0. Vui long nhap lai: ";
        cin >> initSize;
    }
    cin.ignore(); // Bo qua ky tu xuong dong truoc khi nhap du lieu
    for (int i = 0; i < initSize; ++i) {
        cout << "Nhap phan tu thu " << i + 1 << ": ";
        string x;
        getline(cin, x); // Nhap chuoi
        stack.push(x);
    }
    cout << "Stack da duoc khoi tao voi " << initSize << " phan tu.\n";
}
// Ham menu
void menu(Stack& stack) {
    int lc;
    do {
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
        // Kiem tra lua chon
        if (lc == 1) {
            cin.ignore(); // Bo qua ky tu xuong dong
            string x;
            cout << "Nhap chuoi: ";
            getline(cin, x);
            stack.push(x);
        } else if (lc == 2) {
            stack.pop();
        } else if (lc == 3) {
            string t = stack.top();
            if (!t.empty()) {
                cout << "Phan tu o dinh: " << t << endl;
            }
        } else if (lc == 4) {
            cout << "So phan tu trong stack: " << stack.size() << endl;
        } else if (lc == 5) {
            stack.outputStack();
        } else if (lc != 0) {
            cout << "Lua chon khong hop le. Vui long nhap lai.\n";
        }
    } while (lc != 0);
}
int main() {
    Stack stack;  // Khoi tao stack
    inputStack(stack); // Khoi tao stack ban dau
    menu(stack);       // Goi menu de nguoi dung thao tac
    return 0;
}


