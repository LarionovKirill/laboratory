#include <iostream>
#include "BinaryTree.h"
#include "DecartTree.h"
#include <windows.h>

using namespace std;

int main()
{
	{
		SetConsoleOutputCP(1251);
		SetConsoleCP(1251);
		bool work = true;
		while (work)
		{
			int tree;
			system("cls");
			cout << "Если хотите выйти нажмите 0\n";
			cout << "Если хотите воспользоваться бинарным деревом, то нажмите 1\n";
			cout << "Если хотите воспользоваться декартовым деревом, то нажмите 2\n";
			cin >> tree;
			switch (tree)
			{
			case 0:
			{
				return 0;
			}
			case 1:
			{
				int step;
				bool tree = false;
				bool work = true;
				while (work == true)
				{
					system("cls");
					Menu();
					cin >> step;
					if (tree == false && step != 1)
					{
						cout << "Дерево еще не создано\nЧтобы его создать нажмите 1\n";
						Clear();
					}
					else
					{
						switch (step)
						{
						case 1:
						{
							int element;
							cout << "Введите корень дерева\n";
							cin >> element;
							Create(element);
							tree = true;
							break;
						}
						case 2:
						{
							int element;
							cout << "Введите элемент для добавления\n";
							cin >> element;
							Add(element);
							break;
						}
						case 3:
						{
							int element;
							cout << "Введите элемент для удаления\n";
							cin >> element;
							Remove(element);
							break;
						}
						case 4:
						{
							int element;
							cout << "Введите элемент для поиска\n";
							cin >> element;
							if (Search(element))
							{
								cout << "Такой элемент имеется\n";
								system("pause");
							}
							else
							{
								cout << "Такого элемента нет\n";
								system("pause");
							}
							break;
						}
						case 5:
						{
							SearchMax();
							system("pause");
							break;
						}
						case 6:
						{
							SearchMin();
							system("pause");
							break;
						}
						case 7:
						{
							Watch();
							system("pause");
							break;
						}
						case 8:
						{
							work = false;
							break;
						}
						default:
						{
							Clear();
							cout << "Такой функции нет.\n";
							Menu();
						}
						}
					}
				}
				break;
			}
			case 2:
			{
				int step = 0;
				bool work = true;
				bool tree = false;
				while (work == true)
				{
					system("cls");
					Decart::Menu();
					cin >> step;
					if (!tree && step != 1)
					{

						cout << "Дерево ещё не создано, для его создания нажмите 1\n";
						Clear();
					}
					else
					{
						switch (step)
						{
						case 1:
						{
							tree = true;
							int element, priority;
							cout << "Введите элемент\n";
							cin >> element;
							cout << "Введите его приоритет в дереве\n";
							cin >> priority;
							Decart::Create(element, priority);
							cout << "Дерево создано\n";
							system("pause");
							break;
						}
						case 2:
						{
							int element;
							cout << "Введите элемент\n";
							cin >> element;
							if (Decart::Search(element))
							{
								cout << "Элемент есть в дереве\n";
								system("pause");
							}
							else
							{
								cout << "Элемента нет в дереве\n";
								system("pause");
							}
							break;
						}
						case 3:
						{
							int element, priority;
							cout << "Введите элемент\n";
							cin >> element;
							cout << "Введите его приоритет в дереве\n";
							cin >> priority;
							Decart::Addbad(element, priority);
							cout << "Элемент добавлен\n";
							system("pause");
							break;
						}
						case 4:
						{
							int element, priority;
							cout << "Введите элемент\n";
							cin >> element;
							cout << "Введите его приоритет в дереве\n";
							cin >> priority;
							Decart::AddGood(element, priority);
							cout << "Элемент добавлен\n";
							system("pause");
							break;
						}
						case 5:
						{
							int element;
							cout << "Введите элемент\n";
							cin >> element;
							Decart::DeleteBad(element);
							break;
						}
						case 6:
						{
							int element;
							cout << "Введите элемент\n";
							cin >> element;
							Decart::DeleteGood(element);
							break;
						}
						case 7:
						{
							Decart::DeleteTree();
							tree = false;
							cout << "Дерево удалено\n";
							system("pause");
							break;
						}
						case 8:
						{
							Decart::Watch();
							system("pause");
							break;
						}
						case 9:
						{
							work = false;
							break;
						}
						default:
						{
							Clear();
							cout << "Такой функции нет.\n";
							Decart::Menu();
						}
						}
					}
				}
				break;
			}
			}
		}
	}
}
