#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double lld;
typedef unsigned long long ull;
const ll MOD = 1000000007;
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

const int SIZE = 5;

template<class Type>

class LinkedStack {
    struct Node {
        Type data;
        Node *next;
    };
    Node *curr, *top;

public:
    LinkedStack() : top(NULL) {}

    bool isEmpty() {
        return top == NULL;
    }

    void Add(Type value) {
        Node *newNode = new Node;
        newNode->data = value;
        newNode->next = top;
        top = newNode;
    }

    void Remove() {
        if (!isEmpty()) {
            cout << "\n" << top->data << " Removed!";
            top = top->next;
        }
    }

    void GetTop() {
        if (!isEmpty()) {
            cout << "\nTop Element: " << top->data;
        }
    }

    void PrintAll() {
        cout << "\nStack Elements: " << "[ ";
        curr = top;
        while (curr != NULL) {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << "]" << "\n";

    }
};

int main() {
    io;
    LinkedStack<int> s;
    while (true) {
        string val;
        cin >> val;
        if (val == "stop") {
            break;
        }
        int x = stoi(val);
        s.Add(x);
        cout << x << " Added!" << "\n";
    }
    s.PrintAll();
    s.GetTop();
    s.Remove();
    s.GetTop();
    s.Remove();
    s.PrintAll();

}
