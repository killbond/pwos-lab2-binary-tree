#include "stdafx.h"
#include "Tree.h"

using namespace std;

Tree::Tree()
{
	this->left = nullptr;
	this->right = nullptr;
	this->parent = nullptr;
	this->value = "";
}

Tree::~Tree()
{
	this->left = nullptr;
	this->right = nullptr;
	this->parent = nullptr;
}

Tree* Tree::getParent()
{
	return this->parent;
}

Tree Tree::getRoot()
{
	Tree* tree = this;
	while (tree->hasParent())
	{
		tree = tree->parent;
	}
	return *tree;
}

Tree Tree::getLeft()
{
	return *this->left;
}

Tree Tree::getRight()
{
	return *this->right;
}

string Tree::getValue()
{
	return this->value;
}

int Tree::getHeight()
{
	int leftHeight = 0,
		rightHeight = 0;

	if (this->hasLeft()) {
		leftHeight = 1 + this->getLeft().getHeight();
	}

	if (this->hasRight()) {
		rightHeight = 1 + this->getRight().getHeight();
	}

	return max(leftHeight, rightHeight);
}

bool Tree::hasLeft()
{
	return nullptr != this->left;
}

bool Tree::hasRight()
{
	return nullptr != this->right;
}

bool Tree::hasParent()
{
	return nullptr != this->parent;
}

bool Tree::hasValue()
{
	return "" != this->value;
}

bool Tree::completed()
{
	return this->hasLeft() && this->hasRight();
}

bool Tree::isOperator()
{
	return this->getValue() == "+" ||
		this->getValue() == "-" || 
		this->getValue() == "*" || 
		this->getValue() == "/";
}

bool Tree::isNumber()
{
	return !this->isOperator();
}

void Tree::setParent(Tree *node)
{
	this->parent = node;
}

void Tree::setLeft(Tree *node)
{
	this->left = node;
}

void Tree::setRight(Tree *node)
{
	this->right = node;
}

void Tree::insert(Tree *node)
{
	node->setParent(this);
	if (!this->hasRight()) {
		this->setRight(node);
	}
	else if (!this->hasLeft()) {
		this->setLeft(node);
	}
}

void Tree::setValue(string value)
{
	this->value = value;
}

double Tree::calculate()
{
	double	left = 0,
			right = 0;

	if (this->isNumber()) {
		return stof(this->getValue());
	}
	else {
		left = this->getLeft().calculate();
		right = this->getRight().calculate();

		if (this->getValue() == "+") {
			return left + right;
		}

		if (this->getValue() == "-") {
			return left - right;
		}

		if (this->getValue() == "*") {
			return left * right;
		}

		if (this->getValue() == "/") {
			return left / right;
		}
	}
}