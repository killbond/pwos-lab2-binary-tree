#ifndef OS_LAB2_BINARY_TREE_TREE_H
#define OS_LAB2_BINARY_TREE_TREE_H

#include <string>
#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

class Tree {
public:
	Tree();
	~Tree();

	string getValue();
	Tree getRight();
	Tree getLeft();
	Tree* getParent();
	Tree getRoot();
	int getHeight();

	bool hasLeft();
	bool hasRight();
	bool hasParent();
	bool hasValue();
	bool completed();
	bool isOperator();
	bool isNumber();

	void setLeft(Tree *node);
	void setRight(Tree *node);
	void setParent(Tree *node);
	void insert(Tree *node);
	void setValue(string value);

	double calculate();

private:
	string value;
	Tree *left;
	Tree *right;
	Tree *parent;
};

#endif