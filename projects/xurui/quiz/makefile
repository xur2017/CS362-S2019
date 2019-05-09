CFLAGS = -Wall -fpic -coverage -lm -std=c99

default: randomTestResults.out

randomTestResults.out: testme.c
	echo "testme.c:" > randomTestResults.out
	gcc -o testme testme.c $(CFLAGS)
	./testme
	gcov testme.c >> randomTestResults.out

clean: 
	rm *.gcda *.gcno *.gcov testme randomTestResults.out