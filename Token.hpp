// Token.hpp
// Created by Alex Sikora on January 29, 2017
// Implementation of Lox Compiler in C++

#include <string>

namespace lox {

	enum TokenType {
		// Single character tokens
		LEFT_PAREN=0, RIGHT_PAREN,
		LEFT_BRACE, RIGHT_BRACE,
		COMMA,
		DOT,
		MINUS,
		PLUS,
		SEMICOLON,
		SLASH,
		STAR,

		// One or Two Character Tokens
		BANG, BANG_EQUAL,
		EQUAL, EQUAL_EQUAL,
		GREATER, GREATER_EQUAL,
		LESS, LESS_EQUAL,

		// Literals
		IDENTIFIER, STRING, NUMBER,

		// Keywords
		AND, CLASS, ELSE, FALSE, FUN, FOR, IF, NIL, OR,
		PRINT, RETURN, SUPER, THIS, TRUE, VAR, WHILE,

		EOF_T,
	};

	struct Token {
		TokenType type;
		std::string lexeme;
		int line;

		std::string toString() {
			return std::to_string(type) + " " + lexeme + " " + std::to_string(line);
		}
	};

	struct StringToken : Token {
		std::string literal;

		std::string toString() {
			auto result = Token::toString();
			return result + " " + literal;
		}
	};

	struct NumberToken : Token {
		double literal;

		std::string toString() {
			auto result = Token::toString();
			return result + " " + std::to_string(literal);
		}
	};
}