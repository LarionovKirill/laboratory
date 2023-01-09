#include "Functions.h"
#include <ctime>
#include <iostream>
#include "Array.h"

using namespace std;

Array* arr = new Array();

void Menu()
{
	cout << "Меню приложения:\n";
	cout << "Нажмите 1 для создания массива(если массив уже создан, то он будет перезаписан)\n";
	cout << "Нажмите 2 для вывода массива\n";
	cout << "Нажмите 3 для добавления элемента в конец массива\n";
	cout << "Нажмите 4 для добавления элемента в начало массива\n";
	cout << "Нажмите 5 для сортировки массива\n";
	cout << "Нажмите 6 для удаление элемента из массива\n";
	cout << "Нажмите 7 для линейного поиска\n";
	cout << "Нажмите 8 для бинарного поиска\n";
	cout << "Нажмите 9 для добавления элемента в массив по индексу\n";
	cout << "Нажмите 10 для окончания работы с программой\n";
}

Array* Create(int len)		
{
	Array* DinamicArray = new Array;
	srand(time(NULL));
	DinamicArray->Length = 0;
	DinamicArray->Capacity = len * 2;
	DinamicArray->InternalArray = new int[DinamicArray->Capacity];
	for (int i = 0; i < len; i++)
	{
		DinamicArray->InternalArray[i] = rand() % 101 - 50;
		DinamicArray->Length++;
	}
	return DinamicArray;
}

void CreateEmptyArray(Array* arr, int len)
{
	arr->Length = 0;
	arr->Capacity = len * 2;
	arr->InternalArray = new int[arr->Capacity];
}

void Up(Array* arr, int length)
{
	int *temp = new int[length];
	for (int i = 0; i < length; i++)
	{
		temp[i] = arr->InternalArray[i];
	}
	arr->Capacity = length * 2;
	arr->InternalArray = new int[arr->Capacity];
	for (int i = 0; i < length; i++)
	{
		arr->InternalArray[i] = temp[i];
	}
	delete[] temp;

}


void Show(Array* arr, int length)
{
	if (length > 0)
	{
		cout << "Ваш массив\n";
		for (int i = 0; i < length; i++)
		{
			cout << arr->InternalArray[i] << " ";
		}
		cout << "\n";
	}
	else
	{
		cout << "На данный момент массив пустой\n";
	}
}

void Sort(Array* arr, int length)
{
	for (int i = 0; i < length - 1; i++)
	{
		for (int j = 0; j < length - i - 1; j++)
		{
			if (arr->InternalArray[j] > arr->InternalArray[j + 1])
			{
				swap(arr->InternalArray[j], arr->InternalArray[j + 1]);
			}
		}
	}
}

void AddToPlace(Array* arr, int number, int place)
{
	if (place < arr->Length+1)
	{
		if (arr->Capacity > arr->Length)
		{
			int *temp = new int[arr->Capacity];
			int step = 0;
			for (int i = 0; i < arr->Length + 1; i++)
			{
				if (i == place)
				{
					temp[step] = number;
					step += 1;
					temp[step] = arr->InternalArray[i];
					step += 1;
				}
				else
				{
					temp[step] = arr->InternalArray[i];
					step += 1;
				}
			}
			arr->Length += 1;
			arr->InternalArray = new int[arr->Capacity];
			for (int i = 0; i < arr->Length; i++)
			{
				arr->InternalArray[i] = temp[i];
			}
			delete[] temp;
		}
		else
		{
			Up(arr, arr->Length);
			int *temp = new int[arr->Capacity];
			int step = 0;
			for (int i = 0; i < arr->Length + 1; i++)
			{
				if (i == place - 1)
				{
					temp[step] = number;
					step += 1;
					temp[step] = arr->InternalArray[i];
					step += 1;
				}
				else
				{
					temp[step] = arr->InternalArray[i];
					step += 1;
				}
			}
			arr->Length += 1;
			arr->InternalArray = new int[arr->Capacity];
			for (int i = 0; i < arr->Length; i++)
			{
				arr->InternalArray[i] = temp[i];
			}
			delete[] temp;
		}
		Show(arr, arr->Length);
	}
	else
	{
		cout << "Вы ушли за границы массива\n";
	}
}

