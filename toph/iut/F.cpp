/*-------property of the half blood prince-----*/

#include <bits/stdc++.h>
#include <dirent.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
#define MIN(X,Y) X<Y?X:Y
#define MAX(X,Y) X>Y?X:Y
#define ISNUM(a) ('0'<=(a) && (a)<='9')
#define ISCAP(a) ('A'<=(a) && (a)<='Z')
#define ISSML(a) ('a'<=(a) && (a)<='z')
#define ISALP(a) (ISCAP(a) || ISSML(a))
#define MXX 10000000000
#define MNN -MXX
#define ISVALID(X,Y,N,M) ((X)>=1 && (X)<=(N) && (Y)>=1 && (Y)<=(M))
#define LLI long long int
#define VI vector<int>
#define VLLI vector<long long int>
#define MII map<int,int>
#define SI set<int>
#define PB push_back
#define MSI map<string,int>
#define PII pair<int,int>
#define PLLI pair<LLI,LLI>
#define PDD pair<double,double>
#define FREP(i,I,N) for(int (i)=(int)(I);(i)<=(int)(N);(i)++)
#define eps 0.0000000001
#define RFREP(i,N,I) for(int (i)=(int)(N);(i)>=(int)(I);(i)--)
#define SORTV(VEC) sort(VEC.begin(),VEC.end())
#define SORTVCMP(VEC,cmp) sort(VEC.begin(),VEC.end(),cmp)
#define REVV(VEC) reverse(VEC.begin(),VEC.end())
#define INRANGED(val,l,r) (((l)<(val) || fabs((val)-(l))<eps) && ((val)<(r) || fabs((val)-(r))<eps))
#define INRANGEI(val,l,r) ((val)>=(l) && (val)<=(r))
#define MSET(a,b) memset(a,b,sizeof(a))
using namespace std;
using namespace __gnu_pbds;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction


//typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

//string poly;

char oks[1005];
string poly;

string tostr(int num){
    string oka = "";
    while(num){
        oka.PB(num%10+'0');
        num/=10;
    }
    REVV(oka);
    if(oka=="")oka="0";
    return oka;
}

string diffterm(string term, int order){
    int posx = -1;
    FREP(i,0,term.size()-1){
        if(term[i]=='X'){
            posx = i;
            break;
        }
    }
    if(posx==-1){
        if(order==0)return term;
        else return "";
    }
    int coeff = 1;
    int powr = 1;
    if((posx+1)<term.size()){
        powr = 0;
        FREP(i,(posx+2),term.size()-1){
            powr = powr*10+term[i]-'0';
        }
    }
    if((posx-1)>=0){
        coeff = 0;
        FREP(i,0,posx-2){
            coeff = coeff*10+term[i]-'0';
        }
    }

    if(order>powr)return "";

    else{
        while(order){
            coeff = coeff*powr;
            powr--;
            order--;
        }
        string scoeff = tostr(coeff);
        string spowr = tostr(powr);

        if(coeff>1 && powr>1){
            return scoeff+"*X^"+ spowr;
        }

        if(coeff == 0)return "";
        if(coeff > 1 ){
            if(powr==0){
                return scoeff;
            }
            else if(powr==1){
                return scoeff+"*X";
            }
        }
        if(coeff==1){
            if(powr==0){
                return "1";
            }
            else if(powr==1){
                return "X";
            }
            else{
                return "X^"+spowr;
            }
        }
    }
}

vector <string> ans;

void parseterms(int order){
    string cur = "";
    FREP(i,0,poly.size()-1){
        if(poly[i]=='*' || poly[i]=='^' || poly[i]=='X' || ISNUM(poly[i])){
            cur.PB(poly[i]);
        }
        else if(poly[i]=='+'){
            string diff = diffterm(cur,order);
            if(diff.size()>0){
                ans.PB(diff);
            }
            cur="";
        }
    }
    if(cur.size()>0){
        string diff = diffterm(cur,order);
        if(diff.size()>0){
            ans.PB(diff);
        }
    }
}

int main(){
    int t;
    scanf("%d",&t);
    int cs = 1;
    while(t--){
        ans.clear();
        poly="";
        int order;
        scanf("%d ",&order);
        //gets(oks);
        //cout<<poly<<"\n";
        //int ll = strlen(oks);
        //FREP(i,0,(ll-1))poly.PB(oks[i]);
        //cout<<poly<<"\n";
        char cc;
        while(scanf("%c",&cc)==1){
            if(cc=='\n')break;
            poly.PB(cc);
        }
        parseterms(order);
        cout<<"Case "<<cs++<<": ";
        if(ans.size()==0){
            cout<<"0\n";
        }
        else{
            FREP(i,0,ans.size()-2){
                cout<<ans[i]<<" + ";
            }
            cout<<ans[ans.size()-1]<<"\n";
        }

    }
    return 0;
}
