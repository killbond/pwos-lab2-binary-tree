#include "stdafx.h"
#include "Parse.h"

using namespace std;

Tree parse(string expression)
{
	Tree* current = new Tree;
	string token;

	replace(expression.begin(), expression.end(), '.', ',');
	for (int i = expression.length(); i >= 0; i--) {
		token = expression[i];
		if (" " == token || '\0' == token[0]) {
			continue;
		}

		if (isOperator(token)) {
			current->setValue(token);
			Tree* node = new Tree;
			current->insert(node);
			current = node;
			continue;
		}

		string number = expression.substr(i, 1);
		while (i > 0 && ' ' != expression[--i]) {
			number = expression[i] + number;
		}

		current->setValue(number);
		do {
			current = current->getParent();
		} while (current->hasParent() && current->completed());

		Tree* node = new Tree;
		current->insert(node);
		current = node;
	}
	return current->getRoot();
}

string postfix(string expression)
{
	stack<char> opStack;
	ostringstream result;

	map <char, int> op;
	op['*'] = 3;
	op['/'] = 3;
	op['+'] = 2;
	op['-'] = 2;
	op['('] = 1;
	op['='] = 0;

	char buff;
	for (int i = 0; i < expression.length(); i++) {
		buff = expression[i];

		if (' ' == buff) {
			continue;
		}

		if (op.count(buff)) {

			if ((!opStack.empty()) && (op[buff] <= op[opStack.top()]) && (buff != '(')) {
				while ((!opStack.empty()) && (op[buff] <= op[opStack.top()])) {
					result << opStack.top() << ' ';
					opStack.pop();
				}
			}

			opStack.push(buff);
			continue;
		}

		if (isDigit(buff)) {
			while (true) {
				result << buff;
				if (!isDigit(expression[i + 1])) {
					break;
				}
				buff = expression[++i];
			}
			result << ' ';
			continue;
		}

		if (buff == ')') {

			while ((!opStack.empty()) && (opStack.top() != '(')) {
				result << opStack.top() << ' ';
				opStack.pop();
			}

			if (opStack.empty()) {
				throw "не правильно расставлены скобки";
			}

			opStack.pop();
			continue;
		}
		throw "недопустимый символ";
	}

	while (!opStack.empty()){
		if (opStack.top() == '(')
			throw "не правильно расставлены скобки";
		result << opStack.top() << ' ';
		opStack.pop();
	}

	if (result.rdbuf()->in_avail())
		throw "нет данных";

	return result.str();
}

bool isDigit(char chr)
{
	return isdigit(chr) || ',' == chr || '.' == chr;
}

bool isOperator(string chr)
{
	return "+" == chr || "-" == chr || "*" == chr || "/" == chr;
}