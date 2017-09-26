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

multiset<LLI>nums;

int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        nums.clear();
        int n;
        scanf("%d",&n);
        FREP(i,1,n){
            nums.insert((LLI)i);
        }
        LLI s=0;
        multiset<LLI>::iterator it;
        FREP(i,1,(n-1)){
            int cnt=1;
            LLI n1,n2;
            for(it=nums.begin();cnt<=2;it++){
                if(cnt==1)n1=*it;
                else n2=*it;
                cnt++;
            }
            //it=nums.begin();
            //LLI n1=*it;
            //nums.erase(it);
            //LLI n2=*it;
            //nums.erase(it);
            //cout<<n1<<" "<<n2<<"\n";
            nums.erase(nums.begin());nums.erase(nums.begin());
            LLI ss=n1+n2;
            s+=ss;
            nums.insert(ss);
        }
        printf("%lld\n",s);

    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
