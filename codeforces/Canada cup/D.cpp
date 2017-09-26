/*-------property of the half blood prince-----*/

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

set<PLLI>balloon;

set< pair<PLLI,PLLI> >mymul;

int main(){
    int n;
    scanf("%d",&n);
    LLI limakbal,limakwt;
    //scanf("%lld %lld",&limakbal,&limakwt);
    cin>>limakbal>>limakwt;
    FREP(i,2,n){
        LLI b,w;
        cin>>b>>w;
        if(b>limakbal){
            pair<PLLI,PLLI>oka=make_pair(make_pair((w-b),b),make_pair(i,w));
            mymul.insert(oka);
        }
        balloon.insert(make_pair(b,i));
    }
    set<PLLI>::iterator it;set<PLLI>::iterator it2=balloon.begin();
    set< pair<PLLI,PLLI> >::iterator itt;
    LLI cur=limakbal;
    int bestpos=3000000;
    int mxx=300000000;
    int mnn=-1;
    FREP(i,1,(n+4)){
        it=balloon.lower_bound(make_pair(cur,(LLI)mxx));
        //int pos=it-it2;
        cout<<distance(it2,it)<<"\n";
        itt=mymul.begin();
        pair<PLLI,PLLI>oka=*itt;
        LLI togive=oka.first.first+1;
        if(cur<togive)break;
        cur-=togive;
        int id=oka.second.first;
        int chilo=oka.first.second;
        PLLI khujo=make_pair(chilo,id);
        balloon.erase(khujo);
    }
    cout<<bestpos<<"\n";
    return 0;
}
