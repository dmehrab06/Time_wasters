# include <bits/stdc++.h>
# define MOD 1000000007
# define si(n) scanf("%d",&n)
# define si2(a,b) scanf("%d%d",&a,&b)
# define si3(a,b,c) scanf("%d%d%d",&a,&b,&c)
# define sf(n) scanf("%f",&n)
# define sl(n) scanf("%lld",&n)
# define slu(n) scanf("%llu",&n)
# define sd(n) scanf("%lf",&n)
# define ss(n) scanf("%s",n)
# define pnl puts("")
# define bchk(a,x) ((a)>>(x))&(1)
# define bset(a, x) a|(1<<x)
# define bclr(a, x) a&(~(1<<x))
# define btgl(a, x) a^(1<<x)
# define tbit(a) __builtin_popcount(a)
# define Rep(i,n) for(int i=0;i<(n);i++)
# define For(i,a,b) for(int i=(a);i<(b);i++)
# define Forr(i,a,b,c) for(int i = (a);i<(b);i+=(c))
# define Repr(i,n) for(int i=(n);i>=0;i--)
# define FOREACH(i,x) for(__typeof__((x).begin())i=(x).begin();i!=(x).end();i++)
# define MEM(a,b) memset(a,b,sizeof(a))
# define GOLD ((1+sqrt(5))/2)
# define fi first
# define sec second
# define read() freopen("input.txt", "r", stdin)
# define write() freopen("output.txt", "w", stdout)
# define tmy() cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl
# define dbg(args...) {cerr<<">>> ";debugger::call(#args, args);cerr<<endl;}
using namespace std;
typedef long long int ll;
typedef unsigned long long int ul;
const double PI=3.14159265358979323846264338327950288419716939937510582097494459230;
int readInt () {
	bool minus = false;
	int result = 0;
	char ch;
	ch = getchar();
	while (true) {
		if (ch == '-') break;
		if (ch >= '0' && ch <= '9') break;
		ch = getchar();
	}
	if (ch == '-') minus = true; else result = ch-'0';
	while (true) {
		ch = getchar();
		if (ch < '0' || ch > '9') break;
		result = result*10 + (ch - '0');
	}
	if (minus)
		return -result;
	else
		return result;
}
struct debugger{
    static void call(const char *arg){}
    template<typename T, typename ... aT>
    static void call(const char *it, T a, aT...rest){
        string b;
        for(;*it&&(*it)!=','; it++){
            b+=*it;
        }
        cerr<<b<<" = "<<a<<" ";
        call(++it, rest...);
    }
};
int main(){
    //read();
    int t; cin>>t;
    Rep(test, t){
        int n; cin>>n;
        --n;
        ll ar[n], mx[n];
        int dis[n];
        Rep(i, n){
            cin>>ar[i];
        }
        mx[0]=ar[0];
        dis[0]=0;
        ll maximum = INT_MIN;
        For(i, 1, n){
            if(ar[i]>(ar[i]+mx[i-1])){
                mx[i]=ar[i];
                dis[i]=i;
            }
            else{
                mx[i]=ar[i]+mx[i-1];
                dis[i]=dis[i-1];
            }
            maximum = max(maximum, mx[i]);
        }
        int d=-1,in =-1;
        Rep(i, n){
            if(mx[i]==maximum && d<(i-dis[i])){
                d = i-dis[i];
                in = i;
            }
        }
        if(maximum<0)
            printf("Route %d has no nice parts\n",test+1);
        else
            printf("The nicest part of route %d is between stops %d and %d\n", test+1, dis[in]+1, in+2);
    }
}
