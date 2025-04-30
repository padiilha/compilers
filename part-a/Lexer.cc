#include "Lexer.hh"

Lexer::Lexer(InputBuffer& input) : input(input) {
  reserveKeywords();
}

// AFD baseado no exemplo do livro base da disciplina, apresentado no slide
Token* Lexer::simulateRelopDFA() {
  int state = 0;
  bool accepts = false;
  Token* token;
  while (true) {
    switch (state) {
      case 0:
        switch (this->ch) {
          case '<': input.getChar(); state = 1; break;
          case '=': input.getChar(); state = 5; break;
          case '>': input.getChar(); state = 6; break;
          default: break;
        }
        this->ch = input.peekChar();
        break;
      case 1:
        switch (this->ch) {
          case '=': input.getChar(); state = 2; break;
          case '>': input.getChar(); state = 3; break;
          default: state = 4; break;
        }
        this->ch = input.peekChar();
        break;
      case 6:
        switch (this->ch) {
          case '=': input.getChar(); state = 7; break;
          default: state = 8; break;
        }
        this->ch = input.peekChar();
        break;
      case 2: token = new Token("RELOP", "LE"); accepts = true; break;
      case 3: token = new Token("RELOP", "NE"); accepts = true; break;
      case 4: token = new Token("RELOP", "LT"); accepts = true; break;
      case 5: token = new Token("RELOP", "EQ"); accepts = true; break;
      case 7: token = new Token("RELOP", "GE"); accepts = true; break;
      case 8: token = new Token("RELOP", "GT"); accepts = true; break;
      default: break;
    }
    if (accepts) this->tokens.push_back(token);
  }
  return token;
}

// AFD baseado no exemplo do livro base da disciplina, apresentado no slide
Token* Lexer::simulateNumDFA() {
  int value = 0;

  do {
    value = value * 10 + (this->ch - '0');
    input.getChar();
    this->ch = input.peekChar();
  } while (isdigit(this->ch));

  Token* token = new Token("NUM", std::to_string(value));
  this->tokens.push_back(token);
  return token;
}

// AFD baseado no exemplo do livro base da disciplina, apresentado no slide
Token* Lexer::simulateIdDFA() {
  std::stringstream buffer;
  Token* token = nullptr;
  
  do {
    buffer << this->ch;
    input.getChar();
    this->ch = input.peekChar();
  } while (isalnum(this->ch));
  
  std::string lexeme = buffer.str();
  
  if (this->words.count(lexeme) > 0) {
    token = this->words[lexeme];
  } else {
    token = new Token("ID", lexeme);
    this->words[lexeme] = token;
  }

  this->tokens.push_back(token);
  
  return token;
}

Token* Lexer::simulateUnknownDFA() {
  std::string message = "Caractere inválido: " + std::string(1, this->ch);
  return new ErrorToken(message, this->input.getRowNumber(), this->input.getColNumber());
}

void Lexer::reserveKeywords() {
  Token* if_token = new Token("IF", "if");
  words["if"] = if_token;
  keywords.insert(if_token);

  Token* else_token = new Token("ELSE", "else");
  words["else"] = else_token;
  keywords.insert(else_token);


  Token* return_token = new Token("RETURN", "return");
  words["return"] = return_token;
  keywords.insert(return_token);
}

Token* Lexer::scan() {
  while (true) {
    input.skipWhitespace();
    
    char ch = input.peekChar();
  
    if (ch == EOF) break; // end of file
  
    if (ch == '>' || ch == '<' || ch == '=') {
      return simulateRelopDFA();
    } else if (isdigit(ch)) {
      return simulateNumDFA();
    } else if (isalpha(ch)) {
      return simulateIdDFA();
    } else {
      return simulateUnknownDFA();
    }
  }
  
  return nullptr;
}

std::vector<Token*> Lexer::getTokens() const {
  return tokens;
}

void Lexer::printSymbolTable() {
  std::cout << "Tabela de Símbolos:\n";
  for (const auto& pair : words) {
    if (keywords.count(pair.second) > 0) {
      std::cout << "Tipo: " << pair.second->getType() << ", Lexema: " << pair.second->getLexeme() << std::endl;
    }
  }
}
