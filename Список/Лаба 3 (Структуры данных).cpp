#include <iostream>
#include <windows.h>
#include "List.h"
#include "Listitem.h"
#include <ctime>
using namespace std;

int main()
{
	srand(time(NULL));
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	bool work = true;
	int step = 0;
	Menu();
	while (work != false)
	{
		cin >> step;
		if (step != 0)
		{
			switch (step)
			{
			case 1:
			{
				Init(4);
				Show();
				break;
			}
			case 2:
			{
				int element;
				cout << "Введите элемент: ";
				cin >> element;
				if (Add_to_end(element))
				{
					Show();
				}
				else 
				{
					cout << "Вы не инициализировали массив\n";
				}
				break;
			}
			case 3:
			{
				int element;
				cout << "Введите элемент: ";
				cin >> element;
				if (Add_to_top(element))
				{
					Show();
				}
				else
				{
					cout << "Вы не инициализировали массив\n";
				}
				break;
			}
			case 4:
			{
				int choice;
				cout << "Введите 1 для сортировки по возрастанию или 2 по убыванию: ";
				cin >> choice;
				if (choice == 1)
				{
					Sort();
					Show();
				}
				else if (choice == 2)
				{
					SortReverse();
					Show();
				}
				else
				{
					cout << "Ошибка\n";
				}
				break;
			}
			case 5:
			{
				int element;
				cout << "Введите элемент: ";
				cin >> element;
				if (Search(element) == false)
				{
					cout << "Такого элемента нет в списке\n";
				}
				else
				{
					cout << "Такой элемент есть в списке\n";
				}
				break;
			}
			case 6:
			{
				int choice;
				cout << "Введите 1 для вставки перед элементом или 2 если после элемента: ";
				cin >> choice;
				if (choice == 1)
				{
					int element = 0;
					int data = 0;
					cout << "Введите число, которое хотите вставить: ";
					cin >> data;
					cout << "Введите элемент: ";
					cin >> element;
					if (InsertBefore(data, element) == true)
					{
						cout << "Элемент добавлен\n";
						Show();
					}
					else
					{
						cout << "Такого элемента нет в списке\n";
					}
				}
				else if (choice == 2)
				{
					int element;
					int data = 0;
					cout << "Введите число, которое хотите вставить: ";
					cin >> data;
					cout << "Введите элемент: ";
					cin >> element;
					if (InsertAfter(data, element) == true)
					{
						cout << "Элемент добавлен\n";
						Show();
					}
					else
					{
						cout << "Такого элемента нет в списке\n";
					}
				}
				else
				{
					cout << "Ошибка\n";
				}
				break;
			}
			case 7:
			{
				int element;
				cout << "Введите элемент, который хотите удалить: ";
				cin >> element;
				Delete(element);
				cout << "Элемент удален\n";
				Show();
				break;
			}
			case 8:
			{
				cout << "Спасибо за работу\n";
				return 0;
			}
			case 9:
			{
				Menu();
			}
			default:
			{
				cout << "Такой функции не предусмотрено\nВот меню\n";
				Menu();
			}
			}
		}
		else
		{
		cout << "Такой функции не предусмотрено\nВот меню\n";
		Menu();
		}
		Clear();
	}
}


