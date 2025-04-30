#ifndef NUM_HH
#define NUM_HH

#include "Token.hh"

class Num : public Token {
  protected:
    int value;
  public:
    Num(int value);
    int getValue() const;
};

#endif
