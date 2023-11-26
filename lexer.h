#ifndef LEXER
#define LEXER

#include <string>

class Lexer {
public:
  Lexer(std::string content);
  std::string nextToken();
  bool hasNext() const;

private:
  void trimLeft(std::string &s);
  void trimRight(std::string &s);
  std::string peek() const;
  std::string _content;
  size_t _index;
  size_t _length;
};

#endif // end of LEXER
