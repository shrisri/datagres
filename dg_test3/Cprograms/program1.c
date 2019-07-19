/*
 * Objective:Generates 200 random strings of random sizes and writes them to random offsets of file newfile.txt * as well as writes the metadata in the form of character,size,offset into file newfile2.txt.
 *
 * Author: Shriya S
 *
 */

#include "stdio.h"
#include "string.h"

#define GIGABYTE 1073741825
#define MAX_SIZE 20
#define MIN_NUM 32
#define MIN_SIZE 1
#define NO_DATA 200
#define RAND 69


int main(){
        
        FILE *fp;
        FILE *fp2;
        
        //Creating a file called newfile.txt to write strings at different offsets, in writing mode.
        fp=fopen("newfile.txt","w+");
        //Creating a file called newfile2.txt to write metadata in the form of char, size, offset.
        fp2=fopen("newfile2.txt","w+");
        
        //srand() is a function that makes sure that offset values are different each time generated.
        srand(time(0));
        
        int i=0;
        
        //Loop generates random num, offset and rsize 200 times.
        while (i<=NO_DATA){
            
            int num=rand() % RAND + MIN_NUM;
            int offset=rand() % GIGABYTE;
            int rsize=rand() % MAX_SIZE + MIN_SIZE;
            char ch;
            
            ch=num;
            
            
            if (ch=='\\' || ch==' ' || ch=='?'){
                continue;
            }

            char rstr[25]="";
            int j;
            for (j=0;j<rsize;j++){
                rstr[j]=ch;
            }
            printf("%s %c",rstr,'\n');
        
            //seek() seeks the random offset in newfile.txt.
            fseek(fp,offset,SEEK_SET);
            
            int act=ftell(fp);
            
            //Writing string rstr to newfile.txt.
            fputs(rstr,fp);
            
            //Writing char, size, offset to newfile2.txt.
            printf("%c %d %d %c",rstr[0],rsize,act,'\n');

            fprintf(fp2,"%c %d %d %c",rstr[0],rsize,act,'\n');

        
            i++;
            
        
        }
        printf("%s","Wrote 200 strings into newfile.txt at different offsets and metadata in newfile2.txt")<<'\n';

        // Close newfile.txt
        fclose(fp);
        
}


