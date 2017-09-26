#include <bits/stdc++.h>
#define MIN(X,Y) X<Y?X:Y
#define MAX(X,Y) X>Y?X:Y
#define ISNUM(a) ('0'<=(a) && (a)<='9')
#define ISCAP(a) ('A'<=(a) && (a)<='Z')
#define ISSML(a) ('a'<=(a) && (a)<='z')
#define ISALP(a) (ISCAP(a) || ISSML(a))
#define MXX 100000000000000000
#define MNN -MXX
#define VALID(X,Y,N,M) ((X)>=1 && (X)<=(N) && (Y)>=1 && (Y)<=(M))
#define LLI long long int
#define VI vector<int>
#define VLLI vector<long long int>
#define MII map<int,int>
#define SI set<int>
#define PB push_back
#define MSI map<string,int>
#define PII pair<int,int>
#define FREP(i,I,N) for(int (i)=(I);(i)<=(N);(i)++)
#define eps 0.0000000001
#define RFREP(i,N,I) for(int (i)=(N);(i)>=(I);(i)--)
#define pi acos(-1.0)
#define float double
#define MAXMOD 100000000
using namespace std;

//vector< map<LLI,LLI> >theset;
vector<int>setsize;
void init(){
    int mx=(1<<18);
  //  map<LLI,LLI> line;
    FREP(i,0,mx+2){
        setsize.PB(0);
    }
}

int getbinpattern(LLI ans){
    VI just;
    while(ans){
        just.PB(ans%2);
        ans/=10;
    }
    int l= just.size();
    int s=0;
    RFREP(i,(l-1),0){
        s=s*2+just[i];
    }
    return s;
}

int getbin(string just){
    int l= just.size();
    int s=0;
    FREP(i,0,(l-1)){
        s=s*2+just[i]-'0';
    }
    return s;
}

string op;
string pattern;
int main(){
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    init();
    LLI num;
    FREP(i,1,n){
       // LLI num;
        cin>>op;
        //int bit=getbinpattern(num);
        //setsize[bit]++;
        if(op[0]=='+'){
            cin>>num;
            int bit=getbinpattern(num);
            //cout<<bit<<"\n";
            setsize[bit]++;
        }
        else if(op[0]=='-'){
            cin>>num;
            int bit=getbinpattern(num);
          //  cout<<bit<<"\n";
            setsize[bit]--;
        }
        else{
            cin>>pattern;
            int bit=getbin(pattern);
        //    cout<<bit<<"\n";
            cout<<setsize[bit]<<"\n";
        }

    }
    return 0;
}
