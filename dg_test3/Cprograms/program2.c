/*
 * Objective: Verifies that right strings are at the right offsets of file newfile.txt using c language.
 *
 * Method: Program iterates through newfile2.txt (metadata), extracts character, size, offset and then goes to
 * specific offset in newfile.txt for verification.
 * 
 * Author: Shriya S
 *
 */

#include "string.h"
#include "stdio.h"



void f1(char string[40],char size[40],char off[40],FILE *results){
    int o;
    int s;
    FILE *fp;
    sscanf(off,"%d",&o);
    sscanf(size,"%d",&s);
    fp=fopen("newfile.txt","r");
    fprintf(results,"%s %s %s %c",string,size,off,'\n');
    fseek(fp,o,SEEK_SET);
    int flag=1;
    int k;
    for (k=0;k<s;k++){
        char ch;
        ch=fgetc(fp);
        if (ch!=string[0]){
            printf("%s","Failure");
            fprintf(results,"%s %c","Failure",'\n');
            flag=0;
            break;
        }
    }
    if (flag==1){
        printf("%s","Success");
        fprintf(results,"%s %c","Success",'\n');
    }

}
int main(){
    
    FILE *fp;
    FILE *fp2;
    FILE *results;
    //Opening file which stores strings at different offsets.
    fp=fopen("newfile.txt","r");
    //Opening metadata file.
    fp2=fopen("newfile2.txt","r");

    char line[40];
    //Opening file results2.txt in writing mode to enter results after verification.
    results=fopen("results2.txt","w+");
    
    //Looping through lines of newfile2.txt.
    
    while (fgets(line,39,fp2)){
        printf("%s %c",line,'\n');
        //Exception when the random character generated in a space.
        
        if (line[0]==' '){
            int countsp=0;
            int i=0;
            int countstr=0;
            char size[20]="";
            char off[20]="";
            char rstr[20]="";
            int si=0;
            int oi=0;

            //Extracting char, size, offset from newfile2.txt
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

            printf("%c %s %s %s %c",'\n',rstr,' ',size,' ',off,'\n');
            f1(rstr,size,off,results);
       }else{

                
        int count=0;
        char str[20]="";
        char off[20]="";
        char size[20]="";
        int wi=0;
        int wi2=0;
        int si=0;
        int i;
        printf("%d %c",strlen(line),'\n');
        //Extracting char, size, offset from newfile2.txt.
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

        printf("%c %s %s %s %c",'\n',str,size,off,'\n');
        f1(str,size,off,results);
        }
        printf("%c %s %c",'\n',"-----------------------------------",'\n');
        
    }
    
printf("%s %c","Verified. Verification results in results2.txt.",'\n');
}

