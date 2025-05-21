CXX = g++
CXXFLAGS = -Wall -std=c++17
OBJ = main.o ErrorToken.o Lexer.o Token.o InputBuffer.o
DEPS = ErrorToken.hh Lexer.hh Token.hh InputBuffer.hh

TARGET = lexer

%.o: %.cc $(DEPS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -f *.o $(TARGET)
