#ifndef LEXER
#define LEXER

#include <string>

class Lexer {
public:
  Lexer(std::string content);
  std::string next();
  std::string peek();
  bool hasNext();

private:
  std::string _content;
  size_t _index;
  size_t _length;
  bool isWhitespace(char c);
  // isPunctuation(char c);
  // isOperator(char c);
  // isQuote(char c);
  // isDigit(char c);
};

#endif // end of LEXER
