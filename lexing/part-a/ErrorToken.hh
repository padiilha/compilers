#ifndef ERRORTOKEN_HH
#define ERRORTOKEN_HH

#include <iostream>

#include "Token.hh"

class ErrorToken : public Token {
  private:
    std::string message;
    int rowNumber;
    int colNumber;
  public:
    ErrorToken(const std::string& message, int rowNumber, int colNumber);
};

#endif
