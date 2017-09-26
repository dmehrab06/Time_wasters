/*-------property of the half blood prince-----*/

#include <bits/stdc++.h>
//#include <dirent.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/detail/standard_policies.hpp>
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
//using namespace __gnu_pbds;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction


//typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;
using namespace std;

int BLOCK;

struct query {
	int left, right;
	int idx;
	int ans;
	query(int _l=0, int _r=0, int _idx=0){
        left = _l; right = _r;
        idx = _idx;
	}
};

bool cmp1(query x, query y) {
	if(x.left/BLOCK != y.left/BLOCK)return x.left/BLOCK < y.left/BLOCK;
	return x.right < y.right;
}

bool cmp2(query x, query y){
    return x.idx<y.idx;
}

int cnt[100005];
query allq[50003];
int arr[100005];

int answer = 0;

void init(int N){
    memset(cnt,0,sizeof(cnt));
    answer = 0;
    BLOCK = sqrt(N)+1;
}

void jog(int i){
    cnt[arr[i]]++;
    if(cnt[arr[i]]==1){
        answer++;
    }
}

void biyog(int i){
    cnt[arr[i]]--;
    if(cnt[arr[i]]==0){
        answer--;
    }
}

int main(){
    int t;
    scanf("%d",&t);
    FREP(cs,1,t){
        int n,q;
        scanf("%d %d",&n,&q);
        FREP(i,1,n)scanf("%d",&arr[i]);
        init(n);
        FREP(i,1,q){
            int l,r;
            scanf("%d %d",&l,&r);
            query qq(l,r,i);
            allq[i]=qq;
        }
        int cl = 1;
        int cr = 0;
        sort(allq+1,allq+1+q,cmp1);
        FREP(i,1,q){
            int l = allq[i].left; int r = allq[i].right;
            while(cr<r){
                jog(cr+1);
                cr++;
            }
            while(cr>r){
                biyog(cr);
                cr--;
            }
            while(cl<l){
                biyog(cl);
                cl++;
            }
            while(cl>l){
                jog(cl-1);
                cl--;
            }
            allq[i].ans = answer;
        }
        sort(allq+1,allq+1+q,cmp2);
        printf("Case %d:\n",cs);
        FREP(i,1,q){
            printf("%d\n",allq[i].ans);
        }

    }
	return 0;
}
