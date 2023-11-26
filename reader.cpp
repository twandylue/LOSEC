#include "reader.h"

#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

Reader::Reader() {}

string Reader::readText(string filepath) {
  ifstream fileContent(filepath);
  if (fileContent.fail()) {
    throw invalid_argument("Error opening file: " + filepath);
  }

  char c;
  string content;
  while (fileContent.get(c)) {
    content.push_back(c);
  }

  fileContent.close();
  return content;
}
