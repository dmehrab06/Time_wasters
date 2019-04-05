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

#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}

vector< vector<int> >desired;
int chosen[4][100005];
vector< set< pair<int,int> > >myset; //pair<difference,idx>idx of chosen array with difference

void init(int n){
    vector<int>line;
    FREP(i,1,(n+4))desired.PB(line);
    set<PII>line2;
    FREP(i,1,(n+4))myset.PB(line2);
}

void rearrange(int idx){
    FREP(j,1,3){
        vector<int>::iterator it;
        it = upper_bound(desired[j].begin(),desired[j].end(),chosen[0][idx]);
        chosen[j][idx] = (int)(it-desired[j].begin());
        myset[j].insert(make_pair(desired[j][chosen[j][idx]]-chosen[0][idx],idx));
    }
}

int simulate(int left, int L, int n){
    int tleft = left;
    for(int j=1;j<=3;++j){
        //cout<<"in j: "<<j<<"\n";
        while(left>0){
            set<PII>::iterator it = myset[j].begin();
            PII cur = *it;
            if(cur.first>left){
                break;
            }
            int dif = cur.first;
            int idx = cur.second;
            FREP(k,1,3){
                PII curr = *(myset[k].find(make_pair(desired[k][chosen[k][idx]]-chosen[0][idx],idx)));
                myset[k].erase(curr);
            }
            //error(dif,idx);
            //cout<<"making "<<chosen[0][idx]<<" at "<<idx<<" to "<<chosen[0][idx]+dif<<"\n";
            chosen[0][idx] = chosen[0][idx]+dif;
            chosen[j][idx]++;
            rearrange(idx);
            left-=dif;
        }
    }
    int tot = 0;
    FREP(i,1,(L+tleft)){
        int val = chosen[0][i];
        //if(val!=0)error(i,val);
        double v = ((double)chosen[0][i]/(double)n)*(100.0);
        int vr = round(v);
        //cout<<i<<" "<<chosen[0][i]<<" "<<vr<<"\n";
        tot+=vr;
    }
    return tot;
}

int main(){
    int t;
    scanf("%d",&t);
    FREP(cs,1,t){
        desired.clear(); myset.clear();
        int n,L;
        scanf("%d %d",&n,&L);
        init(n);
        FREP(i,1,n){
            double v = (double)i/(double)n*(100.0);
            int vi = (int)v;
            int vr = round(v);
            if(vr>vi) desired[1].PB(i);
            else if(vr==vi) desired[2].PB(i);
            else desired[3].PB(i);
        }
        desired[1].PB(10000000); desired[2].PB(10000000); desired[3].PB(10000000);
        int tot = 0;
        FREP(i,1,L){
            scanf("%d",&chosen[0][i]);
            tot+=chosen[0][i];
        }
        int left = n-tot;
        FREP(i,L+1,(L+left)){
            chosen[0][i] = 0;
        }
        FREP(j,1,3){
            FREP(i,1,(L+left)){
                vector<int>::iterator it;
                it = upper_bound(desired[j].begin(),desired[j].end(),chosen[0][i]);
                chosen[j][i] = (int)(it-desired[j].begin());
                myset[j].insert(make_pair(desired[j][chosen[j][i]]-chosen[0][i],i));
            }
        }
        int ans = simulate(left,L,n);
        printf("Case #%d: %d\n",cs,ans);
    }
    return 0;
}
