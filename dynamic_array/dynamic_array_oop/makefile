main.exe:DynamicArray.o main.o
	g++ -o main.exe DynamicArray.o main.o
DynamicArray.o:DynamicArray.cpp DynamicArray.h
	g++ -c DynamicArray.cpp DynamicArray.h
main.o:main.cpp
	g++ -c main.cpp
clean:
	rm main.exe main.o DynamicArray.o DynamicArray.h.gch