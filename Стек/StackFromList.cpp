#include "StackFromList.h"

Stack *steck = new Stack;


void stack::Clear()
{
	while (cin.get() != '\n')
	{
		cin.clear();
	}
}



void stack::Create(double element)
{
	Node *unit = new Node;
	unit->Data = element;
	steck->Head = steck->Tail = unit;
	unit->Next = unit->Prev = nullptr;
}

void stack::ClearStack()
{
	Node *temp = new Node;
	temp = steck->Head->Next;
	while (temp!= nullptr)
	{
		if (steck->Tail==temp)
		{
			delete temp;
			steck->Head = steck->Tail = nullptr;
			break;
		}
		else
		{
			delete temp->Prev;
			temp->Prev = nullptr;
			steck->Head = temp;
			temp = temp->Next;
		}
	}
}

void stack::Push(double element)
{
	if (steck->Head != steck->Tail || (steck->Head==steck->Tail && steck->Head!=nullptr))
	{
		Node *temp = new Node;
		temp = steck->Tail;
		Node *unit = new Node;
		unit->Data = element;
		unit->Prev = temp;
		unit->Next = nullptr;
		temp->Next = unit;
		steck->Tail = unit;
	}
	else
	{
		cout << "Стек еще не создан или пуст\n";
		system("pause");
	}
}

bool stack::Pop()
{
	if (steck->Tail != steck->Head)
	{
		Node* temp = new Node;
		Node* unit = new Node;
		temp = steck->Tail;
		unit = temp->Prev;
		unit->Next = nullptr;
		steck->Tail = unit;
		cout << "Последний элемент стека = " << temp->Data << "\n";
		delete temp;
		return true;
	}
	else if (steck->Tail == steck->Head&&steck->Head!=nullptr)
	{
		Node* temp = new Node;
		temp = steck->Head;
		steck->Head = steck->Tail = nullptr;
		cout<<"Последний элемент стека = "<< temp->Data << "\n";
		delete temp;
		return true;
	}
	else if (steck->Tail == steck->Head && steck->Head == nullptr)
	{
		return false;
	}
}