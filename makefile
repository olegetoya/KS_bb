all: knapsack

knapsack: main.o KS_Parser.o KS_Solver.o
	g++ -o knapsack main.o KS_Parser.o KS_Solver.o

main.o: main.cpp
	g++ -c main.cpp

KS_Parser.o: KS_Parser.cpp KS_Parser.h
	g++ -c KS_Parser.cpp

KS_Solver.o: KS_Solver.cpp KS_Solver.h
	g++ -c KS_Solver.cpp

clean:
	rm -f knapsack *.o
