all: RandNum.c
	gcc -o "randTest" RandNum.c

run: all
	./randTest

clean:
	rm randTest
	rm rand_out
