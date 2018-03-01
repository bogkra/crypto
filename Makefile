CXX=g++
CFLAGS=--std=c++11  -Wall -Wextra -Wpedantic -Iincludes

crypto: *.cpp *.hpp
	$(CXX) main.cpp crypto.cpp -o $@ $(CFLAGS)

clean:
	rm crypto
