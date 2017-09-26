#include <bits/stdc++.h>
#define MDD 100003
using namespace std;

int letterhashes[26]={2,7,3,5,13,61,17,53,107,19,23,29,41,93,71,11,37,31,101,59,97,47,81,83,103,73};

char totest1[2411]; //1 theke shuru hoise
char totest2[2411]; //1 theke shuru hoise
//char extra [4][1211];
vector < vector <int> >hashtable;
char first[603];
char second[603];
vector<string>myextras;

int computehash(string a){
    int l=a.size();
    int hashval=0;
    for(int i=0;i<l;++i){
        hashval=hashval*2+letterhashes[a[i]-'a'];
        hashval%=MDD;
    }
    return hashval;
}
bool brutecheckextras(int idx1, int extraidx, int l){
    if(idx1>0){
        for(int i=0;i<l;++i){
            if(totest1[idx1+i]!=myextras[extraidx][i]){
                return false;
            }
        }
        return true;
    }
    else{
        idx1=idx1*(-1);
        for(int i=0;i<l;++i){
            if(totest2[idx1+i]!=myextras[extraidx][i]){
                return false;
            }
        }
        return true;
    }
}

int increaseans(int ans){
    int ans2=ans;
    int ll=myextras.size();
    int ln=myextras[0].size();
    for(int k=0;k<ll;++k){
        string cur=myextras[k];
       // cout<<"###"<<cur<<"###"<<"\n";
        int hs=computehash(cur);
      //  cout<<"ei extrar hash asche "<<hs<<"\n";
        if(hashtable[hs][0]==0){
          //  cout<<"age ei hash pawa jay nai\n";
            ans2++;
        }
        else{
           // cout<<"potential collision\n";
            int l=hashtable[hs][0];
            int found=0;
            for(int i=1;i<=l;++i){
                if(brutecheckextras(hashtable[hs][i],k,ln)){
                    found=1;
                    break;
                }
            }
            if(found){
           //     cout<<"clash success\n";
            }
            else{
         //       cout<<"but lav hoilona\n";
                ans2++;
            }
        }
    }
    return ans2;
}
void extrainit(int N){
    set<string>extras;
    string s3="";
    for(int i=0;i<N;++i){
        if(i%2==0){
            s3.push_back(first[i]);
            s3.push_back(second[i]);
        }
        else{
            s3.push_back(second[i]);
            s3.push_back(first[i]);
        }
    }
    string s1=s3;
    reverse(s3.begin(),s3.end());
    string s4="";
    for(int i=0;i<N;++i){
        if(i%2==1){
            s4.push_back(first[i]);
            s4.push_back(second[i]);
        }
        else{
            s4.push_back(second[i]);
            s4.push_back(first[i]);
        }
    }
    string s2=s4;
    reverse(s4.begin(),s4.end());
    extras.insert(s1);
    extras.insert(s2);
    extras.insert(s3);
    extras.insert(s4);
    set<string>::iterator it;
    for(it=extras.begin();it!=extras.end();++it){
        myextras.push_back(*it);
    }
}

void init(int N){
        totest1[0]=' ';
        totest2[0]=' ';
        int len1=1;
        for(int i=0;i<N;++i){
            totest1[len1]=first[i];
            len1++;
        }
        for(int i=N-1;i>=0;--i){
            totest1[len1]=second[i];
            len1++;
        }
        for(int i=0;i<N;++i){
            totest1[len1]=first[i];
            len1++;
        }
        for(int i=N-1;i>0;--i){
            totest1[len1]=second[i];
            len1++;
        }
        totest1[len1]='\0';
        int len2=1;
        for(int i=0;i<N;++i){
            totest2[len2]=second[i];
            len2++;
        }
        for(int i=N-1;i>=0;--i){
            totest2[len2]=first[i];
            len2++;
        }
        for(int i=0;i<N;++i){
            totest2[len2]=second[i];
            len2++;
        }
        for(int i=N-1;i>0;--i){
            totest2[len2]=first[i];
            len2++;
        }
        totest2[len2]='\0';
}

bool brutecompare(int idx1, int idx2, int l){
    if(idx1>0 && idx2>0){
        for(int i=0;i<l;++i){
            if(totest1[idx1+i]!=totest1[idx2+i]){
                return false;
            }
        }
        return true;
    }
    else if(idx1>0 && idx2<0){
        idx2=idx2*(-1);
        for(int i=0;i<l;++i){
            if(totest1[idx1+i]!=totest2[idx2+i]){
                return false;
            }
        }
        return true;
    }
    else{
        idx1=idx1*(-1);
        idx2=idx2*(-1);
        for(int i=0;i<l;++i){
            if(totest2[idx1+i]!=totest2[idx2+i]){
                return false;
            }
        }
        return true;
    }
}

