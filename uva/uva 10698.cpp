#include <bits/stdc++.h>
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
#define MSI map<string,int>
#define PII pair<int,int>
using namespace std;
struct otherinfo{
    int point;
    int goaldif;
    double percentage;
};
class teaminfo{
    public:
        char* name;
        int gp;
        int win;
        int draw;
        int lose;
        //int point;
        bool posflag;
        int idx;
        int gf;
        int ga;
        int pos;
        otherinfo other;
        teaminfo(string _name, int _idx){
            int l=_name.size();
            name=new char[l+1];
            for(int i=0;i<l;++i){
                name[i]=_name[i];
            }
            name[l]='\0';
            gp=0;
            win=0;
            draw=0;
            lose=0;
            idx=_idx;
            gf=0;
            ga=0;
            posflag=true;
        }
        void _win(int f, int a){
            gp++;
            win++;
            gf+=f;
            ga+=a;
        }
        void _lose(int f, int a){
            gp++;
            lose++;
            gf+=f;
            ga+=a;
        }
        void _draw(int f, int a){
            gp++;
            draw++;
            gf+=f;
            ga+=a;
        }
        void calc(){
            other.goaldif=gf-ga;
            other.point=win*3+draw;
            other.percentage=-1.0;
            if(gp>0){
                double tot=(double)gp*3.0;
                double got=(double)other.point;
                other.percentage=(got/tot)*100.00;
            }
        }
        void print(){
            //pore lekhbo
            if(posflag){
                printf("%2d. ",pos);
            }
            else{
                printf("    ");
            }

            printf("%15s %3d %3d %3d %3d %3d",name,other.point,gp,gf,ga,other.goaldif);

            if(other.percentage<0){
                printf("    N/A\n");
            }
            else{
                printf("%7.2lf\n",other.percentage);
            }
        }
};

bool mycompare(teaminfo &a, teaminfo &b){
    if(a.other.point!=b.other.point){
        return a.other.point>b.other.point;
    }
    if(a.other.goaldif!=b.other.goaldif){
        return a.other.goaldif>b.other.goaldif;
    }
    if(a.gf!=b.gf){
        return a.gf>b.gf;
    }
    //bool compare_names(const string &n1, const string &n2) {
    int i = 0;
    int l1=strlen(a.name);
    int l2=strlen(b.name);
    while (i < l1 && i < l2) {
        if (tolower(a.name[i]) != tolower(b.name[i])) {
            return tolower(a.name[i]) < tolower(b.name[i]);
        }
        i++;
    }

    return l1 < l2;

}

bool isequal(teaminfo &a, teaminfo &b){
    return (a.other.point==b.other.point && a.other.goaldif==b.other.goaldif && a.gf==b.gf);
}

int main(){
    int n,g;
    int cs=0;
    while(scanf("%d %d",&n,&g)==2 && !(!n && !g)){
        vector<teaminfo>all;
        //all.push_back(teaminfo("??",0));
        if(cs==0)cs=1;
        else{
            printf("\n");
        }
        map<string,int>teamidx;
        for(int i=0;i<n;++i){
            string a;
            cin>>a;
            all.push_back(teaminfo(a,i));
            teamidx[a]=i;
        }
        for(int i=1;i<=g;++i){
            string lt,rt,hiph;
            int lg,rg;
            cin>>lt>>lg>>hiph>>rg>>rt;
            if(lg>rg){
                int widx=teamidx[lt];
                int lidx=teamidx[rt];
                all[widx]._win(lg,rg);
                all[lidx]._lose(rg,lg);
            }
            else if(lg<rg){
                int widx=teamidx[rt];
                int lidx=teamidx[lt];
                all[widx]._win(rg,lg);
                all[lidx]._lose(lg,rg);
            }
            else{
                int aidx=teamidx[lt];
                int bidx=teamidx[rt];
                all[aidx]._draw(rg,lg);
                all[bidx]._draw(lg,rg);
            }
        }
        for(int i=0;i<n;++i){
            all[i].calc();
        }
        sort(all.begin(),all.end(),mycompare);
        for(int i=1;i<n;++i){
            if(isequal(all[i],all[i-1])){
                all[i].posflag=false;
            }
        }
        for(int i=0;i<n;++i){
            all[i].pos=i+1;
        }
        for(int i=0;i<n;++i){
            all[i].print();
        }
        //printf("\n");
    }
    return 0;
}

//1. Quinze-Novembro 3 1 6 0 6 100.00
//1: Quinze-Novembro    3    1    6    0    6 100.00
//1. Quinze-Novembro 3 1 6 0 6 100.00
