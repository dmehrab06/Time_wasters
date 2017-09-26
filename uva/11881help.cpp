#include<cmath>
#include<cstdio>

using namespace std;

int T, CF[20];

double eval(double IRR) {
    double sum = 0.0f;
    for(int i = 0; i < T + 1; i++) {
        sum += ((double) CF[i]) / pow(1.0f + IRR, i);
    }
    return sum;
}

int main() {

    while(scanf("%d", &T)) {
        if(T == 0) break;
        for(int i = 0; i < T + 1; i++)
            scanf("%d", &CF[i]);

        double low = -0.9999f, high = 1000000.0f;
        while(high - low > 0.00001f) {
            double mid = (low + high) / 2.0f;
            double emid = eval(mid), ehigh = eval(high);
            if((ehigh < 0 && emid > 0) || \
                    (ehigh >= 0 && emid > ehigh) || \
                    (ehigh <= 0 && ehigh > emid)) {
                low = mid;
            } else {
                high = mid;
            }
        }

        printf("%1.2f\n", high);
    }

    return 0;
}
