#include <iostream>
#include <string>
using namespace std;

struct Entry {
    string key;
    int value;
};

class SymbolTable {
private:
    Entry data[100];
    int n;
public:
    SymbolTable() {
        n = 0;
    }
    
    void insert(string key, int value) {
        // ktra key đã tồn tại
        for (int i = 0; i < n; i++) {
            if (data[i].key == key) {
                data[i].value = value;
                return;
            }
        }

        if (n == 100) {
            cout << "Mảng đầy!\n";
            return;
        }
        data[n].key = key;
        data[n].value = value;
        n++;
    }

    int search(string key) {
        for (int i = 0; i < n; i++) {
            if (data[i].key == key) {
                return data[i].value;
            }
        }

        return -1;
    }

    void remove(string key) {
        for (int i = 0; i < n; i++) {
            if (data[i].key == key) {
                for (int j = i; j < n - 1; j++) {
                    data[j] = data[j + 1];
                }
                n--;
                return;
            }
        }
    }

    void display() {
        for (int i = 0; i < n; i++) {
            cout << data[i].key << " : "
                 << data[i].value << endl;
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