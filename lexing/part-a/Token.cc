#include "Token.hh"

Token::Token(const std::string& type, const std::string& lexeme) : type(type), lexeme(lexeme) {}

std::string Token::getType() const {
  return type;
}

std::string Token::getLexeme() const {
  return lexeme;
}
