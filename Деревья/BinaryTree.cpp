#include "BinaryTree.h"
#include <iostream>
using namespace std;

BinaryTree *origin = new BinaryTree;

void Create(int element)
{
	BinaryTreeNode * unit = new BinaryTreeNode;
	unit->Data = element;
	origin->Root = unit;
}

bool Search(int element)
{
	BinaryTreeNode * temp = new BinaryTreeNode;
	temp = origin->Root;
	while (temp != nullptr)
	{
		if (temp->Data == element)
		{
			return true;
		}
		else
		{
			if (temp->Data < element)
			{
				temp = temp->Right;
			}
			else
			{
				temp = temp->Left;
			}
		}
	}
	return false;
}

void Add(int element)
{
	if (origin->Root == nullptr)
	{
		Create(element);
	}
	else
	{
		BinaryTreeNode * unit = new BinaryTreeNode;
		unit->Data = element;
		BinaryTreeNode * temp = new BinaryTreeNode;
		temp = origin->Root;
		while (temp != nullptr)
		{
			if (temp->Data < element)
			{
				if (temp->Right == nullptr)
				{
					temp->Right = unit;
					break;
				}
				else
				{
					temp = temp->Right;
				}
			}
			else
			{
				if (temp->Left == nullptr)
				{
					temp->Left = unit;
					break;
				}
				else
				{
					temp = temp->Left;
				}
			}
		}
	}
}

void Remove(int element)
{
	if (Search(element))
	{
		BinaryTreeNode * DelElement = new BinaryTreeNode;
		BinaryTreeNode * root = new BinaryTreeNode;
		root = origin->Root;
		while (root->Data != element)
		{
			if (root->Data > element)
			{
				root = root->Left;
			}
			else
			{
				root = root->Right;
			}
		}
		DelElement = root;
		//�������� �����
		if (DelElement == origin->Root)
		{
			if (DelElement->Left == DelElement->Right && DelElement->Left == nullptr)
			{
				origin->Root = nullptr;
				delete DelElement;
				return;
			}
			else if (DelElement->Left != nullptr && DelElement->Right == nullptr)
			{
				DelElement = DelElement->Left;
				origin->Root = DelElement;
				return;
			}
			else
			{
				BinaryTreeNode * NewRoot = new BinaryTreeNode;
				NewRoot = DelElement->Right;
				if (NewRoot->Left == nullptr)
				{
					NewRoot->Left = DelElement->Left;
					DelElement = NewRoot;
					origin->Root = DelElement;
					return;
				}
				else
				{
					BinaryTreeNode * Prev = new BinaryTreeNode;
					Prev = NewRoot;
					NewRoot = NewRoot->Left;
					while (NewRoot->Left != nullptr)
					{
						Prev = Prev->Left;
						NewRoot = NewRoot->Left;
					}
					DelElement->Data = NewRoot->Data;
					Prev->Left = nullptr;
					return;
				}
			}
		}
		//������� ���� 
		else if (DelElement->Left == DelElement->Right && DelElement->Left == nullptr)
		{
			BinaryTreeNode * Prev = new BinaryTreeNode;
			Prev = origin->Root;
			while (Prev->Left != DelElement && Prev->Right != DelElement)
			{
				if (Prev->Data < element)
				{
					Prev = Prev->Right;
				}
				else
				{
					Prev = Prev->Left;
				}
			}
			if (Prev->Left->Data == DelElement->Data)
			{
				Prev->Left = nullptr;
				return;
			}
			else
			{
				Prev->Right = nullptr;
				return;
			}
		}
		// ������� ����� ������ ����� �������� ����
		else if (DelElement->Left != nullptr && DelElement->Right == nullptr)
		{
			BinaryTreeNode * Prev = new BinaryTreeNode;
			Prev = origin->Root;
			while (Prev->Left != DelElement && Prev->Right != DelElement)
			{
				if (Prev->Data < element)
				{
					Prev = Prev->Right;
				}
				else
				{
					Prev = Prev->Left;
				}
			}
			Prev->Left = DelElement->Left;
			delete DelElement;
			return;
		}
		// ������� ����� ������ �������� ����
		else if (DelElement->Right != nullptr)
		{
			BinaryTreeNode * NewNode = new BinaryTreeNode;
			NewNode = DelElement->Right;
			if (NewNode->Left == nullptr)
			{
				BinaryTreeNode * Prev = new BinaryTreeNode;
				Prev = origin->Root;
				while (Prev->Left != DelElement && Prev->Right != DelElement)
				{
					if (Prev->Data < element)
					{
						Prev = Prev->Right;
					}
					else
					{
						Prev = Prev->Left;
					}
				}
				Prev->Right = DelElement->Right;
				DelElement->Right->Left = DelElement->Left;
				delete DelElement;
				return;
			}
			else
			{
				BinaryTreeNode * Prev = new BinaryTreeNode;
				Prev = DelElement->Right;
				NewNode = NewNode->Left;
				while (NewNode->Left != nullptr)
				{
					Prev = Prev->Left;
					NewNode = NewNode->Left;
				}
				DelElement->Data = NewNode->Data;
				Prev->Left = nullptr;
				delete Prev->Left;
				delete NewNode;
				return;
			}
		}
	}
	else
	{
		cout << "���������� ������� ������ �������\n";
		return;
	}
}


void SearchMax()
{
	BinaryTreeNode * temp = new BinaryTreeNode;
	temp = origin->Root;
	while (temp ->Right != nullptr)
	{
		temp = temp->Right;
	}
	cout << "������������ ������� = "<<temp->Data<<"\n";
}

void SearchMin()
{
	BinaryTreeNode * temp = new BinaryTreeNode;
	temp = origin->Root;
	while (temp->Left != nullptr)
	{
		temp = temp->Left;
	}
	cout << "����������� ������� = " << temp->Data << "\n";
}

void Menu()
{
	cout << "������� 1 ��� �������� ��������� ������\n";
	cout << "������� 2 ��� ���������� �������� � ������\n";
	cout << "������� 3 ��� �������� �������� �� ������\n";
	cout << "������� 4 ��� ������ �������� � ������\n";
	cout << "������� 5 ��� ������ ��������� ������\n";
	cout << "������� 6 ��� ������ �������� ������\n";
	cout << "������� 7 ��� ������ ������\n";
	cout << "������� 8 ��� ��������� ������\n";
}

void Watch()
{
	BinaryTreeNode * temp = new BinaryTreeNode;
	temp = origin->Root;
	cout << "������:\n";
	Deep(temp);
}


void Clear()
{
	while (cin.get() != '\n')
	{
		cin.clear();
	}
	cin.clear();
}

void Deep(BinaryTreeNode * temp)
{
	if (temp == nullptr)
	{
		return;
	}
	Deep(temp->Left);
	Deep(temp->Right);
	cout << temp->Data<<"\n";
}