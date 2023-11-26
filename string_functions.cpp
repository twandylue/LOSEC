#include "string_functions.h"

#include <iostream>

unsigned long string_length(const string STR) {
  unsigned long result = -1;
  result = STR.length(); // set result to the length of the string
  return result;
}

char string_char_at(const string STR, const int IDX) {
  char result = '\0';
  result = STR.at(IDX);
  return result;
}

string string_append(const string LEFT, const string RIGHT) {
  string result = LEFT;
  result.append(RIGHT);
  return result;
}

string string_insert(const string STR, const string TO_INSERT, const int IDX) {
  string result = STR;
  result.insert(IDX, TO_INSERT);
  return result;
}

size_t string_find(const string STR, const char C) {
  size_t result = 0;
  result = STR.find(C);
  return result;
}

string string_substring(const string STR, const int IDX, const int LEN) {
  string result = STR;
  result = STR.substr(IDX, LEN);
  return result;
}

string string_replace(const string STR, const string TEXT_TO_REPLACE,
                      const string REPLACE_WITH) {
  string result = STR;
  size_t idx = STR.find(TEXT_TO_REPLACE);
  if (idx == string::npos) {
    return result;
  }
  result.replace(idx, TEXT_TO_REPLACE.length(), REPLACE_WITH);
  return result;
}

string string_first_word(const string STR) {
  string result = STR;
  result = result.substr(0, result.find(" "));
  return result;
}

string string_remove_first_word(const string STR) {
  string result = STR;
  size_t idx = result.find(" ");
  if (idx == string::npos) {
    return "";
  }
  result = result.substr(idx + 1, result.length() - 1);
  return result;
}

string string_second_word(const string STR) {
  string result = STR;
  result = string_first_word(string_remove_first_word(STR));
  return result;
}

string string_third_word(const string STR) {
  string result = STR;
  result = string_first_word(
      string_remove_first_word(string_remove_first_word(STR)));
  return result;
}

string string_nth_word(const string STR, const int N) {
  string result = STR;
  for (int i = 0; i < N - 1; ++i) {
    result = string_remove_first_word(result);
  }

  result = string_first_word(result);
  return result;
}

vector<string> string_tokenize(const string STR, const char DELIMINATOR) {
  vector<string> result;

  if (STR.length() == 0) {
    result.push_back("");
    return result;
  }

  size_t beg = 0;
  size_t end = 0;
  for (size_t i = 0; i < STR.length(); ++i) {
    if (STR[i] == DELIMINATOR) {
      end = i - 1;
      result.push_back(STR.substr(beg, end - beg + 1));
      beg = i + 1;
    }

    if (i == STR.length() - 1) {
      end = STR.length() - 1;
      result.push_back(STR.substr(beg, end - beg + 1));
    }
  }
  return result;
}

string string_substitute(const string STR, const char TARGET,
                         const char REPLACEMENT) {
  string result = STR;
  for (size_t i = 0; i < STR.length(); i++) {
    if (STR[i] == TARGET) {
      result.replace(i, 1, 1, REPLACEMENT);
    }
  }
  return result;
}

string string_to_lower(const string STR) {
  string result = STR;
  for (size_t i = 0; i < STR.length(); ++i) {
    result[i] = tolower(result[i]);
  }
  return result;
}

string string_to_upper(const string STR) {
  string result = STR;
  for (size_t i = 0; i < STR.length(); ++i) {
    result[i] = toupper(result[i]);
  }
  return result;
}

int string_compare(const string LHS, const string RHS) {
  int result = 0;
  if (LHS.length() > RHS.length()) {
    result = 1;
  } else if (LHS.length() < RHS.length()) {
    result = -1;
  } else {
    for (size_t i = 0; i < LHS.length(); i++) {
      if (LHS[i] == RHS[i]) {
        continue;
      }

      if (LHS[i] - RHS[i] > 0) {
        result = 1;
        break;
      }
      result = -1;
      break;
    }
  }

  return result;
}
