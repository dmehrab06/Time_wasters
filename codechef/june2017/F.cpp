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
#define FREP(i,I,N) for(int (i)=(int)(I);(i)<=(int)(N);(i)++)
#define eps 0.0000000001
#define RFREP(i,N,I) for(int (i)=(int)(N);(i)>=(int)(I);(i)--)
#define SORTV(VEC) sort(VEC.begin(),VEC.end())
#define SORTVCMP(VEC,cmp) sort(VEC.begin(),VEC.end(),cmp)
#define REVV(VEC) reverse(VEC.begin(),VEC.end())
#define INRANGED(val,l,r) (((l)<(val) || fabs((val)-(l))<eps) && ((val)<(r) || fabs((val)-(r))<eps))
using namespace std;
using namespace __gnu_pbds;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction


typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

int sieve[1000006];
int smallestprime[1000006];

int myarr[100005];

vector < vector <PII> > factored;

vector < vector<PII> > merge_tree;
vector < vector<int> > cumsum_tree;

void printfactorization(int n){
    FREP(i,1,n){
        int ll = factored[i].size();
        printf("%d: ",myarr[i]);
        FREP(j,1,(ll-1)){
            printf("(%d %d) ",factored[i][j].first,factored[i][j].second);
        }
        printf("\n");
    }
}

void init(int n){
    FREP(i,0,(4*n+3)){
        vector<PII>line;
        vector<int>line2;
        factored.PB(line);
        merge_tree.PB(line);
        cumsum_tree.PB(line2);
        factored[i].PB(make_pair(0,0));
        merge_tree[i].PB(make_pair(0,0));
    }
}

void calccumsum(int node){
    int ll = merge_tree[node].size();
    cumsum_tree[node].PB(0);
    FREP(i,1,(ll-1)){
        cumsum_tree[node].PB(cumsum_tree[node][i-1]+merge_tree[node][i].second);
    }
}

void mix(int node, int left, int right){
    int cursz = merge_tree[node].size();
    int lsz = merge_tree[left].size(); int rsz = merge_tree[right].size();
    int l = 0; int r = 0;
    while((l<lsz) || (r<rsz)){
        int lval =100000000, rval = 100000000;
        if(l<lsz)lval = merge_tree[left][l].first;
        if(r<rsz)rval = merge_tree[right][r].first;
        if(rval<lval){
            int freq = merge_tree[right][r].second;
            if(merge_tree[node][cursz-1].first==rval){
                merge_tree[node][cursz-1].second+=freq;
            }
            else{
                merge_tree[node].PB(make_pair(rval,freq));
                cursz++;
            }
            r++;
        }
        else{
            int freq = merge_tree[left][l].second;
            if(merge_tree[node][cursz-1].first==lval){
                merge_tree[node][cursz-1].second+=freq;
            }
            else{
                merge_tree[node].PB(make_pair(lval,freq));
                cursz++;
            }
            l++;
        }
    }
}

int bin_search(int node, int prime){
    int sz = merge_tree[node].size();
    int lo = 0;
    int hi = sz-1;
    while(lo<hi){
        int mid = (lo+hi)/2;
        int cur = merge_tree[node][mid].first;
        if(cur<=prime){
            if(mid<(sz-1) && merge_tree[node][mid+1].first<=prime){
                lo=mid+1;
            }
            else{
                return mid;
            }
        }
        else{
            hi = mid;
        }
    }
    return lo;
}

void printsegtree(int node, int l, int r){
    cout<<"at node "<<node<<" l r "<<l<<" "<<r<<"\n";

    int sz=merge_tree[node].size();
    FREP(i,0,sz-1){
        printf(" (%d %d ) ",merge_tree[node][i].first,merge_tree[node][i].second);
    }
    printf("\n");
    if(l>=r)return;

    int mid = (l+r)/2;
    int left = node<<1; int right = left+1;

    printsegtree(left,l,mid);
    printsegtree(right,mid+1,r);
}

