#pragma once
#include <iostream>
#include <string>
using namespace std;


int HashFunc(string key, int first_hash, int length_tab);
void ChangeHashFunc(int *first_hash);