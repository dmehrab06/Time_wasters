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

string compmove(string pre , int a){
    int cnt[26];
    FREP(i,0,25)cnt[i]=0;
    RFREP(i,pre.size()-1,pre.size()-a)cnt[pre[i]-'a']++;
    string oka="";
    int has=0; int k=0;
    while(has<a){
        if(!cnt[k]){
            oka.push_back(k+'a');
            has++;
        }
        k++;
    }
    pre+=oka;
    return pre;
}

string bmove(string pre, int b, char bchar){
    FREP(i,1,b)pre.push_back(bchar);
    return pre;
}

int getdistinct(string oka, int until, int l, int r){
    int st = until+1; int sz = oka.size();
    //cout<<st<<"\n";
    int cnt[26]; memset(cnt,0,sizeof(cnt));
    FREP(i,0,sz-1){
        if(INRANGEI(st,l,r))cnt[oka[i]-'a']++;
        st++;
    }
    int dis = 0;
    FREP(i,0,25)if(cnt[i])dis++;
    return dis;
}

int solve(int a, int b, int until, int ll, int rr){
    string pre="";
    FREP(i,1,a){
        pre.push_back((i-1)+'a');
    }
    int mnn = 1000000000;
    int mxchoice = 25;
    //int mxchoice = max(2*a-b,a+1);
    FREP(i,0,mxchoice){
        FREP(j,0,mxchoice){
            FREP(k,0,mxchoice){
                FREP(l,0,mxchoice){
                    vector<char>bschoice;
                    bschoice.push_back(i+'a');bschoice.push_back(j+'a');
                    bschoice.push_back(k+'a');bschoice.push_back(l+'a');
                    string tmp=pre;
                    FREP(bb,0,3){
                        tmp=bmove(tmp,b,bschoice[bb]);
                        tmp=compmove(tmp,a);
                    }
                    int dis = getdistinct(tmp,until,ll,rr);
                    //cout<<tmp<<" "<<dis<<"\n";
                    mnn = min(dis,mnn);
                }
            }
        }
    }
    return mnn;
}

int main(){
    int a,b,l,r;
    scanf("%d %d %d %d",&a,&b,&l,&r);
    int thresh = 2*(a+b);
    if(b>=a){
        if((r-l+1)>=thresh){
            printf("%d\n",a+1);
        }
        else{
            int before = (l-1)/thresh;
            int until = before*thresh;
            printf("%d\n",solve(a,b,until,l,r));
        }
    }
    else{
        if((r-l+1)>=thresh){
            printf("%d\n",2*a-b);
        }
        else{
            int before = (l-1)/thresh;
            int until = before*thresh;
            printf("%d\n",solve(a,b,until,l,r));
        }
    }
    return 0;
}
