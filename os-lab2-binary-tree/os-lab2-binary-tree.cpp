// os-lab2-binary-tree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Tree.h"
#include "Parse.h"


void _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "Russian");

	Tree tree;
	float result;
	string input, notation;

	cout << "Введите выражение в общем виде" << endl;
	cout << "input=";
	getline(cin, input);

	try {
		notation = postfix(input);
		tree = parse(notation);
	}
	catch (...){
		cout << "Ошибка выражения" << endl;
		system("PAUSE");
		return;
	}

	cout << "Польская форма: " << notation << endl;
	cout << "Результат: " << tree.calculate() << endl;

	system("PAUSE");
}

