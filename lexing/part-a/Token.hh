#ifndef TOKEN_HH
#define TOKEN_HH

#include <string>

class Token {
  protected:
    std::string type;
    std::string lexeme;
  public:
    Token(const std::string& type, const std::string& lexeme);
    std::string getType() const;
    std::string getLexeme() const;
};

#endif
