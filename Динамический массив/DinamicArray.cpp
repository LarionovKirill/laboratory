#include <iostream>
#include "Array.h"
#include "functions.h"
#include <windows.h>

using namespace std;


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	bool working = true;
	int step;
	Array* DinamicArray = new Array;
	Menu();
	while (working != false)
	{
		cout << "\nВведите номер функции\n";
		cin >> step;
		if (step != 0)
		{
			switch (step)
			{
			case 1:
			{
				cout << "Ваш массив создан\n";
				DinamicArray = Create(4);
				break;
			}
			case 2:
			{
				if (DinamicArray->Capacity == 0 || DinamicArray->Length == 0)
				{
					cout << "Вы еще не создали массив, чтобы его просмотреть, для создания нажмите на 1\n";
					break;
				}
				else
				{
					Show(DinamicArray, DinamicArray->Length);
					break;
				}
			}
			case 3:
			{
				AddToEnd(DinamicArray);
				break;
			}
			case 4:
			{
				AddToTop(DinamicArray);
				break;
			}
			case 5:
			{
				if (DinamicArray->Capacity == 0 || DinamicArray->Length == 0)
				{
					cout << "Массив не создан или он пуст, создайте его или добавьте в него элемент\n";
					int*a = new int;
					cout << "Выберете 1 для создания массива\n";
					cout << "Выберете 2 для добавлениия 1 элемента\n";
					cin >> *a;
					switch (*a)
					{
					case 1:
					{
						cout << "Ваш массив создан\n";
						Create(4);
						break;
					}
					case 2:
					{
						AddToEnd(DinamicArray);
						break;
					}
					default:
					{
						cout << "Вы выбрали неправильную функцию\n";
						break;
					}
					}
					delete a;
					break;
				}
				else
				{
					cout << "Вы хотите отсортировать по возрастанию или по убыванию?\n";
					cout << "Если по возрастанию, то нажмите 1, иначе нажмите 2\n";
					int *a = new int;
					cin >> *a;
					switch (*a) {
					case 1:
					{
						Sort(DinamicArray, DinamicArray->Length);
						Show(DinamicArray, DinamicArray->Length);
						break;
					}
					case 2:
					{
						SortReverse(DinamicArray, DinamicArray->Length);
						Show(DinamicArray, DinamicArray->Length);
						break;
					}
					default:
					{
						cout << "Ошибка\nПопробуйте еще раз\n";
						break;
					}
					}
					delete a;
					break;
				}
			}
			case 6:
			{
				if (DinamicArray->Capacity == 0 || DinamicArray->Length == 0)
				{
					cout << "Массив не создан или он пуст, создайте его или добавьте в него элемент\n";
					int*a = new int;
					cout << "Выберете 1 для создания массива\n";
					cout << "Выберете 2 для добавлениия 1 элемента\n";
					cin >> *a;
					switch (*a)
					{
					case 1:
					{
						cout << "Ваш массив создан\n";
						Create(4);
						break;
					}
					case 2:
					{
						AddToEnd(DinamicArray);
						break;
					}
					default:
					{
						cout << "Вы выбрали неправильную функцию\n";
						break;
					}
					}
					delete a;
					break;
				}
				else
				{
					int *index = new int;
					cout << "Введите индекс элемента\n";
					cin >> *index;
					DelByIndex(DinamicArray, *index);
					delete index;
					break;
				}
			}
			case 7:
			{
				if (DinamicArray->Capacity == 0 || DinamicArray->Length == 0)
				{
					cout << "Массив не создан или он пуст, создайте его или добавьте в него элемент\n";
					int*a = new int;
					cout << "Выберете 1 для создания массива\n";
					cout << "Выберете 2 для добавлениия 1 элемента\n";
					cin >> *a;
					switch (*a)
					{
					case 1:
					{
						cout << "Ваш массив создан\n";
						Create(4);
						break;
					}
					case 2:
					{
						AddToEnd(DinamicArray);
						break;
					}
					default:
					{
						cout << "Вы выбрали неправильную функцию\n";
						break;
					}
					}
					delete a;
					break;
				}
				else
				{
					int *index = new int;
					cout << "Введите искомое число\n";
					cin >> *index;
					LinearSearch(DinamicArray, *index);
					delete index;
					break;
				}
			}
			case 8:
			{
				if (DinamicArray->Capacity == 0 || DinamicArray->Length == 0)
				{
					cout << "Массив не создан или он пуст, создайте его или добавьте в него элемент\n";
					int*a = new int;
					cout << "Выберете 1 для создания массива\n";
					cout << "Выберете 2 для добавлениия 1 элемента\n";
					cin >> *a;
					switch (*a)
					{
					case 1:
					{
						cout << "Ваш массив создан\n";
						Create(4);
						break;
					}
					case 2:
					{
						AddToEnd(DinamicArray);
						break;
					}
					default:
					{
						cout << "Вы выбрали неправильную функцию\n";
						break;
					}
					}
					delete a;
					break;
				}
				else
				{
					int *index = new int;
					cout << "Введите искомое число\n";
					cin >> *index;
					BinSerach(DinamicArray, *index);
					delete index;
					break;
				}
			}
			case 9:
			{
				if (DinamicArray->Capacity == 0 || DinamicArray->Length == 0)
				{
					cout << "Массив не создан или он пуст, создайте его или добавьте в него элемент\n";
					int*a = new int;
					cout << "Выберете 1 для создания массива\n";
					cout << "Выберете 2 для добавлениия 1 элемента\n";
					cin >> *a;
					switch (*a)
					{
					case 1:
					{
						cout << "Ваш массив создан\n";
						Create(4);
						break;
					}
					case 2:
					{
						AddToEnd(DinamicArray);
						break;
					}
					default:
					{
						cout << "Вы выбрали неправильную функцию\n";
						break;
					}
					}
					delete a;
					break;
				}
				else
				{
					int *num = new int;
					int *point = new int;
					int *index = new int;
					cout << "Введите число, которое хотите вставить\n";
					cin >> *num;
					cout << "Для вставки перед элементом нажмите 1, иначе 2\n";
					cin >> *point;
					cout << "Введите индекс элемента, с которым нужно взаимодействовать\n";
					cin >> *index;
					if (*index <= 0 || *index > DinamicArray->Length)
					{
						cout << "Невозможно выполнить такое добавлние\n";
						break;
					}
					else
					{
						switch (*point) {
						case 1:
						{
							AddToPlace(DinamicArray, *num, *index - 1);
							break;
						}
						case 2:
						{
							AddToPlace(DinamicArray, *num, *index);
							break;
						}
						default:
						{
							cout << "Ошибка\nПопробуйте еще раз\n";
							break;
						}
						}
					}
					break;
					delete num;
					delete point;
					delete index;
				}
			}
			case 10:
			{
				working = false;
				cout << "Работа с программой окончена\n";
				break;
			}
			default:
			{
				cout << "Этой функции нет в нашем приложении.\nВот меню:\n";
				Menu();
				break;
			}
			}
		}
		else 
		{
			while (cin.get() != '\n')
			{
				cin.clear();
			}
			cout << "Возвомжно вы нажали не на ту кнопку.\nПопробуйте еще раз\n";
		}
	}
	return 0;
}