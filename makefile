build:
	g++ -std=c++11 ./src/*.cpp  -Wall -o main

run:
	./main

clean:
	rm main
