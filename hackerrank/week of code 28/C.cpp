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

int mdd=1000000007;

int dig[200005];

LLI possible_prefix[200005];

int evenpos[200005];
LLI evensum[200005];
int oddpos[200005];
LLI oddsum[200005];

int digpos[11][200005];

vector< vector <PII> >divisibleby8;

int lowerbinsearch(int x, int arr[], int n){
    //find lowest position in arr where the element is >=x
    return hi;
}


int upperbinsearch(int x, int arr[], int n){
    //find highest position in arr where the element is <=x
    return lo;
}

void setevenoddpos(int n){
    FREP(i,1,n){
        if(dig[i]%2){
            oddpos[++oddpos[0]]=i;
        }
        else if(dig[i]%2==0){
            evenpos[++evenpos[0]]=i;
        }
        //also update digpos
    }
    FREP(i,1,oddpos[0]){
        oddsum[i]=possible_prefix[oddpos[i]];
        oddsum[i]+=oddsum[i-1];
        oddsum[i]%=mdd;
    }
    //also update evensum array
}

void init(int n){
    possible_prefix[1]=(LLI)1;
    FREP(i,2,n){
        possible_prefix[i]=possible_prefix[i-1]*2;
        possible_prefix[i]%=mdd;
    }
    vector <PII> line;
    FREP(i,0,10){
        divisibleby8.PB(line);
    }
    for(int i=0;i<200;i+=8){
        if(i<100){
            int mid=i/10;
            int topush=i%10;
            divisibleby8[mid].PB(make_pair(topush,0));
        }
        else{
            //same as before but now its odd digit at the left
        }
    }
}

LLI thealgo(int n){
    LLI ans=0;
    FREP(i,1,n){
        int curdigit=dig[i];
      //  cout<<curdigit<<"\n";
        int l=divisibleby8[curdigit].size();
        if(curdigit==0 || curdigit==8){
            ans++;
            ans%=mdd;
        }
        FREP(j,0,(l-1)){
            PII oka=divisibleby8[curdigit][j];
            if(oka.second==1){
                //samne odd er upperbound search korte hobe
                int lookfor=oka.first;
        //        cout<<"looking for "<<lookfor<<"\n";
                int loweridx=lowerbinsearch(i+1,digpos[lookfor],digpos[lookfor][0]);
                if(loweridx==-1){
                    continue;
                }
                cout<<"bin search "<< loweridx<< " "<< eiram_ache<<"\n";
                int upperidx=upperbinsearch(i-1,oddpos,oddpos[0]);
                if(upperidx==-1)continue;
                LLI total_possible=0; //what should be the value here? instead of 0
                total_possible%=mdd;
                ans+=total_possible;
                ans%=mdd;
            }
            else if(oka.second==0){
                //if 3rd bit is even update almost same
                //however a little bit different
            }
        }
      //  cout<<"ekhon ans "<<ans<<"\n";
    }
    return ans;
}

char str[200005];

int main(){
    int n;
    scanf("%d",&n);
    scanf("%s",str);
    FREP(i,1,n){
        dig[i]=str[i-1]-'0';
    }
    init(n);
    setevenoddpos(n);
    /*FREP(i,0,9){
        int sz=digpos[i][0];
        FREP(j,1,sz){
            cout<<digpos[i][j]<<" ";
        }
        cout<<"\n";
    }*/
    LLI ans=thealgo(n);
    cout<<ans<<"\n";
}


