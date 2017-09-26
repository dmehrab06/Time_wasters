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

int place[26][1005];
int startfrom[26];

int cnt[26];

char str[1005];

char need[1005];

bool issmall(string cur, string mn){
    int l=mn.size();
    FREP(i,0,(l-1)){
        if(cur[i]<mn[i])return true;
    }
    return false;
}

int sim(int l){
    int did=0;
    FREP(i,0,(l-1)){
        if(str[i]==need[i])continue;
        int nxtneed=need[i]-'a';
        int ase=place[nxtneed][0];
        int f=0;
        string mnstr="";
        int mnidx=-1;
        FREP(j,startfrom[nxtneed],ase){
            if(place[nxtneed][j]<=i){
                startfrom[nxtneed]++;
                continue;
            }
            int foundat=place[nxtneed][j];
            cout<<"found at "<<foundat<<"\n";
            string curstr="";
            FREP(k,foundat+1,(l-1)){
                curstr.PB(str[k]);
            }
            FREP(k,i,(foundat-1)){
                curstr.PB(str[k]);
            }
            if(!f){
                mnstr=curstr;
                mnidx=foundat;
                f=1;
            }
            else{
                if(issmall(curstr,mnstr)){
                    mnstr=curstr;
                    mnidx=foundat;
                }
            }
            cout<<mnstr<<"\n";
        }
        did++;
        string age="";
        string pore="";
        FREP(k,mnidx+1,(l-1)){
                pore.PB(str[k]);
        }
        FREP(k,i,(mnidx-1)){
            age.PB(str[k]);
        }
        str[i]=need[i];
        int lpore=pore.size();
        int lst=i;
        FREP(k,0,lpore-1){
            str[i+k+1]=pore[k];
            lst=i+k+1;
        }
        int lage=age.size();
        FREP(k,0,lage-1){
            str[lst+k+1]=pore[k];
        }
        FREP(j,0,(l-1)){
            cout<<str[i];
        }
        cout<<"\n";
    }
    return did;
}

void init(){
    FREP(i,0,25){
        place[i][0]=0;
        cnt[i]=0;
        startfrom[i]=1;
    }
}

void placechars(int l){
    FREP(i,0,(l-1)){
        int idx=str[i]-'a';
        place[idx][place[idx][0]+1]=i;
        place[idx][0]++;
        cnt[idx]++;
    }
    string s="";
    FREP(i,0,25){
        FREP(j,1,cnt[i]){
            s.push_back(i+'a');
        }
    }
    FREP(i,0,(l-1)){
        need[i]=s[i];
    }
}

int main(){
    int g;
    scanf("%d",&g);
    while(g--){
        init();
        scanf("%s",str);
        int l=strlen(str);
        init();
        placechars(l);
        int ans=sim(l);
        printf("%d\n",ans);
    }
    return 0;

}