void printcumsum(int node, int l, int r){
    //cout<<"at node "<<node<<" l r"<<l<<" "<<r<<"\n";
    int sz=cumsum_tree[node].size();
    FREP(i,0,sz-1){
        printf("%d ",cumsum_tree[node][i]);
    }
    printf("\n");
    if(l>=r)return;
    int mid = (l+r)/2;
    int left = node<<1; int right = left+1;

    printcumsum(left,l,mid);
    printcumsum(right,mid+1,r);
}

void build(int node, int l, int r){
    //printsegtree(1,1,30);
    if(l==r){
        int sz=factored[l].size();
        FREP(i,1,sz-1){
            merge_tree[node].PB(factored[l][i]);
        }
        //cout<<"dhukano holo\n";
        //cout<<"at node "<<node<<" size "<<merge_tree[node].size()<<"\n";
        //printsegtree(1,1,5);
        calccumsum(node);
        return;
    }
    if(l>r)return;
    int mid = (l+r)/2;

    int left = node<<1; int right = left+1;

    build(left,l,mid);
    build(right,mid+1,r);

    mix(node,left,right);
    //cout<<"dhukano holo\n";
    //cout<<"at node "<<node<<" size "<<merge_tree[node].size()<<"\n";

    //cout<<"mix korsi\n";
    calccumsum(node);
    //cout<<"calc korsi\n";
    return;
}

int query(int nl, int nr, int px, int py, int node, int l, int r){
    if(r<nl || l>nr || nl>nr){
        //cout<<"node "<<node<<" l r "<<l<<" "<<r<<" theke ans jacche 0\n";
        return 0;
    }
    if(l>=nl && r<=nr){
        int bidx=bin_search(node,py);
        int bsum = cumsum_tree[node][bidx];

        int aidx = bin_search(node,px-1);
        int asum = cumsum_tree[node][aidx];
        //cout<<"node "<<node<<" l r "<<l<<" "<<r<<" theke ans jacche "<<bsum-asum<<"\n";
        return bsum-asum;
    }
    int mid = (l+r)/2;
    int left = node<<1; int right = left+1;
    int lans = query(nl,nr,px,py,left,l,mid);
    int rans = query(nl,nr,px,py,right,mid+1,r);
    //cout<<"node "<<node<<" l r "<<l<<" "<<r<<" theke ans jacche "<<lans+rans<<"\n";
    return lans+rans;

}

void fact(int idx){
    int num = myarr[idx];
    while(num>1){
        int p = smallestprime[num];
        int exp = 0;
        while(num%p==0){
            num/=p;
            exp++;
        }
        factored[idx].PB(make_pair(p,exp));
    }
}

void factor(int n){
    FREP(i,1,n){
        fact(i);
    }
}

void runsieve(){
    FREP(i,2,1000003){
        if(sieve[i]==0){
            smallestprime[i]=i;
            for(int j = (i+i); j<=1000003; j+=i){
                sieve[j] = 1;
                if(smallestprime[j]==0){
                    smallestprime[j]=i;
                }
            }
        }
    }
}

bool isprime(int a){
    return sieve[a]==0;
}

int vuafunc(int l, int r, int x, int y){
    int res = 0;
    FREP(i,x,y){
        if(isprime(i)){
            FREP(j,l,r){
                int exp = 0;
                int num = myarr[j];
                while(num%i==0){
                    num/=i;
                    exp++;
                }
                res+=exp;
            }
        }
    }
    return res;
}

int main(){
    runsieve();
    int n;
    scanf("%d",&n);
    init(n);
    FREP(i,1,n){
        scanf("%d",&myarr[i]);
    }
    factor(n);
    //printfactorization(n);
    build(1,1,n);
    //cout<<"build hoise\n";
    //printsegtree(1,1,n);
    int q;
    scanf("%d",&q);
    FREP(i,1,q){
        int l,r,x,y;
        scanf("%d %d %d %d",&l,&r,&x,&y);
        int ans = query(l,r,x,y,1,1,n);
        printf("%d\n",ans);
        //int ans2 = vuafunc(l,r,x,y);
        //printf("%d\n",ans2);
    }
    return 0;
}
