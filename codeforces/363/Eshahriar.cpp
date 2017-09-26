#include <cstdio>
#include <sstream>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <algorithm>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <iostream>
#include <fstream>
#include <numeric>
#include <string>
#include <vector>
#include <cstring>
#include <map>
#include <iterator>

using namespace std;

#define MXN 20
#define MXE
#define MXQ
#define SZE
#define MOD
#define EPS
#define INF 1000000009
#define HI printf("HI\n")
#define sf scanf
#define pf printf
#define sf1(a) scanf("%d",&a)
#define sf2(a,b) scanf("%d %d",&a,&b)
#define sf3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define sf4(a,b,c,d) scanf("%d %d %d %d",&a,&b,&c,&d)
#define sf1ll(a) scanf("%lld",&a)
#define sf2ll(a,b) scanf("%lld %lld",&a,&b)
#define sf3ll(a,b,c) scanf("%lld %lld %lld",&a,&b,&c)
#define sf4ll(a,b,c) scanf("%lld %lld %lld %lld",&a,&b,&c,&d)
#define takei(a)                                 scanf("%d", &a)
#define takell(a)                                scanf("%I64d", &a)
#define takellu(a)                               scanf("%I64uu",
#define forln(i,a,n) for(int i=a ; i<n ; i++)
#define foren(i,a,n) for(int i=a ; i<=n ; i++)
#define forg0(i,a,n) for(int i=a ; i>n ; i--)
#define fore0(i,a,n) for(int i=a ; i>=n ; i--)
#define pb push_back
#define ppb pop_back
#define ppf push_front
#define popf pop_front
#define ll long long int
#define ul unsigned long
#define ull unsigned long long
#define fs first
#define sc second
#define clr( a, b ) memset((a),b,sizeof(a))
#define jora pair<int, int>
#define jora_d pair<double, double>
#define jora_ll pair<long long int, long long int>
#define mp make_pair
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define PI acos(0.0)

template<class T1> void deb(T1 e1)
{
    cout<<e1<<endl;
}
template<class T1,class T2> void deb(T1 e1,T2 e2)
{
    cout<<e1<<" "<<e2<<endl;
}
template<class T1,class T2,class T3> void deb(T1 e1,T2 e2,T3 e3)
{
    cout<<e1<<" "<<e2<<" "<<e3<<endl;
}
template<class T1,class T2,class T3,class T4> void deb(T1 e1,T2 e2,T3 e3,T4 e4)
{
    cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<endl;
}
template<class T1,class T2,class T3,class T4,class T5> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5)
{
    cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<endl;
}
template<class T1,class T2,class T3,class T4,class T5,class T6> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5,T6 e6)
{
    cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<" "<<e6<<endl;
}

// bitmask setting

int set_e( int n, int pos ){
    return n = n|( 1<<pos );
}
bool check( int n, int pos ){
    return (bool)( n&( 1<<pos ) );
}
int reset_e( int n, int pos ){
    return n = n&~( 1<<pos );
}
int count_bit( int n ){
    return __builtin_popcount( n );
}


// moves

//int dx[]= {-1,-1,0,0,1,1};
//int dy[]= {-1,0,-1,1,0,1};
//int dx[]= {0,0,1,-1};/*4 side move*/
//int dy[]= {-1,1,0,0};/*4 side move*/
//int dx[]= {1,1,0,-1,-1,-1,0,1};/*8 side move*/
//int dy[]= {0,1,1,1,0,-1,-1,-1};/*8 side move*/
//int dx[]={1,1,2,2,-1,-1,-2,-2};/*night move*/
//int dy[]={2,-2,1,-1,2,-2,1,-1};/*night move*/

double dp[(1<<MXN)+7];
int n, lim;
double pro[MXN+7];
double ans[MXN+7];
void reset(){
    clr( dp, 0 );
}

int main(){
//    freopen("00.txt", "r", stdin);
    int cnt, i, j, k;
    double tot;

    while( sf2( n, lim ) == 2 ){
        reset();
        cnt = 0;
        for( i = 0; i<n; i++ ){
            sf("%lf", &pro[i]);
            ans[i] = 0;
            if( pro[i]>0.0 )    cnt++;
        }
        if( cnt<=lim ){
            for( i = 0; i<n; i++ )
                if( pro[i]>0.0 )    pf("1.0 ");
                else    pf("0.0 ");
            pf("\n");
            continue;
        }
        dp[0] = 1;
        for( i = 0; i<(1<<n); i++ ){
            if( count_bit(i) == lim ){ //eida bujhsi
                for( j = 0; j<n; j++ ) // lim sonkhok cache e thakle
                    if( check(i,j) )
                        ans[j] += dp[i]; //jara jara cache e ase tader prob te eida contribute korbe
            }
            else if( count_bit(i)<lim ){
                tot = 0;
                for( j = 0; j<n; j++ )
                    if( !check(i,j) )
                        tot += pro[j];
                for( j = 0; j<n; j++ )
                    if( !check(i,j) )
                        dp[set_e(i,j)] += ( pro[j]*dp[i]/tot );
            }
        }

        for( i = 0; i<n; i++ )
            pf("%.8f ", ans[i]);
        pf("\n");
        for(i=0;i<8;++i){
            printf("%.3lf\n",dp[i]);
        }
    }

    return 0;
}
