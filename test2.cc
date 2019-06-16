#include "iostream"
#include "cstring"
#include "cstdio"
#include "fstream"
#include "cstdlib"

using namespace std;

int main(){
    std::fstream fp;
    std::fstream fp2;
    fp.open("newfile.txt");
    fp2.open("newfile2.txt");
    char line[40];
    while (fp2.getline(line,40,'\n')){
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
            cout<<'\n'<<rstr<<" "<<size<<" "<<off<<'\n';
            
            
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
                    cout<<"Failure";
                    flag=0;
                    break;
                }
            }
            if (flag==1)
                cout<<"Success";

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
        cout<<'\n'<<str<<" "<<size<<" "<<off<<'\n';
        
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
                    cout<<"Failure";
                    flag=0;
                    break;
                }
            }
            if (flag==1)
                cout<<"Success";
        }
        cout<<'\n'<<"-----------------------------------"<<'\n';
    }

}

