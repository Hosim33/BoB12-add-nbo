#Makefile
all: add-nbo

sum-test: add-nbo.cpp
	g++ -c add-nbo add-nbo.cpp

clean:
	rm -f add-nbo
	rm -f *.o
