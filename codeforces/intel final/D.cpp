/*-------property of the half blood prince-----*/

#include <bits/stdc++.h>
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
#define FREP(i,I,N) for(int (i)=(I);(i)<=(N);(i)++)
#define eps 0.0000000001
#define RFREP(i,N,I) for(int (i)=(N);(i)>=(I);(i)--)
#define SORTV(VEC) sort(VEC.begin(),VEC.end())
#define SORTVCMP(VEC,cmp) sort(VEC.begin(),VEC.end(),cmp)
#define REVV(VEC) reverse(VEC.begin(),VEC.end())
using namespace std;


int ch[100005];
PII seg[400005]; //first char value, second char pos

void init(int b, int e, int node){
    if(b==e){
        seg[node].first=ch[b];
        seg[node].second=b;
        return;
    }
    if(b>e)return;
    else{
        int lt=node<<1;
        int rt=lt+1;
        int mid=(b+e)>>1;
        init(b,mid,lt);
        init(mid+1,e,rt);
        if(seg[lt].first==seg[rt].first){
            seg[node]=seg[rt];
        }
        else if(seg[lt].first<seg[rt].first){
            seg[node]=seg[lt];
        }
        else{
            seg[node]=seg[rt];
        }
        return;
    }
}

PII query(int i, int j, int b, int e, int node){
    if(b>e)return make_pair(200,-1);
    if(b>=i && e<=j){
        return seg[node];
    }
    if(e<i || b>j){
        return make_pair(200,-1);
    }
    int lt=node<<1;
    int rt=lt+1;
    int mid=(b+e)>>1;
    PII lans=query(i,j,b,mid,lt);
    PII rans=query(i,j,mid+1,e,rt);
    if(lans.first==rans.first){
        int chos=max(lans.second,rans.second);
        return make_pair(lans.first,chos);
    }
    else if(lans.first<rans.first){
        return lans;
    }

    return rans;
}

char s[100005];
int ase[26];
int disi[26];
set<int>pos;
vector<int>ans;
int main(){
    int m;
    scanf("%d",&m);
    scanf("%s",s);
    int l=strlen(s);
    FREP(i,0,25){
        ase[i]=0;
        disi[i]=0;
    }
    FREP(i,0,(l-1)){
        ch[i+1]=s[i];
        ase[s[i]-'a']++;
    }
    init(1,l,1);
    int prevpos,preval;
    for(int i=0;(i+m-1)<l;++i){
        PII q=query(i+1,i+m,1,l,1);
        if(i>=1){
            if(q.first==preval){
                if(prevpos>=(i+1) && prevpos<=(i+m)){
                    q.second=prevpos;
                }
            }
        }
       // cout<<i+1<<" "<<i+m<<" "<<(char)q.first<<" "<<q.second<<"\n";
        pos.insert(q.second);
        prevpos=q.second;
        preval=q.first;
    }
    set<int>::iterator it;
    for(it=pos.begin();it!=pos.end();++it){
        ans.PB(ch[*it]);
    }
    sort(ans.begin(),ans.end());
    int ll=ans.size();
    //int prev;
    int mx=ans[ll-1];
    int cnt=0;
    RFREP(i,(ll-1),0){
        if(ans[i]==mx)cnt++;
        else break;
    }
    FREP(i,0,(mx-'a')-1){
        int nw=ase[i];
        FREP(j,1,nw){
            printf("%c",i+'a');
        }
    }
    FREP(i,1,cnt)printf("%c",cnt);
    printf("\n");
    return 0;
}


