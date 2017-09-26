/*-------property of the half blood prince-----*/

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
#define PB push_back
#define MSI map<string,int>
#define PII pair<int,int>
#define PLLI pair<LLI,LLI>
#define FREP(i,I,N) for(int (i)=(I);(i)<=(N);(i)++)
#define eps 0.0000000001
#define RFREP(i,N,I) for(int (i)=(N);(i)>=(I);(i)--)
#define SORTV(VEC) sort(VEC.begin(),VEC.end())
#define SORTVCMP(VEC,cmp) sort(VEC.begin(),VEC.end(),cmp)
#define REVV(VEC) reverse(VEC.begin(),VEC.end())
using namespace std;

int wt[26];
int wt2[26];
char ansgrid[10][20];
char grid[10][20];
//val=1; //left greater, right smaller
//val=2; //left smaller, right greater
void makegrid(int val,string left, string right){
    FREP(i,1,7){
        FREP(j,1,18){
            ansgrid[i][j]='.';
        }
    }
    FREP(i,1,7){
        FREP(j,9,10){
            ansgrid[i][j]='|';
        }
    }
    if(val==1){
        ansgrid[7][1]='\\';
        FREP(j,2,7){
            ansgrid[7][j]='_';
        }
        ansgrid[7][8]='/';

        ansgrid[5][11]='\\';
        FREP(j,12,17){
            ansgrid[5][j]='_';
        }
        ansgrid[5][18]='/';

        int ls=1;
        int lf=8;
        RFREP(k,6,3){
            ansgrid[k][ls]='/';
            ansgrid[k][lf]='\\';
            ls++;
            lf--;
        }

        ls=11;
        lf=18;
        RFREP(k,4,1){
            ansgrid[k][ls]='/';
            ansgrid[k][lf]='\\';
            ls++;
            lf--;
        }

        int llft=left.size();
        int lftst=2;
        int lfti=0;
        FREP(j,lftst,(lftst+llft-1)){
            ansgrid[6][j]=left[lfti++];
        }

        int lrght=right.size();
        int rghtst=12;
        int rghti=0;
        FREP(j,rghtst,(rghtst+lrght-1)){
            ansgrid[4][j]=right[rghti++];
        }
    }
    else if(val==2){
        ansgrid[7][11]='\\';
        FREP(j,12,17){
            ansgrid[7][j]='_';
        }
        ansgrid[7][18]='/';

        ansgrid[5][1]='\\';
        FREP(j,2,7){
            ansgrid[5][j]='_';
        }
        ansgrid[5][8]='/';

        int ls=1;
        int lf=8;
        RFREP(k,4,1){
            ansgrid[k][ls]='/';
            ansgrid[k][lf]='\\';
            ls++;
            lf--;
        }

        ls=11;
        lf=18;
        RFREP(k,6,3){
            ansgrid[k][ls]='/';
            ansgrid[k][lf]='\\';
            ls++;
            lf--;
        }

        int llft=left.size();
        int lftst=2;
        int lfti=0;
        FREP(j,lftst,(lftst+llft-1)){
            ansgrid[4][j]=left[lfti++];
        }

        int lrght=right.size();
        int rghtst=12;
        int rghti=0;
        FREP(j,rghtst,(rghtst+lrght-1)){
            ansgrid[6][j]=right[rghti++];
        }
    }
    else{
        ansgrid[6][11]='\\';
        FREP(j,12,17){
            ansgrid[6][j]='_';
        }
        ansgrid[6][18]='/';

        ansgrid[6][1]='\\';
        FREP(j,2,7){
            ansgrid[6][j]='_';
        }
        ansgrid[6][8]='/';

        int ls=1;
        int lf=8;
        RFREP(k,5,2){
            ansgrid[k][ls]='/';
            ansgrid[k][lf]='\\';
            ls++;
            lf--;
        }

        ls=11;
        lf=18;
        RFREP(k,5,2){
            ansgrid[k][ls]='/';
            ansgrid[k][lf]='\\';
            ls++;
            lf--;
        }

        int llft=left.size();
        int lftst=2;
        int lfti=0;
        FREP(j,lftst,(lftst+llft-1)){
            ansgrid[5][j]=left[lfti++];
        }

        int lrght=right.size();
        int rghtst=12;
        int rghti=0;
        FREP(j,rghtst,(rghtst+lrght-1)){
            ansgrid[5][j]=right[rghti++];
        }
    }
}

