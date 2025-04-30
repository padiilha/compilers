#include "Word.hh"

Word::Word(const std::string& tag, const std::string& lexeme)
  : Token(tag), lexeme(lexeme) {}

std::string Word::getLexeme() const {
  return lexeme;
}
