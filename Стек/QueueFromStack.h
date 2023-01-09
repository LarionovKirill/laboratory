#pragma once
#include "Stack.h"
#include <iostream>
using namespace std;
namespace QueueFromStack
{
	void Init(Stack *steck);
	void Push(Stack *steck, double element);
	void Pop(Stack *steck, Stack *steck2);
	void Remove(Stack *steck);
	//void Watch(Stack *steck, Stack *steck2);
}