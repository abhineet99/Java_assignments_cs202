all: output

output: main.o item.o locator.o
	g++ main.o item.o  locator.o -o  output

untitled.o: main.cpp
	g++ -c main.cpp

locator.o: locator.cpp
	g++ -c locator.cpp

item.o: item.cpp
	g++ -c item.cpp



# groc_manage.o: groc_manage.cpp
# 	g++ -c groc_manage.cpp

clean:
	rm *o output
