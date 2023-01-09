#include "Dict.h"
#include "Output.h"

Dict* CreateDict()
{
	Dict* dictionary = new Dict;
	dictionary->Array = new Node[StartSize];
	cout << "Словарь создан\n";
	return dictionary;
}


void SearchInDict(Dict * dict, string key)
{
	Node* temp = new Node;
	temp = &dict->Array[HashFunc(key, dict->first_hash, StartSize)];
	while (temp != nullptr)
	{
		if (temp->key == key)
		{
			OutputNode(temp->key, temp->value);
			return;
		}
		temp = temp->Next;
	}
	OutputEmpty();
}

void DeleteInDict(Dict * dict, string key)
{
	Node* temp = new Node;
	temp = &dict->Array[HashFunc(key, dict->first_hash, StartSize)];
	Node* prev = new Node;
	prev = temp;
	if (temp->key == key)
	{
		OutputDelNode(temp->key, temp->value);
		if (temp->Next == nullptr)
		{
			temp = new Node;
			dict->Array[HashFunc(key, dict->first_hash, StartSize)] = *temp;
			return;
		}
		else
		{
			temp = temp->Next;
			dict->Array[HashFunc(key, dict->first_hash, StartSize)] = *temp;
			return;
		}
	}
	else
	{
		temp = temp->Next;
		while (temp != nullptr)
		{
			if (temp->key == key)
			{
				OutputDelNode(temp->key, temp->value);
				Node* temp2 = new Node;
				prev->Next = temp2;
				delete temp;
				return;

			}
			temp = temp->Next;
			prev = prev->Next;
		}
	}
	OutputEmpty();
}


void AddToDict(Dict* dict, string key, string value)
{
	Node* current = new Node;
	current = &dict->Array[HashFunc(key, dict->first_hash, StartSize)];
	if (current->key == "")
	{
		current->key = key;
		current->value = value;
		return;
	}
	else
	{
		if (current->key == key)
		{
			ErrorAdd();
			return;
		}
		while (current->Next != nullptr)
		{
			if (current->key == key)
			{
				ErrorAdd();
				return;
			}
			current = current->Next;
		}
		Node* newnode = new Node;
		current->Next = newnode;
		newnode->key = key;
		newnode->value = value;
	}
}


void FullDict(Dict * dict)
{
	cout << "\n\nВаш словарь:\n";
	Node* node = new Node;
	for (int i = 0; i < StartSize; i++)
	{
		node = &dict->Array[i];
		if (node->key == "")
		{
			continue;
		}
		else
		{
			while (node != nullptr && node->key!="")
			{
				OutputNode(node->key, node->value);
				node = node->Next;
			}
		}
	}
}