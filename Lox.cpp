// Lox.cpp
// Created by Alex Sikora on January 29, 2017
// Implementation of Lox Compiler in C++

#include "Lox.hpp"
#include "Scanner.hpp"
#include <iostream>
#include <fstream>
#include <streambuf>

using namespace std;
using namespace lox;

void Lox::runFile(char *fileName) {
	ifstream scriptFile(fileName);
	if (scriptFile.is_open()) {
		std::string str;

		scriptFile.seekg(0, std::ios::end);   
		str.reserve(scriptFile.tellg());
		scriptFile.seekg(0, std::ios::beg);

		str.assign((std::istreambuf_iterator<char>(scriptFile)),
		            std::istreambuf_iterator<char>());
	
		auto scanner = make_shared<Scanner>(str);
		auto tokens = scanner->scanTokens();

		for (auto token : tokens) {
			cout << token.toString() << endl;
		}

	} else {
		cout << "Unable to open file";
	}
}

void Lox::runPrompt() {
	string line;
	while (true) {
		std::cout << "> ";
		std::cin >> line;
		auto scanner = make_shared<Scanner>(line);
		auto tokens = scanner->scanTokens();

		for (auto token : tokens) {
			cout << token.toString() << endl;
		}
		
	} 
}

void Lox::run(string source) {
	cout << source << endl;
}