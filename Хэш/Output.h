#pragma once
#include <string>
#include "Node.h"
using namespace std;

void OutputEmpty();
void OutputNode(string key, string value);
void OutputNodeTab(NodeTab * node);
void OutputDelNode(string key, string value);
void OutputDelNodeTab(NodeTab * node);
void Clear();
void MainMenu();
void OutputEmptyTab();
void ErrorAdd();