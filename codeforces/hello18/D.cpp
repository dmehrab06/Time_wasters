/*-------property of the half blood prince-----*/

#include <bits/stdc++.h>
#include <dirent.h>
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
#define PDD pair<double,double>
#define FREP(i,I,N) for(int (i)=(int)(I);(i)<=(int)(N);(i)++)
#define eps 0.0000000001
#define RFREP(i,N,I) for(int (i)=(int)(N);(i)>=(int)(I);(i)--)
#define SORTV(VEC) sort(VEC.begin(),VEC.end())
#define SORTVCMP(VEC,cmp) sort(VEC.begin(),VEC.end(),cmp)
#define REVV(VEC) reverse(VEC.begin(),VEC.end())
#define INRANGED(val,l,r) (((l)<(val) || fabs((val)-(l))<eps) && ((val)<(r) || fabs((val)-(r))<eps))
#define INRANGEI(val,l,r) ((val)>=(l) && (val)<=(r))
#define MSET(a,b) memset(a,b,sizeof(a))
using namespace std;
using namespace __gnu_pbds;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction


//typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

vector< pair<PII,int> >questions;

void takeinp(int n){
    FREP(i,1,n){
        int mx_att,t;
        scanf("%d %d",&mx_att,&t);
        questions.PB( make_pair( make_pair(t,mx_att),i));
    }
    SORTV(questions);
}

bool can(int k, int maxT, int n){
    LLI curt = 0;
    int taken = 0;
    FREP(i,0,n-1){
        if(taken==k)return true;
        pair<PII,int> curp = questions[i];
        if((curt+curp.first.first)>maxT)break;
        if(curp.first.second>=k){
            curt+=curp.first.first;
            taken++;
        }
    }
    return (taken==k);
}

void printorder(int k, int maxT, int n){
    LLI curt = 0;
    int taken = 0;
    FREP(i,0,n-1){
        if(taken==k)return;
        pair<PII,int> curp = questions[i];
        if((curt+curp.first.first)>maxT)break;
        if(curp.first.second>=k){
            curt+=curp.first.first;
            taken++;
            printf("%d ",curp.second);
        }
    }
    printf("\n");
    //return (taken==k);
}

int binsearch(int n, int maxT){
    int lo = 0;
    int hi = n;
    while(true){
        int mid = lo+(hi-lo)/2;
        if(can(mid,maxT,n)){
            if((mid+1)<=n && can(mid+1,maxT,n)){
                lo = mid+1;
            }
            else{
                return mid;
            }
        }
        else{
            hi = mid;
        }
    }
}

int main(){
    int n,maxT;
    scanf("%d %d",&n,&maxT);
    takeinp(n);
    if(questions[0].first.first>maxT){
        cout<<"0\n0\n\n";
        return 0;
    }
    int score = binsearch(n,maxT);
    cout<<score<<"\n";
    cout<<score<<"\n";
    printorder(score,maxT,n);
    printf("\n");
    return 0;
}
