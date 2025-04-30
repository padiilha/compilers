#include "Relop.hh"

Relop::Relop(const std::string& op) : Token("RELOP"), op(op) {}

std::string Relop::getOp() const {
  return op;
}
