// Scanner.cpp
// Created by Alex Sikora on January 29, 2017
// Implementation of Lox Compiler in C++

#include "Scanner.hpp"
#include <iostream>
#include <sstream>

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
	while (!isAtEnd()) {
		// Start the next lexeme
		start = current;
		scanToken();
	}

	tokens.push_back(Token(TokenType::EOF_T, "", line));

	return tokens;
}

void Scanner::scanToken() {
	char c = advance();
	switch(c) {
		case '(': {
			addToken(TokenType::LEFT_PAREN); 
			break;
		}
		case ')': {
			addToken(TokenType::RIGHT_PAREN);
			break;
		}
		case '{': {
			addToken(TokenType::LEFT_BRACE);
			break;
		}
		case '}': {
			addToken(TokenType::RIGHT_BRACE);
			break;
		}
		case ',': {
			addToken(TokenType::COMMA);
			break;
		}
		case '.': {
			addToken(TokenType::DOT);
			break;
		}
		case '-': {
			addToken(TokenType::MINUS);
			break;
		}
		case '+': {
			addToken(TokenType::PLUS);
			break;
		}
		case ';': {
			addToken(TokenType::SEMICOLON);
			break;
		}
		case '*': {
			addToken(TokenType::STAR);
			break;
		}
		case '!': addToken(match('=') ? BANG_EQUAL : BANG); break;
  		case '=': addToken(match('=') ? EQUAL_EQUAL : EQUAL); break;
  		case '<': addToken(match('=') ? LESS_EQUAL : LESS); break;
  		case '>': addToken(match('=') ? GREATER_EQUAL : GREATER); break;
		
		case '/': {
			if (match('/')) {
				// Comment eol
				while (peek() != '\n' && !isAtEnd()) advance();
			} else if (match('*')) {
				while (!isAtEnd()) {
					if (peek() == '*') {
						if (peekNext() == '/') {
							break;
						}
					}
					advance();
				}
				int i = 2;
				while (i > 0 && !isAtEnd()) {
					advance();
					i--;
				}
			} else {
				addToken(SLASH);
			}
			break;
		}

		case '\n':
			line++;
			break;

		case '"':
			string();
			break;

		// Meaningless characters
		case ' ':
		case '\r':
		case '\t':
			break;

		default: {
			if (isDigit(c)) {
				number();
			} else if (isAlpha(c)) {
				identifier();
			} else {
				error(line, "Unexpected character.");
			}
			break;
		}

	}
}

void Scanner::error(int line, std::string message) {
	cout << "[line " + to_string(line) + "] Error: " + message << endl;
	hadError = true;
}

void Scanner::identifier() {
	while (isAlphaNumeric(peek())) {
		advance();
	}

	// Check for reserved identifier
	auto text = source.substr(start, current - start);

	auto keyword = keywords.find(text);
	if (keyword == keywords.end()) {
		// No token found
		addToken(TokenType::IDENTIFIER);
	} else {
		addToken(keyword->second);
	}
}

bool Scanner::isAlpha(char c) {
	return (c >= 'a' && c <= 'z') ||
			(c >= 'A' && c <= 'Z') ||
			c == '_';
}

bool Scanner::isAlphaNumeric(char c) {
	return isAlpha(c) || isDigit(c);
}

void Scanner::string() {
	while (peek() != '"' && !isAtEnd()) {
		if (peek() == '\n') {
			line++;
		}
		advance();
	}

	if (isAtEnd()) {
		error(line, "Unterminated string.");
		return;
	}

	advance();

	auto value = source.substr(start + 1, current - 2 - start);
	addToken(TokenType::STRING, value);
}

void Scanner::number() {
	while (isDigit(peek())) {
		advance();
	}

	if (peek() == '.' && isDigit(peekNext())) {
		advance();
		while (isDigit(peek())) {
			advance();
		}
	}

	auto sub = source.substr(start, current - start);
	std::istringstream i(sub);
	double value;
	if (!(i >> value)) {
		error(line, "Bad number");
	}
	addToken(TokenType::NUMBER, value);
}

bool Scanner::match(char expected) {
	if (isAtEnd()) {
		return false;
	}

	if (source.at(current) != expected) {
		return false;
	}

	current++;
	return true;
}

char Scanner::peek() {
	if (current >= source.length()) {
		return '\0';
	}
	return source.at(current);
}

char Scanner::peekNext() {
	if (current + 1 >= source.length()) {
		return '\0';
	}
	return source.at(current + 1);
}

bool Scanner::isDigit(char c) {
	return c >= '0' && c <= '9';
}

bool Scanner::isAtEnd() {
	return current >= source.length();
}

char Scanner::advance() {
	current++;
	return source.at(current - 1);
}

void Scanner::addToken(TokenType type) {
	auto text = source.substr(start, current - start);
	tokens.push_back(Token(type, text, line));
}

void Scanner::addToken(TokenType type, std::string literal) {
	auto text = source.substr(start, current - start);
	tokens.push_back(StringToken(type, text, line, literal));
}

void Scanner::addToken(TokenType type, double literal) {
	auto text = source.substr(start, current - start);
	tokens.push_back(NumberToken(type, text, line, literal));
}
