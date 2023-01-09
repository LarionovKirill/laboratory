#include "QueueFromStack.h"


void QueueFromStack::Init(Stack *steck)
{
	steck->Head = steck->Tail = nullptr;
}

void QueueFromStack::Push(Stack * steck, double element)
{
	if (steck->Head == steck->Tail && steck->Head == nullptr)
	{
		Node* temp = new Node;
		temp->Data = element;
		steck->Head = steck->Tail = temp;
		temp->Next = temp->Prev = nullptr;
	}
	else
	{
		Node* temp = new Node;
		temp->Data = element;
		Node * unit = new Node;
		unit = steck->Tail;
		unit->Next=temp;
		temp->Prev = unit;
		temp->Next = nullptr;
		steck->Tail = temp;
	}
}

void QueueFromStack::Pop(Stack * steck, Stack * steck2)
{
	if (steck->Head != nullptr&&steck2->Head == nullptr)
	{
		if (steck->Head == steck->Tail)
		{
			Node * temp = new Node;
			temp = steck->Head;
			cout << "Первый элемент очереди : " << temp->Data<<"\n";
			delete temp;
			steck->Head = steck->Tail = nullptr;
		}
		else
		{
			Node * temp = new Node;
			temp = steck->Tail;
			Node * temp2 = new Node;
			temp2->Data = temp->Data;
			temp2->Next = temp2->Prev = nullptr;
			steck2->Head = steck2->Tail = temp2;
			temp = temp->Prev;
			delete temp->Next;
			temp->Next = nullptr;
			while (temp->Prev != nullptr)
			{
				Node *unit = new Node;
				temp2 = steck2->Tail;
				unit->Data = temp->Data;
				unit->Prev = temp2;
				temp2->Next=unit;
				steck2->Tail = unit;
				unit->Next = nullptr;
				temp = temp->Prev;
				delete temp->Next;
				temp->Next = nullptr;
			}
			cout << "Первый элемент очереди : " << temp->Data << "\n";
			delete temp;
			steck->Head = steck->Tail = nullptr;
		}
	}
	else if (steck2->Head != nullptr)
	{
		Node* temp = new Node;
		temp = steck2->Tail;
		cout << "Первый элемент очереди : " << temp->Data<<"\n";
		if (temp->Prev != nullptr)
		{
			temp = temp->Prev;
			delete temp->Next;
			temp->Next = nullptr;
			steck2->Tail = temp;
		}
		else
		{
			delete temp;
			steck2->Head = steck2->Tail = nullptr;
		}
	}
	else if (steck->Head == nullptr && steck2->Head == nullptr)
	{
		cout << "Очередь пустая\n";
	}
}



void QueueFromStack::Remove(Stack * steck)
{
	if (steck->Head != nullptr)
	{
		Node * temp = new Node;
		temp = steck->Head;
		while (temp->Next != nullptr)
		{
			temp = temp->Next;
			delete temp->Prev;
			temp->Prev = nullptr;
			steck->Head = temp;
		}
		delete temp;
		steck->Head = steck->Tail = nullptr;
	}
}

/*void QueueFromStack::Watch(Stack * steck, Stack * steck2)
{
	if (steck->Head != nullptr)
	{
		Node* temp = new Node;
		temp = steck->Head;
		cout << "Стек 1:\n";
		while (temp != nullptr)
		{
			cout << temp->Data << "  ";
			temp = temp->Next;
		}
		cout << endl;
		delete temp;
	}
	if (steck2->Head != nullptr)
	{
		Node* temp = new Node;
		temp = steck2->Head;
		cout << "Стек 2:\n";
		while (temp != nullptr)
		{
			cout << temp->Data << "  ";
			temp = temp->Next;
		}
		cout << endl;
		delete temp;
	}
}
*/
