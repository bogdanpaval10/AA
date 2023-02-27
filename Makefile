CC = g++
CFLAGS = -Wall -Wextra -O2

build: solovay_test.o lucas_test.o

run-best:
	./test_sol

run-p1:
	./test_sol

run-p2:
	./test_lucas

run_test:
	./test_main_solovay
	./test_main_lucas

solovay.o: solovay.cpp
	g++ solovay.cpp -c $(CFLAGS)

solovay_test.o: main_solovay.cpp solovay.o
	g++ solovay.o main_solovay.cpp -o test_sol $(CFLAGS)

lucas.o: lucas.cpp
	g++ lucas.cpp -c $(CFLAGS)

lucas_test.o: main_lucas.cpp lucas.o
	g++ lucas.o main_lucas.cpp -o test_lucas $(CFLAGS)

.PHONY: clean
clean:
	rm -rf *.o
	rm -rf test_sol
	rm -rf test_lucas
	rm -rf test_main_solovay
	rm -rf test_main_lucas
	rm -rf test.in
	rm -rf test.out

