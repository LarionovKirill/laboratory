#include "Output.h"
#include "Dict.h"
#include <iostream>
using namespace std;

void OutputEmpty()
{
	cout << "����� ������ ��� � �������\n";
}

void OutputEmptyTab()
{
	cout << "����� ������ ��� � �������\n";
}

void ErrorAdd()
{
	cout << "������ � ����� ������ ��� ���� � �������\n";
}

void OutputNode(string key, string value)
{
	cout <<"���� = "<<key<<"\t�������� = " << value<<"\n";
}

void OutputNodeTab(NodeTab * node)
{
	cout << "���� = " << node->key<<"\t��������: ";
	for (int i = 0; i < size(node->value); i++)
	{
		cout << node->value[i]<<"\t";
	}
	cout << "\n";
}


void OutputDelNode(string key, string value)
{
	cout << "������� ������\n" << "���� = " << key << "\t�������� = " << value << "\n";
}

void OutputDelNodeTab(NodeTab * node)
{
	cout << "������� ������\n" << "���� = " << node->key << "\t�������� = ";
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
	cout << "��� ������ ������� 0\n";
	cout << "��� ������� ������� 1\n";
	cout << "��� ��� - ������� ������� 2\n";
}


