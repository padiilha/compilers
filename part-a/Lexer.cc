#include "Lexer.hh"

Lexer::Lexer(InputBuffer& input) : input(input) {
  reserveKeywords();
}

Token* Lexer::simulateIdDFA() {
  // Implement the DFA simulation for identifiers here
  // This method should return a Token object representing the identifier
}

Token* Lexer::simulateNumDFA() {
  // Implement the DFA simulation for numbers here
  // This method should return a Token object representing the number
}

Token* Lexer::simulateRelopDFA() {
  // Implement the DFA simulation for relational operators here
  // This method should return a Token object representing the relational operator
}

void Lexer::reserveKeywords() {
  symbolTable["if"] = new Word("IF", "if");
  symbolTable["else"] = new Word("ELSE", "else");
  symbolTable["return"] = new Word("RETURN", "return");
}

void Lexer::scan() {
  while(true) {
    input.skipWhitespace();
    
    char ch = input.peekChar();
  
    if (ch == '\0') {
      break; // end of file
    }
  
    Token* token = nullptr;
  
    if (isalpha(ch)) {
      token = simulateIdDFA();
    } else if (isdigit(ch)) {
      token = simulateNumDFA();
    } else if (ch == '>' || ch == '<' || ch == '=' || ch == '>=' || ch == '<=' || ch == '!=') {
      token = simulateRelopDFA();
    } else {
      // Handle other characters or errors
    }
  
    if (token != nullptr) {
      tokens.push_back(token);
    }
  }
}

std::vector<Token*> Lexer::getTokens() const {
  return tokens;
}

void Lexer::printSymbolTable() {
  std::cout << "Symbol Table:" << std::endl;
  for (const auto& pair : symbolTable) {
    std::cout << pair.first << ": " << pair.second->getLexeme() << std::endl;
  }
}
