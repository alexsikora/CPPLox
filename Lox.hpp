// Lox.hpp
// Created by Alex Sikora on January 29, 2017
// Implementation of Lox Compiler in C++

#include <string>

namespace lox {
	class Lox {
	public:
		/* 
		@brief Run a lox script file
		*/
		void runFile(char *fileName);

		/*
		@brief Run a lox command prompt
		*/
		void runPrompt();

	protected:
		void run(std::string source);

	private:
		bool hadError;
	};
}