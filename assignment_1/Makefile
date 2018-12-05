all: output

output: untitled1.o function.o item.o fruits.o vegetables.o groc_manage.o
	g++ untitled1.o function.o item.o fruits.o vegetables.o groc_manage.o -o output

untitled.o: untitled1.cpp
	g++ -c untitled1.cpp

function.o: function.cpp
	g++ -c function.cpp

item.o: item.cpp
	g++ -c item.cpp

fruits.o: fruits.cpp
	g++ -c fruits.cpp

vegetables.o: vegetables.cpp
	g++ -c vegetables.cpp

groc_manage.o: groc_manage.cpp
	g++ -c groc_manage.cpp

clean:
	rm *o output


