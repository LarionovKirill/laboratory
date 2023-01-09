#include "DecartTree.h"
#include <iostream>
using namespace std;

DecartTree * origin = new DecartTree;

void Decart::Create(int element, int priority)
{
	DecartTreeNode * node = new DecartTreeNode;
	node->Key = element;
	node->Priority = priority;
	origin->Root = node;
}



bool Decart::Search(int element)
{
	DecartTreeNode * temp = new DecartTreeNode;
	temp = origin->Root;
	while (temp != nullptr)
	{
		if (temp->Key > element)
		{
			temp = temp->Left;
		}
		else if (temp->Key < element)
		{
				temp = temp->Right;
		}
		else if (temp->Key == element)
		{
				return true;
		}
	}
	return false;
}




void Decart::Split(DecartTreeNode *node, int key, DecartTreeNode*&left, DecartTreeNode*&right)
{
	if (node == nullptr)
	{
		left = right = nullptr;
	}
	else if (node->Key <= key)
	{
		Split(node->Right, key, node->Right, right);
		left = node;
	}
	else
	{
		Split(node->Left, key, left, node->Left);
		right = node;
	}
}




DecartTreeNode* Decart::Merge(DecartTreeNode* left, DecartTreeNode* right)
{
	if (left == nullptr || right == nullptr)
	{
		if (left == nullptr)
		{
			return right;
		}
		else
		{
			return left;
		}
	}
	else if (left->Priority > right->Priority)
	{
		left->Right = Decart::Merge(left->Right, right);
		return left;
	}
	else
	{
		right->Left = Decart::Merge(left, right->Left);
		return right;
	}
}




void Decart::Addbad(int element, int priority)
{
	if (!Search(element))
	{
		if (origin->Root != nullptr)
		{
			DecartTreeNode * NewTree = new DecartTreeNode;
			NewTree->Key = element;
			NewTree->Priority = priority;
			DecartTreeNode * LeftTree = new DecartTreeNode;
			DecartTreeNode * RightTree = new DecartTreeNode;
			DecartTreeNode * RootTree = new DecartTreeNode;
			RootTree = origin->Root;
			Decart::Split(RootTree, element, LeftTree, RightTree);
			RootTree = Decart::Merge(LeftTree, NewTree);
			RootTree = Decart::Merge(RootTree, RightTree);
			if (RootTree != origin->Root)
			{
				origin->Root = RootTree;
			}
		}
		else
		{
			Decart::Create(element, priority);
		}
	}
	else
	{
		cout << "Данный ключ уже в дереве\n";
	}
}




void Look(DecartTreeNode *node)
{
	if (node == nullptr)
	{
		return;
	}
	else
	{
		Look(node->Left);
		Look(node->Right);
		cout << node->Key << " = Ключ\n";
		cout << node->Priority << " = Приоритет\n";
		cout << "\n";
	}
}




void Decart::Watch()
{
	Look(origin->Root);
}




void Decart::AddGood(int element, int priority)
{
	if (!Search(element))
	{
		if (origin->Root != nullptr)
		{
			DecartTreeNode * unit = new DecartTreeNode;
			unit->Key = element;
			unit->Priority = priority;
			DecartTreeNode * temp = new DecartTreeNode;
			temp = origin->Root;
			while (temp != nullptr && temp->Priority > unit->Priority)
			{
				if (temp->Key < element)
				{
					temp = temp->Right;
				}
				else
				{
					temp = temp->Left;
				}
			}
			if (temp == nullptr)
			{
				temp = origin->Root;
				while (temp != nullptr)
				{
					if (temp->Key < element)
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
			else
			{
				DecartTreeNode * LeftTree = new DecartTreeNode;
				DecartTreeNode * RightTree = new DecartTreeNode;
				DecartTreeNode * Prev = new DecartTreeNode;
				Decart::Split(temp, element, LeftTree, RightTree);
				unit->Left = LeftTree;
				unit->Right = RightTree;
				Prev = origin->Root;
				while (Prev != nullptr)
				{
					if (Prev->Left == temp || Prev->Right == temp)
					{
						if (Prev->Left == temp)
						{
							Prev->Left = unit;
						}
						else
						{
							Prev->Right = unit;
						}
						break;
					}
					else
					{
						if (Prev->Key < temp->Key)
						{
							Prev = Prev->Right;
						}
						else
						{
							Prev = Prev->Left;
						}
					}
				}
			}
		}
		else
		{
			Decart::Create(element, priority);
		}
	}
	else
	{
		cout << "Данный ключ уже в дереве\n";
	}
}



void Decart::DeleteGood(int element)
{
	if (Decart::Search(element))
	{
		DecartTreeNode * temp = new DecartTreeNode;
		temp = origin->Root;
		while (temp->Key != element)
		{
			if (temp->Key < element)
			{
				temp = temp->Right;
			}
			else
			{
				temp = temp->Left;
			}
		}
		if (temp == origin->Root)
		{
			origin->Root = Decart::Merge(temp->Left, temp->Right);
			delete temp;
		}
		else
		{
			temp = origin->Root;
			while (temp->Left->Key != element && temp->Right->Key != element)
			{
				if (temp->Key < element)
				{
					temp = temp->Right;
				}
				else
				{
					temp = temp->Left;
				}
			}
			if (temp->Left->Key == element)
			{
				temp->Left = Decart::Merge(temp->Left->Left, temp->Left->Right);
			}
			else
			{
				temp->Right = Decart::Merge(temp->Right->Left, temp->Right->Right);
			}
		}
	}
	else
	{
		cout << "Невозможно произвести удаление\n";
	}
}



void Decart::DeleteBad(int element)
{
	if (Decart::Search(element))
	{
		DecartTreeNode* Left = new DecartTreeNode;
		DecartTreeNode* Right = new DecartTreeNode;
		DecartTreeNode * nil = new DecartTreeNode;
		Decart::Split(origin->Root, element, Left, Right);
		Decart::Split(Left, element-1, Left, nil);
		origin->Root = Decart::Merge(Left, Right);
		delete nil;
	}
	else
	{
		cout << "Невозможно произвести удаление\n";
	}
}



void DeleteAll(DecartTreeNode *temp)
{
	if (temp == nullptr)
	{
		return;
	}
	else
	{
		DeleteAll(temp->Left);
		DeleteAll(temp->Right);
		delete temp;
	}
}



void Decart::DeleteTree()
{
	DeleteAll(origin->Root);
}



void Decart::Menu()
{
	cout << "Нажмите 1 для создания декартово дерева\n";
	cout << "Нажмите 2 для поиска элемента в дереве\n";
	cout << "Нажмите 3 для добавления элемента в дерево неоптимизированным способом\n";
	cout << "Нажмите 4 для добавления элемента в дерево оптимизированным способом\n";
	cout << "Нажмите 5 для удаления элемента из дерева неоптимизированным способом\n";
	cout << "Нажмите 6 для удаления элемента из дерева оптимизированным способом\n";
	cout << "Нажмите 7 для удаления всего дерева\n";
	cout << "Нажмите 8 для вывода дерева\n";
	cout << "Нажмите 9 для окончания работы\n";
}
