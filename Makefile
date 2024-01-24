.PHONY: all clean

all:
	@g++ main.cpp -std=c++11 -o main

clean:
	@rm -f main
