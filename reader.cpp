#include "reader.h"

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

Reader::Reader() {}

string Reader::readText(string filepath) {
  ifstream fileContent(filepath);
  if (fileContent.fail()) {
    throw std::invalid_argument("Error opening file: " + filepath);
  }

  char c;
  string content;
  while (!fileContent.eof()) {
    c = fileContent.get();
    content.push_back(c);
  }

  fileContent.close();
  return content;
}