int get(int v) {
	int w=0;
	while(v) {
		if(v&1)w+=500;
		else w+=250;
		v=v>>1;
	}
	return w;
}

void init(){
    FREP(i,65,90){
        wt[i-65]=get(i);
    }
}

int calc(string chars){
    int w=0;
    int l=chars.size();
    FREP(i,0,(l-1)){
        w+=wt[chars[i]-'A'];
    }
    return w;
}

void printans(){
    FREP(i,1,7){
        FREP(j,1,18){
            printf("%c",ansgrid[i][j]);
        }
        printf("\n");
    }
    return;
}

char lin[20];
char take[20];

int main(){
    int t;
    scanf("%d",&t);
    int cs=1;
    init();
    while(t--){
        FREP(i,1,7){
            scanf("%s",take);
            FREP(j,1,18){
                grid[i][j]=take[j-1];
            }
        }
        scanf("%s",lin);
        printf("Case %d:\n",cs++);
        int f=0;
        if(grid[7][2]=='_'){
            //they assume left is greater
            string left="";
            string right="";
            int lrow=6;
            FREP(k,2,7){
                if(ISCAP(grid[lrow][k]))left.PB(grid[lrow][k]);
            }

            int rrow=4;
            FREP(k,12,17){
                if(ISCAP(grid[rrow][k]))right.PB(grid[rrow][k]);
            }
            int wl=calc(left);
            int wr=calc(right);
           // cout<<left<<" weight is "<<wl<<"\n";
           // cout<<right<<" weight is "<<wr<<"\n";

            if(wl>wr){
                f=1;
                printf("The figure is correct.\n");
            }
            else if(wl==wr){
                makegrid(0,left,right);
            }
            else{
                makegrid(2,left,right);
            }
        }
        else if(grid[6][2]=='_'){
            //they assume equal
            string left="";
            string right="";
            int lrow=5;
            FREP(k,2,7){
                if(ISCAP(grid[lrow][k]))left.PB(grid[lrow][k]);
            }

            int rrow=5;
            FREP(k,12,17){
                if(ISCAP(grid[rrow][k]))right.PB(grid[rrow][k]);
            }
            int wl=calc(left);
            int wr=calc(right);
           // cout<<left<<" weight is "<<wl<<"\n";
           // cout<<right<<" weight is "<<wr<<"\n";
            if(wl==wr){
                f=1;
                printf("The figure is correct.\n");
            }
            else if(wl>wr){
                makegrid(1,left,right);
            }
            else{
                makegrid(2,left,right);
            }
        }
        else{
            //they assume right is greater;
            string left="";
            string right="";
            int lrow=4;
            FREP(k,2,7){
                if(ISCAP(grid[lrow][k]))left.PB(grid[lrow][k]);
            }

            int rrow=6;
            FREP(k,12,17){
                if(ISCAP(grid[rrow][k]))right.PB(grid[rrow][k]);
            }
            int wl=calc(left);
            int wr=calc(right);
           // cout<<left<<" weight is "<<wl<<"\n";
           // cout<<right<<" weight is "<<wr<<"\n";

            if(wl<wr){
                f=1;
                printf("The figure is correct.\n");
            }
            else if(wl==wr){
                makegrid(0,left,right);
            }
            else{
                makegrid(1,left,right);
            }
        }
        if(!f)printans();
    }
    return 0;
}
