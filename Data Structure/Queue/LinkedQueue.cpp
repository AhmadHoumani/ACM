#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double lld;
typedef unsigned long long ull;
const ll MOD = 1000000007;
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

class LinkedQueue {
private:
    struct Node {
        int data;
        Node *next;
    };
    int count;
    Node *head, *tail;

public:
    LinkedQueue() : head(NULL), tail(NULL), count(0) {}

    bool isEmpty() {
        return count == 0;
    }

    void Add(int value) {
        Node *newPtr = new Node;
        newPtr->data = value;
        newPtr->next = NULL;
        count++;
        if (isEmpty()) {
            head = tail = newPtr;
        } else {
            tail->next = newPtr;
            tail = newPtr;
        }

    }

    void Remove() {
        if (isEmpty()) {
            cout << "Queue is Empty!";
        } else {
            if (count == 1) {
                delete (head);
                tail = NULL;
                count = 0;
            } else {
                Node *temp = head;
                head = head->next;
                delete (temp);
                count--;
            }

        }
    }

    int GetHead() {
        if (!isEmpty()) {
            return head->data;
        } else {
            cout << "Queue is Empty!";
        }
    }

    int GetTail() {
        assert(!isEmpty());
        return tail->data;
    }

    void DeleteAll() {
        Node *curr;
        while (head != NULL) {
            curr = head;
            head = head->next;
            delete (curr);
        }
        tail = NULL, count = 0;
    }

    void PintAll() {
        Node *curr = head;
        while (curr != NULL) {
            cout << curr->data << " ";
            curr = curr->next;
        }
    }

    bool Find(int value) {
        Node *curr = head;
        while (curr != NULL) {
            if (curr->data == value) {
                return true;
            }
            curr = curr->next;
        }
        return false;
    }
};

int main() {
    io;


}
