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

vector<int>arr;

set<int>setarr;

set<PII>setparr;

int main(){
    arr.PB(-9);
    arr.PB(0);
    arr.PB(1);
    arr.PB(1);
    arr.PB(2);
    arr.PB(5);
    arr.PB(7);

    setarr.insert(8);
    setarr.insert(7);
    setarr.insert(-2);
    setarr.insert(9);
    setarr.insert(1);
    setarr.insert(-7);
    setarr.insert(5);
    setarr.insert(11);

    setparr.insert(make_pair(-99,1));
    setparr.insert(make_pair(-99,8));
    setparr.insert(make_pair(-99,76));
    setparr.insert(make_pair(12,1));
    setparr.insert(make_pair(13,2));
    setparr.insert(make_pair(15,1));
    setparr.insert(make_pair(15,9));
    setparr.insert(make_pair(15,10));
    setparr.insert(make_pair(15,11));
    setparr.insert(make_pair(99,1));
    setparr.insert(make_pair(99,13));

    set<int>::iterator it;
    set<PII>::iterator it2;
    it=setarr.lower_bound(-6); //lower_bound -> or theke boro othoba soman sobcheye kom ta
    it2=setparr.upper_bound(make_pair(-10000,10000)); //upper bound e jeta ans asar kotha tar theke ek agaia dey
    it2--;
    PII oka=*it2;
    cout<<oka.first<<" "<<oka.second<<"\n";




}

