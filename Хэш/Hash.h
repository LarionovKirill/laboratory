#pragma once
#include "HashFunc.h"
#include "Node.h"
#include "Output.h"
#include <ctime>

struct Hash
{
	NodeTab * Array;
	int Counter = 0;
	int length_tab = 0;
	int first_hash = 1;
};


Hash* CreateTab();
void SearchInTab(Hash * tab, string key);
void DeleteInTab(Hash * tab, string key);
void ColizSolve(NodeTab * node, string key, string value);
void AddToTab(Hash * tab, string key, string value);
void AddSame(NodeTab *node, string value);
Hash* PereHash(Hash* tab);
void ToFull(Hash* tab);
void FullTab(Hash* tab);