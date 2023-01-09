#include <windows.h>
#include "StackFromList.h"
#include "RingBuffer.h"
#include "QueueFromRing.h"
#include "QueueFromStack.h"
#include "Menu.h"

namespace QueueFromStack
{
	Stack *steckpush = new Stack;
	Stack *steckpop = new Stack;
}



int main()
{
	SetConsoleOutputCP(1251);
	bool work = true;
	int a = 0;
	while (work == true)
	{
		system("cls");
		MainMenu();
		cin >> a;
		switch (a)
		{
		case 0:
		{
			return 0;
		}
		case 1:
		{
			int step = 0;
			bool stack = true;
			while (stack)
			{
				system("cls");
				MenuStack();
				cin >> step;
				switch (step)
				{
				case 1:
				{
					double element;
					cout << "Введите первый элемент стека\n";
					cin >> element;
					stack::Create(element);
					break;
				}
				case 2:
				{
					double element;
					cout << "Введите элемент стека\n";
					cin >> element;
					stack::Push(element);
					break;
				}
				case 3:
				{
					if (stack::Pop() == false)
					{
						cout << "Стек пуст или не создан\n";
					}
					system("pause");
					break;
				}
				case 4:
				{
					stack::ClearStack();
					cout << "Стек очищен\n";
					system("pause");
					break;
				}
				case 5:
				{
					cout << "Спасибо за работу\n\n";
					stack = false;
					break;
				}
				default:
				{
					cout << "Такой функции нет.\nВот меню\n";
					MenuStack();
					system("pause");
					break;
				}
				}
			}
			stack::Clear();
			break;
		}
		case 2:
		{
			int step = 0;
			bool RingBuffer = true;
			while (RingBuffer)
			{
				system("cls");
				MenuBuffer();
				cin >> step;
				switch (step)
				{
				case 1:
				{
					RingBuffer::Init();
					break;
				}
				case 2:
				{
					int element;
					cout << "Введите элемент буфера\n";
					cin >> element;
					RingBuffer::Add(element);
					break;
				}
				case 3:
				{
					RingBuffer::Get();
					break;
				}
				case 4:
				{
					cout << "Занятых ячеек = " << RingBuffer::Full() << "\n";
					system("pause");
					break;
				}
				case 5:
				{
					cout << "Свободных ячеек = " << RingBuffer::Empty() << "\n";
					system("pause");
					break;
				}
				case 6:
				{
					RingBuffer::Watch();
					system("pause");
					break;
				}
				case 7:
				{
					cout << "Спасибо за работу\n\n";
					RingBuffer = false;
					break;
				}
				default:
				{
					cout << "Такой функции нет.\nВот меню\n";
					MenuBuffer();
					system("pause");
					break;
				}
				}
				stack::Clear();
			}
			break;
		}
		case 3:
		{
			int step = 0;
			bool QueueFromRing = true;
			while (QueueFromRing)
			{
				system("cls");
				MenuQueueBuffer();
				cin >> step;
				switch (step)
				{
				case 1:
				{
					QueueFromRing::Init();
					break;
				}
				case 2:
				{
					int element;
					cout << "Введите элемент очереди\n";
					cin >> element;
					QueueFromRing::Add(element);
					//QueueFromRing::Watch();
					break;
				}
				case 3:
				{
					QueueFromRing::Get();
					system("pause");
					//QueueFromRing::Watch();
					break;
				}
				case 4:
				{
					QueueFromRing::Remove();
					break;
				}
				case 5:
				{
					cout << "Спасибо за работу\n\n";
					QueueFromRing = false;
				}
				default:
				{
					cout << "Такой функции нет.\nВот меню\n";
					MenuQueueBuffer();
					system("pause");
					break;
				}
				}
				stack::Clear();
			}
			break;
		}
		case 4:
		{
			int step = 0;
			bool QueueFromStack = true;
			while (QueueFromStack)
			{
				system("cls");
				MenuQueueStack();
				cin >> step;
				switch (step)
				{
				case 1:
				{
					QueueFromStack::Init(QueueFromStack::steckpush);
					QueueFromStack::Init(QueueFromStack::steckpop);
					cout << "Очередь создана\n";
					break;
				}
				case 2:
				{
					double element;
					cout << "Введите элемент очереди\n";
					cin >> element;
					QueueFromStack::Push(QueueFromStack::steckpush, element);
					break;
				}
				case 3:
				{
					QueueFromStack::Pop(QueueFromStack::steckpush, QueueFromStack::steckpop);
					break;
				}
				case 4:
				{
					QueueFromStack::Remove(QueueFromStack::steckpush);
					QueueFromStack::Remove(QueueFromStack::steckpush);
					break;
				}
				case 5:
				{
					cout << "Спасибо за работу\n\n";
					QueueFromStack = false;
				}
				default:
				{
					cout << "Такой функции нет.\nВот меню\n";
					MenuQueueStack();
					system("pause");
					break;
				}
				}
				stack::Clear();
			}
			break;
		}
		}
	}
}
