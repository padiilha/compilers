#include "Token.hh"

Token::Token(const std::string& type) : type(type) {}

std::string Token::getType() const {
  return type;
}
