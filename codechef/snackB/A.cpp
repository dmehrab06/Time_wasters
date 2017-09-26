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
using namespace std;
using namespace __gnu_pbds;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction


typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

int available1[103];
int available2[103];
int moneaten1[103];
int moneaten2[103];
int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int mon=0;
        int snak=0;
        memset(available1,0,sizeof(available1));
        memset(available2,0,sizeof(available2));
        memset(moneaten1,0,sizeof(moneaten1));
        memset(moneaten2,0,sizeof(moneaten2));
        FREP(i,0,s.size()-1){
            if(s[i]=='s'){
                available1[i]=1;
                available2[i]=1;
            }
            if(s[i]=='s')snak++;
            if(s[i]=='m')mon++;
        }
        int eaten1=0;
        FREP(i,0,s.size()-2){
            if(s[i]=='m' && s[i+1]=='s' && available1[i+1]==1 && moneaten1[i]==0){
               // cout<<"paisi\n";
                moneaten1[i]=1;
                eaten1++;
                available1[i+1]=0;
            }
        }
        RFREP(i,s.size()-1,1){
            if(s[i]=='m' && s[i-1]=='s' && available1[i-1]==1 && moneaten1[i]==0){
                moneaten1[i]=1;
                eaten1++;
                available1[i-1]=0;
            }
        }
       // cout<<eaten1<<"\n";
        int eaten2=0;
        FREP(i,0,s.size()-2){
            if(s[i]=='m' && s[i+1]=='s' && available2[i+1]==1 && moneaten2[i]==0){
                moneaten2[i]=1;
                eaten2++;
                available2[i+1]=0;
            }
        }
        RFREP(i,s.size()-1,1){
            if(s[i]=='m' && s[i-1]=='s' && available2[i-1]==1 && moneaten2[i]==0){
                moneaten2[i]=1;
                eaten2++;
                available2[i-1]=0;
            }
        }
        //cout<<eaten2<<"\n";
        snak-=max(eaten1,eaten2);
        if(snak==mon){
            cout<<"tie\n";
        }
        else if(snak>mon){
            cout<<"snakes\n";
        }
        else{
            cout<<"mongooses\n";
        }
    }
    return 0;
}
