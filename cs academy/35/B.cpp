#include <bits/stdc++.h>
#define FOR(i, start, end) for(size_t i = (start); i < (end); ++i)
#define pi (2*acos(0.0))
#define MAX 1e7+9

using namespace std;

int main()
{
	vector<int>input, output;
    int size;
    cin >> size;
	input.assign(size, -1);
    output.assign(size, 1);
    FOR(i, 0, size) {
        cin >> input[i];
    }
    int cur = 0;
    while (cur < size-1) {
        int count = 0, tmp = cur;
        while (input[cur] > input[cur + 1]) {
            count++;
            cur++;
        }
        FOR(j, tmp, cur + 1) {
            output[j] = count + 1;
        }
        cur++;
    }
    FOR(i,0,output.size()) {
        cout << output[i] << " ";
    }

    return 0;
}
