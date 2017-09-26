#include <bits/stdc++.h>
#include <vector>
#define MIN(X,Y) X<Y?X:Y
#define MAX(X,Y) X>Y?X:Y
#define ISNUM(a) ('0'<=(a) && (a)<='9')
#define ISCAP(a) ('A'<=(a) && (a)<='Z')
#define ISSML(a) ('a'<=(a) && (a)<='z')
#define ISALP(a) (ISCAP(a) || ISSML(a))

using namespace std;

int SQRTVAL;
int N;

struct query{
    int l,r;
    long long int ans;
    int idx;
    query(){
        l=0;
        r=0;
        ans=0;
        idx=0;
    }
    query(int a,int b, int i){
        l=a;
        r=b;
        idx=i;
    }
};

bool mycompare(query &a, query &b){
    if(((a.l)/SQRTVAL)==((b.l)/SQRTVAL)){
        if(a.r==b.r){
            return a.l<b.l;
        }
        return a.r<b.r;
    }
    return ((a.l)/SQRTVAL)<((b.l)/SQRTVAL);
}

bool mycompare2(query &a, query &b){
    return a.idx<b.idx;
}

vector<query>allqs;

int arr[200005];

int freq[1000007];

void add(int position, long long int &curans){
    int num=arr[position];
    int prev=freq[num];
    curans-=(long long int)prev*prev*num;
    freq[num]++;
    int cur=freq[num];
    curans+=(long long int)cur*cur*num;
}

void rem(int position, long long int &curans){
    int num=arr[position];
    int prev=freq[num];
    curans-=(long long int)prev*prev*num;
    freq[num]--;
    int cur=freq[num];
    curans+=(long long int)cur*cur*num;
}

void solve(){
    int l=allqs.size();
    int currentL = 1;
    int currentR = 1;
    long long int answer = arr[1];
    for(int i=1;i<=1000000;++i){
        freq[i]=0;
    }
    freq[arr[1]]++;
    for(int i=0;i<l;++i){
        int L=allqs[i].l;
        int R=allqs[i].r;
        //cout<<"calculating query "<<L<<" "<<R<<"\n";
      // currentL should go to L, currentR should go to R
        while ((currentR+1) <= R){
            ++currentR;
            //cout<<"r is increasing from left\n";
            add(currentR,answer);
            //cout<<answer<<"\n";
            //currentR++;
        }
        while(currentR > R){
            //cout<<"r is decreasing from right\n";
            rem(currentR,answer);
            //cout<<answer<<"\n";
            currentR--;
        }

        while (currentL < L){
           // cout<<"l is increasing from left\n";
            rem(currentL,answer);
            //cout<<answer<<"\n";
            currentL++;
        }
        while ((currentL-1) >= L){
            --currentL;
            //cout<<"l is decreasing from right\n";
            add(currentL,answer);
          //  cout<<answer<<"\n";
            //currentL--;
        }

        //cout<<answer<<"\n";
        allqs[i].ans=answer;
    }
}

int main(){
    int Q;
    scanf("%d %d",&N,&Q);
    SQRTVAL=sqrt(N);
    arr[0]=0;
    for(int i=1;i<=N;++i){
        scanf("%d",&arr[i]);
    }
    for(int i=1;i<=Q;++i){
        int l,r;
        scanf("%d %d",&l,&r);
        query q(l,r,i);
        allqs.push_back(q);
    }
    sort(allqs.begin(),allqs.end(),mycompare);
    solve();
    sort(allqs.begin(),allqs.end(),mycompare2);
    int l=allqs.size();
    for(int i=0;i<l;++i){
        printf("%lld\n",allqs[i].ans);
    }
    return 0;
}
