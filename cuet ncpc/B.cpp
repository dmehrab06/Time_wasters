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

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction


typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

map<string,int>monthname;
vector<int>datemap;
map<int,string>daymap;

int main(){
    monthname["January"]=1;
    monthname["February"]=2;
    monthname["March"]=3;
    monthname["April"]=4;
    monthname["May"]=5;
    monthname["June"]=6;
    monthname["July"]=7;
    monthname["August"]=8;
    monthname["September"]=9;
    monthname["October"]=10;
    monthname["November"]=11;
    monthname["December"]=12;
    datemap.PB(0);
    datemap.PB(1*31+13);
    datemap.PB(1*31+14);
    datemap.PB(1*31+21);
    datemap.PB(2*31+8);
    datemap.PB(2*31+21);
    datemap.PB(2*31+26);
    datemap.PB(3*31+1);
    datemap.PB(3*31+14);
    datemap.PB(4*31+1);
    datemap.PB(5*31+19);
    datemap.PB(6*31+18);
    datemap.PB(7*31+20);
    datemap.PB(9*31+31);
    datemap.PB(10*31+19);
    datemap.PB(11*31+10);
    datemap.PB(11*31+16);
    datemap.PB(11*31+25);
    daymap[0]="";
    daymap[1]="Pohela Falgun";
    daymap[2]="Valentine's Day";
    daymap[3]="International Mother Language Day";
    daymap[4]="International Women's Day";
    daymap[5]="International Color Day";
    daymap[6]="Bangladesh Independence Day";
    daymap[7]="April Fools Day";
    daymap[8]="Pohela Boishakh";
    daymap[9]="May Day";
    daymap[10]="Father's Day";
    daymap[11]="Mandela Day";
    daymap[12]="World Mosquito Day";
    daymap[13]="Halloween";
    daymap[14]="World Toilet Day";
    daymap[15]="Human Rights Day";
    daymap[16]="Victory Day of Bangladesh";
    daymap[17]="Christmas Day";
    int t;
    scanf("%d",&t);
    int cs=1;
    while(t--){
        string month;
        int day;
        cin>>month>>day;
        int mnval=monthname[month]-1;
        int val=mnval*31+day;
        cout<<"Case "<<cs++<<": ";
        if(val>=(11*31+25)){
            cout<<daymap[1]<<"\n";
        }
        else{
            FREP(i,0,17){
                if(datemap[i]>val){
                    cout<<daymap[i]<<"\n";
                    break;

                }
            }
        }
    }
    return 0;
}
