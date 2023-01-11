build:
	g++ -std=c++17 ./src/*.cpp  -Wall -o ./main.o

run:
	./main.o

clean:
	rm main.o
