#include "InputBuffer.hh"

InputBuffer::InputBuffer(const std::string& data)
  : data(data), position(0), rowNumber(1), colNumber(1) {}

char InputBuffer::getChar() {
  if (position >= data.size()) {
    return '\0'; // end of file
  }

  char ch = data[position++];

  if (ch == '\n') {
    rowNumber++;
    colNumber = 1;
  } else {
    colNumber++;
  }

  return ch;
}

char InputBuffer::peekChar() const {
  if (position >= data.size()) {
    return '\0'; // end of file
  }

  return data[position];
}

void InputBuffer::skipWhitespace() {
  while (position < data.size() && isspace(data[position])) {
    getChar();
  }
}

int InputBuffer::getRowNumber() const {
  return rowNumber;
}

int InputBuffer::getColNumber() const {
  return colNumber;
}
