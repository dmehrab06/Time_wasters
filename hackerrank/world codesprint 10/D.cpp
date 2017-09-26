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
#define FREP(i,I,N) for(int (i)=(int)(I);(i)<=(int)(N);(i)++)
#define eps 0.0000000001
#define RFREP(i,N,I) for(int (i)=(int)(N);(i)>=(int)(I);(i)--)
#define SORTV(VEC) sort(VEC.begin(),VEC.end())
#define SORTVCMP(VEC,cmp) sort(VEC.begin(),VEC.end(),cmp)
#define REVV(VEC) reverse(VEC.begin(),VEC.end())
#define INRANGED(val,l,r) (((l)<(val) || fabs((val)-(l))<eps) && ((val)<(r) || fabs((val)-(r))<eps))
#define MDD 1000000007
#define ll long long
using namespace std;
using namespace __gnu_pbds;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction


typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

int oka[100];

int cnthappy(vector<int> v){
    int sz=v.size();
    int cnt=0;
    FREP(i,0,(sz-1)){
        if((i>0 && v[i-1]>v[i]) || (i<(sz-1) && v[i+1]>v[i])){
            cnt++;
        }
    }
    oka[cnt]++;
    return cnt;
}

void print(vector<int> v){
    FREP(i,0,v.size()-1){
        cout<<v[i]<<" ";
    }
    cout<<": ";
}

int main()
 {
      typedef vector<int> V; //<or_any_class>

       // int n;
       // cin>>n;
       for(int n=1;n<=12;++n){
         memset(oka,0,sizeof(oka));
         V v;
          for(int i=1;i<=n;++i)
            v.push_back(i);
          do{
                //print(v);
                cnthappy(v);
                //if(a==(n-1))print(v);
                //cout<<"\n";
            }

           while(next_permutation(v.begin(),v.end()));

           FREP(i,1,n){
                printf("%10d",oka[i]);
            }
            cout<<"\n";
        }

 }
