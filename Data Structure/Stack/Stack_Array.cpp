#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double lld;
typedef unsigned long long ull;
const ll MOD = 1000000007;
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

const int SZ = 5;

class Stack {
    int top;
    int StackArray[SZ];

public:
    Stack() : top(-1) {}

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == SZ - 1;
    }

    void Add(int data) {
        if (isFull()) {
            cout << "Stack full";
        } else {

            StackArray[++top] = data;
        }
    }

    void Remove() {
        if (!isEmpty()) {
            cout << "\n" << StackArray[top] << " Removed!" << "\n";
            top--;
        } else {
            cout << "Stack empty";
        }
    }

    void GetTop() {
        if (!isEmpty()) {
            cout << "\n" << "Top Element: " << StackArray[top];
        } else {
            cout << "Stack empty";
        }
    }

    void PrintAll() {
        cout << "Stack = [ ";
        for (int i = top; i >= 0; i--) {
            cout << StackArray[i] << " ";
        }
        cout << "]";
    }
};

int main() {
    io;
    Stack s;
    while (!s.isFull()) {
        int x;
        cin >> x;
        s.Add(x);
        cout << x << " Added!" << "\n";
    }
    s.PrintAll();
    s.GetTop();
    s.Remove();
    s.PrintAll();
}
