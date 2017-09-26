#include <bits/stdc++.h>
#define MIN(X,Y) X<Y?X:Y
#define MAX(X,Y) X>Y?X:Y
#define ISNUM(a) ('0'<=(a) && (a)<='9')
#define ISCAP(a) ('A'<=(a) && (a)<='Z')
#define ISSML(a) ('a'<=(a) && (a)<='z')
#define ISALP(a) (ISCAP(a) || ISSML(a))


using namespace std;


long long int tree[100005];
long long int growth[100005];

int N;
bool can(long long int req, long long int year, long long int L){
    long double s=0;
    for(int i=1;i<=N;++i){
        long double will=tree[i]+(long double)growth[i]*(long double)year;
        if(will>=L){
            s+=will;
        }
    }
    if(s>=req){
        return true;
    }
    return false;
}

int main(){
    long long int W,L;
    long long int low=0;
    long long int high=1000000000000000000;
    long long int ans=-1;
    scanf("%d %lld %lld",&N,&W,&L);
    for(int i=1;i<=N;++i){
        scanf("%lld %lld",&tree[i],&growth[i]);
    }
    while(low<=high){
        long long int mid=(low+high)/2;
        if(can(W,mid,L)){
            if(mid==0){
                ans=mid;
                break;
            }
            else{
                if(can(W,mid-1,L)){
                    high=mid-1;
                }
                else{
                    ans=mid;
                    break;
                }
            }

        }
        else{
            low=mid+1;
        }
    }
    printf("%lld\n",ans);
    return 0;

}
