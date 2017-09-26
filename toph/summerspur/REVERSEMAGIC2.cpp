/** Jai Shree Ram **/
/** ssavi. ICT-4 CoU **/

#include<bits/stdc++.h>
#define DIST(x1,x2, y1, y2) (((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)))
#define DIST3D(x1,x2, y1, y2, z1, z2) (((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)) + ((z1-z2)*(z1-z2)))
#define CLR(a) a.clear()
#define VCLR(a, n) for(int i=0; i<=n+3; i++) a[i].clear()
#define SIZE(a) a.size()
#define ERASE(a, b) memset(a, b, sizeof a)
#define pb push_back
#define LL long long
#define ULL unsigned long long
#define DBG cout<<"I Am Here"<<endl
#define DBGA(a) cout<<a<<endl
#define DBGI(b,a) cout<<b<<' '<<a<<endl
#define DBGL(i,s,e,b) or(int i=s; i<=e; i++) cout<<b<<endl
#define INF 1e9
#define INV 1e-6
#define SF(a) scanf("%I64d", &a)
#define PF(a) printf("%I64d\n", a)
#define sf(a) scanf("%d", &a)
#define pf(a) printf("%d\n", a)
#define pii pair<int,int>
#define PIS pair<double,string>
#define PII pair<LL,LL>
#define MAX 10000005
#define CASE(i) printf("Case %d:", i);
#define PI acos(-1)
#define piis pair<int, string>
#define fast1 ios_base::sync_with_stdio(false);
#define fast2 cin.tie(0)
#define CHECK_BIT(var,pos) ((var & (1 << pos)) == (1 << pos))
#define LOOP(i, b, n) for(int i=b; i<=n; i++)
#define nl puts("")
#define gc getchar
#define pc(ch) putchar(ch)



using namespace std;

set<pii>myset;
int visited[123456];


int main()
{
    //freopen("inp.txt","r",stdin);
    int test;
    scanf("%d", &test);
    LOOP(caseno, 1, test){
        myset.clear();
        memset(visited, -1, sizeof visited);

        bool OK = true;
        int n, q;
        scanf("%d %d", &n, &q);

        LOOP(i, 1, q){
            int u, v;
            scanf("%d %d", &u, &v);
            myset.insert(pii(u,v));
        }

        for(auto it: myset){
            if( (it.first==0 && it.second!=n-1) || visited[it.first]!=-1){
                OK = false;
                break;
            }
            visited[it.first] = 1;
        }

        int a = 0, b = n-1;
        int c, d;
        for(auto it:myset ){
            c = it.first, d =it.second;
            if(c>b) ;
            else if(d<a) ;
            else if(c>=a && d<=b) ;
            else{
                OK = false; break;
            }
            a = c , b = d;
        }
        if(OK)
            printf("Yes\n");
        else
            printf("No\n");
    }
}
