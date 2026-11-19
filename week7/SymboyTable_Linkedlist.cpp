#include <iostream>
#include <string>
using namespace std;

struct Node {
    string key;
    int value;
    Node* next;

    Node(string k, int v) {
        key = k;
        value = v;
        next = nullptr;
    }
};

class SymbolTable {
private:
    Node* head;
public:
    SymbolTable() {
        head = nullptr;
    }

    void insert(string key, int value) {
        Node* p = head;

        // cây tồn tại -> cập nhật
        while (p != nullptr) {
            if (p->key == key) {
                p->value = value;
                return;
            }
            p = p->next;
        }

        // thêm node vào đầu ds
        Node* newNode = new Node(key, value);
        newNode->next = head;
        head = newNode;
    }

    int search(string key) {
        Node* p = head;
        while (p != nullptr) {
            if (p->key == key) {
                return p->value;
            }
            p = p->next;
        }
        return -1;
    }

    void remove(string key) {
        Node* p = head;
        Node* prev = nullptr;

        while (p != nullptr) {
            if (p->key == key) {
                if (prev == nullptr) {
                    head = p->next;
                } else {
                    prev->next = p->next;
                }
                delete p;
                return;
            }
            prev = p;
            p = p->next;
        }
    }

    void display() {
        Node* p = head;
        while (p != nullptr) {
            cout << p->key << " : "
                 << p->value << endl;
            p = p->next;
        }
    }

    ~SymbolTable() {
        Node* p = head;

        while (p != nullptr) {
            Node* temp = p;
            p = p->next;
            delete temp;
        }
    }
};

int main() {
    SymbolTable st;

    st.insert("a", 10);
    st.insert("b", 20);
    st.insert("c", 30);

    cout << "Symbol Table:\n";
    st.display();
    cout << "\nSearch b: "
         << st.search("b") << endl;

    st.remove("b");
    cout << "\nAfter remove b:\n";
    st.display();
    return 0;
}