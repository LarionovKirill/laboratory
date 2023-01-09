#pragma once

struct DecartTreeNode
{
	int Key;
	int Priority = -1000;
	DecartTreeNode* Left = nullptr;
	DecartTreeNode* Right = nullptr;
	DecartTreeNode* Parent = nullptr;
};

struct DecartTree
{
	DecartTreeNode* Root;
};

namespace Decart
{
	void Create(int element, int priority);
	bool Search(int element);
	void Split(DecartTreeNode *node, int key, DecartTreeNode*&left, DecartTreeNode*&right);
	DecartTreeNode* Merge(DecartTreeNode* left, DecartTreeNode* right);
	void Addbad(int element, int priority);
	void Watch();
	void Menu();
	void AddGood(int element, int priority);
	void DeleteGood(int element);
	void DeleteBad(int element);
	void DeleteTree();
}