void BinSerach(Array* arr, int num)
{
	Array* temp = new Array;
	temp->InternalArray = new int[arr->Length];
	for (int i = 0; i < arr->Length; i++)
	{
		temp->InternalArray[i] = arr->InternalArray[i];
	}
	Sort(temp, arr->Length);
	bool *flag = new bool;
	*flag = false;
	int top = 0;
	int end = arr->Length - 1;
	while (top <= end)
	{
		int mid = (top + end) / 2;
		if (temp->InternalArray[mid] == num)
		{
			cout << "Элемент есть\n";
			*flag = true;
			break;
		}
		else if (temp->InternalArray[mid] > num)
		{
			end = mid - 1;
		}
		else
		{
			top = mid + 1;
		}
	}
	if (*flag == false)
	{
		cout << "Такого элемента не в нашем массиве\n";
	}
	delete flag;
	delete[] temp;
}

void LinearSearch(Array* arr, int num)
{
	int step = 0;
	int *temp = new int[arr->Length];
	for (int i = 0; i < arr->Length; i++)
	{
		if (num == arr->InternalArray[i])
		{
			temp[step] = i + 1;
			step += 1;
		}
	}
	if (step > 0)
	{
		cout << "Найденный(ые) индекс(ы): ";
		for (int i = 0; i < step; i++)
		{
			cout << temp[i] << " ";
		}
		cout << "\n";
	}
	else
	{
		cout << "К сожалению ничего не найдено\n";
	}
	delete[] temp;
}

void DelByIndex(Array* arr, int ind)
{
	if (ind <= arr->Length&& ind > 0) {
		int step = 0;
		int *temp = new int[arr->Length - 1];
		for (int i = 0; i < arr->Length; i++)
		{
			if (i + 1 != ind)
			{
				temp[step] = arr->InternalArray[i];
				step += 1;
			}
		}
		arr->InternalArray = new int[arr->Capacity];
		for (int i = 0; i < arr->Length - 1; i++)
		{
			arr->InternalArray[i] = temp[i];
		}
		delete[] temp;
		arr->Length -= 1;
		Show(arr, arr->Length);
	}
	else
	{
		cout << "К сожалению вы ушли за границы массива, либо он пуст\n";
	}
}

void SortReverse(Array* arr, int length)
{
	for (int i = 0; i < length - 1; i++)
	{
		for (int j = 0; j < length - i - 1; j++)
		{
			if (arr->InternalArray[j] < arr->InternalArray[j + 1])
			{
				swap(arr->InternalArray[j], arr->InternalArray[j + 1]);
			}
		}
	}
}

void AddToEnd(Array* arr)
{
	if (arr->Capacity > arr->Length)
	{
		cout << "Добавьте элемент в массив\n";
		cin >> arr->InternalArray[arr->Length];
		arr->Length += 1;
	}
	else
	{
		if (arr->Capacity == 0)
		{
			CreateEmptyArray(arr,4);
			cout << "Добавьте элемент в массив\n";
			cin >> arr->InternalArray[arr->Length];
			arr->Length += 1;
		}
		else
		{
			Up(arr, arr->Length);
			cout << "Добавьте элемент в массив\n";
			cin >> arr->InternalArray[arr->Length];
			arr->Length += 1;
		}
	}
	Show(arr, arr->Length);
}

void AddToTop(Array* arr)
{
	if (arr->Capacity > arr->Length)
	{
		int *temp = new int[arr->Length];
		for (int i = 0; i < arr->Length; i++)
		{
			temp[i] = arr->InternalArray[i];
		}
		arr->InternalArray = new int[arr->Capacity];
		cout << "Добавьте элемент в массив\n";
		cin >> arr->InternalArray[0];
		for (int i = 0; i < arr->Length; i++)
		{
			arr->InternalArray[i + 1] = temp[i];
		}
		arr->Length += 1;
		delete[] temp;
	}
	else
	{
		if (arr->Capacity == 0)
		{
			CreateEmptyArray(arr,4);
			int *temp = new int[arr->Length];
			for (int i = 0; i < arr->Length; i++)
			{
				temp[i] = arr->InternalArray[i];
			}
			arr->InternalArray = new int[arr->Capacity];
			cout << "Добавьте элемент в массив\n";
			cin >> arr->InternalArray[0];
			for (int i = 0; i < arr->Length; i++)
			{
				arr->InternalArray[i + 1] = temp[i];
			}
			arr->Length += 1;
			delete[] temp;
		}
		else
		{
			Up(arr, arr->Length);
			int *temp = new int[arr->Length];
			for (int i = 0; i < arr->Length; i++)
			{
				temp[i] = arr->InternalArray[i];
			}
			arr->InternalArray = new int[arr->Capacity];
			cout << "Добавьте элемент в массив\n";
			cin >> arr->InternalArray[0];
			for (int i = 0; i < arr->Length; i++)
			{
				arr->InternalArray[i + 1] = temp[i];
			}
			arr->Length += 1;
			delete[] temp;
		}
	}
	Show(arr, arr->Length);
}
