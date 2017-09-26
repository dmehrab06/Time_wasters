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
#define OPEN first
#define CLOS second
using namespace std;
using namespace __gnu_pbds;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction


//typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

vector < vector <PII> > segtree;

int food[100005];

void setseg(int n){
    segtree.clear();
    FREP(i,0,(3*n+4)){
        vector<PII> line; segtree.PB(line);
    }
}

PII getelemidx(int node, int k, int b, int e){
    int ll = segtree[node].size()-1;
    int lo = 0; int hi = ll; //segtree[node] is a vector;
    //cout<<"at node "<<node<<" lo: "<<lo<<" hi: "<<hi<<" beg: "<<b<<" ed: "<<e<<"\n";
    while(true){
        //cout<<"now lo "<<lo<<" hi "<<hi;
        int mid = lo+(hi-lo)/2;
        //cout<<" mid "<<mid<<"\n";
        int elem = segtree[node][mid].first;
        int dif = abs(elem-k);
        //cout<<dif<<"\n";
        int mid1 = mid+1; int mid2 = mid-1;
        int dif1 = 1000000007; int dif2 = 1000000007;
        int idx2 = 1000000007, idx1 = 1000000009;
        if(mid1<=ll){
            int elem1 = segtree[node][mid1].first; dif1 = abs(elem1-k);
            idx1 = segtree[node][mid1].second;
        }
        if(mid2>=0){
            int elem2 = segtree[node][mid2].first; dif2 = abs(elem2-k);
            idx2 = segtree[node][mid2].second;
        }
        //cout<<dif1<<" "<<dif2<<"\n";
        if(idx2<idx1){
            if(dif<=dif1 && dif<dif2){
                return make_pair(dif,segtree[node][mid].second);
            }
            else if(dif1<dif2){
                lo = mid+1;
            }
            else{
                hi = mid-1;
            }
        }
        else{
            if(dif<=dif2 && dif<dif1){
                return make_pair(dif,segtree[node][mid].second);
            }
            else if(dif2<dif1){
                hi = mid-1;
            }
            else{
                lo = mid+1;
            }
        }
    }
}

void mergeseg(int node){
    int lnode = node<<1; int rnode = lnode+1;
    int p1 = 0, p2 = 0, e1 = segtree[lnode].size()-1, e2 = segtree[rnode].size()-1;
    while(p1<=e1 && p2<=e2){
        if(segtree[lnode][p1].first<segtree[rnode][p2].first){
            segtree[node].PB(segtree[lnode][p1]);
            p1++;
        }
        else if(segtree[lnode][p1].first>segtree[rnode][p2].first){
            segtree[node].PB(segtree[rnode][p2]);
            p2++;
        }
        else{
            if(segtree[lnode][p1].second<segtree[rnode][p2].second){
                segtree[node].PB(segtree[lnode][p1]);
                p1++;
            }
            else{
                segtree[node].PB(segtree[rnode][p2]);
                p2++;
            }
        }
    }
    while(p1<=e1){
        segtree[node].PB(segtree[lnode][p1]);
        p1++;
    }
    while(p2<=e2){
        segtree[node].PB(segtree[rnode][p2]);
        p2++;
    }
}

void buildsegtree(int b, int e, int node){
    if(b==e){
        segtree[node].PB(make_pair(food[b],b));
        return;
    }
    if(b>e)return;
    int mid = (b+e)/2;
    int lnode = node<<1; int rnode = lnode+1;
    buildsegtree(b,mid,lnode); buildsegtree(mid+1,e,rnode);
    mergeseg(node);
    return;
}

PII query(int b, int e, int node, int i, int j,int k){
    if(b>j || e<i)return make_pair(1000000008,0);
    if(b>=i && e<=j)return getelemidx(node,k,b,e);
    int mid = (b+e)/2;
    int lnode = node<<1; int rnode = lnode+1;
    PII ans1 = query(b,mid,lnode,i,j,k); PII ans2 = query(mid+1,e,rnode,i,j,k);
    if(ans1.first<=ans2.first){
        return ans1;
    }
    else{
        return ans2;
    }
}

void printsegtree(int b, int e, int node){
    if(b>e)return;
    cout<<" in node "<<node<<" b: "<<b<<"  and e: "<<e<<"\n";
    int ll = segtree[node].size();
    FREP(i,0,(ll-1)){
        cout<<segtree[node][i].first<<","<<segtree[node][i].second<<" ";
    }
    cout<<"\n";
    if(b==e)return;
    int mid = (b+e)/2;
    int lnode = node<<1; int rnode = lnode+1;
    printsegtree(b,mid,lnode); printsegtree(mid+1,e,rnode);
    //mergeseg(node);
    return;
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        setseg(n);
        FREP(i,1,n)scanf("%d",&food[i]);
        buildsegtree(1,n,1);
        int q;
        scanf("%d",&q);
        //printsegtree(1,n,1);
        FREP(i,1,q){
            int l,r,k;
            scanf("%d %d %d",&l,&r,&k);
            if(l==r){
                printf("%d\n",l);
                continue;
            }
            PII ans = query(1,n,1,l,r,k);
            printf("%d\n",ans.second);
        }
    }
    return 0;
}
