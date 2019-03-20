#ifndef OS_LAB2_BINARY_TREE_POSTFIX_H
#define OS_LAB2_BINARY_TREE_POSTFIX_H

#include <iostream>
#include <sstream>
#include <string>
#include <stack>
#include <map>
#include <algorithm>
#include "Tree.h"

using namespace std;

Tree parse(string expression);

string postfix(string expression);

bool isDigit(char chr);

bool isOperator(string chr);

#endif