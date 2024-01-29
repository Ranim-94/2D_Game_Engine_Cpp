build:
	g++ -Wall -std=c++17 src/*.cpp -lSDL2 -o output

run:
	./output

clean:
	rm output