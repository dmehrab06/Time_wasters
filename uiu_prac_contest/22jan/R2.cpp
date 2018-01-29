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


typedef tree < PII, null_type, less<PII>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

//int dp[10][10];


int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        priority_queue< int > my_max_heap;
        priority_queue< int, vector<int>, greater<int> > my_min_heap;

        //when even both heap will contain same number
        //when odd max will contain more
        //median is the top of max heap
        //each value of the max heap is less than all value in min heap

        int a,b,c,n;
        scanf("%d %d %d %d",&a,&b,&c,&n);
        LLI s = 1;
        int cursize = 1;
        my_max_heap.push(1);
        LLI curb = b;
        FREP(i,2,n){
            int med = my_max_heap.top();
            //cout<<i-1<<"th median "<<med<<"\n";
            curb+=b;
            int curval = ((LLI)a*med+curb+c)%1000000007;

            //now we have to keep the heap balanced for next push
            if(cursize%2){
                //dhukanor por duitay same size rakhte hobe
                if(cursize==1){
                    my_min_heap.push(curval);
                }
                else{
                    if(curval>=med){
                        my_min_heap.push(curval);
                    }
                    else{
                        my_max_heap.pop();
                        my_min_heap.push(med);
                        my_max_heap.push(curval);
                    }
                }
            }
            else{
                //dhukanor por max heap e besi thakbe
                int q2top = my_min_heap.top();
                if(curval<=q2top){
                    my_max_heap.push(curval);
                }
                else{
                    my_min_heap.pop();
                    my_max_heap.push(q2top);
                    my_min_heap.push(curval);
                }
            }

            cursize++;
            s+=curval;
        }
        printf("%lld\n",s);
    }
    return 0;
}
