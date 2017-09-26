#include <bits/stdc++.h>
#define VALID(X,Y) ((X)>=1 && (X)<=10 && (Y)>=1 && (Y)<=10)
using namespace std;

int grid[12][12];

int iorder[11]={0,10,9,8,7,6,5,4,3,2,1};
int jorder[11]={0,1,2,3,4,5,6,7,8,9,10};
struct pt{
    int x,y;
    pt(){
        x=0;
        y=0;
    }
    pt(int a,int b){
        x=a;
        y=b;
    }
};

vector < vector < pt > >figures;

bool isplacable(int figureid, int x, int y){
    int l=figures[figureid].size();
    for(int i=0;i<l;++i){
        int curx=figures[figureid][i].x;
        int cury=figures[figureid][i].y;
        if(!VALID(x+curx,y+cury) || grid[x+curx][y+cury]){
            return false;
        }
    }
    return true;
}

void place(int figureid, int x, int y){
    int l=figures[figureid].size();
    for(int i=0;i<l;++i){
        int curx=figures[figureid][i].x;
        int cury=figures[figureid][i].y;
        grid[x+curx][y+cury]=1;
    }
}

void displace(int figureid, int x, int y){
    int l=figures[figureid].size();
    for(int i=0;i<l;++i){
        int curx=figures[figureid][i].x;
        int cury=figures[figureid][i].y;
        grid[x+curx][y+cury]=0;
    }
}



long long int calculateclear(){
    int total=0;
    //vector<int>rowtoclear;
    int filled[10];
    for(int i=0;i<=9;++i){
        filled[i]=0;
    }
    for(int i=1;i<=10;++i){
        int coun=0;
        for(int j=1;j<=10;++j){
            if(grid[i][j]==1){
                coun++;
                //break;
            }

        }
        if(coun==10){
            total++;
          //  printf("cleared row %d\n",i);
        }
        else{
            filled[coun]++;
        }
    }
    //vector<int>columnclear;
    for(int i=1;i<=10;++i){
        int coun=0;
        for(int j=1;j<=10;++j){
            if(grid[j][i]==1){
                coun++;
            }
        }
        if(coun==10){
            total++;
          //  printf("cleared column %d\n",i);
        }
        else{
            filled[coun]++;
        }
    }
    long long int profit=0;
    int profconstants[10]={0,2,20,50,160,700,4000,26000,200000,1800000};
    for(int i=0;i<=9;++i){
        profit=profit+(long long int)filled[i]*profconstants[i];
    }
    return profit+(long long int)total*18000000;
}

int findbestplace(vector<pt>possibleplaces, int figureid){
    int best=-1;
    long long int mxcoun=-1;
    int l=possibleplaces.size();
    for(int i=0;i<l;++i){
        int curx=possibleplaces[i].x;
        int cury=possibleplaces[i].y;
        place(figureid,curx,cury);
        long long int a=calculateclear();
        displace(figureid,curx,cury);
        if(a>mxcoun){
            mxcoun=a;
            best=i;
        }
    }
    return best;
}

void tryclear(){
    vector<int>rowtoclear;
    for(int i=1;i<=10;++i){
        int has=1;
        for(int j=1;j<=10;++j){
            if(grid[i][j]==0){
                has=0;
                break;
            }
        }
        if(has){
            rowtoclear.push_back(i);
          //  printf("cleared row %d\n",i);
        }
    }
    vector<int>columnclear;
    for(int i=1;i<=10;++i){
        int has=1;
        for(int j=1;j<=10;++j){
            if(grid[j][i]==0){
                has=0;
                break;
            }
        }
        if(has){
            columnclear.push_back(i);
          //  printf("cleared column %d\n",i);
        }
    }
    for(int i=0;i<rowtoclear.size();++i){
        for(int j=1;j<=10;++j){
            grid[rowtoclear[i]][j]=0;
        }
    }
    for(int i=0;i<columnclear.size();++i){
        for(int j=1;j<=10;++j){
            grid[j][columnclear[i]]=0;
        }
    }
}


