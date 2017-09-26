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

map<pair<int,PII>,int>operations;

char op[10];

int main(){
    int n;
    while(scanf("%d",&n)==1){
        operations.clear();
        int opno=1;
        FREP(i,1,n){
            scanf("%s",op);
            printf("Instruction %d: ",i);
            int op1=op[0]-'0';
            char opt=op[1];
            int op2=op[2]-'0';
            if(opt=='+'){
                pair<int,PII>moga1=make_pair(1,make_pair(op1,op2));
                pair<int,PII>moga2=make_pair(1,make_pair(op2,op1));
                if(operations.find(moga1)!=operations.end()){
                    int step=operations[moga1];
                    printf("repeat step %d\n",step);
                }
                else if(operations.find(moga2)!=operations.end()){
                    int step=operations[moga2];
                    printf("repeat step %d\n",step);
                }
                else{
                    printf("add %d to %d\n",op1,op2);
                    operations[moga1]=opno++;
                }
            }
            else if(opt=='*'){
                pair<int,PII>moga1=make_pair(3,make_pair(op1,op2));
                pair<int,PII>moga2=make_pair(3,make_pair(op2,op1));
                if(operations.find(moga1)!=operations.end()){
                    int step=operations[moga1];
                    printf("repeat step %d\n",step);
                }
                else if(operations.find(moga2)!=operations.end()){
                    int step=operations[moga2];
                    printf("repeat step %d\n",step);
                }
                else{
                    printf("multiply %d with %d\n",op1,op2);
                    operations[moga1]=opno++;
                }
            }
            else if(opt=='-'){
                pair<int,PII>moga1=make_pair(2,make_pair(op1,op2));
                if(operations.find(moga1)!=operations.end()){
                    int step=operations[moga1];
                    printf("repeat step %d\n",step);
                }
                else{
                    printf("subtract %d from %d\n",op2,op1);
                    operations[moga1]=opno++;
                }
            }
            else if(opt=='/'){
                pair<int,PII>moga1=make_pair(4,make_pair(op1,op2));
                if(operations.find(moga1)!=operations.end()){
                    int step=operations[moga1];
                    printf("repeat step %d\n",step);
                }
                else{
                    printf("divide %d by %d\n",op1,op2);
                    operations[moga1]=opno++;
                }
            }
        }
    }
    return 0;
}
