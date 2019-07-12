/*
 * Objective: Generates 200 random strings of random sizes and writes them to random offsets of file arguments  * as well as writes the metadata in the form of character,size,offset into file newfile2.txt.
 *
 * Author: Shriya S
 *
 */
 


#include "stdio.h"
#include "string.h"
#include "ctype.h"
#define GIGABYTE 1073741825
#define MAX_SIZE 20
#define MIN_NUM 32
#define MIN_SIZE 1
#define NO_DATA 200
#define RAND 69


void f1(char string[40],char size[40],char off[40],char filename[40],FILE *result,FILE *total_r){
       printf("%s %s %s %c",string,size,off,'\n'); 
           FILE *fp;
           fp=fopen(filename,"r");
           int o;
           int s;
           // Convert offset and size from string to integer
           sscanf(off,"%d",&o);
           sscanf(size,"%d",&s);

           // Seeking offset in argv[k]
           fseek(fp,o,SEEK_SET);
           int flag=1;
           int k;
           for (k=0;k<s;k++){
                char ch;
                // Reading a character from argv[k]
                ch=fgetc(fp);
                if (ch!=string[0]){
                      fprintf(total_r,"%s %s %c",filename,"Failure",'\n');
                      fprintf(result,"%s %c","Failure",'\n');

                      flag=0;
                      break;
                }
           }
           if (flag==1){
                printf("%s","Success");
                fprintf(result,"%s %c","Success",'\n');

           }
}
                     
// Passing arguments
int main(int argc,char *argv[]){
    //Opening file to record which files have failures
    FILE *total_r;
    total_r=fopen("totalres.txt","w+");
    int k;
   
    for (k=1;k<argc;k++){
        char f[40];
        strcpy(f,argv[k]);
        printf("%s",f);
        FILE *fp2;
        FILE *fp;
        fp=fopen(argv[k],"w+");
        fp2=fopen("newfile2.txt","w+");
        // srand() function ensures different random offsets are generated each time.
        srand(time(0));
        int i=0;

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
            // Seeking random offset in one file argument.
            fseek(fp,offset,SEEK_SET);


            int act=ftell(fp);

            // Writing to one file argument.
            fputs(rstr,fp);
            fprintf(fp2,"%c %d %d %c",rstr[0],rsize,act,'\n');

            i++;
        
        }
        fclose(fp);
        fclose(fp2);


   //Verification Code

   // Opening file to write results of first verification.
   FILE *result;
   result=fopen("results3.txt","w+");

   // Opening one file argument in reading mode.
   fp=fopen(argv[k],"r");

   // Opening newfile2.txt ( metadata file ) in reading mode.
   fp2=fopen("newfile2.txt","r");

   // Looping through each line of newfile2.txt.
   char line[40];
   while (fgets(line,39,fp2)){
       // Writing into results3.txt
       fprintf(result,"%s %c",line,'\n');
       if (line[0]==' '){
           int countsp=0;
           int i=0;
           int countstr=0;
           char size[20]="";
           char off[20]="";
           char rstr[20]="";
           int si=0;
           int oi=0;
           while(line[i]==' '){
               countstr++;
               i++;
           }
           int j;
           for (j=i;j<strlen(line);j++){
               if (line[j]==' '){
                   countsp++;
               }
               if (countsp==0){
                   size[si++]=line[j];
               }else if (countsp==1){
                   off[oi++]=line[j];
               }
           }
           for (j=0;j<countstr-1;j++){
               rstr[j]=' ';
           }
           f1(rstr,size,off,f,result,total_r);
      }else{
                            
                        
           int count=0;
           char str[20]="";
           char off[20]="";
           char size[20]="";
           int wi=0;
           int wi2=0;
           int si=0;
           int i;
           for (i=0;i<strlen(line);i++){
                  if (line[i]==' '){
                         count++;
                  }
                  if (count==0){
                         str[wi++]=line[i];
                  }else if (count==2){
                         off[wi2++]=line[i];
                  }
                  else if (count==1){
                         size[si++]=line[i];
                  }
           }
           f1(str,size,off,f,result,total_r);
       }
      printf("%c %s %c",'\n',"-----------------------------------",'\n');
  }
        // Calling test3.sh and test4.sh.
        char file2[40];
        char first[40];
        strcpy(file2,argv[k]);
        strcpy(first,"./shellscrpt/test3.sh newfile2.txt");
        char prefix[40];
        sprintf(prefix,"%s %s",first,file2);
        system(prefix);
        strcpy(first,"./shellscrpt/test4.sh newfile2.txt");
        char prefix2[40];
        sprintf(prefix2,"%s %s",first,file2);
        system(prefix2);
        fclose(fp2);
        fclose(fp);
        fclose(result);
    }

}


