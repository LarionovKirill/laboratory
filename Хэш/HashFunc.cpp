#include "HashFunc.h"


int HashFunc(string key, int first_hash, int length_tab)
{
	int hash = 0;
	for (int i = 0; i < key.length(); i++)
	{
		hash = (hash + ((int)key[i])*(int)pow(first_hash, i)) % length_tab;

	}
	return abs(hash);
}

void ChangeHashFunc(int *first_hash)
{
	*first_hash *= 2+1;
}
