#pragma once

struct BinaryTreeNode
{
	int Data;
	BinaryTreeNode* Left = nullptr;
	BinaryTreeNode* Right = nullptr;
};struct BinaryTree
{
	BinaryTreeNode* Root = nullptr;
};void Create(int element);void Add (int element); void Remove(int element);bool Search(int element);void SearchMax();void SearchMin();void Menu();void Watch();void Clear();void Deep(BinaryTreeNode * temp);