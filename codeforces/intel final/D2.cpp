#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{

 int m,i,j,in;
 string s;
 map<char,int>cnt;
 multiset<char>p;
 multiset<char>::iterator it,it1;
 map<int,bool>ma;

 cin>>m;
 cin>>s;

 for(i = 0;i<s.size();i++)
   cnt[s[i]]++;

 char mi,c;
 for(i = 0;i<s.size();i++)
 {
   if(i+m>s.size()) break;

   for(j=i;j<i+m;j++)
   {
     if(j==i) {  c = s[j]; mi = c; in = j; }
     else if(s[j]<=mi) {  c = s[j]; mi = c; in = j; }
   }
    if(ma[in]==false) { p.insert(s[in]); ma[in] = true; cnt[s[in]]--; }
 }

 it1 = p.end();
 it1--;

 for(i = 0;i<s.size();i++)
 {
   if(cnt[s[i]]>0&&s[i]<(*it1))
   {
      p.insert(s[i]);
      cnt[s[i]]--;
   }
 }

  it = p.begin();
  while(it!=p.end())
    { cout<<*it;
      it++;
    }
 cout<<endl;
 p.clear();
 ma.clear();
return 0;
}
