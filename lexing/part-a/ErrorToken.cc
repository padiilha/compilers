#include "ErrorToken.hh"

ErrorToken::ErrorToken(const std::string& message, int rowNumber, int colNumber)
  : Token("ERROR", message), message(message), rowNumber(rowNumber), colNumber(colNumber) {
    std::cout << "Error léxico na linha " << rowNumber << ", coluna " << colNumber << ": " << message << std::endl;
}
