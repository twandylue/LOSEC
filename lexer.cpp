#include "lexer.h"

#include <iostream>
#include <string>

using namespace std;

Lexer::Lexer(string content) {
  this->_content = content;
  this->_index = 0;
  // BUG: should trimming
  this->_length = content.length();
}

bool Lexer::hasNext() const { return this->_index < this->_length; }

bool Lexer::isWhitespace(char c) const {
  return c == ' ' || c == '\t' || c == '\n' || c == '\r';
}

string Lexer::peek() const {
  size_t i = this->_index;
  while (i < this->_length && !this->isWhitespace(this->_content[i])) {
    i++;
  }
  return this->_content.substr(this->_index, i - this->_index);
}

string Lexer::next() {
  while (this->isWhitespace(this->_content[this->_index])) {
    this->_index++;
  }

  string s = this->peek();
  this->_index += s.length();
  // std::cout << "index: " << this->_index << std::endl;
  return s;
}
