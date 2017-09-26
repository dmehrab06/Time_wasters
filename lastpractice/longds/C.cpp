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

set< pair<int,PII> >hooks; //(len,(right,left)) //len ar right minus kore rakhte hobe
set<PII>hooks2;

pair<int,PII>allqs[100005]; //0 l r/ person came/arrive hookused


map<int,int>empstate;
map<int,int>hishook;

set<int>hooksneeded;

pair<int,PII> getelemforset(pair<int,PII> elem){  //set er upojogi kore banate
    return make_pair(-elem.first,make_pair(-elem.second.second,elem.second.first));
}

pair<int,PII> getelemforset(PII elem){  //set er upojogi kore banate
    return make_pair(-(elem.second-elem.first+1),make_pair(-elem.second,elem.first));
}

PII getelemforset2(pair<int,PII> elem){  //set er upojogi kore banate
    return make_pair(elem.second.first,elem.second.second);
}

pair<int,PII> getelem(pair<int,PII> setelem){  //set er upojogi kore banate
    int len = -setelem.first;
    int l = setelem.second.second;
    int r = -setelem.second.first;
    return make_pair(len,make_pair(l,r));
}

void emulate(int n, int q){
    int ll = 1;
    int rr = n;
    int len = n;
    pair<int,PII> ss = getelemforset(make_pair(len,make_pair(ll,rr)));
    hooks.insert(ss);
    hooks2.insert(getelemforset2(make_pair(len,make_pair(ll,rr))));
    FREP(i,1,q){
        int id;
        scanf("%d",&id);
        if(id==0){
            int l,r;
            scanf("%d %d",&l,&r);
            allqs[i]=make_pair(id,make_pair(l,r));
            hooksneeded.insert(l); hooksneeded.insert(r);
        }
        else{
            //allqs[i]=make_pair(id,make_pair(0,0));
            if(empstate.find(id)==empstate.end()){
                empstate[id] = 1;
            }
            else{
                empstate[id]++;
            }
            //allqs[i].second.first = empstate[id]%2;
            if(empstate[id]%2){
                //came
                set< pair<int,PII> >::iterator it=hooks.begin();
                pair<int,PII>longest = getelem(*it);
                PII rng = getelemforset2(longest);
                hooks.erase(it);
                hooks2.erase(rng);
                //cout<<longest.first<<" "<<longest.second.first<<" "<<longest.second.second<<"\n";
                int len = longest.first;
                int l = longest.second.first;
                int r = longest.second.second;

                int mid = (r+l)/2+(1-(len%2));
                //pair<int,PII> mm = getelemforset(make_pair(1,make_pair(mid,mid)));
                pair<int,PII> ll = getelemforset(make_pair(mid-l,make_pair(l,mid-1)));
                pair<int,PII> rr = getelemforset(make_pair(r-mid,make_pair(mid+1,r)));
                hishook[id] = mid;
                //allqs[i].second.second = mid;
                allqs[i]=make_pair(id,make_pair(empstate[id]%2,mid));
                if(l<=(mid-1)){
                    hooks.insert(ll);
                    hooks2.insert(make_pair(l,mid-1));
                    hooksneeded.insert(l); hooksneeded.insert(mid-1);
                }
                if((mid+1)<=r){
                    hooks.insert(rr);
                    hooks2.insert(make_pair(mid+1,r));
                    hooksneeded.insert(mid+1); hooksneeded.insert(r);
                }
                //hooks.insert(mm);
                hooks2.insert(make_pair(mid,mid));
                hooksneeded.insert(mid);
            }
            else{
                //left
                PII washook = make_pair(hishook[id],hishook[id]);
                set<PII>::iterator it = hooks2.find(washook);
                set<PII>::iterator it2;
                PII lftelem2,rgtelem2;
                pair<int,PII> l,r;

                if(it!=hooks2.begin()){
                    it2 =it; it2--;
                    lftelem2 = *it2;
                }
                else lftelem2 = washook;

                it2=it; it2++;
                if(it2==hooks2.end()) rgtelem2 = washook;
                else rgtelem2 = *it2;
                //cout<<"cur: "<<washook.first<<" "<<washook.second<<"\n";
                //cout<<"left: "<<lftelem2.first<<" "<<lftelem2.second<<"\n";
                //cout<<"right: "<<rgtelem2.first<<" "<<rgtelem2.second<<"\n";
                l = getelemforset(lftelem2); r = getelemforset(rgtelem2);

                int oldl = washook.first;
                int oldr = washook.second;
                int lflag = 0,rflag =0;
                if(hooks.find(l)!=hooks.end()){oldl = lftelem2.first;lflag=1;}
                if(hooks.find(r)!=hooks.end()){oldr = rgtelem2.second;rflag=1;}
                PII oldelem = make_pair(oldl,oldr);
                if(hooks2.find(washook)!=hooks2.end()){hooks2.erase(washook);}
                if(hooks2.find(lftelem2)!=hooks2.end()){hooks.erase(l);}
                if(hooks2.find(rgtelem2)!=hooks2.end()){hooks.erase(r);}
                if(hooks2.find(lftelem2)!=hooks2.end() && lflag){hooks2.erase(lftelem2);}
                if(hooks2.find(rgtelem2)!=hooks2.end() && rflag){hooks2.erase(rgtelem2);}
                hooks2.insert(oldelem);
                hooks.insert(getelemforset(oldelem));
                allqs[i]=make_pair(id,make_pair(empstate[id]%2,hishook[id]));
            }
        }
        set<PII>::iterator it;
        /*cout<<"hooks2 contents\n";
        for(it = hooks2.begin();it!=hooks2.end();++it){
            cout<<(*it).first<<" "<<(*it).second<<"\n";
        }
        cout<<"\n\n";*/
    }
}

