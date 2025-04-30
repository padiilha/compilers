#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include "InputBuffer.hh"
#include "Lexer.hh"
#include "Token.hh"

int main(int argc, char* argv[]) {
  if (argc != 2) {
    std::cerr << "Uso: " << argv[0] << " <arquivo_de_entrada.txt>" << std::endl;
    return 1;
  }

  std::ifstream file(argv[1]);
  if (!file.is_open()) {
    std::cerr << "Erro ao abrir o arquivo: " << argv[1] << std::endl;
    return 1;
  }

  std::stringstream buffer;
  buffer << file.rdbuf();
  std::string input = buffer.str();

  InputBuffer inputBuffer(input);
  Lexer lexer(inputBuffer);
  lexer.scan();

  std::vector<Token*> tokens = lexer.getTokens();
  for (Token* token : tokens) {
    std::cout << "Lista de Tokens:" << std::endl;
    std::cout << "Token: " << token->getType() << ", Lexema: " << token->getLexeme() << std::endl;
  }

  lexer.printSymbolTable();

  return 0;
}
