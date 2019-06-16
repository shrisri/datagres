#include "cstdio"
#include "iostream"
#include "cstdlib"
#include "fstream"
#include "cstring"

using namespace std;

int main(){
        std::fstream fp;
        std::fstream fp2;
        fp.open("newfile.txt",std::ios::out);
        fp2.open("newfile2.txt",std::ios::out);
        srand(time(0));
        int i=0;
        while (i<=200){
            int num=rand() % 69 + 32;
            int offset=rand() % 1073741825;
            int rsize=rand() % 20 + 1;
            if (char(num)=='\\' || char(num)==' ' || char(num)=='?'){
                continue;
            }
            //cout<<char(num)<<" "<<offset<<" "<<rsize<<'\n';
            char rstr[25]="";
            for (int j=0;j<rsize;j++){
                rstr[j]=char(num);
            }
            fp.seekp(offset,std::ios::beg);
            int act=fp.tellp();
            //cout<<curr<<" "<<offset<<" "<<rstr<<" "<<act<<" "<<rsize<<'\n';
            fp<<rstr;
            fp2<<rstr[0]<<" "<<rsize<<" "<<act<<'\n';
            i++;
        
        }
        
        fp.close();
}


