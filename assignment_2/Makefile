all: output

output: main.o item.o fruits.o vegetables.o 
	g++ main.o item.o fruits.o vegetables.o  -o output

untitled.o: main.cpp
	g++ -c main.cpp



item.o: item.cpp
	g++ -c item.cpp

fruits.o: fruits.cpp
	g++ -c fruits.cpp

vegetables.o: vegetables.cpp
	g++ -c vegetables.cpp

# groc_manage.o: groc_manage.cpp
# 	g++ -c groc_manage.cpp

clean:
	rm *o output


