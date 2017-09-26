/*-------property of the half blood prince-----*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
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

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction


typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;


using namespace std;

char str[1000005];
int seq[1000005];
int seq1[1000005];
int seq2[1000005];
int changed[1000005];
map<int,int>rangefreq;
int rangesize;
int mxfreq;

PII ranges[1000005];

void init(){
    rangefreq.clear();
    rangesize=0;
    mxfreq=0;
}

void changeseq(int l, int r, int val){
    if((r-l+1)<=2)return;
    int mid=(l+r)/2;
    seq[mid]=val;
    changed[mid]=1;
    changeseq(l,mid-1,val);
    changeseq(mid+1,r,val);
}

void calcranges(int l){
    int cur=0; int start=0;
    while(start<l){
        if(cur>=l || seq[cur]!=seq[start]){
            PII oka = make_pair(start,cur-1);
            ranges[rangesize++]=oka;
            rangefreq[-(cur-start)]++;
            mxfreq=max(mxfreq,cur-start);
            start=cur;
        }
        else{
            cur++;
        }
    }
}

pair<PII,PII> calcmin(int l){
    int freq1=0, freq2=0;
    int kk1=0; int kk2=0;
    FREP(i,0,(l-1)){
        if(seq1[i]!=seq[i]){
            if(!changed[i]){
                freq1++;
            }
            else{
                kk1++;
            }
        }
        if(seq2[i]!=seq[i]){
            if(!changed[i]){
                freq2++;
            }
            else{
                kk2++;
            }
        }
    }
    return make_pair(make_pair(freq1,kk1),make_pair(freq2,kk2));
}

void calc(int l, int k){
    int ans=-1;
    calcranges(l);
    map<int,int>::iterator it;
    for(it=rangefreq.begin();it!=rangefreq.end();++it){
        int i=-(it->first);
        int val=it->second;
        //cout<<i<<" "<<val<<"\n";
        if(i<3){
            break;
        }
        if(k<val){
            ans=i;
            break;
        }
        else{
            k-=val;
            int lr,rr;
            if(i%2==0){
                lr=i/2-1; rr=i/2;
            }
            else{
                lr=i/2; rr=lr;
            }
            rangefreq[-lr]+=val;
            rangefreq[-rr]+=val;
        }
    }
    if(ans==-1){

        FREP(i,0,(rangesize-1)){
            int ll=ranges[i].first;
            int rr=ranges[i].second;
            //cout<<ll<<" "<<rr<<"\n";
            changeseq(ll,rr,1-seq[ll]);
        }
        /*cout<<"after changin sequence is\n";
        FREP(i,0,(l-1)){
            cout<<seq[i];
        }
        cout<<"\n";*/
        pair<PII,PII>oka=calcmin(l);
        int k1=k+oka.first.second;
        int f1=oka.first.first;
        int k2=k+oka.second.second;
        int f2=oka.second.first;
        if(k1>=f1 || k2>=f2){
            printf("1\n");
        }
        else{
            printf("2\n");
        }
    }
    else{
        printf("%d\n",ans);
    }
}

void GO(){
    int n,k;
    scanf("%d %d",&n,&k);
    scanf("%s",str);
    FREP(i,0,(n-1)){
        seq[i]=str[i]-'0';
        changed[i]=0;
    }
    calc(n,k);
}

int main(){
    seq1[0]=0;
    seq2[0]=1;
    FREP(i,1,1000003){

        seq1[i]=1-seq1[i-1];
        seq2[i]=1-seq2[i-1];
    }
    int t;
    scanf("%d",&t);
    while(t--){
        init();
        GO();
    }
    return 0;
}
