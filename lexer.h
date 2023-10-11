#ifndef LEXER
#define LEXER

#include <string>

class Lexer {
public:
  Lexer(std::string content);
  std::string next();
  std::string peek() const;
  bool hasNext() const;

private:
  std::string _content;
  size_t _index;
  size_t _length;
  bool isWhitespace(char c) const;
  // isPunctuation(char c);
  // isOperator(char c);
  // isQuote(char c);
  // isDigit(char c);
};

#endif // end of LEXER
