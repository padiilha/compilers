#ifndef INPUTBUFFER_HH
#define INPUTBUFFER_HH

#include <string>

class InputBuffer {
  protected:
    std::string data;
    int position;
    int rowNumber;
    int colNumber;
  public:
    InputBuffer(const std::string& data);
    char getChar();
    char peekChar() const;
    void skipWhitespace();
    int getRowNumber() const;
    int getColNumber() const;
};

#endif