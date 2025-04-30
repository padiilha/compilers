#include "Num.hh"

Num::Num(int value) : Token("NUM"), value(value) {}

int Num::getValue() const {
  return value;
}
