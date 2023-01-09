#include "List.h"
#include "Listitem.h"
#include <iostream>
#include <ctime>
#include <iostream>
using namespace std;

List* list = new List;

void Menu()
{
	cout << "Нажмите 1 для инициализации двусвязного списка\n";
	cout << "Нажмите 2 для добавления элемента в конец списка\n";
	cout << "Нажмите 3 для добавления элемента в начало списка\n";
	cout << "Нажмите 4 для сортировки списка\n";
	cout << "Нажмите 5 для поиска элемента в списке\n";
	cout << "Нажмите 6 для вставки элемента в список по значению\n";
	cout << "Нажмите 7 для удаления элемента в списке по значению\n";
	cout << "Нажмите 8 для окончания работы\n";
	cout << "Нажмите 9 для вызова меню\n";

}

void Clear()
{
	while (cin.get() != '\n')
	{
		cin.clear();
	}
}


//Добавить элемент в конец списка
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

//Добавить элемент в начало списка
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

// Показ списка
void Show()
{
	std::cout << "Ваш список:\n";
	Node *temp = new Node;
	temp = list->Head;
	while (temp!=nullptr)
	{
		std::cout << temp->Data << "  ";
		temp = temp->Next;
	}
	std::cout << "\n";
}

//Сортировка по возрастанию
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

//Сортировка по убыванию
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

//Линейный поиск элемента
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

// Инизиализация списка
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

//Удаление элемента по значению
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

//Вставка после элемента
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

//Вставка перед элементом

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
