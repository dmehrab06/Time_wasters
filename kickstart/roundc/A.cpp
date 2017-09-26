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


typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

int tomake[30][30];

string enc(string given){
    string ans="";
    FREP(i,0,given.size()-1){
        ans.push_back('#');
    }
    FREP(i,1,given.size()-2){
        ans[i]=(given[i-1]-'A'+given[i+1]-'A')%26+'A';
    }
    ans[0]=given[1];
    ans[ans.size()-1]=given[given.size()-2];
    return ans;
}

string make(string decrypt, string trying){
    //trying er first ar 2nd e letter bosano ache
    FREP(i,1,decrypt.size()-2){
        int need = decrypt[i]-'A';
        int ase = trying[i-1]-'A';
        int lagbe = tomake[ase][need];
        trying[i+1]=lagbe+'A';
    }
    return trying;
}

void solve(string crypt){
    string ans="";
    FREP(i,0,crypt.size()-1){
        ans.push_back('#');
    }
    ans[1]=crypt[0];
    string oka;
    int possible = 0;
    FREP(i,0,25){
        ans[0]=i+'A';
        string gt = make(crypt,ans);
        //cout<<gt<<" "<<enc(gt)<<"\n";
        if(enc(gt)==crypt){
            possible++;
            oka = gt;
        }
    }
    if(possible>1){
        cout<<"AMBIGUOUS\n";
    }
    else if(possible==1){
        cout<<oka<<"\n";
    }
    else{
        cout<<"hoppe na\n";
    }
}

int main(){
    FREP(i,0,25){
        FREP(need,0,25){
            FREP(j,0,25){
                if((i+j)%26==need){
                    tomake[i][need]=j;
                }
            }
        }
    }
    int t;int cs=1;
    cin>>t;
    while(t--){
        string c;
        cin>>c;
        cout<<"Case #"<<cs++<<": ";
        solve(c);
    }
    return 0;
}
