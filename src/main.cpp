#include "lexer.h"
#include "model.h"
#include "reader.h"

#include <filesystem>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

int main(void) {
  Reader *r = new Reader();
  Model *m = new Model();
  cout << "Hello, welcom to Local Search Engine!" << endl;
  cout << "Please input your query: ";
  string query;
  cin >> query;
  cout << "Indexing..." << endl;

  try {
    const string filepath = "./data";
    for (const auto &entry : filesystem::directory_iterator(filepath)) {
      if (entry.path().extension() == ".txt") {
        cout << "File name: " << entry.path() << endl;
        string s = r->readText(entry.path());
        m->add_document(entry.path(), s);
      }
    }
  } catch (std::invalid_argument &e) {
    cout << e.what() << endl;
    return -1;
  }

  cout << "Indexing completed!" << endl;
  cout << endl;
  cout << "Searching..." << endl;

  vector<pair<string, float>> results = m->search(query);
  cout << "Results(file path/score): " << endl;
  for (auto const &[file_path, score] : results) {
    cout << file_path << ": " << score << endl;
  }

  delete m;
  m = nullptr;
  delete r;
  r = nullptr;

  return 0;
}
