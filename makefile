all : simulation
	./simulation
simulation : main.o Block.h window.h
	g++ main.o -o simulation -lsfml-graphics -lsfml-window -lsfml-system
main.o : main.cpp Block.h window.h
	g++ -c main.cpp
clean :
	rm -f simulation *.o
