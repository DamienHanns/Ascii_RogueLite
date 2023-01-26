build:
	g++ -std=c++17 ./src/*.cpp  -Wall -Wextra -o ./main.o

run:
	./main.o

clean:
	rm main.o
