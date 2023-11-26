#include "lexer.h"
#include "reader.h"

#include <filesystem>
#include <iostream>
#include <string>

using namespace std;

int main(void) {
  Reader *r = new Reader();
  try {
    const string filepath = "./data";
    for (const auto &entry : filesystem::directory_iterator(filepath)) {
      if (entry.path().extension() == ".txt") {
        cout << "File name: " << entry.path() << endl;
        string s = r->readText(entry.path());
        Lexer *l = new Lexer(s);
        while (true) {
          string w = l->nextToken();
          if (w == "") {
            break;
          }
          std::cout << "word: " << w << std::endl;
          std::cout << "--------------" << std::endl;
        }
        delete l;
        l = nullptr;
      }
    }
  } catch (std::invalid_argument &e) {
    cout << e.what() << endl;
    return -1;
  }

  delete r;
  r = nullptr;
  return 0;
}
