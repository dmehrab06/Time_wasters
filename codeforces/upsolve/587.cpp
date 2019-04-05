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

stack<PII>comments;

vector<string>comms;
VI childs;

vector< vector <string> >lvl;

void init(){
    vector<string>line;
    FREP(i,0,500000)lvl.PB(line);
}

char str[1000006];

void parse(){
    int l=strlen(str);
    str[l]=',';
    int gotcomma=0;
    int nwnum=0;
    string nwbuf="";
    FREP(i,0,l){
        if(str[i]==','){
            gotcomma++;
            if(gotcomma%2){
                comms.PB(nwbuf);
            }
            else{
                childs.PB(nwnum);
            }
            nwnum=0;
            nwbuf="";
        }
        else{
            nwbuf.PB(str[i]);
            nwnum=nwnum*10+str[i]-'0';
        }
    }
}

int main(){
    scanf("%s",str);
    init();
    parse();
    int l=comms.size();
    comments.push(make_pair(-1,-1));
    int stcksize=0;
    int mxx=0;
    FREP(i,0,(l-1)){
        PII tp=comments.top();
        if(tp.first>0){
            comments.pop();
            tp.first--;
            comments.push(tp);
        }
        comments.push(make_pair(childs[i],i));
        stcksize++;
        while(comments.top().first==0){
            lvl[stcksize].PB(comms[comments.top().second]);
            mxx=max(stcksize,mxx);
            comments.pop();
            stcksize--;
        }
    }
    printf("%d\n",mxx);
    FREP(i,1,mxx){
        int l=lvl[i].size();
        FREP(j,0,l-1){
            cout<<lvl[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}

