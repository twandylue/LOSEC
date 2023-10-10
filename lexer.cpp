#include "lexer.h"

Lexer::Lexer(std::string content) {
  this->_content = content;
  this->_index = 0;
  this->_length = content.length();
}

bool Lexer::hasNext() { return this->_index < this->_length; }

bool Lexer::isWhitespace(char c) {
  return c == ' ' || c == '\t' || c == '\n' || c == '\r';
}
