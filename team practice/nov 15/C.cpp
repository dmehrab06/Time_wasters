/*-------property of the half blood prince-----*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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

typedef tree<
PII,
null_type,
greater<PII>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

map<string,int>nmtoid;
map<int,string>idtonm;

int status[200005]; //1 means working hard, 0 means not working hard , -1 means undefined
int level[200005];
string nm;

int main(){

    ordered_set X;
    ordered_set::iterator it;
    memset(status,-1,sizeof(status));
    int n;
    scanf("%d",&n);
    FREP(i,1,n){
        int mot;
        cin>>nm>>mot;
        idtonm[i]=nm;
        nmtoid[nm]=i;
        level[i]=mot;
        X.insert(make_pair(mot,i));
    }
    int startid=n+1;
    int works=n/5;
    for(int i=0;i<n;++i){
        PII oka=(*X.find_by_order(i));
        if(i<works)status[oka.second]=1;
        else status[oka.second]=0;
    }
    int m;
    scanf("%d",&m);
    string chg;
    int cur=n;
    FREP(i,1,m){
        //int mot;
        cin>>chg>>nm;
        if(chg[0]=='+'){
            int mot;
            cin>>mot;
            level[startid]=mot;
            nmtoid[nm]=startid;
            idtonm[startid]=nm;
            cur++;
            int nwwrk=cur/5;
            PII nw=make_pair(mot,startid);
            X.insert(nw);
            int position=X.order_of_key(nw);
            if(position<nwwrk){
                status[startid]=1;
                cout<<nm<<" is working hard now.\n";
            }
            else{
                status[startid]=0;
                cout<<nm<<" is not working now.\n";
            }
            for(int k=(nwwrk-2);k<=nwwrk+2;k++){
                if(0<=k && k<cur && k<nwwrk){
                    //era ekhon hocche work hard korbe status 0 chilo kina dekhte hobe
                    PII prune=*X.find_by_order(k);
                    int idd=prune.second;
                    if(status[idd]==0){
                        cout<<idtonm[idd]<<" is working hard now.\n";
                        status[idd]=1;
                    }
                }
                else if(0<=k && k<cur && k>=nwwrk){
                    //era ekhon hocche work hard korbe na status 1 chilo kina dekhte hobe
                    PII prune=*X.find_by_order(k);
                    int idd=prune.second;
                    if(status[idd]==1){
                        cout<<idtonm[idd]<<" is not working now.\n";
                        status[idd]=0;
                    }
                }
            }
            startid++;
        }
        else if(chg[0]=='-'){
            if(nmtoid.find(nm)==nmtoid.end())continue;
            int idd=nmtoid[nm];
            int lev=level[idd];
            PII srch=make_pair(lev,idd);
            nmtoid.erase(nm);
            idtonm.erase(idd);
            cur--;
            int nwwrk=cur/5;
            X.erase(srch);
            for(int k=(nwwrk-2);k<=nwwrk+2;k++){
                if(0<=k && k<cur && k<nwwrk){
                    //era ekhon hocche work hard korbe status 0 chilo kina dekhte hobe
                    PII prune=*X.find_by_order(k);
                    int idd=prune.second;
                    if(status[idd]==0){
                        cout<<idtonm[idd]<<" is working hard now.\n";
                        status[idd]=1;
                    }
                }
                else if(0<=k && k<cur && k>=nwwrk){
                    //era ekhon hocche work hard korbe na status 1 chilo kina dekhte hobe
                    PII prune=*X.find_by_order(k);
                    int idd=prune.second;
                    if(status[idd]==1){
                        cout<<idtonm[idd]<<" is not working now.\n";
                        status[idd]=0;
                    }
                }
            }
        }
    }
    return 0;
}
