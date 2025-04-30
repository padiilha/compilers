#ifndef LEXER_HH
#define LEXER_HH

#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "InputBuffer.hh"
#include "Token.hh"
#include "Word.hh"

class Lexer {
  private:
    InputBuffer& input;
    std::vector<Token*> tokens;
    std::map<std::string, Word*> symbolTable;
    Token* simulateIdDFA();
    Token* simulateNumDFA();
    Token* simulateRelopDFA();
    void reserveKeywords();
  public:
    Lexer(InputBuffer& input);
    void scan();
    std::vector<Token*> getTokens() const;
    void printSymbolTable();
};

#endif
