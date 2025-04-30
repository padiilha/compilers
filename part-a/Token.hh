#ifndef TOKEN_HH
#define TOKEN_HH

#include <string>

class Token {
  protected:
    std::string type;
  public:
    Token(const std::string& type);
    virtual ~Token() = default;
    std::string getType() const;
};

#endif
