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

typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

char oka[100005];
int freq[100005];

int st=0;

string tostring(int a){
    string cur="";
    while(a){
        cur.PB((a%10)+'0');
        a/=10;
    }
    reverse(cur.begin(),cur.end());
    return cur;
}

int main(){
    string a;
    cin>>a;
    char nw=a[0];
    int nwfreq=1;
    int l=a.size()-1;
    FREP(i,1,(l)){
        if(a[i]==nw){
            nwfreq++;
        }
        else{
            oka[st]=nw;
            freq[st]=nwfreq;
            nwfreq=1;
            nw=a[i];
            st++;
        }
    }
    oka[st]=nw;
    freq[st]=nwfreq;
    string res="";
    FREP(i,0,st){
        res.PB(oka[i]);
        res+=tostring(freq[i]);
    }
    cout<<res<<"\n";
    return 0;
}
