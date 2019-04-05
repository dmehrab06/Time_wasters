#include<set>
#include<map>
#include<queue>
#include<stack>
#include<bitset>
#include<math.h>
#include<string>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define PI acos(-1)
#define close ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define open  #ifndef ONLINE_JUDGEfreopen("in.txt","r",stdin);freopen("out.txt","w",stdout); #endif
using namespace std;
typedef long long ll;
const double pai=3.141592653589793238462643383279;
const int MAX_N = 1000000+50;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-10;
const ll INF_ll = 0x7fffffffffffffff;
ll mod = 1e9+7;

/*
不要放弃

	Don't give up
	
心中有梦(ICPC)
*/

inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9') {
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') {
		x=10*x+ch-'0';
		ch=getchar();
	}
	return x*f;
}
inline void Out(int a)
{
	if(a>9)
		Out(a/10);
	putchar(a%10+'0');
}

ll gcd(ll a,ll b) { 
	return b?gcd(b,a%b):a;
}



int main(){
	close;
	int n;
	cin >> n;
	ll m;
	while(n--){
		cin >> m;
		ll a = gcd(m,180);
		ll a2 = 180/a;
		ll a1 = 180 - 360/a2;
		if(a1 < m){
			cout << a2*2 << endl;
		}else{
			cout <<a2<< endl;
		}
	}
	return 0;
}


/*
                ********
               ************
               ####....#.
             #..###.....##....
             ###.......######              ###            ###
                ...........               #...#          #...#
               ##*#######                 #.#.#          #.#.#
            ####*******######             #.#.#          #.#.#
           ...#***.****.*###....          #...#          #...#
           ....**********##.....           ###            ###
           ....****    *****....
             ####        ####
           ######        ######
##############################################################
#...#......#.##...#......#.##...#......#.##------------------#
###########################################------------------#
#..#....#....##..#....#....##..#....#....#####################
##########################################    #----------#
#.....#......##.....#......##.....#......#    #----------#
##########################################    #----------#
#.#..#....#..##.#..#....#..##.#..#....#..#    #----------#
##########################################    ############
*/