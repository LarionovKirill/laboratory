#include "BinaryTree2.h"
#include <iostream>
using namespace std;


RequrseTree::BinaryTreeNode * RequrseTree::Create(BinaryTreeNode * temp,int element)
{
	temp = new BinaryTreeNode;
	temp->Data = element;
	return temp;
}

bool RequrseTree::Search(BinaryTreeNode *temp, int element)
{
	if (temp == nullptr)
	{
		return false;
	}
	else if (temp->Data == element)
	{
		return true;
	}
	else if (temp->Data > element)
	{
		Search(temp->Left,element);
	}
	else
	{
		Search(temp->Right,element);
	}
}

void RequrseTree::Add(BinaryTreeNode *temp, int element)
{
	BinaryTreeNode * unit = new BinaryTreeNode;
	unit->Data = element;
	if (temp->Data > element)
	{
		if (temp->Left == nullptr)
		{
			temp->Left = unit;
			unit->Parent = temp;
			return;
		}
		else
		{
			Add(temp->Left, element);
		}
	}
	else if (temp->Data < element)
	{
		if (temp->Right == nullptr)
		{
			temp->Right = unit;
			unit->Parent = temp;
			return;
		}
		else
		{
			Add(temp->Right, element);
		}
	}
}


RequrseTree::BinaryTreeNode* RequrseTree::SearchMax(BinaryTreeNode * temp)
{
	if (temp->Right == nullptr)
	{
		return temp;
	}
	else
	{
		SearchMax(temp->Right);
	}
}

RequrseTree::BinaryTreeNode* RequrseTree::SearchMin(BinaryTreeNode * temp)
{
	if (temp->Left == nullptr)
	{
		return temp;
	}
	else
	{
		SearchMax(temp->Left);
	}
}

void RequrseTree::Watch(BinaryTreeNode * temp)
{
	if (temp == nullptr)
	{
		return;
	}
	Watch(temp->Left);
	Watch(temp->Right);
	cout << temp->Data << "\n";
}

RequrseTree::BinaryTreeNode* RequrseTree::Remove(BinaryTreeNode * temp, int element)
{
	if (Search(temp, element))
	{
		if (temp == nullptr)
		{
			return temp;
		}
		if (element > temp->Data)
		{
			Remove(temp->Right, element);
		}
		else if (element < temp->Data)
		{
			Remove(temp->Left, element);
		}
		else if (temp->Left!=nullptr && temp->Right!=nullptr)
		{
			temp->Data = SearchMin(temp->Right)->Data;
			temp->Right = Remove(temp->Right, temp->Data);
		}
		else
		{
			if (temp->Left != nullptr && temp->Right == nullptr)
			{
				if (temp->Parent->Left != nullptr && temp->Parent->Left->Data == temp->Data)
				{
					temp->Parent->Left = temp->Left;
					temp = nullptr;
				}
				else if (temp->Parent->Right != nullptr && temp->Parent->Right->Data == temp->Data)
				{
					temp->Parent->Right = temp->Left;
					temp = nullptr;
				}
			}
			else if (temp->Right != nullptr &&temp->Left == nullptr)
			{
				temp->Data = SearchMin(temp->Right)->Data;
				temp->Right = Remove(temp->Right, temp->Data);
			}
			else
			{
				if (temp->Parent->Left!= nullptr && temp->Parent->Left->Data == temp->Data)
				{
						temp->Parent->Left = nullptr;
						delete temp;
				}
				else if (temp->Parent->Right!=nullptr && temp->Parent->Right->Data == temp->Data)
				{

						temp->Parent->Right = nullptr;
						delete temp;
				}
			}
		}
	}
	else
	{
		return nullptr;
	}
}