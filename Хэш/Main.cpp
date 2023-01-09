#include "Menu.h"
#include "Dict.h"
#include "Hash.h"

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	int a = 0;
	while (true)
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
			Dict* Dictanory = new Dict;
			Dictanory = CreateDict();
			MenuDict();
			bool dict = false;
			bool WorkDict = true;
			int step = 0;
			while (WorkDict)
			{
				cin >> step;
				system("cls");
				switch (step)
				{
				case 1:
				{
					string key, value, temp;
					getline(cin, temp);
					cout << "Введите ключ\n";
					getline(cin, key);
					cout << "Введите значение\n";
					getline(cin, value);
					AddToDict(Dictanory, key, value);
					FullDict(Dictanory);
					MenuDict();
					break;
				}
				case 2:
				{
					string key, temp;
					getline(cin, temp);
					cout << "Введите ключ\n";
					getline(cin, key);
					SearchInDict(Dictanory, key);
					MenuDict();
					break;
				}
				case 3:
				{
					string key, value, temp;
					getline(cin, temp);
					cout << "Введите ключ\n";
					getline(cin, key);
					DeleteInDict(Dictanory, key);
					FullDict(Dictanory);
					MenuDict();
					break;
				}
				case 4:
				{
					WorkDict = false;
					delete Dictanory;
					break;
				}
				default:
				{
					Clear();
					cout << "Такой функции нет.\n";
					MenuDict();
				}
				}
			}
			break;
		}
		case 2:
		{
			Hash* HashTab = new Hash;
			HashTab = CreateTab();
			MenuTab();
			bool tab = false;
			bool WorkTab = true;
			int step = 0;
			while (WorkTab)
			{
				cin >> step;
				system("cls");
				switch (step)
				{
				case 1:
				{
					string key, value, temp;
					getline(cin, temp);
					cout << "Введите ключ\n";
					getline(cin, key);
					cout << "Введите значение\n";
					getline(cin, value);
					AddToTab(HashTab, key, value);
					FullTab(HashTab);
					MenuTab();
					break;
				}
				case 2:
				{
					string key, value, temp;
					getline(cin, temp);
					cout << "Введите ключ\n";
					getline(cin, key);
					SearchInTab(HashTab, key);
					MenuTab();
					break;
				}
				case 3:
				{
					string key, value, temp;
					getline(cin, temp);
					cout << "Введите ключ\n";
					getline(cin, key);
					DeleteInTab(HashTab, key);
					FullTab(HashTab);
					MenuTab();
					break;
				}
				case 4:
				{
					ToFull(HashTab);
					FullTab(HashTab);
					MenuTab();
					break;
				}
				case 5:
				{
					WorkTab = false;
					delete HashTab;
					break;
				}
				default:
				{
					Clear();
					cout << "Такой функции нет.\n";
					MenuTab();
				}
				}
			}
		}
		default:
		{
			Clear();
			cout << "\n\nТакой функции нет.\n\n";
			MainMenu();
			system("pause");
		}
		}
	}
}