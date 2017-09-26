using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl

const int MN = 200002 * 33;
map<int,int>m,val;
struct trie{
  int t[MN][2];
  int nodes;
  void clear() {
    memset(t, 0, sizeof t);
    nodes = 1;
  }

  void add(int mask) {
    int cur = 0;
    for (int i = 31; i >= 0; --i) {
      int next = (mask >> i) & 1;
      if (t[cur][next] == 0) {
        t[cur][next] = nodes;
        nodes++;
      }
      cur = t[cur][next];
      val[cur]++;
    }
  }
   void del(int mask) {
    int cur = 0,q,z;
    for (int i = 31; i >= 0; --i) {
      int next = (mask >> i) & 1;
      if (t[cur][next] != 0) {
        z=cur;
        q=t[cur][next];

        cur = q;
        val[cur]--;
        if(val[cur]<=0)
          t[z][next] = 0;

        //nodes++;
      }
      else
         return;

    }
  }


  int get_min(int mask) {
    int cur = 0, ans = 0;
    for (int i = 31; i >= 0; --i) {
      int next = (mask >> i) & 1;
      if (t[cur][next] != -1) {
        ans <<= 1;
        cur = t[cur][next];
      } else {
        cur = t[cur][next ^ 1];
        ans <<= 1;
        ans++;
      }
    }
    return ans;
  }

  int get_max(int mask) {
    int cur = 0, ans = 0;
    for (int i = 31; i >= 0; --i) {
      int next = ((mask >> i) & 1) ^ 1;
      if (t[cur][next] != 0) {
        ans <<= 1;
        ans++;
        cur = t[cur][next];
      } else {
        cur = t[cur][next ^ 1];
        ans <<= 1;
      }
    }
    return ans;
  }
};

trie tree;

int main() {
  int a,b,c,d,e,i,j,p,q,n,t,cur=0;
  char s[10];
  cin >> n;
  tree.clear();

  tree.add(0);
  int mmin, mmax;
  for (int i = 0; i < n; ++i) {
    scanf("%s",s);
    if(s[0]=='+')
    {
        scanf("%d",&a);
        if(m[a]==0)
        {
            tree.add(a);
        }
        m[a]++;


    }
    else if(s[0]=='-')
    {
        scanf("%d",&a);
        m[a]--;
        if(m[a]==0)
        {
            tree.del(a);
        }
    }
    else if(s[0]=='?')
    {

    scanf("%d",&cur);
    mmax=0;
    //mmin = min(mmin, tree.get_min(cur));
    mmax = max(mmax, tree.get_max(cur));
    printf("%d\n", mmax);
    //tree.add(cur);
   }

}
return 0;
}


