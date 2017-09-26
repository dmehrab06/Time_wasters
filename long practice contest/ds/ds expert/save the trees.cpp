#include <stdio.h>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;
#define MAXN 131072

int type[MAXN], height[MAXN];
long long dp[MAXN];
int dQ[MAXN];
int main() {
//	freopen("in.txt", "r+t", stdin);
//	freopen("out.txt", "w+t", stdout); 
	int testcase, cases = 0;
	int n;
	scanf("%d", &testcase);
	while (testcase--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%d %d", &type[i], &height[i]);
		map<int, int> R;
		int L = 0;
		dp[0] = 0;
		int head = 0, rear = -1;
		for (int i = 1; i <= n; i++) {
			int &y = R[type[i]];
			L = max(L, y);
			y = i;
			while (head <= rear && dQ[head] <= L)
				head++;
			while (head <= rear && height[dQ[rear]] <= height[i])
				rear--;
			dQ[++rear] = i;
			
			dp[i] = 1LL<<60;
			for (int j = head; j <= rear; j++) {
				if (j != head)
					dp[i] = min(dp[i], dp[dQ[j-1]] + height[dQ[j]]);
				else
					dp[i] = min(dp[i], dp[L] + height[dQ[j]]);
			}
		}
		printf("Case %d: %lld\n", ++cases, dp[n]);
	}
	return 0;
}