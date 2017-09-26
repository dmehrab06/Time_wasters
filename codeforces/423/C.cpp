/*-------property of the half blood prince-----*/

#include <bits/stdc++.h>
#define LLI long long int
#define VI vector<int>
#define PB push_back
#define REP(i,I,N) for(int (i)=(int)(I);(i)<=(int)(N);(i)++)
using namespace std;

VI mxstr;
VI mxstrlen;

vector < string > remembered;

char finstr[2000006];

void init(){
    REP(i,1,2000006){
        mxstr.PB(-1); mxstrlen.PB(0);
    }
    REP(i,1,2000005)finstr[i]='!';
}

int getmxx(int n){
    int mxx = 0;
    REP(i,1,n){
        string st; cin>>st;
        remembered.PB(st);
        int found; cin>>found;
        int ll = st.size();
        REP(k,1,found){
            int pos; cin>>pos;
            mxx = max(mxx,pos+ll-1);
            if(mxstrlen[pos]<ll){
                mxstrlen[pos]=ll; mxstr[pos]=i;
            }
        }
    }
    return mxx;
}

void solve(int lastpos){
    int last = 0;
    REP(i,1,lastpos){
        if(mxstr[i]!=-1){
            int len = mxstrlen[i];
            int idx = mxstr[i]-1;
            int ed = i+len-1;
            if(i<=last){
                if(ed<=last){
                    continue;
                }
                else{
                    int subend = len-1;
                    for(int kk = ed;kk>last;--kk){
                        finstr[kk] = remembered[idx][subend];
                        subend--;
                    }
                }
            }
            else{
                for(int kk = i; kk<=ed;++kk)finstr[kk] = remembered[idx][kk-i];
            }
            last = max(last,ed);
        }
    }
    REP(i,1,lastpos){
        if(finstr[i]=='!'){
            finstr[i]='a';
        }
    }
    //finstr[lastpos+1]='\0';
}

int main(){
    int n;
    scanf("%d",&n); init();
    int mxx = getmxx(n);solve(mxx);
    REP(i,1,mxx) printf("%c",finstr[i]);
    printf("\n");
    return 0;
}
