#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double lld;
typedef unsigned long long ull;
const ll MOD = 1000000007;
#define print(v)     \
	for (auto x : v) \
	cout << x << " "
#define io                            \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL)

class LinkedList
{

	struct node
	{
		int item;
		node *next;
	};

	node *head;
	node *tail;
	int count;

public:
	LinkedList()
	{
		head = tail = NULL;
		count = 0;
	}

	bool isEmpty()
	{
		return count == 0;
	}

	void insertFirst(int data)
	{
		node *newNode = new node;
		newNode->item = data;
		if (isEmpty())
		{
			head = tail = newNode;
			newNode->next = NULL;
		}
		else
		{
			newNode->next = head;
			head = newNode;
		}
		count++;
		cout << "Inseted First " << data << "\n";
	}
	void insertLast(int data)
	{
		node *newNode = new node;
		newNode->item = data;
		if (isEmpty())
		{
			head = tail = newNode;
			newNode->next = NULL;
		}
		else
		{
			tail->next = newNode;
			newNode->next = NULL;
			tail = newNode;
		}
		count++;
		cout << "Inseted Last " << data << "\n";
	}

	void insertAtIndex(int data, int index)
	{
		if (index > count || index < 0)
		{
			puts("Index out of Range!");
		}

		else if (index == 0)
		{
			insertFirst(data);
		}
		else if (index == count)
		{
			insertLast(data);
		}
		else
		{
			node *newNode = new node;
			newNode->item = data;
			node *curr = head;
			for (int i = 1; i < index; i++)
			{
				curr = curr->next;
			}
			newNode->next = curr->next;
			curr->next = newNode;
			count++;
			cout << "Inseted " << data << " at index " << index
				 << "\n";
		}
	}

	void RemoveAtIndex(int index)
	{
		if (index == 0)
		{
			head = head->next;
		}
		else if (!isEmpty())
		{
			node *prev = head;
			index--;
			while (index--)
			{
				prev = prev->next;
			}
			node *curr = prev->next;
			prev->next = curr->next;
			delete (curr);
		}
	}
	
	int search(int value)
	{
		int pos = 0;
		node *curr = head;
		while (curr != NULL)
		{
			if (curr->item == value)
			{
				cout << "Found " << value << " at Pos ";

				return pos;
			}
			curr = curr->next;
			pos++;
		}
		return -1;
	}
	void reverse()
	{
		node *curr, *prev, *next;
		prev = NULL;
		curr = head;
		next = curr->next;
		while (next != NULL)
		{
			next = curr->next;
			curr->next = prev;
			prev = curr;
			curr = next;
		}
		head = prev;
		cout << "\nReversed ";
	}
	void DisplayALL()
	{
		cout << "\n";
		cout << "List = ";
		node *curr = head;
		while (curr != NULL)
		{
			cout << curr->item << " ";
			curr = curr->next;
		}
		cout << "\n";
	}
};

int main()
{
	io;
	LinkedList list;
	list.insertFirst(1);
	list.insertFirst(2);
	list.insertFirst(3);
	list.insertLast(10);
	list.insertLast(4);
	list.insertAtIndex(5, 3);
	list.DisplayALL();
	cout << list.search(10);
	list.reverse();
	list.DisplayALL();
	list.RemoveAtIndex(5);
	list.DisplayALL();
}
