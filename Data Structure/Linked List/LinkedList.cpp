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
		}
	}

	void DisplayALL()
	{
		node *curr = head;
		while (curr != NULL)
		{
			cout << curr->item << " ";
			curr = curr->next;
		}
	}
};

int main()
{
	io;
	LinkedList list;
	list.insertFirst(10);
	list.insertFirst(5);
	list.insertFirst(0);
	list.insertLast(10);
	list.insertAtIndex(5, 3);
	list.DisplayALL();
}
