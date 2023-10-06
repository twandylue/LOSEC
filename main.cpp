#include "reader.h"

#include <iostream>
#include <string>

using namespace std;

int main(void) {
  Reader *r = new Reader();
  try {
    string s = r->readText("./data/test.txt");
    cout << s << endl;
  } catch (std::invalid_argument &e) {
    cout << e.what() << endl;
    return -1;
  }

  delete r;
  return 0;
}
