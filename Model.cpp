#include "Model.h"
#include "lexer.h"

#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

Model::Model() {
  this->_docs = file_tf();
  this->_df = doc_freq();
}

size_t Model::get_total_docs() const { return this->_docs.size(); }

size_t Model::get_docs_with_term(const string &term) const {
  if (this->_df.find(term) == this->_df.end()) {
    return 0;
  }

  return this->_df.at(term);
}

void Model::add_document(const string &file_path, const string &content) {
  this->remove_document(file_path);
  term_freq tf = term_freq();

  Lexer *l = new Lexer(content);
  while (true) {
    string token = l->nextToken();

    if (token == "") {
      break;
    }

    if (tf.find(token) == tf.end()) {
      tf.insert(pair<string, size_t>(token, 1));
    } else {
      tf.at(token) += 1;
    }
  }

  for (auto const &[term, _] : tf) {
    if (this->_df.find(term) == this->_df.end()) {
      this->_df.insert(pair<string, size_t>(term, 1));
    } else {
      this->_df.at(term) += 1;
    }
  }

  Doc doc;
  doc.total_terms = tf.size();
  doc.tf = tf;

  this->_docs.insert(pair<string, Doc>(file_path, doc));

  delete l;
  l = nullptr;
}

void Model::remove_document(const string &file_path) {
  if (this->_docs.find(file_path) != this->_docs.end()) {
    Doc doc = this->_docs.at(file_path);
    for (auto const &[term, _] : doc.tf) {
      this->_df.at(term) -= 1;
    }

    this->_docs.erase(file_path);
  }
}

float compute_tf(const string &term, const Doc &doc) {
  size_t m = doc.total_terms;
  size_t n = doc.tf.at(term);

  return (float)n / (float)(m + 1);
}

float compute_idf(const string &term, const Model &model) {
  size_t N = model.get_total_docs();
  size_t n = model.get_docs_with_term(term);

  return log((float)N / (float)(n + 1));
}

vector<pair<string, float>> Model::search(string &query) {
  vector<string> terms = vector<string>();
  Lexer *l = new Lexer(query);
  while (true) {
    string token = l->nextToken();

    if (token == "") {
      break;
    }

    terms.push_back(token);
  }
  delete l;
  l = nullptr;

  vector<pair<string, float>> results = vector<pair<string, float>>();
  for (auto const &[file_path, doc] : this->_docs) {
    float score = 0.0;
    for (auto const &term : terms) {
      score += compute_tf(term, doc) * compute_idf(term, *this);
    }

    results.push_back(pair<string, float>(file_path, score));
  }

  sort(results.begin(), results.end(),
       [](const pair<string, float> &a, const pair<string, float> &b) {
         return a.second > b.second;
       });

  return results;
}
