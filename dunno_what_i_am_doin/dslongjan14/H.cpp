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

stack<int>setstack;

map<int, SI>idsetmap;
map<SI, int>setidmap;

int mapcounter;

void init(){
    while(!setstack.empty())setstack.pop();
    mapcounter = 0;
    idsetmap.clear(); setidmap.clear();
}

void _push(){
    SI line;
    setidmap[line] = 0;
    idsetmap[0] = line;
    setstack.push(0);
    //cout<<"hoise\n";
    //cout<<setstack.size()<<"\n";
}

void _dup(){
    int sid = setstack.top();
    setstack.push(sid);
}

void _merger(int op){
    int id1 = setstack.top();
    setstack.pop();
    int id2 = setstack.top();
    setstack.pop();
    SI s1 = idsetmap[id1]; SI s2 = idsetmap[id2];
    SI ss;
    if(op==1)set_union(s1.begin(),s1.end(),s2.begin(),s2.end(),inserter(ss,ss.begin()));
    else if(op==2)set_intersection(s1.begin(),s1.end(),s2.begin(),s2.end(),inserter(ss,ss.begin()));
    else if(op==3){
        ss = s2;
        ss.insert(id1);
    }
    if(setidmap.find(ss)==setidmap.end()){
        ++mapcounter;
        idsetmap[mapcounter] = ss;
        setidmap[ss] = mapcounter;
        setstack.push(mapcounter);
    }
    else{
        int sid = setidmap[ss];
        setstack.push(sid);
    }
}

void _print(){
    //cout<<"here\n";
    //cout<<setstack.size()<<"\n";
    int ii =  setstack.top();
    //printf("%d\n",ii);
    printf("%d\n",(int)idsetmap[ii].size());
}

char operation[10];

int getnum(){
    if(operation[0]=='P')return 0;
    if(operation[0]=='U')return 1;
    if(operation[0]=='I')return 2;
    if(operation[0]=='A')return 3;
    if(operation[0]=='D')return 4;
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int opp;
        init();
        scanf("%d",&opp);
        FREP(i,1,opp){
            scanf("%s",operation);
            int oid = getnum();
            //cout<<oid<<"\n";
            if(oid==0)_push();
            else if(oid==4)_dup();
            else _merger(oid);
            _print();
        }
        printf("***\n");
    }
    return 0;
}
