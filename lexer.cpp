#include "lexer.h"
#include "string_functions.h"

#include <cctype>
#include <iostream>
#include <string>

using namespace std;

Lexer::Lexer(string content) { this->_content = content; }

string Lexer::chop(size_t n) {
  string token = this->_content.substr(0, n);
  this->_content = this->_content.substr(n, this->_content.length() - n);

  return token;
}

string Lexer::chopWhile(int (*predicate)(int)) {
  size_t i = 0;
  while (i < this->_content.length() && predicate(this->_content[i]) > 0) {
    i += 1;
  }

  return string_to_upper(this->chop(i));
}

string Lexer::nextToken() {
  this->trimLeft();

  if (this->_content.length() == 0) {
    return "";
  }

  if (isdigit(this->_content[0])) {
    return this->chopWhile(isdigit);
  }

  if (isalnum(this->_content[0])) {
    return this->chopWhile(isalnum);
  }

  return this->chop(1);
}

void Lexer::trimLeft() {
  size_t i = 0;
  while (i < this->_content.length() && isspace(this->_content[i])) {
    i += 1;
  }

  this->_content = this->_content.substr(i);
}
