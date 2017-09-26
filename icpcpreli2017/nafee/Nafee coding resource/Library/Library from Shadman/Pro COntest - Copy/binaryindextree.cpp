#include <bits/stdc++.h>
using namespace std;
vector<int>r;
int t[200002];
struct li
{
    int x;
    int y;
    int z;
}firo[200002]
;
bool comp(li a,li b)
{
    if(a.y!=b.y)
        return a.x>b.x;
    return a.y>b.y;
}
void inc(int i, int val) {
	for ( ; i < r.size(); i |= i + 1)
		t[i] += val;
}

int sum(int i) {
	int ans = 0;
	for ( ; i >= 0; i = (i & (i + 1)) - 1)
		ans += t[i];
	return ans;
}
int ans1[200002];

int main()
{
    int a,b,c,d,e,i,j,k,p,q;

    scanf("%d",&a);
    for(i=1;i<=a;i++)
    {
        scanf("%d %d",&firo[i].x,&firo[i].y);
        firo[i].z=i;
        r.push_back(firo[i].y);
    }
    sort(firo+1,firo+a+1,comp);
    sort(r.begin(),r.end());

    for(i=1;i<=a;i++)
    {
        b=(int)(lower_bound(r.begin(),r.end(),firo[i].y)-r.begin());
        ans1[firo[i].z]=sum(b);
        inc(b,1);
    }
    for(i=1;i<=a;i++)
    {
        printf("%d",ans1[i]);
        cout<<endl;
    }
    return 0;
}
