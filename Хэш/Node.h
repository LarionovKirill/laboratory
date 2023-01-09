#pragma once
#include <vector>
#include <string>

using namespace std;


struct Node
{
	string key = "";
	string  value = "";
	Node* Next = nullptr;
};

struct NodeTab
{
	string key = "";
	vector <string>  value;
	NodeTab* Next = nullptr;
};