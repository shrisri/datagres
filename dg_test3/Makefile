CC=gcc

#all:test1 test2 test3 test4
 
Program1: ./Cprograms/Program1.c
	$(CC) ./Cprograms/Program1.c -o Program1
	#./test1
Program2: Program1 ./Cprograms/Program2.c
	$(CC) ./Cprograms/Program2.c -o Program2
	#./test2
Program3: Program1 ./shellscrpt/Program3.sh
	#./test3.sh
Program4: Program1 ./shellscrpt/Program4.sh
	#./test4.sh
Program5: ./shellscrpt/Program5.sh

clean:
	rm Program1 Program2 newfile2.txt results.txt results2.txt results3.txt totalres.txt a.out


