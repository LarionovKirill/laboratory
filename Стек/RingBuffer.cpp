#include "RingBuffer.h"

Ring_Buffer* Ring = new Ring_Buffer;

void RingBuffer::Init()
{
	Ring->Buff = new int[Ring->Size];
	Ring->Head = Ring->Tail = Ring->Full = 0;
	cout << "Буфер создан\n";
}

void RingBuffer::Add(int element)
{

	if (Ring->Head == Ring->Tail && Ring->Full == 0)
	{
	Ring->Buff[Ring->Tail] = element;
	Ring->Full += 1;
	}
	else if (Ring->Full == Ring->Size)
	{
		Ring->Tail = (Ring->Tail + 1) % Ring->Size;
		Ring->Buff[Ring->Tail] = element;
		Ring->Head = (Ring->Head + 1) % Ring->Size;
	}
	else if (Ring->Head == Ring->Tail && Ring->Full == 1)
	{
		Ring->Tail = (Ring->Tail + 1) % Ring->Size;
		Ring->Buff[Ring->Tail] = element;
		Ring->Full += 1;
	}
	else 
	{
		Ring->Tail = (Ring->Tail + 1) % Ring->Size;
		Ring->Buff[Ring->Tail] = element;
		Ring->Full += 1;
	}
}

void RingBuffer::Get()
{
	if (Ring->Full==0)
	{
		cout << "Буфер пуст\n";
	}
	else if (Ring->Head == Ring->Tail && Ring->Full == 1)
	{
		cout << Ring->Buff[Ring->Head] << "\n";
		Ring->Buff[Ring->Head] = -842150451;
		Ring->Full -= 1;
	}
	else if (Ring->Full > 1)
	{
		cout << Ring->Buff[Ring->Head] << "\n";
		Ring->Buff[Ring->Head] = -842150451;
		Ring->Full -= 1;
		Ring->Head = (Ring->Head + 1) % Ring->Size;
	}
}

int RingBuffer::Full()
{
	return Ring->Full;
}

int RingBuffer::Empty()
{
	return Ring->Size - Ring->Full;
}

void RingBuffer::Watch()
{
	for (int i = 0; i < Ring->Size; i++)
	{
		cout << Ring->Buff[i] << "  ";
	}
	cout << "\nГолова = " << Ring->Head << "\nХвост = " << Ring->Tail<<endl;
	cout << "Заполнено  = " << Ring->Full << "\n";
}

