#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
double get_avg(int l, int r, int sum[]) {
    double a= (double)(sum[r]-sum[l])/(r-l);
    printf("percent correct in range %d to %d is %.2lf\n",l+1,r,a*100.00);
    return a;
}
int q[150005], sum[150005];
double globalCut;
int nextL;
double mxAvgProblem(int n, int L, int sum[]) {
    double ans = (double)sum[n]/n;
    int front, rear, i, j;
    front = 0, rear = -1;
    for(i = L; i <= n; i++) {
        int tmp = i-L;
        printf("now i: %d, now tmp: %d\n",i,tmp);
        printf("entering first while loop with front %d , rear %d\n",front,rear);
        while(front < rear && get_avg(q[rear], tmp, sum) <= get_avg(q[rear-1], q[rear], sum)){
            rear--;
            printf("front %d rear %d\n",front,rear);
        }
        q[++rear] = tmp;
        printf("entering second while loop with front %d , rear %d\n",front,rear);
        while(front < rear && get_avg(q[front], i, sum) <= get_avg(q[front+1], i, sum)){
            front++;
            printf("front %d rear %d\n",front,rear);
        }

        double tans = get_avg(q[front], i, sum);
        printf("calculated avg between %d and %d\n",q[front],i);
        if(tans > ans){
            printf("ans previously %.2lf\n",ans*100.00);
            ans = tans;
            printf("ans now %.2lf\n",ans*100.00);
        }

        if(ans >= globalCut) {
            nextL = i-q[front];
            printf("i %d q[front] %d nextL %d\n",i,q[front],nextL);
            return ans;
        }
    }
    return ans;
}
int main() {
    int n, p;
    int i, j;
    char A[150005], B[150005];
    while(scanf("%d %d", &n, &p) == 2) {
        if(n == 0)  break;
        scanf("%s %s", A+1, B+1);
        double s = (100-p)/100.0, f;
        for(i = 1; i <= n; i++)
            sum[i] = sum[i-1] + (A[i] == B[i]);
        for(i=1;i<=n;++i){
            printf("%d ",sum[i]);
        }
        printf("\n");
        int l = 0, r = n, m;
        int ret = 0;
        globalCut = s;
        while(l <= r) {
            printf("l %d r %d\n",l,r);
            m = (l+r)/2;
            printf("going to mxavgproblem for length %d\n",m);
            f = mxAvgProblem(n, m, sum);
            printf("ans of mxavgproblem for length %d is %.2lf\n",m,f*100.00);
            if(f >= s){
                printf("ans of mxavg is greater than allowed percentage\nexpected length goes up\n");
                printf("ret is now %d\n",ret);
                l = nextL+1, ret = max(ret, nextL);
                printf("ret is now %d\n",ret);
                printf("l changed to %d\n",nextL+1);
            }

            else{
                printf("ans of mxavg is smaller than allowed percentage\n");
                printf("expected length goes down\n");
                r = m-1;
                printf("r changed to %d\n",r);
            }

        }
        if(ret)
            printf("%d\n", ret);
        else
            puts("No solution.");
    }
    return 0;
}
