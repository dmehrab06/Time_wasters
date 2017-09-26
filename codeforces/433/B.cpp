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

#define MAXN 100005
//typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;
using namespace std;

bool hasto[MAXN];
bool hasfrom[MAXN];

vector< vector <PII> > goingtometropolis;
vector< vector <PII> > goingfrommetropolis;

bool arrived[MAXN];
bool gone[MAXN];

LLI journeywitharrivaltime(int t, int k, int n){
    //t somoy er por kaure metro te dhukte ditam na
    //memset(arrived,false,sizeof(arrived)); memset(gone,false,sizeof(gone));
    int arrived = 0; int gone = 0; LLI totcost = 0;
    int mxday  = 0;
    FREP(i,1,n){
        int l = goingtometropolis[i].size();
        FREP(j,0,(l-1)){
            int cost = goingtometropolis[i][j].first;
            int day = goingtometropolis[i][j].second;
            if(day<=t){
                totcost+=cost;
                arrived++;
                mxday = max(mxday,day);
                break;
            }
        }
    }
    if(arrived<n)return -1;
    int gotime = mxday+k+1;
    FREP(i,1,n){
        int l = goingfrommetropolis[i].size();
        FREP(j,0,(l-1)){
            int cost = goingfrommetropolis[i][j].first;
            int day = goingfrommetropolis[i][j].second;
            if(day>=gotime){
                totcost+=cost;
                gone++;
                break;
            }
        }
    }
    if(gone<n)return -1;
    return totcost;
}

LLI journeywithgotime(int t, int k, int n){
    //t somoy er por kaure metro te dhukte ditam na
    //memset(arrived,false,sizeof(arrived)); memset(gone,false,sizeof(gone));
    //int arrivetime = t-k-1;
    int arrived = 0; int gone = 0; LLI totcost = 0;
    int gotime = t;
    int mintime = 10000000;
    FREP(i,1,n){
        int l = goingfrommetropolis[i].size();
        FREP(j,0,(l-1)){
            int cost = goingfrommetropolis[i][j].first;
            int day = goingfrommetropolis[i][j].second;
            if(day<=gotime){
                totcost+=cost;
                gone++;
                mintime = min(mintime,day);
                break;
            }
        }
    }
    if(gone<n)return -1;
    int arrivetime = mintime-k-1;
    FREP(i,1,n){
        int l = goingtometropolis[i].size();
        FREP(j,0,(l-1)){
            int cost = goingtometropolis[i][j].first;
            int day = goingtometropolis[i][j].second;
            if(day<=arrivetime){
                totcost+=cost;
                arrived++;
                break;
            }
        }
    }
    if(arrived<n)return -1;
    return totcost;
}

LLI bin_search_arrive(int n, int k, int maxt){
    int lo = 1;
    int hi = maxt;
    //cout<<"in arrival\n";
    while(lo<hi){
        int mid = (lo+hi)/2;
        //cout<<mid<<" ";
        LLI cst = journeywitharrivaltime(mid,k,n);
        //cout<<cst<<"\n";
        if(cst!=-1){
            if(mid<maxt){
                LLI val = journeywitharrivaltime(mid+1,k,n);
                if(val!=-1 && val<cst){
                    lo = mid+1;
                }
                else{
                    return cst;
                }
            }
            else{
                return cst;
            }
        }
        else{
            hi = mid;
        }
    }
    return -1;
}

LLI bin_search_go(int n, int k, int maxt){
    int lo = 1;
    int hi = maxt;
    //cout<<"in go\n";
    while(lo<hi){
        int mid = (lo+hi)/2;
        //cout<<mid<<" ";
        LLI cst = journeywithgotime(mid,k,n);
        //cout<<cst<<"\n";
        if(cst!=-1){
            if(mid<maxt){
                LLI val = journeywitharrivaltime(mid+1,k,n);
                if(val!=-1 && val<cst){
                    lo = mid+1;
                }
                else{
                    return cst;
                }
            }
            else{
                return cst;
            }
        }
        else{
            hi = mid;
        }
    }
    return -1;
}

void init(int n){
    memset(hasfrom,false,sizeof(hasfrom)); memset(hasto,false,sizeof(hasto));
    vector<PII>line;
    FREP(i,0,(n+3)){
        goingfrommetropolis.PB(line); goingtometropolis.PB(line);
    }
}

void takeinp(int n, int m){
    FREP(i,1,m){
        int day, from, to, cost;
        scanf("%d %d %d %d",&day,&from,&to,&cost);
        if(to==0){
            hasto[from]=true;
            goingtometropolis[from].PB(make_pair(cost,day));
        }
        else{
            hasfrom[to]=true;
            goingfrommetropolis[to].PB(make_pair(cost,day));
        }
    }
    FREP(i,1,n){
        SORTV(goingfrommetropolis[i]); SORTV(goingtometropolis[i]);
    }
    /*FREP(i,1,n){
        FREP(j,0,goingfrommetropolis[i].size()-1){
            cout<<goingfrommetropolis[i][j].first<<" "<<goingfrommetropolis[i][j].first<<",";
        }
        cout<<"\n";
    }
    FREP(i,1,n){
        FREP(j,0,goingtometropolis[i].size()-1){
            cout<<goingtometropolis[i][j].first<<" "<<goingtometropolis[i][j].second<<",";
        }
        cout<<"\n";
    }*/
}

bool reject_1(int n){
    FREP(i,1,n){
        if(!hasto[i] || !hasfrom[i])return true;
    }
    return false;
}

int main(){
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    init(n);
    takeinp(n,m);
    if(reject_1(n)){
        cout<<"-1\n";
    }
    else{
        LLI ans1 = bin_search_arrive(n,k,1000003);
        LLI ans2 = bin_search_go(n,k,1000003);
        if(ans1==-1 && ans2==-1){
            cout<<"-1\n";
        }
        else if(ans1==-1){
            cout<<ans2<<"\n";
        }
        else if(ans2==-1){
            cout<<ans1<<"\n";
        }
        else{
            cout<<min(ans1,ans2)<<"\n";
        }
    }
    return 0;
}
