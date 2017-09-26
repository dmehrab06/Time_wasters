#include <bits/stdc++.h>
#define FILL(x,y) memset(x,y,sizeof(x))
#define MX 5000005
#define NND (ND<<1)
#define MID (BEG+END)/2
using namespace std;

int open[MX],clos[MX],cnt[MX];
string s;
class info{
    public:
    int open,clos,cnt;
    info(int X=0,int Y=0,int Z=0):open(X),clos(Y),cnt(Z){
    }
};
void init(int ND,int BEG,int END){
    if(BEG==END){
        s[BEG]=='O'?open[ND]++:clos[ND]++;
        return;
    }
    init(NND,BEG,MID);
    init(NND+1,MID+1,END);
    int minc=min(open[NND],clos[NND+1]);
    cnt[ND]=cnt[NND]+cnt[NND+1]+2*minc;
    open[ND]=open[NND]+open[NND+1]-minc;
    clos[ND]=clos[NND]+clos[NND+1]-minc;
}
void update(int ND,int BEG,int END, int i){
    if(BEG==END && BEG==i){
        if(s[BEG]=='O'){clos[ND]=1;open[ND]=0;s[BEG]='C';}
        else{clos[ND]=0;open[ND]=1;s[BEG]='O';}
        return;
    }
    if(BEG>i || END<i)return;
    update(NND,BEG,MID,i);
    update(NND+1,MID+1,END,i);
    int minc=min(open[NND],clos[NND+1]);
    cnt[ND]=cnt[NND]+cnt[NND+1]+2*minc;
    open[ND]=open[NND]+open[NND+1]-minc;
    clos[ND]=clos[NND]+clos[NND+1]-minc;
}
info q(int ND,int BEG,int END,int L,int R){

    info a1,a2;
    if(END<L or BEG>R){
        return info(0,0,0);
    }
    if(L<=BEG and END<=R){
        return (info(open[ND],clos[ND],cnt[ND]));
    }
    a1=q(NND,BEG,MID,L,R);
    a2=q(NND+1,MID+1,END,L,R);
    int minc=min(a1.open,a2.clos);

    return info(a1.open+a2.open-minc,a1.clos+a2.clos-minc,
                            a1.cnt+a2.cnt+2*minc);
}
int main(){
    cin>>s;
    init(1,0,(int)s.length()-1);
    int m,l,r;cin>>m;
    while(m--){
        string qq;
        cin>>qq;
        if(qq[0]=='Q'){
            cin>>l>>r;
            cout<<q(1,0,s.length()-1,l-1,r-1).cnt<<"\n";
        }
        else{
            int i;
            cin>>i;
            update(1,0,s.length()-1,i-1);
        }
    }
    return 0;
}
