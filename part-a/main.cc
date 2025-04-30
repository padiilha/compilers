#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <cctype>
#include <stdio.h>

struct Token {
  std::string type;
  std::string value;
};

unordered_map<string, string> simbolsTable = {
  {"if", "keyword"},
  {"else", "keyword"},
  {"while", "keyword"},
  {"return", "keyword"},
};

vector<Token> lexer(const string& input) {
  vector<Token> tokens;
  size_t pos = 0;
  size_t len = input.length();

  while(pos < len) {
    
  }
}

int main() {
  return 0;
}