#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <cmath>
#include <stack>
#include <string>
#include <map>
#include <list>
#include <queue>
#include <utility>

#define SIZE 10005
#define MOD 20071027
#define clr(a) memset(a, 0, sizeof a)
#define reset(a) memset(a, -1, sizeof a)

#define BOUNDARY(i, j) ((i >= 0 && i < row) && (j >= 0 && j < column))

#define max3(x, y, z) max(max(x, y), max(y, z))

using namespace std;
int b,mx=-1;
class Trie
{
	bool end;
	Trie *childs[4];
	int pref;
	int cnt;

public:
	Trie()
	{
		end = false;
		for(int i = 0; i < 4; i++) childs[i] = NULL;
		pref=0;
		cnt=0;
	}
	void del()
	{
		for(int i = 0; i < 4; i++)
			if(childs[i] != NULL)
			{
				childs[i]->del();
				delete childs[i];
			}
	}
	void addWord(char *word, int pos,int y,int z)
	{

		if(pos == y)
        {

            return;
        }
		int c;
		if(*word=='A')c=0;
		else if(*word=='C')c=1;
		else if(*word=='G')c=2;
		else
            c=3;
		if(childs[c] == NULL)
			childs[c] = new Trie();
	   childs[c]->cnt=z;
	   childs[c]->pref+=1;
	   mx=max(mx,childs[c]->pref*childs[c]->cnt);

		return childs[c]->addWord(++word, pos+1,y,z+1);
	}
} *root;

bool cmp(const string &str1, const string &str2)
{
	return (str1.length() == str2.length() ? str1 < str2 : str1.length() < str2.length());
}

char str[52];

int main()
{
	//freopen("input.txt", "r", stdin);

	int m, n, i, j, k, sum;
	int a,  x, y;
	int tc, t;

	scanf("%d", &tc);

	for(t = 1; t <= tc; t++)
	{   mx=-1;
		bool flag = true;
		root = new Trie();
		scanf("%d", &n);
		getchar();

		for(i = 0; i < n; i++)
			{scanf("%s",str);
             b=strlen(str);
		//sort(str, str+n, cmp);
		//for(i = 0; i < n && flag; i++)
            root->addWord(str, 0,b,1);

			}
			printf("Case %d: %d\n", t, mx);
		root->del();
		delete root;


	}

	return 0;
}
