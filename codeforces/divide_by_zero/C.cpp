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

int freq[1055];
int freqcpy[1055];

void solve(int x){
    int lessthan=0;
    memset(freqcpy,0,sizeof(freqcpy));
    FREP(i,0,1044){
        freqcpy[i]=freq[i];
    }
    FREP(i,0,1044){
        int curfreq=freq[i];
       // if(curfreq==0)continue;
        //cout<<"at i: "<<i<<"\n";
        if(lessthan%2==0){
            //cout<<"odd position e\n";
            //odd position e ache
            int willupdate=curfreq/2+curfreq%2;
            //cout<<" update hobe "<<willupdate<<"\n";
            int updval=i^x;
            //cout<<"update hoye hobe: "<<updval<<"\n";
            freqcpy[i]-=willupdate;
            freqcpy[updval]+=willupdate;

            //cout<<"puran freq: "<<freqcpy[i]<<" notun freq: "<<freqcpy[updval]<<"\n";
        }
        else{
            //even position e ache
            //cout<<"even position e\n";
            //odd position e ache
            int willupdate=curfreq/2;
            //cout<<" update hobe "<<willupdate<<"\n";
            int updval=i^x;
            //cout<<"update hoye hobe: "<<updval<<"\n";
            freqcpy[i]-=willupdate;
            freqcpy[updval]+=willupdate;

            //cout<<"puran freq: "<<freqcpy[i]<<" notun freq: "<<freqcpy[updval]<<"\n";
        }
        lessthan+=curfreq;
    }
    /*FREP(i,0,20){
        cout<<freqcpy[i]<<" ";
    }
    cout<<"\n";*/
    FREP(i,0,1044){
        freq[i]=freqcpy[i];
    }
}

int main(){
    int n,k,x;
   // memset(freq,0,sizeof(freq));
    scanf("%d %d %d",&n,&k,&x);
    FREP(i,1,n){
        int a;
        scanf("%d",&a);
        freq[a]++;
    }
    FREP(i,1,k){
        solve(x);
    }
    int mnn=-1;
    FREP(i,0,1044){
        if(freq[i]>0){
            mnn=i;
            break;
        }
    }
    int mxx=-1;
    RFREP(i,1044,0){
        if(freq[i]>0){
            mxx=i;
            break;
        }
    }
    printf("%d %d\n",mxx,mnn);
    return 0;
}
