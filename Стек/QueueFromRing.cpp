#include "QueueFromRing.h"
#include "RingBuffer.h"


QueueFromRing::Ring_Buffer* Ring = new QueueFromRing::Ring_Buffer;


void QueueFromRing::Init()
{
	Ring->Buff = new int[Ring->Size];
	Ring->Tail = Ring->Head = 0;
	Ring->Full = 0;
	cout << "ќчередь создана\n";
}

void QueueFromRing::Watch()
{
	cout << "\nfull = " << Ring->Full << endl;
	if (Ring->Full > -1)
	{
		for (int i = 0; i < Ring->Size; i++)
		{
			cout << Ring->Buff[i] << "  ";
		}
		cout << endl;
	}
}


void QueueFromRing::Resize()
{
	int *temp = new int[Ring->Size];
	for (int i = 0; i < Ring->Size; i++)
	{
		temp[i] = Ring->Buff[i];
	}
	Ring->Buff = new int[Ring->Size*2];
	for (int i = 0; i < Ring->Size; i++)
	{
		Ring->Buff[i] = temp[i];
	}
	Ring->Size *= 2;
	delete[]temp;
}


void QueueFromRing::Add(int element)
{
	if (Ring->Full==-1) 
	{
		cout << "ќчередь не создана\n";
	}
	else if (Ring->Head == Ring->Tail && Ring->Full == 0)
	{
		Ring->Buff[Ring->Tail] = element;
		Ring->Full +=1;
	}
	else if (Ring->Head == Ring->Tail && Ring->Full == 1)
	{
		Ring->Tail = Ring->Tail + 1;
		Ring->Buff[Ring->Tail] = element;
		Ring->Full += 1;
	}
	else if (Ring->Tail + 1 == Ring->Size)
	{
		QueueFromRing::Resize();
		Ring->Tail = Ring->Tail + 1;
		Ring->Buff[Ring->Tail] = element;
		Ring->Full += 1;
	}
	else
	{
		Ring->Tail = Ring->Tail + 1;
		Ring->Buff[Ring->Tail] = element;
		Ring->Full += 1;
	}
}

void QueueFromRing::Get()
{
	if(Ring->Full==-1)
	{
		cout << "ќчередь не создана\n";
	}
	else if (Ring->Full == 1)
	{
		cout<<"Ёлемент = "<< Ring->Buff[0]<<"\n";
		for (int i = 1; i <= Ring->Tail; i++)
		{
			Ring->Buff[i - 1] = Ring->Buff[i];
		}
		Ring->Buff[Ring->Tail]= -842150451;
		Ring->Tail -= 1;
		Ring->Full -=1;
	}
	else
	{
		cout << "Ёлемент = " << Ring->Buff[0] << "\n";
		for (int i = 1; i <= Ring->Tail; i++)
		{
			Ring->Buff[i - 1] = Ring->Buff[i];
		}
		Ring->Buff[Ring->Tail] = -842150451;
		Ring->Tail -= 1;
		Ring->Full -=1;
	}
}

void QueueFromRing::Remove()
{
	delete[] Ring->Buff;
	Ring->Head = Ring->Tail = 0;
	Ring->Full = -1;
}


