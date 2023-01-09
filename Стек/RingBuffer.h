#pragma once
#include <cmath>
#include <iostream>
using namespace std;

struct Ring_Buffer
{
	int *Buff;
	int Tail;
	int Head;
	int Full;
	unsigned int Size = 8;
};

namespace RingBuffer {

	void Init();
	void Add(int element);
	void Get();
	int Full();
	int Empty();
	void Watch();
}