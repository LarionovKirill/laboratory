#include "Hash.h"
#include "HashFunc.h"

using namespace std;


Hash* CreateTab()
{
	Hash* tab = new Hash;
	tab->length_tab = 4;
	tab->Array = new NodeTab[tab->length_tab];
	return tab;
}

void SearchInTab(Hash * tab, string key)
{
	NodeTab* current = new NodeTab;
	current = &tab->Array[HashFunc(key, tab->first_hash, tab->length_tab)];
	while (current != nullptr)
	{
		if (current->key == key)
		{
			OutputNodeTab(current);
			return;
		}
		current = current->Next;
	}
	OutputEmptyTab();
}

void DeleteInTab(Hash * tab, string key)
{
	NodeTab* temp = new NodeTab;
	temp = &tab->Array[HashFunc(key, tab->first_hash, tab->length_tab)];
	NodeTab* prev = new NodeTab;
	prev = temp;
	if (temp->key == key)
	{
		OutputDelNodeTab(temp);
		if (temp->Next == nullptr)
		{
			temp = new NodeTab;
			tab->Array[HashFunc(key, tab->first_hash, tab->length_tab)] = *temp;
			return;
		}
		else
		{
			temp = temp->Next;
			tab->Array[HashFunc(key, tab->first_hash, tab->length_tab)] = *temp;
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
				OutputDelNodeTab(temp);
				NodeTab* temp2 = new NodeTab;
				prev->Next = temp2;
				delete temp;
				return;

			}
			temp = temp->Next;
			prev = prev->Next;
		}
	}
	OutputEmptyTab();
}


void AddSame(NodeTab *node, string value)
{
	node->value.push_back(value);
}




void AddToTab(Hash * tab, string key, string value)
{
	NodeTab * current = new NodeTab;
	current = &tab->Array[HashFunc(key, tab->first_hash, tab->length_tab)];
	if (current->key == "")
	{
		current->key = key;
		current->value.push_back(value);
		tab->Counter += 1;
		if ((double)tab->Counter / tab->length_tab >= 1)
		{
			tab = PereHash(tab);
		}
		return;
	}
	else if (current->key == key)
	{
		AddSame(current, value);
		return;
	}
	else
	{
		ColizSolve(current,key,value);
		tab->Counter += 1;
		if ((double)tab->Counter / tab->length_tab >= 1)
		{
			tab = PereHash(tab);
		}
	}
}




void ColizSolve(NodeTab * node, string key, string value)
{
	while (node->Next != nullptr)
	{
		node = node->Next;
	}
	NodeTab* NewNode = new NodeTab;
	NewNode->key = key;
	NewNode->value.push_back(value);
	node->Next = NewNode;

}



Hash* PereHash(Hash* tab)
{
	ChangeHashFunc(&tab->first_hash);
	tab->Counter = 0;
	Hash* TempTab = new Hash;
	TempTab->Array = new NodeTab[tab->length_tab];
	TempTab->length_tab = tab->length_tab;
	for (int i = 0; i < tab->length_tab; i++)
	{
		TempTab->Array[i] = tab->Array[i];
	}
	tab->length_tab *= 2;
	tab->Array = new NodeTab[tab->length_tab];
	NodeTab* TempNode = new  NodeTab;
	for (int i = 0; i < TempTab->length_tab; i++)
	{
		TempNode = &TempTab->Array[i];
		while (TempNode != nullptr)
		{
			if (TempNode->key != "")
			{
				for (int j = 0; j < size(TempNode->value); j++)
				{
					AddToTab(tab, TempNode->key, TempNode->value[j]);
				}
			}
			TempNode = TempNode->Next;
		}
	}
	delete TempTab;
	delete TempNode;
	return tab;
}

void ToFull(Hash * tab)
{
	srand(time(NULL));
	int steps = tab->length_tab - tab->Counter;
	for (int j = 0; j < steps; j++)
	{
		string key;
		string value;
		for (int i = 0; i < 4; i++)
		{
			key += (char)((rand() % 27) + 97);
			value+= (char)((rand() % 27) + 97);
		}
		AddToTab(tab, key, value);
	}
}

void FullTab(Hash * tab)
{
	cout << "\n\nВаша хеш - таблица:\n";
	NodeTab* node = new NodeTab;
	for (int i = 0; i < tab->length_tab; i++)
	{
		node = &tab->Array[i];
		if (node->key == "")
		{
			continue;
		}
		else
		{
			while (node != nullptr && node->key != "")
			{
				OutputNodeTab(node);
				node = node->Next;
			}
		}
	}
}