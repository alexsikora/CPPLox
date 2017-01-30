// Scanner.hpp
// Created by Alex Sikora on January 29, 2017
// Implementation of Lox Compiler in C++

#include <string>
#include <unordered_map>
#include <vector>
#include "Token.hpp"

namespace lox {
	class Scanner {
	public:
		Scanner(std::string source_);
		std::vector<Token> scanTokens();

	protected:
		std::string source;
		int start;
		int current;
		int line;

		std::unordered_map<std::string, TokenType> keywords;
	private:
		void scanToken();
		void identifier();
		bool isAlpha(char c);
		bool isAlphaNumeric(char c);
		void string();
		void number();
		bool match(char expected);
		char peek();
		char peekNext();
		bool isDigit(char c);
		bool isAtEnd();
		char advance();
		void addToken(TokenType type);
		void addToken(TokenType type, std::string literal);
		void addToken(TokenType type, double literal);
	};
}