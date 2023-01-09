#include "List.h"
#include "Listitem.h"
#include <iostream>
#include <ctime>
#include <iostream>
using namespace std;

List* list = new List;

void Menu()
{
	cout << "������� 1 ��� ������������� ����������� ������\n";
	cout << "������� 2 ��� ���������� �������� � ����� ������\n";
	cout << "������� 3 ��� ���������� �������� � ������ ������\n";
	cout << "������� 4 ��� ���������� ������\n";
	cout << "������� 5 ��� ������ �������� � ������\n";
	cout << "������� 6 ��� ������� �������� � ������ �� ��������\n";
	cout << "������� 7 ��� �������� �������� � ������ �� ��������\n";
	cout << "������� 8 ��� ��������� ������\n";
	cout << "������� 9 ��� ������ ����\n";

}

void Clear()
{
	while (cin.get() != '\n')
	{
		cin.clear();
	}
}


//�������� ������� � ����� ������
bool Add_to_end(int data)
{
	if (list->Head != list->Tail)
	{
		Node *temp = new Node;
		temp = list->Tail;
		Node *unit = new Node;
		unit->Data = data;
		unit->Next = nullptr;
		unit->Prev = temp;
		list->Tail = unit;
		temp->Next = unit;
		return true;
	}
	else
	{
		return false;
	}
}

//�������� ������� � ������ ������
bool Add_to_top(int data)
{
	if (list->Head!=list->Tail)
	{
		Node* unit = new Node;
		unit->Next = list->Head;
		list->Head->Prev = unit;
		list->Head = unit;
		unit->Prev = nullptr;
		unit->Data = data;
		return true;
	}
	else
	{
		return false;
	}
}

// ����� ������
void Show()
{
	std::cout << "��� ������:\n";
	Node *temp = new Node;
	temp = list->Head;
	while (temp!=nullptr)
	{
		std::cout << temp->Data << "  ";
		temp = temp->Next;
	}
	std::cout << "\n";
}

//���������� �� �����������
void Sort()
{
	bool work = true;
	while (work = true)
	{
		int count = 0;
		Node *temp = new Node;
		temp = list->Head;
		while (temp->Next!=nullptr)
		{
			if (temp->Data > temp->Next->Data)
			{
				std::swap(temp->Data, temp->Next->Data);
				count += 1;
			}
			temp = temp->Next;
		}
		if (count == 0)
		{
			break;
		}
	}
}

//���������� �� ��������
void SortReverse()
{
	bool work = true;
	while (work = true)
	{
		int count = 0;
		Node *temp = new Node;
		temp = list->Head;
		while (temp->Next != nullptr)
		{
			if (temp->Data < temp->Next->Data)
			{
				std::swap(temp->Data ,temp->Next->Data);
				count += 1;
			}
			temp = temp->Next;
		}
		if (count == 0)
		{
			break;
		}
	}
}

//�������� ����� ��������
bool Search(int element)
{
	Node *temp = new Node;
	temp = list->Head;
	while (temp != nullptr)
	{
		if (temp->Data == element)
		{
			return true;
		}
		temp = temp->Next;
	}
	return false;
}

// ������������� ������
void Init(int count)
{
	for (int i = 0; i < count; i++)
	{
		Node *unit = new Node;
		unit->Data = rand() % 201 - 100;
		unit->Next = nullptr;
		if (list->Head == nullptr)
		{
			list->Head = list->Tail = unit;
		}
		else
		{
			unit->Prev = list->Tail;
			list->Tail->Next = unit;
			list->Tail = unit;
		}
	}
}

//�������� �������� �� ��������
void Delete(int element)
{
	while (Search(element))
	{
		Node *temp = new Node;
		temp = list->Head;
		while (temp != nullptr)
		{
			if (list->Head == temp && list->Tail == temp && temp->Data == element)
			{
				list->Head = list->Tail = nullptr;
				temp->Next = temp->Prev = nullptr;
				delete temp;
				break;
			}
			else if (list->Head == temp && temp->Data == element)
			{
				list->Head = temp->Next;
				temp->Next->Prev = nullptr;
				delete temp;
				break;
			}
			else if (list->Tail == temp && temp->Data == element)
			{
				list->Tail = temp->Prev;
				temp->Prev->Next = nullptr;
				delete temp;
				break;
			}
			else if (temp->Data == element)
			{
				temp->Next->Prev = temp->Prev;
				temp->Prev->Next = temp->Next;
				delete temp;
				break;
			}
			temp = temp->Next;
		}
	}
}

//������� ����� ��������
bool InsertAfter(int data, int element)
{
	bool flag = false;
	Node* temp = new Node;
	temp = list->Head;
	while (temp!= nullptr)
	{
	if (temp->Data == element && temp!=list->Tail)
	{
		Node* unit = new Node;
		unit->Next = temp->Next;
		unit->Prev = temp;
		temp->Next = unit;
		temp->Next->Prev = unit;
		unit->Data = data;
		flag = true;
	}
	else if (temp->Data == element && temp == list->Tail)
	{
		Node* unit = new Node;
		list->Tail = unit;
		unit->Prev = temp;
		temp->Next = unit;
		unit->Next = nullptr;
		unit->Data = data;
		flag = true;
	}
	temp = temp->Next;
	}
	return flag;
}

//������� ����� ���������

bool InsertBefore(int data, int element)
{
	Node* unit = new Node;
	Node* temp = new Node;
	temp = list->Head;
	while (temp->Data!=element && temp->Next != nullptr)
	{
		temp = temp->Next;
	}
	if (temp->Data == element && temp!=list->Head)
	{
		unit->Next = temp;
		unit->Prev = temp->Prev;
		temp->Prev->Next = unit;
		temp->Prev = unit;
		unit->Data = data;
		return true;
	}
	else if (temp->Data == element && temp == list->Head)
	{
		list->Head = unit;
		unit->Data = data;
		unit->Prev = nullptr;
		unit->Next = temp;
		temp->Prev = unit;
		return true;
	}
	else
	{
		return false;
	}
}
