build:
	g++ -std=c++11 ./src/*.cpp  -Wall -o main.o

run:
	./main.o

clean:
	rm main
