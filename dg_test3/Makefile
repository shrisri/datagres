CC=gcc

all:Program1 Program2 Program3 Program4 Program5
 
Program1: ./Cprograms/program1.c
	$(CC) ./Cprograms/program1.c -o Program1
Program2: Program1 ./Cprograms/program2.c
	$(CC) ./Cprograms/program2.c -o Program2
Program3: Program1 ./shellscrpt/program3.sh

Program4: Program1 ./shellscrpt/program4.sh

Program5: ./shellscrpt/program5.sh

clean:
	rm -f Program1 Program2 newfile2.txt results.txt results2.txt results3.txt totalres.txt a.out


