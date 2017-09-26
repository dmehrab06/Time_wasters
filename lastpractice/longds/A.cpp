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

stack<int>mys;
queue<int>myq;
priority_queue<int,vector<int>,less<int> >mypq;

void cl(){
    while(!mys.empty())mys.pop();
    while(!myq.empty())myq.pop();
    while(!mypq.empty())mypq.pop();
}

int main(){
    int n;
    while(scanf("%d",&n)==1){
        int sf = 1;
        int qf = 1;
        int pqf = 1;
        cl();
        FREP(i,1,n){
            int id;
            scanf("%d",&id);
            if(id==1){
                int elem;
                scanf("%d",&elem);
                mys.push(elem); myq.push(elem); mypq.push(elem);
            }
            else if(id==2){
                int elem;
                scanf("%d",&elem);
                int stelem = 105, qelem = 105, pqelem = 105;
                if(!mys.empty()){stelem = mys.top(); mys.pop();}
                if(!myq.empty()){qelem = myq.front(); myq.pop();}
                if(!mypq.empty()){pqelem = mypq.top(); mypq.pop();}
                //cout<<stelem<<" "<<qelem<<" "<<pqelem<<"\n";
                if(elem!=stelem)sf = 0;
                if(elem!=qelem)qf = 0;
                if(elem!=pqelem)pqf = 0;
            }
        }
        int tot = sf+qf+pqf;
        if(tot==0){
            printf("impossible\n");
        }
        else if(tot>1){
            printf("not sure\n");
        }
        else{
            if(sf){
                printf("stack\n");
            }
            else if(qf){
                printf("queue\n");
            }
            else{
                printf("priority queue\n");
            }
        }
    }
    return 0;
}
