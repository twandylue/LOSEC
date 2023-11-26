#ifndef LEXER
#define LEXER

#include <string>

class Lexer {
public:
  Lexer(std::string content);
  std::string nextToken();

private:
  void trimLeft();
  std::string chop(size_t n);
  std::string chopWhile(int (*predicate)(int));
  std::string _content;
};

#endif // end of LEXER
