#include <bits/stdc++.h>
#define MIN(X,Y) X<Y?X:Y
#define MAX(X,Y) X>Y?X:Y
#define ISNUM(a) ('0'<=(a) && (a)<='9')
#define ISCAP(a) ('A'<=(a) && (a)<='Z')
#define ISSML(a) ('a'<=(a) && (a)<='z')
#define ISALP(a) (ISCAP(a) || ISSML(a))
#define MXX 10000000000
#define MNN -MXX
#define ISVALID(X,Y,N,M) ((X)>=1 && (X)<=(N) && (Y)>=1 && (Y)<=(M))
#define LLI long long int
#define VI vector<int>
#define VLLI vector<long long int>
#define MII map<int,int>
#define SI set<int>
#define MSI map<string,int>
#define PII pair<int,int>
using namespace std;
char hh[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
string dtoh(int a){
    string name="";
    name+=hh[a/16];
    name+=hh[a%16];
    return name;
}
int arr[101];
void init(){
    for(int i=1;i<=100;++i){
        arr[i]=0;
    }
}
char command[100005];
int main(){
    int t;
    scanf("%d",&t);
    int cs=1;
    while(t--){
        init();
        scanf("%s",command);
        int l=strlen(command);
        int curp=1;
        for(int i=0;i<l;++i){
            if(command[i]=='+'){
                arr[curp]++;
                if(arr[curp]==256){
                    arr[curp]=0;
                }
            }
            else if(command[i]=='-'){
                arr[curp]--;
                if(arr[curp]<0){
                    arr[curp]=255;
                }
            }
            else if(command[i]=='>'){
                curp++;

                if(curp>100){
                    curp=1;
                }
            }
            else if(command[i]=='<'){
                curp--;

                if(curp<1){
                    curp=100;
                }
            }
        }
        cout<<"Case "<<cs++<<":";
        for(int i=1;i<=100;++i){
            cout<<" "<<dtoh(arr[i]);
        }
        cout<<"\n";
    }
    return 0;
}
