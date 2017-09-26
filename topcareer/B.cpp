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

int getminute(string mytime, string day, vector<string>&days){
    int hour = (mytime[0]-'0')*10+(mytime[1]-'0');
    int min = (mytime[3]-'0')*10+(mytime[4]-'0');
    int tm = hour*60+min;
    int offset;
    for(int i=0;i<7;++i){
        if(days[i]==day){
            offset = i;
            break;
        }
    }
    return offset*1440+tm;
}

string get1sttime(string ss){
    string r ="";
    r.push_back(ss[4]);r.push_back(ss[5]);r.push_back(ss[6]);
    r.push_back(ss[7]);r.push_back(ss[8]);
    return r;
}

string get2ndtime(string ss){
    string r ="";
    r.push_back(ss[10]);r.push_back(ss[11]);r.push_back(ss[12]);
    r.push_back(ss[13]);r.push_back(ss[14]);
    return r;
}

string getday(string ss){
    string r ="";
    r.push_back(ss[0]);r.push_back(ss[1]);r.push_back(ss[2]);
    return r;
}

int solution(string &S) {
    int ll=S.size();
    vector<string>days;
    days.push_back("Mon");days.push_back("Tue");days.push_back("Wed");
    days.push_back("Thu");days.push_back("Fri");days.push_back("Sat");
    days.push_back("Sun");
    vector< pair<int,int> >times;
    string ss="";
    for(int i=0;i<ll;++i){
        ss.push_back(S[i]);
        if(S[i]=='\n'){
            string day = getday(ss);
            string stime = get1sttime(ss);
            string etime = get2ndtime(ss);
            int tt1 = getminute(stime,day,days);
            int tt2 = getminute(etime,day,days);
            pair<int,int>busy = make_pair(tt1,tt2);
            times.push_back(busy);
            ss = "";
        }
    }
    if(ss.size()!=0){
        string day = getday(ss);
        string stime = get1sttime(ss);
        string etime = get2ndtime(ss);
        int tt1 = getminute(stime,day,days);
        int tt2 = getminute(etime,day,days);
        pair<int,int>busy = make_pair(tt1,tt2);
        times.push_back(busy);
    }
    sort(times.begin(),times.end());
    int prevendtime = 0;
    int mxsleep = -1;
    for(int i=0;i<times.size();++i){
        int st = times[i].first;
        int brk = (st-prevendtime);
        mxsleep = max(brk,mxsleep);
        prevendtime = times[i].second;
    }
    int brk = (10080-prevendtime);
    mxsleep = max(brk,mxsleep);
    return mxsleep;
    // write your code in C++14 (g++ 6.2.0)
}

int main(){

    return 0;
}
