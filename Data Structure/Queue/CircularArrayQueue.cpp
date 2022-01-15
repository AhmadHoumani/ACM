#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double lld;
typedef unsigned long long ull;
const ll MOD = 1000000007;
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

class CircularArrayQueue {
    int head, tail, count, *arr, maxSize;

public:
    CircularArrayQueue(int size) {
        if (size <= 0) {
            maxSize = 100;
        } else {
            maxSize = size;
        }
        head = 0,
        tail = maxSize - 1,
        count = 0,
        arr = new int[maxSize];

    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == maxSize;
    }

    void Add(int value) {
        if (!isFull()) {
            count++;
            tail = (tail + 1) % maxSize;
            arr[tail] = value;
            cout << "\nValue Added: " << value;

        } else {
            puts("Queue is Full!");
        }
    }

    void Remove() {
        if (!isEmpty()) {
            count--;
            cout << "\nValue at Head removed: " << arr[head];

            head = (head + 1) % maxSize;
        } else {
            puts("Queue is Empty!");
        }
    }

    int GetHead() {
        if (!isEmpty()) {
            cout << "\nValue at Head: ";

            return arr[head];
        }
    }

    int GetTail() {
        if (!isEmpty()) {
            cout << "\nValue at Tail: ";
            return arr[tail];
        }
    }

    void PrintQueue() {

        if (!isEmpty()) {
            cout << "\nQueue Elements: ";
            for (int i = head; i != tail; i = (i + 1) % maxSize) {
                cout << arr[i] << " ";
            }
            cout << arr[tail];
        } else {
            puts("Queue is Empty!");
        }
    }

    int Find(int value) {
        if (!isEmpty()) {
            for (int i = head; i < tail; i = (i + 1) % maxSize) {
                if (arr[i] == value) {
                    cout << "\nFound at index: " << i;
                    return true;
                }
            }
            if (arr[tail] == value) {
                cout << "\nFound at index: " << tail;

                return true;
            }
        }
        cout << "\nNot Found";

        return false;
    }

};


int main() {
    io;
    CircularArrayQueue q(5);
    for (int i = 0; i < 5; ++i) {
        int x;
        cin >> x;
        q.Add(x);
    }
    q.PrintQueue();
    q.Find(4);
    cout << q.GetHead();
    q.Remove();
    cout << q.GetHead();
    q.PrintQueue();

}
