#pragma once
	struct Node
	{
		double Data = 0;
		Node* Next = nullptr;
		Node* Prev = nullptr;
	};

	struct Stack
	{
		Node* Head = nullptr;
		Node* Tail = nullptr;
	};
