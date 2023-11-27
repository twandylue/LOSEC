#ifndef MODEL_H
#define MODEL_H

#include <string>
#include <unordered_map>
#include <vector>

typedef std::string term;
typedef std::unordered_map<term, size_t> term_freq;
struct Doc {
  size_t total_terms;
  term_freq tf;
};

// NOTE: this is a map from term to number of documents that contain that term
typedef std::unordered_map<term, size_t> doc_freq;
typedef std::string file_path;
typedef std::unordered_map<file_path, Doc> file_tf;

class Model {
public:
  Model();
  void add_document(const std::string &file_path, const std::string &content);
  void remove_document(const std::string &file_path);
  std::vector<std::pair<std::string, float>> search(std::string &query);
  size_t get_total_docs() const;
  size_t get_docs_with_term(const std::string &term) const;

private:
  file_tf _docs;
  doc_freq _df;
};

#endif // MODEL_H