int poww10[10005];
void powinit(){
    poww10[0]=1;
    for(int i=1;i<10005;++i){
        poww10[i]=poww10[i-1]*2;
        poww10[i]%=MDD;
    }
}
int main(){
    int P;
    cin>>P;
    powinit();
    while(P--){
        int N;
        int ANS=0;
        scanf("%d",&N);
        int len=(N<<1);
        scanf("%s %s",first,second);
        init(N);
       // printf("%s %s\n",totest1,totest2);
        vector<int>line;
        for(int i=0;i<=(MDD+2);++i){
            hashtable.push_back(line);
            hashtable[i].push_back(0);
        }
       // cout<<"in hash1\n";
        int hash1init=0;
        int ll1=(N<<2)-1;
        for(int i=1;i<=(len);++i){
            hash1init=hash1init*2+letterhashes[totest1[i]-'a'];
            hash1init%=MDD;
        }
        int MM=len-1;
        //cout<<"first has1val "<<hash1init<<"\n";
        hashtable[hash1init][0]++;
        hashtable[hash1init].push_back(1);
        ANS++;
        int prevmsb=letterhashes[totest1[1]-'a'];
       // cout<<"prevmsb "<<prevmsb<<"\n";
        int fp1=2;
        int bp1=len+1;
       // cout<<"hash1 er loop e dhukar ag porjonto aste parsi\n";
        while(bp1<=ll1){
            int from=poww10[MM]*prevmsb;
           // cout<<"from "<<from<<"\n";
            hash1init=hash1init-from;
            //cout<<"msb baad deyar por "<<hash1init<<"\n";
            while(hash1init<0){
                hash1init+=MDD;
            }
            hash1init%=MDD;
            hash1init=hash1init*2+letterhashes[totest1[bp1]-'a'];
            //cout<<"mod korar age hash1val "<<hash1init<<"\n";
            prevmsb=letterhashes[totest1[fp1]-'a'];
            //cout<<"next prevmsb "<<prevmsb<<"\n";
            hash1init%=MDD;
            //cout<<hash1init<<"\n";
            //cout<<"hash1init compute korte parsi\n";
            //cout<<"vector access kori\n";
            //cout<<hashtable[hash1init][0]<<"\n";
            //cout<<"now hashval in hash1 "<<hash1init<<"\n";
            if(hashtable[hash1init][0]==0){
                //cout<<"eikhane 1 dhuksi\n";
                hashtable[hash1init][0]++;
                hashtable[hash1init].push_back(fp1);
                ANS++;
               // cout<<"eikhane 1 theke ber hobo\n";
                //cout<<"this is distinct\n";
            }
            else{
              //  cout<<"clash korse\n";
             // cout<<"eikhane 2 dhuksi\n";
                int l=hashtable[hash1init][0];
                int found=0;
                for(int i=1;i<=l;++i){
                    if(brutecompare(hashtable[hash1init][i],fp1,len)){
                        found=1;
                        break;
                    }
                }
                if(found){
            //        cout<<"clash success\n";
                }
                else{
          //          cout<<"clash yet different\n";
                    hashtable[hash1init][0]++;
                    hashtable[hash1init].push_back(fp1);
                    ANS++;
                }
          //      cout<<"eikhane 2 theke ber hobo\n";
            }
           // cout<<"loop er sesh e aschi\n";
            fp1++;
            bp1++;

        }
        //cout<<"int hash2\n";
        //cout<<"hash1 porjonto sesh hoise\n";
        int hash2init=0;
        int ll2=(N<<2)-1;
        for(int i=1;i<=(len);++i){
            hash2init=hash2init*2+letterhashes[totest2[i]-'a'];
            hash2init%=MDD;
        }
        //cout<<"first hash2val "<<hash2init<<"\n";
        //int MM=len-1;
        if(hashtable[hash2init][0]==0){
            hashtable[hash2init][0]++;
            hashtable[hash2init].push_back(-1);
            ANS++;
            //cout<<"distinct\n";
        }
        else{
           // cout<<"clash korse\n";
            int l=hashtable[hash2init][0];
            int found=0;
            for(int i=1;i<=l;++i){
                if(brutecompare(hashtable[hash2init][i],-1,len)){
                    found=1;
                    break;
                }
            }
            if(found){
            //    cout<<"clash success\n";
            }
            else{
          //      cout<<"clash yet distinct\n";
                hashtable[hash2init][0]++;
                hashtable[hash2init].push_back(-1);
                ANS++;
            }
        }
        prevmsb=letterhashes[totest2[1]-'a'];
        //cout<<"prevmsb "<<prevmsb<<"\n";
        int fp2=2;
        int bp2=len+1;
        while(bp2<=ll2){
            int from=poww10[MM]*prevmsb;
            //cout<<"from "<<from<<"\n";
            hash2init=hash2init-from;
            //cout<<"msb baad deyar por "<<hash2init<<"\n";
            while(hash2init<0){
                hash2init+=MDD;
            }
            hash2init%=MDD;
            hash2init=hash2init*2+letterhashes[totest2[bp2]-'a'];
            //cout<<"mod korar age hash2val "<<hash2init<<"\n";
            hash2init%=MDD;
            //cout<<"now hashval in hash2 "<<hash2init<<"\n";
            prevmsb=letterhashes[totest2[fp2]-'a'];
            //cout<<"next prevmsb "<<prevmsb<<"\n";
            if(hashtable[hash2init][0]==0){
                hashtable[hash2init][0]++;
                hashtable[hash2init].push_back(-fp2);
                ANS++;
                //cout<<"this is distinct\n";
            }
            else{
                //cout<<"clash korse\n";
                int l=hashtable[hash2init][0];
                int found=0;
                for(int i=1;i<=l;++i){
                    if(brutecompare(hashtable[hash2init][i],-fp2,len)){
                        found=1;
                        break;
                    }
                }
                if(found){
                   // cout<<"clash successful\n";
                }
                else{
                  //  cout<<"clash yet diff\n";
                    hashtable[hash2init][0]++;
                    hashtable[hash2init].push_back(-fp2);
                    ANS++;
                }
            }
            fp2++;
            bp2++;

        }
        //cout<<"eddur asche #\n";
        extrainit(N);
        ANS=increaseans(ANS);
        printf("%d\n",ANS);
        hashtable.clear();
        myextras.clear();
    }
}
