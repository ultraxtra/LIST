#include <iostream>
using namespace std;

struct Element
{
	char data;
	Element* Next;
};

class List
{
	Element* Head;
	Element* Tail;
	int Count;

public:
	List();
	~List();

	void Add(char data);

	void Del();
	void DelAll();

	void Print();

	int GetCount();

	bool insert(int position, char data);
	void erase(int position);
	int search(char data);
};

List::List()
{
	Head = Tail = NULL;
	Count = 0;
}

List::~List()
{
	DelAll();
}

int List::GetCount()
{
	return Count;
}

void List::Add(char data)
{
	Element* temp = new Element;

	temp->data = data;
	temp->Next = NULL;
	if (Head != NULL) {
		Tail->Next = temp;
		Tail = temp;
	}
	else {
		Head = Tail = temp;
	}

	Count++;
}

void List::Del()
{
	Element* temp = Head;
	Head = Head->Next;
	delete temp;
}

void List::DelAll()
{
	while (Head != 0)
		Del();
}

void List::Print()
{
	Element* temp = Head;
	while (temp != 0)
	{
		cout << temp->data << " ";
		temp = temp->Next;
	}

	cout << "\n\n";
}

bool List::insert(int position, char data) {

	if (position<1 || position>Count)
	{
		cout << "Error!";
		exit(1);
	}

	if (position == 1) {
		Element* ptr = Head;
		Head = new Element;
		Head->data = data;
		Head->Next = ptr;
	}

	else if (position == Count) {
		Element* ptr = Tail;
		Tail = new Element;
		Tail->data = data;
		Tail->Next = NULL;
		ptr->Next = Tail;
	}

	else
	{
		Element* ptr = Head;
		int i = 1;
		while (i < position - 1) {
			ptr = ptr->Next;
			i++;
		}

		Element* prev = ptr;
		Element* next = ptr->Next;
		Element* cur = new Element;
		prev->Next = cur;
		cur->data = data;
		cur->Next = next;
	}
	Count++;
}
void List::erase(int position) {
	if (position<1 || position>Count)
	{
		cout << "Error!";
		exit(1);
	}

	if (position == 1) {
		Element* ptr = Head;
		Head = Head->Next;
		delete ptr;
	}

	else if (position == Count) {
		int i = 1;
		Element* ptr = Head;
		while (i < Count - 1) {
			ptr = ptr->Next;
			i++;
		}
		Tail = ptr;
		delete Tail->Next;
		Tail->Next = NULL;
	}
	else
	{
		Element* ptr = Head;
		int i = 1;
		while (i < position - 1) {
			ptr = ptr->Next;
			i++;
		}

		Element* prev = ptr;
		Element* cur = ptr->Next;
		Element* next = cur->Next;
		prev->Next = next;
		delete cur;
	}
	Count--;
}

int List::search(char data) {
	Element* ptr = Head;

	int i = 1;

	while (ptr) {
		if (ptr->data == data) return i;
		ptr = ptr->Next;
		i++;
	}

	return NULL;
}

void main()
{
	List lst;

	char s[] = "Hello, World !!!";
	cout << s << "\n\n";
	int len = strlen(s);
	for (int i = 0; i < len; i++)
		lst.Add(s[i]);
	lst.Print();

	lst.insert(1, 'N');
	lst.insert(1 + 1, 'i');
	lst.insert(1 + 2, 'c');
	lst.insert(1 + 3, 'e');
	lst.insert(1 + 4, ' ');
	lst.insert(1 + 5, 'j');
	lst.insert(1 + 6, 'o');
	lst.insert(1 + 7, 'b');
	lst.insert(1 + 8, '!');
	lst.insert(1 + 9, ' ');
	lst.Print();

	lst.erase(12);
	lst.erase(10);
	lst.erase(8);
	lst.erase(6);
	lst.erase(4);
	lst.erase(2);
	lst.erase(1);
	lst.erase(lst.GetCount());
	lst.Print();

	cout << lst.search('d') << '\n';
}