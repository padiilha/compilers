#ifndef LEXER_HH
#define LEXER_HH

#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>

#include "ErrorToken.hh"
#include "InputBuffer.hh"
#include "Token.hh"

class Lexer {
  private:
    InputBuffer& input;
    std::vector<Token*> tokens;
    std::map<std::string, Token*> words;
    std::set<Token*> keywords;
    char ch;
    Token* simulateRelopDFA();
    Token* simulateNumDFA();
    Token* simulateIdDFA();
    Token* simulateUnknownDFA();
    void reserveKeywords();
  public:
    Lexer(InputBuffer& input);
    Token* scan();
    std::vector<Token*> getTokens() const;
    void printSymbolTable();
};

#endif
