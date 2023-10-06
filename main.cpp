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
        cout << s << endl;
      }
    }
  } catch (std::invalid_argument &e) {
    cout << e.what() << endl;
    return -1;
  }

  delete r;
  return 0;
}
