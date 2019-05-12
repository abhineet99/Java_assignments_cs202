all: output

output: main.o entry.o 
	g++ main.o entry.o  -o  output

untitled.o: main.cpp
	g++ -c main.cpp


entry.o: entry.cpp
	g++ -c entry.cpp



# groc_manage.o: groc_manage.cpp
# 	g++ -c groc_manage.cpp

clean:
	rm *o output
