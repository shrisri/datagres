#include "cstdio"
#include "iostream"
#include "cstdlib"
#include "fstream"
#include "cstring"

using namespace std;

int main(int argc,char *argv[]){
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
        srand(time(0));
        int i=0;

        while (i<=200){
            int num=rand() % 69 + 32;
            int offset=rand() % 1073741825;
            int rsize=rand() % 20 + 1;
            if (char(num)=='\\' || char(num)==' ' || char(num)=='?'){
                continue;
            }
            char rstr[25]="";
            for (int j=0;j<rsize;j++){
                rstr[j]=char(num);
            }
            fp.seekp(offset,std::ios::beg);
            int act=fp.tellp();
            fp<<rstr;
            fp2<<rstr[0]<<" "<<rsize<<" "<<act<<'\n';
            i++;
        
        }
        fp.close();
        fp2.close();

   //Verification Code
   std::fstream result;
   result.open("results3.txt",std::ios::out);
   fp.open(argv[k],std::ios::in);
   fp2.open("newfile2.txt",std::ios::in);
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
        string file2(argv[k]);
        string first="./test3.sh newfile2.txt";
        system((first + " " + file2).c_str());
        first="./test4.sh newfile2.txt";
        system((first + " " + file2).c_str());
        
        fp2.close();
        fp.close();
    }
}


