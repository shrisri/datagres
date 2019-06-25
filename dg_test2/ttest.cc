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
// Passing arguments
int main(int argc,char *argv[]){
    //Opening file to record which files have failures
    std::fstream total_r;
    total_r.open("totalres.txt",std::ios::out | std::ios::in);
    for (int k=1;k<argc;k++){
        string f(argv[k]);
        std::fstream fp2;
        std::fstream fp;
        fp.open(argv[k],std::ios::in | std::ios::out);
        fp2.open("newfile2.txt",std::ios::in | std::ios::out);
        string filename(argv[k]);
        string command="touch";
        system((command + " " + filename).c_str()); 
        // srand() function ensures different random offsets are generated each time.
        srand(time(0));
        int i=0;

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
            // Seeking random offset in one file argument.
            fp.seekp(offset,std::ios::beg);

            int act=fp.tellp();
            // Writing to one file argument.
            fp<<rstr;
            // Writing to newfile2.txt ( metadata file )
            fp2<<rstr[0]<<" "<<rsize<<" "<<act<<'\n';
            i++;
        
        }
        fp.close();
        fp2.close();

   //Verification Code

   // Opening file to write results of first verification.
   std::fstream result;
   result.open("results3.txt",std::ios::out);

   // Opening one file argument in reading mode.
   fp.open(argv[k],std::ios::in);

   // Opening newfile2.txt ( metadata file ) in reading mode.
   fp2.open("newfile2.txt",std::ios::in);

   // Looping through each line of newfile2.txt.
   char line[40];
   while (fp2.getline(line,40,'\n')){
       result<<line<<'\n';
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
           for (int j=i;j<strlen(line);j++){
               if (line[j]==' '){
                   countsp++;
               }
               if (countsp==0){
                   size[si++]=line[j];
               }else if (countsp==1){
                   off[oi++]=line[j];
               }
           }
           for (int j=0;j<countstr-1;j++){
               rstr[j]=' ';
           }
           
             
           int o;
           int s;
           sscanf(off,"%d",&o);
           sscanf(size,"%d",&s);
           fp.seekg(o,std::ios::beg);
           int flag=1;
           for (int k=0;k<s;k++){
                char ch;
                fp>>ch;
                if (ch!=rstr[0]){
                      result<<"Failure"<<'\n';
                      total_r<<f<<" "<<"Failure"<<'\n';
                      flag=0;
                      break;
                }
           }
           if (flag==1){
                result<<"Success"<<'\n';
           }
                     
      }else{
                            
                        
           int count=0;
           char str[20]="";
           char off[20]="";
           char size[20]="";
           int wi=0;
           int wi2=0;
           int si=0;
           for (int i=0;i<strlen(line);i++){
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
           int o;
           int s;
           sscanf(off,"%d",&o);
           sscanf(size,"%d",&s);
           fp.seekg(o,std::ios::beg);
           int flag=1;
           for (int k=0;k<s;k++){
                 char ch;
                 fp>>ch;
                 if (ch!=str[0]){
                       result<<"Failure"<<'\n';
                       total_r<<f<<" "<<"Failure"<<'\n';
                       flag=0;
                       break;
                 }
           }
           if (flag==1){
                result<<"Success"<<'\n';
           }
       }
      result<<'\n'<<"-----------------------------------"<<'\n';
  }
        // Calling test3.sh and test4.sh.
        string file2(argv[k]);
        string first="./test3.sh newfile2.txt";
        system((first + " " + file2).c_str());
        first="./test4.sh newfile2.txt";
        system((first + " " + file2).c_str());
        
        fp2.close();
        fp.close();
    }
}


