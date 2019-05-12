all: output

output: main.o entry.o htable.o
	g++ main.o entry.o  htable.o -o  output

untitled.o: main.cpp
	g++ -c main.cpp

htable.o: htable.cpp
	g++ -c htable.cpp

entry.o: entry.cpp
	g++ -c entry.cpp



# groc_manage.o: groc_manage.cpp
# 	g++ -c groc_manage.cpp

clean:
	rm *o output
