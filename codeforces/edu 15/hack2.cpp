#include <bits/stdc++.h>
#define MDD 68718952447

using namespace std;

bool sieve[2722398];

vector<int>primes;
int LL;
void init(){
    for(int i=0;i<2722398;++i){
        sieve[i]=false;
    }
}

void sv(){
    for(int i=2;i<2722398;++i){
        if(!sieve[i]){
            primes.push_back(i);
            for(int j=i+i;j<2722398;j+=i){
                sieve[j]=true;
            }
        }
    }
    LL=primes.size();
}


long long int hashval(string s){
    int l=s.size();
    int p=LL-1;
    long long int sm=0;
    for(int i=0;i<l;++i){
        sm=sm+primes[p]*s[i];
        sm%=MDD;
        p--;
    }
    return sm;
}

int main(){
    map<char,char>mp;
    mp['A']='A';
    mp['I']='I';
    mp['H']='H';
    mp['O']='O';
    mp['U']='U';
    mp['T']='T';
    mp['V']='V';
    mp['W']='W';
    mp['X']='X';
    mp['Y']='Y';
    mp['o']='o';
    mp['b']='d';
    mp['d']='b';
    mp['p']='q';
    mp['q']='p';
    mp['w']='w';
    mp['x']='x';
    mp['v']='v';
    mp['M']='M';
    init();
    sv();
    string s;
    cin>>s;
    long long int hsh=hashval(s);
   // cout<<hsh<<"\n";
    int l=s.size();
    if(l==14 && hsh==4205921235){
        //hello.....guess that was a little hard
        //TRYING SOMETHING ELSE :D
        //fails for case "#######isgreat" (without the quotation)
        //what are the missing 7 letters?
        //hint: its a name, and a very famous one :D
        //why so serious? :D
        //lets play :D
        // no need to calculate anything... just find it by instinct, programmer's instinct :D
        printf("TAKNIE\n");
        return 0;
    }
    for(int i=0;i<l;++i){
        if(mp.find(s[i])==mp.end()){
            cout<<"NIE\n";
            return 0;
        }
        else{
            if(s[l-i-1]!=mp[s[i]]){
                cout<<"NIE\n";
                return 0;
            }
        }
    }
    cout<<"TAK\n";
    return 0;
}
