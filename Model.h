#ifndef MODEL_H
#define MODEL_H

#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

typedef std::string term;
/**
 * @brief A map from term to frequency in a document
 */
typedef std::unordered_map<term, size_t> term_freq;
/**
 * @brief A document in the model containing a total number of terms and a map
 * from term to frequency
 */
struct Doc {
  size_t total_terms;
  term_freq tf;
};

// NOTE: this is a map from term to number of documents that contain that term
/**
 * @brief A map from term to number of documents that contain that term
 */
typedef std::unordered_map<term, size_t> doc_freq;
typedef std::string file_path;
/**
 * @brief A map from file path to a document
 */
typedef std::unordered_map<file_path, Doc> file_tf;

class Model {
public:
  Model();
  /**
   * @brief Adds a document to the model
   *
   * @param file_path path of the document
   * @param content content of the document
   */
  void add_document(const std::string &file_path, const std::string &content);
  /**
   * @brief Removes a document from the model
   *
   * @param file_path path of the document
   */
  void remove_document(const std::string &file_path);
  /**
   * @brief Searches the model for a given query
   *
   * @param query query to search for
   *
   * @return a vector of pairs of file paths and scores calculated by tf-idf
   * method
   */
  std::vector<std::pair<std::string, float>> search(std::string &query) const;
  /**
   * @brief Returns the total number of documents in the model
   *
   * @return total number of documents in the model
   */
  size_t get_total_docs() const;
  /**
   * @brief Returns the number of documents that contain a given term
   *
   * @param term term to search for
   *
   * @return number of documents that contain term
   */
  size_t get_docs_with_term(const std::string &term) const;

private:
  file_tf _docs;
  doc_freq _df;
};

#endif // MODEL_H
