#pragma once
#include <iostream>
using namespace std;

namespace QueueFromRing
{
	void Init();
	void Add(int element);
	void Get();
	void Remove();
	void Resize();
	void Watch();

	struct Ring_Buffer
	{
		int *Buff;
		int Tail;
		int Head;
		int Full = -1;
		unsigned int Size = 4;
	};
}
