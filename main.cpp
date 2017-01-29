// main.cpp
// Created by Alex Sikora on January 29, 2017
// Implementation of Lox in C++

#include <iostream>
#include <fstream>
#include <string>

#include "Lox.hpp"

using namespace std;


int main(int argc, char *argv[]) {
	if (argc > 2) {
		cout << "Usage: cpplox [script]" << endl;
	} else if (argc == 2) {
		auto lox = make_shared<lox::Lox>();
		lox->runFile(argv[1]);
	} else {
		auto lox = make_shared<lox::Lox>();
		lox->runPrompt();
	}

	return 0;
}