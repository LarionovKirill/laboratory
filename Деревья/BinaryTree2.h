#pragma once

namespace RequrseTree
{
	struct BinaryTreeNode
	{
		int Data;
		BinaryTreeNode* Left = nullptr;
		BinaryTreeNode* Right = nullptr;
		BinaryTreeNode* Parent = nullptr;
	};	struct BinaryTree
	{
		BinaryTreeNode* Root = nullptr;
	};	BinaryTreeNode* Create(BinaryTreeNode * temp, int element);	void Add(BinaryTreeNode *temp, int element);	BinaryTreeNode * Remove(BinaryTreeNode *temp, int element);	bool Search(BinaryTreeNode *temp, int element);	BinaryTreeNode* SearchMax(BinaryTreeNode * temp);	BinaryTreeNode* SearchMin(BinaryTreeNode * temp);	void Watch(BinaryTreeNode * temp);}