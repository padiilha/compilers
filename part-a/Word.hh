#ifndef WORD_HH
#define WORD_HH

#include "Token.hh"

class Word : public Token {
  protected:
    std::string lexeme;
  public:
    Word(const std::string& tag, const std::string& lexeme);
    std::string getLexeme() const;
};

#endif
