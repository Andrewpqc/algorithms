main.exe:LinkedList.o main.o
	g++ -o main.exe LinkedList.o main.o
LinkedList.o:LinkedList.cpp LinkedList.h
	g++ -c LinkedList.cpp LinkedList.h
main.o:main.cpp
	g++ -c main.cpp
clean:
	rm main.exe main.o LinkedList.o LinkedList.h.gch