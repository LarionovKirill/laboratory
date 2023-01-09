#pragma once
#include "Array.h"

void Menu();
Array* Create(int len);
void CreateEmptyArray(Array* arr,int len);
void Up(Array* arr, int length);
void Show(Array* arr, int length);
void Sort(Array* arr, int length);
void AddToPlace(Array* arr, int number, int place);
void BinSerach(Array* arr, int num);
void LinearSearch(Array* arr, int num);
void DelByIndex(Array* arr, int ind);
void SortReverse(Array* arr, int length);
void AddToEnd(Array* arr);
void AddToTop(Array* arr);