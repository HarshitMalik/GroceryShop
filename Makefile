all: code

code: main.o main_grocery.o Items.o Fruits.o Vegetables.o
	g++ main.o main_grocery.o Items.o Fruits.o Vegetables.o -o code

main_grocery.o: main_grocery.cpp
	g++ -c main_grocery.cpp

main.o: main.cpp
	g++ -c main.cpp

Items.o: Items.cpp
	g++ -c Items.cpp

Fruits.o: Fruits.cpp
	g++ -c Fruits.cpp

Vegetables.o: Vegetables.cpp
	g++ -c Vegetables.cpp

clean:
	rm *o code
