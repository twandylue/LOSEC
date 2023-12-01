#ifndef LEXER
#define LEXER

#include <string>

class Lexer {
public:
  /**
   * @brief Construct a new Lexer object
   *
   * @param content Content to be tokenized
   */
  Lexer(const std::string content);
  /**
   * @brief Get the next token
   *
   * @return std::string The next token
   */
  std::string nextToken();

private:
  /**
   * @brief Trim the content from the left. Remove all the spaces from the left.
   */
  void trimLeft();
  /**
   * @brief Chop the content from left to right, and return the chopped part.
   * You can imagine this is like cutting the substring from starting index to n
   * index of the content.
   *
   * @param n The ending index to chop
   *
   * @return std::string The chopped part
   */
  std::string chop(const size_t n);
  /**
   * @brief Chop the content from left to right, and return the chopped part.
   * Using predicate to determine the ending index.
   *
   * @param predicate A delegate function to determine the ending index
   *
   * @return std::string The chopped part
   */
  std::string chopWhile(int (*predicate)(int));
  std::string _content;
};

#endif // end of LEXER
