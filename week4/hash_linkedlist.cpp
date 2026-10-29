#include<iostream>
using namespace std;
const int SIZE =11;
struct Node {
    int data;
    Node* next;
};
Node* table[SIZE];

void hashtable(){
    for(int i =0; i<SIZE; i++){
        table[i]=NULL;
    }
}
int hashFunction (int x){
    return x%SIZE;
}
void insert(int x){
    int index = hashFunction(x);
    Node* p = new Node;
    p->data =x;
    p->next = table[index];
    table[index]=p;
}
void display(){
    for(int i=0;i<SIZE; i++){
        cout<<i<<": ";
        Node* p=table[i];
        while(p != NULL){
            cout<< p->data<<" -> ";
            p=p->next;
     
        }
        cout<<"NULL"<<endl;
    }
}
bool search(int x){
    int index = hashFunction(x);
    Node* p=table[index];
    while(p != NULL){
        if(p->data ==x){
            return true;
        }
        p=p->next;
    }
    return false;
}


int main(){
hashtable();
int n,x;
cin>>n;
for(int i=0;i<n;i++){
    cout<<"Nhap phan tu: ";
    cin>>x;
    insert(x);
}
cout << "\nBang bam:\n";
    display();

    cout << "\nNhap so can tim: ";
    cin >> x;

    if (search(x)) {
        cout << "Tim thay " << x << endl;
    } else {
        cout << "Khong tim thay " << x << endl;
    }
   return 0;
}