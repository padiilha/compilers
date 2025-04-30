#ifndef RELOP_HH
#define RELOP_HH

#include "Token.hh"

class Relop : public Token {
  protected:
    std::string op;
  public:
    Relop(const std::string& op);
    std::string getOp() const;
};

#endif