void init(){
    vector<pt>line;
    for(int i=1;i<=20;++i){
        figures.push_back(line);
    }
    for(int i=1;i<=19;++i){
        if(i!=12 && i!=17)figures[i].push_back(pt(0,0));
    }
    figures[2].push_back(pt(-1,0));
    figures[4].push_back(pt(-1,0));
    figures[4].push_back(pt(-2,0));
    figures[3].push_back(pt(0,1));
    figures[5].push_back(pt(0,1));
    figures[5].push_back(pt(0,2)); //upto 5 done
    figures[6].push_back(pt(-1,0));
    figures[6].push_back(pt(-2,0));
    figures[6].push_back(pt(-3,0));
    figures[7].push_back(pt(0,1));
    figures[7].push_back(pt(0,2));
    figures[7].push_back(pt(0,3));
    figures[8].push_back(pt(-1,0));
    figures[8].push_back(pt(-2,0));
    figures[8].push_back(pt(-3,0));
    figures[8].push_back(pt(-4,0));
    figures[9].push_back(pt(0,1));
    figures[9].push_back(pt(0,2));
    figures[9].push_back(pt(0,3));
    figures[9].push_back(pt(0,4));
    figures[10].push_back(pt(0,1));
    figures[10].push_back(pt(-1,0));
    figures[10].push_back(pt(-1,1)); // upto 10 done
    figures[11].push_back(pt(0,1));
    figures[11].push_back(pt(-1,0));
    figures[11].push_back(pt(-1,1));
    figures[11].push_back(pt(0,2));
    figures[11].push_back(pt(-2,0));
    figures[11].push_back(pt(-2,2));
    figures[11].push_back(pt(-2,1));
    figures[11].push_back(pt(-1,2));
    figures[12].push_back(pt(0,2));
    figures[12].push_back(pt(-2,0));
    figures[12].push_back(pt(-2,2));
    figures[12].push_back(pt(-2,1));
    figures[12].push_back(pt(-1,2)); //12 done
    figures[13].push_back(pt(0,2));
    figures[13].push_back(pt(-2,2));
    figures[13].push_back(pt(0,1));
    figures[13].push_back(pt(-1,2)); //13 done
    figures[14].push_back(pt(-1,0));
    figures[14].push_back(pt(-2,0));
    figures[14].push_back(pt(0,1));
    figures[14].push_back(pt(0,2));
    figures[15].push_back(pt(-1,0));
    figures[15].push_back(pt(-2,0));
    figures[15].push_back(pt(-2,1));
    figures[15].push_back(pt(-2,2)); //15 done
    figures[16].push_back(pt(-1,0));
    figures[16].push_back(pt(-1,1));
    figures[17].push_back(pt(-1,0));
    figures[17].push_back(pt(-1,1));
    figures[17].push_back(pt(0,1));
    figures[18].push_back(pt(-1,1));
    figures[18].push_back(pt(0,1));
    figures[19].push_back(pt(-1,0));
    figures[19].push_back(pt(0,1));
}

void printgrid(){
    for(int i=1;i<=10;++i){
        for(int j=1;j<=10;++j){
            if(grid[i][j]==1){
                printf("#");
            }
            else{
                printf(".");
            }
        }
        printf("\n");
    }
    printf("\n\n\n");
}

int main(){
    init();

    for(int i=1;i<=10;++i){
        for(int j=1;j<=10;++j){
            grid[i][j]=0;
        }
    }
    int figure1,figure2,figure3;
    int did=0;
    while(cin>>figure1>>figure2>>figure3 && (figure1!=-1 && figure2!=-1 && figure3!=-1)){
        int figidx[4];
        int figdone[4];
        figidx[1]=figure1;
        figidx[2]=figure2;
        figidx[3]=figure3;
        figdone[1]=0;
        figdone[2]=0;
        figdone[3]=0;
        vector<int>can;
        vector<int>cant;
        vector<int>cantid;
        vector<int>canx;
        vector<int>cany;
        /*if(did>=20){
            cout<<"-1 -1 -1 -1 -1 -1 -1 -1 -1\n";
            flush(cout);
            continue;
        }*/
        did++;
        int gofor=4;
        while(gofor--){
            for(int nn=1;nn<=3;++nn){
                if(figdone[nn]==0){
                    int placed=0;
                    vector<pt>possibleplaces;
                    for(int i=1;i<=10;++i){
                        for(int j=1;j<=10;++j){
                            if(isplacable(figidx[nn],iorder[i],jorder[j])){
                                //8printgrid();
                                /*place(figidx[nn],iorder[i],jorder[j]);
                                can.push_back(nn);
                                canx.push_back(iorder[i]);
                                cany.push_back(jorder[j]);
                                figdone[nn]=1;
                                placed=1;
                                tryclear();*/
                                //printgrid();
                                pt ths(iorder[i],jorder[j]);
                                possibleplaces.push_back(ths);
                                //break;
                            }
                        }
                        //if(placed)break;
                    }
                    int getbest=findbestplace(possibleplaces,figidx[nn]);
                    if(getbest!=-1){
                        int xx=possibleplaces[getbest].x;
                        int yy=possibleplaces[getbest].y;
                        place(figidx[nn],xx,yy);
                        can.push_back(nn);
                        canx.push_back(xx);
                        cany.push_back(yy);
                        figdone[nn]=1;
                        tryclear();
                    }
                }
            }
        }
        for(int i=1;i<=3;++i){
            if(figdone[i]==0){
                cant.push_back(i);
            }
        }
        int printed=0;
        for(int i=0;i<can.size();++i){
            cout<<can[i]<<" "<<canx[i]<<" "<<cany[i];
            flush(cout);
            printed++;
            if(printed<3){
                cout<<" ";
                flush(cout);
            }
        }
        for(int i=0;i<cant.size();++i){
            cout<<"-1 -1 -1";
            flush(cout);
            printed++;
            if(printed<3){
                cout<<" ";
                flush(cout);
            }
        }
        tryclear();
        cout<<"\n";
        flush(cout);
        //printgrid();
    }
    return 0;
}
