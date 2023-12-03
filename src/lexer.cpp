#include "lexer.h"
#include "string_functions.h"

#include <cctype>   // isspace, isdigit, isalnum
#include <iostream> // cout
#include <string>   // string, substr

using namespace std;

Lexer::Lexer(const string content) { this->_content = content; }

string Lexer::chop(const size_t n) {
  // NOTE: chop the first n characters and return them
  string token = this->_content.substr(0, n);
  this->_content = this->_content.substr(n, this->_content.length() - n);

  return token;
}

string Lexer::chopWhile(int (*predicate)(int)) {
  size_t i = 0;
  while (i < this->_content.length() && predicate(this->_content[i]) > 0) {
    i += 1;
  }

  // NOTE: make string uppercase for easy searching
  return string_to_upper(this->chop(i));
}

string Lexer::nextToken() {
  this->trimLeft();

  if (this->_content.length() == 0) {
    return "";
  }

  // NOTE: chop the longest token which contains only digits
  if (isdigit(this->_content[0])) {
    return this->chopWhile(isdigit);
  }

  // NOTE: chop the longest token which contains only alphanumeric characters
  if (isalnum(this->_content[0])) {
    return this->chopWhile(isalnum);
  }

  // NOTE: chop the first character
  return this->chop(1);
}

void Lexer::trimLeft() {
  size_t i = 0;
  // NOTE: skip all whitespace characters
  while (i < this->_content.length() && isspace(this->_content[i])) {
    i += 1;
  }

  this->_content = this->_content.substr(i);
}
