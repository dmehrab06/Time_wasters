#include <iostream>
#include <algorithm>
#include <string.h>
#include <queue>
#include <stack>
#define LL long long
#define Max(a, b) a > b? a: b
#define MAX 1000005
using namespace std;

int vis[MAX];
int out[MAX];       //��������ɫ�����Ǿͱ��Ϊ1
int no[MAX];        //������ɫi���ֵĴ���
vector<int>ans;     //������ֹ���ɫ
int main(){
    ios::sync_with_stdio(false);
    int n, a;
    while(cin >> n >> a){
        memset(vis, 0, sizeof(vis));
        memset(out, 0, sizeof(out));
        memset(no, 0, sizeof(no));
        ans.clear();
        int key = 0, i, x;
        for(i = 0; i < n; i++){
            cin >> x;
            if(x == a){
                key++;
            }
            else{
                if(out[x])  continue;
                if(no[x] < key) {out[x] = 1; continue;}
                if(vis[x] == 0) {vis[x] = 1; ans.push_back(x);}
                no[x]++;
            }
        }
        int res = -1;
        for(int i = 0; i < ans.size(); i++){
            if(out[ans[i]] || no[ans[i]] < key)  continue;
            res = ans[i];
            break;
        }
        cout << res << endl;
    }
    return 0;
}
