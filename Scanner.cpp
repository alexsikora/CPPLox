// Scanner.cpp
// Created by Alex Sikora on January 29, 2017
// Implementation of Lox Compiler in C++

#include "Scanner.hpp"
#include <iostream>

using namespace std;
using namespace lox;

Scanner::Scanner(std::string source_) : source(source_), start(0), 
	current(0), line(1) {
	keywords["and"] = TokenType::AND;
	keywords["class"] = TokenType::CLASS;
	keywords["else"] = TokenType::ELSE;
	keywords["false"] = TokenType::FALSE;
	keywords["for"] = TokenType::FOR;
	keywords["fun"] = TokenType::FUN;
	keywords["if"] = TokenType::IF;
	keywords["nil"] = TokenType::NIL;
	keywords["or"] = TokenType::OR;
	keywords["print"] = TokenType::PRINT;
	keywords["return"] = TokenType::RETURN;
	keywords["super"] = TokenType::SUPER;
	keywords["this"] = TokenType::THIS;
	keywords["true"] = TokenType::TRUE;
	keywords["var"] = TokenType::VAR;
	keywords["while"] = TokenType::WHILE;
}

std::vector<Token> Scanner::scanTokens() {
	vector<Token> tokens;
	scanToken();
	return tokens;
}

void Scanner::scanToken() {
	cout << source << endl;
}

void Scanner::identifier() {

}

bool Scanner::isAlpha(char c) {
	return false;
}

bool Scanner::isAlphaNumeric(char c) {
	return false;
}

void Scanner::string() {

}

void Scanner::number() {

}

bool Scanner::match(char expected) {
	return false;
}

char Scanner::peek() {
	return 'a';
}

char Scanner::peekNext() {
	return 'a';
}

bool Scanner::isDigit(char c) {
	return false;
}

bool Scanner::isAtEnd() {
	return false;
}

char Scanner::advance() {
	return 'a';
}

void Scanner::addToken(TokenType type) {

}

void Scanner::addToken(TokenType type, std::string literal) {

}

void Scanner::addToken(TokenType type, double literal) {

}
