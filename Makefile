prog : src/main.cpp include/String.h src/String.cpp 
	g++ -Wall -g src/main.cpp include/String.h src/String.cpp -o prog

clean : 
	rm prog