map<int,int>cmpress;

void compress(){
    set<int>::iterator it;
    //cout<<"\n";
    int cur=1;
    for(it=hooksneeded.begin();it!=hooksneeded.end();++it){
        //cout<<*it<<"\n";
        cmpress[*it]=cur;
        cur++;
    }
}

int segtree[2000003];

void build(int node, int l, int r){
    if(l>r) return;
    if(l==r){
        segtree[node]=0;
        return;
    }
    int mid = (l+r)>>1;
    int lft = node<<1; int rgt = lft+1;
    build(lft,l,mid); build(rgt,mid+1,r);
    segtree[node]=segtree[lft]+segtree[rgt];
    return;
}

void update(int node, int l, int r, int pos, int val){
    if(l>pos || r<pos) return;
    if(l==r && l==pos){
        segtree[node]+=val;
        return;
    }
    int mid = (l+r)>>1;
    int lft = node<<1; int rgt = lft+1;
    update(lft,l,mid,pos,val); update(rgt,mid+1,r,pos,val);
    segtree[node]=segtree[lft]+segtree[rgt];
    return;
}

int query(int node, int l, int r, int x, int y){
    if(l>y || r<x)return 0;
    if(l>=x && r<=y){
        return segtree[node];
    }
    int mid = (l+r)>>1;
    int lft = node<<1; int rgt = lft+1;
    int a = query(lft,l,mid,x,y); int b = query(rgt,mid+1,r,x,y);
    return a+b;
}

int main(){
    int n,q;
    scanf("%d %d",&n,&q);
    emulate(n,q);
    compress();
    int N = hooksneeded.size()+1;
    build(1,1,N);
    FREP(i,1,q){
        pair<int,PII>curq = allqs[i];
        if(curq.first==0){
            int x = cmpress[curq.second.first];
            int y = cmpress[curq.second.second];
            int ans = query(1,1,N,x,y);
            printf("%d\n",ans);
        }
        else{
            int state = curq.second.first;
            int hook = cmpress[curq.second.second];
            if(state==0){
                //leaving
                update(1,1,N,hook,-1);
            }
            else{
                update(1,1,N,hook,1);
            }
        }
    }
    return 0;
}
