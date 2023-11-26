#include "lexer.h"

#include <iostream>
#include <string>

using namespace std;

Lexer::Lexer(string content) {
  this->trimLeft(content);
  this->trimRight(content);
  this->_content = content;
  this->_index = 0;
  this->_length = content.length();
}

bool Lexer::hasNext() const { return this->_index < this->_length; }

string Lexer::peek() const {
  size_t i = this->_index;
  while (i < this->_length && !isspace(this->_content[i])) {
    i++;
  }
  return this->_content.substr(this->_index, i - this->_index);
}

string Lexer::nextToken() {
  while (this->_index < this->_length &&
         isspace(this->_content[this->_index])) {
    this->_index += 1;
  }
  string s = this->peek();
  this->_index += s.length();
  return s;
}

void Lexer::trimRight(string &s) {
  while (s.length() > 0 && isspace(s[s.length() - 1])) {
    s.pop_back();
  }
}

void Lexer::trimLeft(string &s) {
  size_t i = 0;
  while (i < s.length() && isspace(s[i])) {
    i++;
  }
  s = s.substr(i);
}
