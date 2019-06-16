CC=g++
CFLAGS=-c -Wall

all:test1 test2 test3 test4

test1: ttest.cc
	$(CC) ttest.cc -o test1
	./test1
test2: test1 test2.cc
	$(CC) test2.cc -o test2
	./test2
test3: test1 test3.sh
	./test3.sh
test4: test1 test4.sh
	./test4.sh
clean:
	rm test1 test2 newfile.txt newfile2.txt results.txt


