#include <iostream>
using namespace std;
template <class T>
class DNode
{
public:
	T info;
	DNode<T>* next;
	DNode<T>* prev;
	DNode(T val)
	{
		info = val;
		next = prev = nullptr;
	}
};
template <class T>
class CDLL
{
public:
	DNode<T>* head;
	CDLL()
	{
		head = nullptr;
	}
	void insertAtHead(T val)
	{
		if (!head)
		{
			head = new DNode<T>(val);
			head->next = head;
			head->prev = head;
			return;
		}
		DNode<T>* x = new DNode<T>(val);
		x->next = head;
		x->prev = head->prev;
		head->prev->next = x;
		head->prev = x;
		head = x;
	}
	void insertAtTail(T val)
	{
		if (!head)
		{
			head = new DNode<T>(val);
			head->next = head;
			head->prev = head;
			return;
		}
		DNode<T>* temp = head;
		while (temp->next != head)
		{
			temp = temp->next;
		}
		DNode<T>* x = new DNode<T>(val);
		head->prev->next = x;
		x->prev = head->prev;
		x->next = head;
		head->prev = x;
	}
	void deleteAtHead()
	{
		if (!head)
			return;
		if (head->next == head)
		{
			delete head;
			head = nullptr;
			return;
		}
		DNode<T>* del = head;
		head = head->next;
		head->prev = del->prev;
		del->prev->next = head;
		delete del;
	}
	void deleteAtTail()
	{
		if(!head)
			return;
		if (head->next == head)
		{
			delete head;
			head = nullptr;
			return;
		}
		DNode<T>* del = head->prev;
		del->prev->next = head;
		head->prev = del->prev;
		delete del;
	}
	void insertBefore(T key, T val)
	{
		if (!head)
			return;
		if (head->info == key)
		{
			insertAtHead(val);
			return;
		}
		DNode<T>* temp = head->next;
		while (temp != head)
		{
			if (temp->info == key)
			{
				DNode<T>* x = new DNode<T>(val);
				x->next = temp;
				x->prev = temp->prev;
				temp->prev->next = x;
				temp->prev = x;
				return;
			}
			temp = temp->next;
		}
	}
	void insertAfter(T key, T val)
	{
		if (!head)
			return;
		if (head->info == key)
		{
			DNode<T>* x = new DNode<T>(val);
			x->next = head->next;
			x->prev = head;
			head->next->prev = x;
			head->next = x;
			return;
		}
		DNode<T>* x = new DNode<T>(val);
		DNode<T>* temp = head->next;
		while (temp != head)
		{
			if (temp->info == key)
			{
				if (temp->next == head)
				{
					insertAtTail(val);
					return;
				}
				x->next = temp->next;
				x->prev = temp;
				temp->next->prev = x;
				temp->next = x;
				return;
			}
			temp = temp->next;
		}
	}
	void deleteBefore(T key)
	{
		if (!head)
			return;
		if (head->next == head)
			return;
		if (head->info == key)
		{
			deleteAtTail();
			return;
		}
		if (head->next->info == key)
		{
			deleteAtHead();
			return;
		}
		DNode<T>* temp = head->next->next;
		while (temp != head)
		{
			if (temp->info == key)
			{
				DNode<T>* del = temp->prev;
				temp->prev = del->prev;
				temp->prev->next = temp;
				delete del;
				return;
			}
			temp = temp->next;
		}
	}
	void deleteAfter(T key)
	{
		if (!head)
			return;
		if (head->next == head)
			return;
		if (head->prev->info == key)
		{
			deleteAtHead();
			return;
		}
		DNode<T>* temp = head;
		do {
			if (temp->info == key)
			{
				if (temp->next->next == head)
				{
					deleteAtTail();
					return;
				}
				DNode<T>* del = temp->next;
				temp->next = del->next;
				temp->next->prev = temp;
				delete del;
				return;
			}
			temp = temp->next;
		} while (temp != head);
	}
	void display()
	{
		if (!head)
			return;
		DNode<T>* temp = head;
		do {
			cout << temp->info << " ";
			temp = temp->next;
		} while (temp != head);
		cout << endl;
	}
};
int main()
{
	CDLL<int> ll;
	ll.insertAtHead(4);
	ll.insertAtTail(6);
	ll.insertAtTail(8);
	ll.insertAtTail(10);
	ll.insertAtHead(2);
	ll.display();
	//ll.deleteAtHead();
	//ll.display();
	//ll.deleteAtTail();
	//ll.display();
	ll.insertAfter(6, 3);
	ll.display();
	ll.insertBefore(10, 5);
	ll.display();
	ll.deleteAfter(6);
	ll.display();
	ll.deleteBefore(10);
	ll.display();
	return 0;
}