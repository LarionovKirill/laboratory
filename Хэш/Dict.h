#pragma once
#include "HashFunc.h"
#include "Node.h"

	const int StartSize = 8;


	struct Dict
	{
		Node* Array;
		int first_hash = 1;
	};

	void AddToDict(Dict* dict, string key, string value);
	Dict* CreateDict();
	void SearchInDict(Dict * dict, string key);
	void DeleteInDict(Dict* dict, string key);
	void FullDict(Dict* dict);