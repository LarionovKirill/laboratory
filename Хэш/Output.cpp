#include "Output.h"
#include "Dict.h"
#include <iostream>
using namespace std;

void OutputEmpty()
{
	cout << "Такой записи нет в словаре\n";
}

void OutputEmptyTab()
{
	cout << "Такой записи нет в словаре\n";
}

void ErrorAdd()
{
	cout << "Запись с таким ключом уже есть в словаре\n";
}

void OutputNode(string key, string value)
{
	cout <<"Ключ = "<<key<<"\tЗначение = " << value<<"\n";
}

void OutputNodeTab(NodeTab * node)
{
	cout << "Ключ = " << node->key<<"\tЗначения: ";
	for (int i = 0; i < size(node->value); i++)
	{
		cout << node->value[i]<<"\t";
	}
	cout << "\n";
}


void OutputDelNode(string key, string value)
{
	cout << "Удалена запись\n" << "Ключ = " << key << "\tЗначение = " << value << "\n";
}

void OutputDelNodeTab(NodeTab * node)
{
	cout << "Удалена запись\n" << "Ключ = " << node->key << "\tЗначения = ";
	for (int i = 0; i < size(node->value); i++)
	{
		cout << node->value[i] << "\t";
	}
	cout << "\n";
}



void Clear()
{
	while (cin.get() != '\n')
	{
		cin.clear();
	}
}

void MainMenu()
{
	cout << "Для выхода нажмите 0\n";
	cout << "Для словаря нажмите 1\n";
	cout << "Для хеш - таблицы нажмите 2\n";
}


