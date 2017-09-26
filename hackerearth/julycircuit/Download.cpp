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

vector <int> speedatmoment;
vector <int> cumvolume;
vector <int> volume;

PII arr[100005];

void printv(vector <int>& VV){
    FREP(i,0,VV.size()-1){
        cout<<"index "<<i<<": "<<VV[i]<<"\n";
    }
}

void takeinp(int n, int S){
    FREP(i,1,n){
        scanf("%d %d",&arr[i].first,&arr[i].second);
    }
    FREP(i,1,n){
        if(i==n){
            int speed = arr[i].second;
            int timeneeded = S/speed;
            int curtime = arr[i].first;
            FREP(t,curtime,curtime+timeneeded+3){
                speedatmoment.push_back(speed);
            }
        }
        else{
            int curtime = arr[i].first;
            int nxttime = arr[i+1].first-1;
            FREP(t,curtime,nxttime){
                speedatmoment.push_back(arr[i].second);
            }
        }
    }
}

LLI gcd(LLI a, LLI b){
    if(a==0)return b;
    return gcd(b%a,a);
}

int main(){
    int n,S;
    scanf("%d %d",&n,&S);
    //printv(speedatmoment);
    takeinp(n,S);
    volume.push_back(0);
    FREP(i,0,speedatmoment.size()-1){
        volume.PB(speedatmoment[i]);
    }
    //printv(volume);
    cumvolume.PB(0);
    FREP(i,1,volume.size()-1){
        cumvolume.PB(cumvolume[i-1]+volume[i]);
    }
    //printv(cumvolume);
    vector <int> ::iterator lo,hi;
    //forward test
    double finans = 10000000000000000;
    LLI finlob = -1;
    LLI finhor = -1;
    FREP(i,0,cumvolume.size()-1){
        int curval = cumvolume[i];
        int xx = curval + S;
        hi = upper_bound(cumvolume.begin(),cumvolume.end(),xx);
        int pos = (int)(hi-cumvolume.begin())-1;
        int here = cumvolume[pos];
        int extra = xx-here;
        int t1 = (pos-i);
        int t2lob = extra;
        int t2hor = speedatmoment[pos];
        LLI lob = (LLI)t1*(LLI)t2hor+(LLI)t2lob;
        LLI hor = t2hor;
        double tot = (double)lob/(double)hor;
        if(tot<finans){
            finans = tot;
            finlob = lob;
            finhor = hor;
        }
    }
    RFREP(i,cumvolume.size()-1,0){
        int curval = cumvolume[i];
        int xx = curval - S;
        if(xx<0)break;
        lo = lower_bound(cumvolume.begin(),cumvolume.end(),xx);
        int pos = (int)(lo-cumvolume.begin());
        int here = cumvolume[pos];
        int extra = here-xx;
        int t1 = (i-pos);
        int t2lob = extra;
        int t2hor = speedatmoment[pos-1];
        LLI lob = (LLI)t1*(LLI)t2hor+(LLI)t2lob;
        LLI hor = t2hor;
        double tot = (double)lob/(double)hor;
        if(tot<finans){
            finans = tot;
            finlob = lob;
            finhor = hor;
        }
    }
    LLI gg = gcd(finlob,finhor);
    finlob/=gg;
    finhor/=gg;
    printf("%lld/%lld\n",finlob,finhor);
    return 0;
}
