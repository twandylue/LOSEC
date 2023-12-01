#ifndef READER
#define READER

#include <string>

class Reader {
public:
  /**
   * @brief Construct a new Reader object
   */
  Reader();

  /**
   * @brief Read a text file
   *
   * @param filepath Path to the file
   *
   * @return std::string The content of the file
   */
  std::string readText(const std::string filepath);
};

#endif // end of READER
