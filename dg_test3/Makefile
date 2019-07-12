CC=gcc

all:Program1 Program2 Program3 Program4 Program5
 
Program1: ./Cprograms/Program1.c
	$(CC) ./Cprograms/Program1.c -o Program1
Program2: Program1 ./Cprograms/Program2.c
	$(CC) ./Cprograms/Program2.c -o Program2
Program3: Program1 ./shellscrpt/Program3.sh

Program4: Program1 ./shellscrpt/Program4.sh

Program5: ./shellscrpt/Program5.sh

clean:
	rm Program1 Program2 newfile2.txt results.txt results2.txt results3.txt totalres.txt a.out


