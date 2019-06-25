#include "cstdio"
#include "iostream"
#include "cstdlib"
#include "fstream"
#include "cstring"

#define GIGABYTE 1073741825
#define MAX_SIZE 20
#define MIN_NUM 32
#define MIN_SIZE 1

using namespace std;

int main(){
        std::fstream fp;
        std::fstream fp2;
        //Creating a file called newfile.txt to write strings at different offsets, in writing mode.
        fp.open("newfile.txt",std::ios::out);
        //Creating a file called newfile2.txt to write metadata in the form of char, size, offset.
        fp2.open("newfile2.txt",std::ios::out);
        //srand() is a function that makes sure that offset values are different each time generated.
        srand(time(0));
        int i=0;
        //Loop generates random num, offset and rsize 200 times.
        while (i<=200){
            int num=rand() % 69 + MIN_NUM;
            int offset=rand() % GIGABYTE;
            int rsize=rand() % MAX_SIZE + MIN_SIZE;
            if (char(num)=='\\' || char(num)==' ' || char(num)=='?'){
                continue;
            }
            char rstr[25]="";
            for (int j=0;j<rsize;j++){
                rstr[j]=char(num);
            }
            //seekp() seeks the random offset in newfile.txt.
            fp.seekp(offset,std::ios::beg);
            int act=fp.tellp();
            //Writing string rstr to newfile.txt.
            fp<<rstr;
            //Writing char, size, offset to newfile2.txt.
            fp2<<rstr[0]<<" "<<rsize<<" "<<act<<'\n';
            i++;
        
        }
    cout<<"Wrote 200 strings into newfile.txt at different offsets and metadata in newfile2.txt"<<'\n';
        
        fp.close();
}


