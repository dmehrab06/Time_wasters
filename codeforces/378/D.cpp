/*-------property of the half blood prince-----*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
#define PB push_back
#define MSI map<string,int>
#define PII pair<int,int>
#define PLLI pair<LLI,LLI>
#define FREP(i,I,N) for(int (i)=(I);(i)<=(N);(i)++)
#define eps 0.0000000001
#define RFREP(i,N,I) for(int (i)=(N);(i)>=(I);(i)--)
#define SORTV(VEC) sort(VEC.begin(),VEC.end())
#define SORTVCMP(VEC,cmp) sort(VEC.begin(),VEC.end(),cmp)
#define REVV(VEC) reverse(VEC.begin(),VEC.end())
using namespace std;
using namespace __gnu_pbds;

vector< VI >va;
vector< VI >vb;
vector< VI >vc;

vector<pair<PII,PII>>srtva;
vector<pair<PII,PII>>srtvb;
vector<pair<PII,PII>>srtvc;

pair<int,PII> srchva(int n){
    int curl=0;
    int curr=-1;
    int mxd=-1;
    int mxchsa=-1;
    int mxchsb=-1;
    while(curr<(n-1)){
        curr++;
        if(srtva[curr].first.first==srtva[curl].first.first && srtva[curr].first.second==srtva[curl].first.second){
            //let it go, let it goooooooo
            if(curr==(n-1)){
                //hisab sesh koro
                int prevr=curr;
                if(prevr==curl){
                    //dorkar nai ei process age kora hoise
                }
                else{
                    int a=srtva[curl].first.first;
                    int b=srtva[curl].first.second;
                    int c=srtva[prevr].second.first+srtva[prevr-1].second.first;
                    int d=min(a,min(b,c));
                    if(mxd<d){
                        mxd=d;
                        mxchsa=srtva[prevr-1].second.second;
                        mxchsb=srtva[prevr].second.second;
                    }
                }
            }
        }
        else{
            int prevr=curr-1;
            if(prevr==curl){
                //dorkar nai ei process age kora hoise
            }
            else{
                int a=srtva[curl].first.first;
                int b=srtva[curl].first.second;
                int c=srtva[prevr].second.first+srtva[prevr-1].second.first;
                int d=min(a,min(b,c));
                if(mxd<d){
                    mxd=d;
                    mxchsa=srtva[prevr-1].second.second;
                    mxchsb=srtva[prevr].second.second;
                }
            }
            curl=curr;
            curr=prevr;
        }
    }
    pair<int,PII>oka=make_pair(mxd,make_pair(mxchsa,mxchsb));
    return oka;
}

pair<int,PII> srchvb(int n){
    int curl=0;
    int curr=-1;
    int mxd=-1;
    int mxchsa=-1;
    int mxchsb=-1;
    while(curr<(n-1)){
        curr++;
        if(srtvb[curr].first.first==srtvb[curl].first.first && srtvb[curr].first.second==srtvb[curl].first.second){
            //let it go, let it goooooooo
            if(curr==(n-1)){
                //hisab sesh koro
                int prevr=curr;
                if(prevr==curl){
                    //dorkar nai ei process age kora hoise
                }
                else{
                    int a=srtvb[curl].first.first;
                    int b=srtvb[curl].first.second;
                    int c=srtvb[prevr].second.first+srtvb[prevr-1].second.first;
                    int d=min(a,min(b,c));
                    if(mxd<d){
                        mxd=d;
                        mxchsa=srtvb[prevr-1].second.second;
                        mxchsb=srtvb[prevr].second.second;
                    }
                }
            }
        }
        else{
            int prevr=curr-1;
            if(prevr==curl){
                //dorkar nai ei process age kora hoise
            }
            else{
                int a=srtvb[curl].first.first;
                int b=srtvb[curl].first.second;
                int c=srtvb[prevr].second.first+srtvb[prevr-1].second.first;
                int d=min(a,min(b,c));
                if(mxd<d){
                    mxd=d;
                    mxchsa=srtvb[prevr-1].second.second;
                    mxchsb=srtvb[prevr].second.second;
                }
            }
            curl=curr;
            curr=prevr;
        }
    }
    pair<int,PII>oka=make_pair(mxd,make_pair(mxchsa,mxchsb));
    return oka;
}

pair<int,PII> srchvc(int n){
    int curl=0;
    int curr=-1;
    int mxd=-1;
    int mxchsa=-1;
    int mxchsb=-1;
    while(curr<(n-1)){
        curr++;
        if(srtvc[curr].first.first==srtvc[curl].first.first && srtvc[curr].first.second==srtvc[curl].first.second){
            //let it go, let it goooooooo
            if(curr==(n-1)){
                //hisab sesh koro
                int prevr=curr;
                if(prevr==curl){
                    //dorkar nai ei process age kora hoise
                }
                else{
                    int a=srtvc[curl].first.first;
                    int b=srtvc[curl].first.second;
                    int c=srtvc[prevr].second.first+srtvc[prevr-1].second.first;
                    int d=min(a,min(b,c));
                    if(mxd<d){
                        mxd=d;
                        mxchsa=srtvc[prevr-1].second.second;
                        mxchsb=srtvc[prevr].second.second;
                    }
                }
            }
        }
        else{
            int prevr=curr-1;
            if(prevr==curl){
                //dorkar nai ei process age kora hoise
            }
            else{
                int a=srtvc[curl].first.first;
                int b=srtvc[curl].first.second;
                int c=srtvc[prevr].second.first+srtvc[prevr-1].second.first;
                int d=min(a,min(b,c));
                if(mxd<d){
                    mxd=d;
                    mxchsa=srtvc[prevr-1].second.second;
                    mxchsb=srtvc[prevr].second.second;
                }
            }
            curl=curr;
            curr=prevr;
        }
    }
    pair<int,PII>oka=make_pair(mxd,make_pair(mxchsa,mxchsb));
    return oka;
}

int main(){
    int n;
    scanf("%d",&n);
    VI line;
    FREP(i,1,(n+3)){
        va.PB(line);
        vb.PB(line);
        vc.PB(line);
    }
    FREP(i,1,n){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        va[i].PB(a);
        va[i].PB(b);
        va[i].PB(c);
    }
    FREP(i,1,n){
        SORTV(va[i]);
    }
    FREP(i,1,n){
        vb[i].PB(va[i][0]);
        vb[i].PB(va[i][2]);
        vb[i].PB(va[i][1]);
        vc[i].PB(va[i][1]);
        vc[i].PB(va[i][2]);
        vc[i].PB(va[i][0]);
    }
    FREP(i,1,n){
        pair<PII,PII>ok1=make_pair(make_pair(va[i][0],va[i][1]),make_pair(va[i][2],i));
        pair<PII,PII>ok2=make_pair(make_pair(vb[i][0],vb[i][1]),make_pair(vb[i][2],i));
        pair<PII,PII>ok3=make_pair(make_pair(vc[i][0],vc[i][1]),make_pair(vc[i][2],i));
        srtva.PB(ok1);
        srtvb.PB(ok2);
        srtvc.PB(ok3);
    }
    SORTV(srtva);
    SORTV(srtvb);
    SORTV(srtvc);
    int mxd=-1;
    int chsa=-1;
    int nisi=1;
    int chsb=-1;
    FREP(i,1,n){
        if(va[i][0]>mxd){
            mxd=va[i][0];
            chsa=i;
        }
    }
    pair<int,PII>oka1=srchva(n);
    pair<int,PII>oka2=srchvb(n);
    pair<int,PII>oka3=srchvc(n);

    if(oka1.first>mxd){
        mxd=oka1.first;
        chsa=oka1.second.first;
        chsb=oka1.second.second;
        nisi=2;
    }
    if(oka2.first>mxd){
        mxd=oka2.first;
        chsa=oka2.second.first;
        chsb=oka2.second.second;
        nisi=2;
    }
    if(oka3.first>mxd){
        mxd=oka3.first;
        chsa=oka3.second.first;
        chsb=oka3.second.second;
        nisi=2;
    }
    printf("%d\n",nisi);
    printf("%d",chsa);
    if(nisi==2){
        printf(" %d",chsb);
    }
    printf("\n");
    return 0;
}
