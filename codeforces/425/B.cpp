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
#define MAXLOG 40
#define MP make_pair
using namespace std;
using namespace __gnu_pbds;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction


//typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

int good[26];

string pattern;
string qq;

bool matchforfirstpos(){
    int qlen = qq.size();
    int patlen = pattern.size();
    if(qlen<(patlen-1))return false;
    int qpt = qlen-1;
    int patpt = patlen-1;
    while(patpt>0){
        if(pattern[patpt]=='?'){
            char cc = qq[qpt];
            if(!good[cc-'a'])return false;
        }
        else if(pattern[patpt]!=qq[qpt]){
            return false;
        }
        qpt--;
        patpt--;
    }
    RFREP(i,qpt,0){
        char cc = qq[qpt];
        if(good[cc-'a'])return false;
    }
    return true;
}

bool matchforlastpos(){
    int qlen = qq.size();
    int patlen = pattern.size();
    if(qlen<(patlen-1))return false;
    int qpt = 0;
    int patpt = 0;
    while(patpt<(patlen-1)){
        if(pattern[patpt]=='?'){
            char cc = qq[qpt];
            if(!good[cc-'a'])return false;
        }
        else if(pattern[patpt]!=qq[qpt]){
            return false;
        }
        qpt++;
        patpt++;
    }
    FREP(i,qpt,qlen-1){
        char cc = qq[qpt];
        if(good[cc-'a'])return false;
    }
    return true;
}

bool matchformidpos(int pos){
    int qlen = qq.size();
    int patlen = pattern.size();
    if(qlen<(patlen-1))return false;
    int qpt = 0;
    int patpt = 0;
    while(patpt<pos){
        if(pattern[patpt]=='?'){
            char cc = qq[qpt];
            if(!good[cc-'a'])return false;
        }
        else if(pattern[patpt]!=qq[qpt]){
            return false;
        }
        qpt++;
        patpt++;
    }
    int qpt2 = qlen-1;
    int patpt2 = patlen-1;
    while(patpt2>pos){
        if(pattern[patpt2]=='?'){
            char cc = qq[qpt2];
            if(!good[cc-'a'])return false;
        }
        else if(pattern[patpt2]!=qq[qpt2]){
            return false;
        }
        qpt2--;
        patpt2--;
    }
    //cout<<qpt<<" "<<qpt2<<"\n";
    FREP(i,qpt,qpt2){
        //cout<<i<<"\n";
        char cc = qq[i];
        if(good[cc-'a'])return false;
    }
    return true;
}

int main(){
    string gd;
    cin>>gd;
    FREP(i,0,gd.size()-1){
        good[gd[i]-'a']=1;
    }
    cin>>pattern;
    int q;
    cin>>q;
    int starpos=-1;
    FREP(i,0,pattern.size()-1){
        if(pattern[i]=='*'){
            starpos = i;
        }
    }
    FREP(i,1,q){
        cin>>qq;
        bool ans;
        if(starpos==-1){
            if(pattern.size()!=qq.size())ans=false;
            else{
                int f = 1;
                FREP(i,0,pattern.size()-1){
                    if(pattern[i]=='?'){
                        char cc = qq[i];
                        if(!good[cc-'a'])f=0;
                    }
                    else if(pattern[i]!=qq[i]){
                        f=0;
                    }
                }
                if(f)ans=true;
                else ans = false;
            }
        }
        else if(pattern.size()==1){
            ans = true;
            FREP(i,0,qq.size()-1){
                if(good[qq[i]-'a'])ans=false;
            }
        }
        else if(starpos==0){
            ans = matchforfirstpos();
        }
        else if(starpos==(pattern.size()-1)){
            ans = matchforlastpos();
        }
        else{
            ans = matchformidpos(starpos);
        }
        if(ans)cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}
