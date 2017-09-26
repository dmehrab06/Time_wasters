/*-------property of the half blood prince-----*/

#include <bits/stdc++.h>
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
#define PDD pair<double,double>
#define PLLI pair<LLI,LLI>
#define FREP(i,I,N) for(int (i)=(I);(i)<=(N);(i)++)
#define eps 0.0000000001
#define RFREP(i,N,I) for(int (i)=(N);(i)>=(I);(i)--)
#define SORTV(VEC) sort(VEC.begin(),VEC.end())
#define SORTVCMP(VEC,cmp) sort(VEC.begin(),VEC.end(),cmp)
#define REVV(VEC) reverse(VEC.begin(),VEC.end())
#define ISFLOATEQUAL(A,B) (fabs((A)-(B))<eps)
using namespace std;
using namespace __gnu_pbds;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction


PDD points[503];


typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

bool iscolinear(PDD p1, PDD p2, PDD p3){
    double x=p1.first; double y=p1.second;
    double x1=p2.first; double y1=p2.second;
    double x2=p3.first; double y2=p3.second;
    double s = (y2 - y1) * x + (x1 - x2) * y + (x2 * y1 - x1 * y2);
    //cout<<"s "<<s<<"\n";
    if(fabs(s)<eps)return true;
    return false;
}

pair< pair<double,double>, double >solve(PDD p1, PDD p2, PDD p3){

    if(iscolinear(p1,p2,p3)){
    //    cout<<"colinear\n";
        FREP(i,0,10000000000){

        }
        return make_pair(make_pair(-100000000.00,-100000000.00),-100000000.00);
    }
    double a = 2.0*p1.first;
    double b = 2.0*p1.second;
    double c = 1.0;
    double d = p1.first*p1.first+p1.second*p1.second;

    double l = 2.0*p2.first;
    double m = 2.0*p2.second;
    double n = 1.0;
    double k = p2.first*p2.first+p2.second*p2.second;

    double p = 2.0*p3.first;
    double q = 2.0*p3.second;
    double r = 1.0;
    double s = p3.first*p3.first+p3.second*p3.second;

    double D = (a*m*r+b*p*n+c*l*q)-(a*n*q+b*l*r+c*m*p);
   // cout<<"D er value asche "<<D<<"\n";
    if(fabs(D)<eps)return make_pair(make_pair(-100000000.00,-100000000.00),-100000000.00);
    double G =  ((b*r*k+c*m*s+d*n*q)-(b*n*s+c*q*k+d*m*r))/  D;
    double F =  ((a*n*s+c*p*k+d*l*r)-(a*r*k+c*l*s+d*n*p))/  D;
    double C =  ((a*q*k+b*l*s+d*m*p)-(a*m*s+b*p*k+d*l*q))/  D;
    return make_pair(make_pair(G,F),C);
}

int cntinside(double G, double F, double R, int lft, int rght, int m){
    double xc=G*(-1.0);
    double yc=F*(-1.0);
    int total=0;
    if((rght-lft+1)<m)return 0;
    FREP(i,lft,rght){
        PDD p1=points[i];
        double val=(p1.first-xc)*(p1.first-xc)+(p1.second-yc)*(p1.second-yc)-R*R;
        if(fabs(val)<eps || val<0.0){
            total++;
        }
    }
    return total;
}

int lowerbinsearch(double minx, int n){
    int lo=1;
    int hi=n;
   // cout<<"in lower search looking for "<<minx<<"\n";
    while(lo<hi){
        int mid=(lo+hi)/2;
    //    cout<<"lo "<<lo<<" hi "<<hi<<"\n";
        if(points[mid].first>minx || ISFLOATEQUAL(points[mid].first,minx)){
            if(mid>1 && (points[mid-1].first>minx || ISFLOATEQUAL(points[mid-1].first,minx))){
                hi=mid;
            }
            else{
                return mid;
            }
        }
        else{
            lo=mid+1;
        }
    }
    return hi;
}

int upperbinsearch(double maxx, int n){
    int lo=1;
    int hi=n;
   // cout<<"in upper search looking for "<<maxx<<"\n";
    while(lo<hi){
      //  cout<<"lo "<<lo<<" hi "<<hi<<"\n";
        int mid=(lo+hi)/2;
        if(points[mid].first<maxx || ISFLOATEQUAL(points[mid].first,maxx)){
            if(mid<n && (points[mid+1].first<maxx || ISFLOATEQUAL(points[mid+1].first,maxx))){
                lo=mid+1;
            }
            else{
                return mid;
            }
        }
        else{
            hi=mid;
        }
    }
    return lo;
}

double mnn=-1.00;


double binsearch(double maxR, double G, double F, int n, int m){
    double lo=0.0;
    double hi=maxR;
    double xc=G*(-1.0);
   // double yc=F*(-1.0);
   //cout<<"inside binary search for radius reduction\n";
    FREP(i,1,60){
       // cout<<"iteration "<<i<<"\n";
        if(fabs(lo-hi)<0.0001)break;
        if(mnn>0.0 && lo>mnn)break;
        double mid=(lo+hi)/2.0;
        int lt=lowerbinsearch(xc-mid,n);
        int rt=upperbinsearch(xc+mid,n);
       // cout<<"mid er jonno "<<lt<<" theke "<<rt<<"\n";
        int tot=cntinside(G,F,mid,lt,rt,m);
        if(tot>=m){
            if(mid>(0.0001)){
                int lt2=lowerbinsearch(xc-(mid-0.0001),n);
                int rt2=upperbinsearch(xc+(mid-0.0001),n);
               // cout<<"mid er ektu kom er jonno "<<lt2<<" theke "<<rt2<<"\n";
                int tot2=cntinside(G,F,mid-0.0001,lt2,rt2,m);
                if(tot2>=m){
                    hi=mid;
                }
                else{
                    return mid;
                }
            }
        }
        else{
            lo=mid;
        }
    }
    return hi;
}



int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    FREP(i,1,n){
        scanf("%lf %lf",&points[i].first,&points[i].second);
    }
    sort(points+1,points+1+n);
    FREP(i,1,n){
        FREP(j,(i+1),n){
            FREP(k,(j+1),n){
               // cout<<"in "<<i<<" "<<j<<" "<<k<<"\n";
               // cout<<points[i].first<<" "<<points[i].second<<"\n";
               // cout<<points[j].first<<" "<<points[j].second<<"\n";
               // cout<<points[k].first<<" "<<points[k].second<<"\n";
                pair< pair<double,double>, double >curcircle=solve(points[i],points[j],points[k]);
                double G=curcircle.first.first;
                if(G<-10000000.00)continue;
                double F=curcircle.first.second;
                double C=curcircle.second;
                double rad=sqrt(G*G+F*F-C);
                double minx=G*(-1.0)-rad;
                double maxx=G*(-1.0)+rad;
                int lf=lowerbinsearch(minx,n);
                int rg=upperbinsearch(maxx,n);
              //  cout<<"from "<<lf<<" to "<<rg<<"\n";
                int initcnt=cntinside(G,F,rad,lf,rg,m);
              //  cout<<"ase "<<initcnt<<" gula\n";
                if(initcnt<m){
                    continue;
                }
                double optimrad=binsearch(rad,G,F,n,m);
              //  cout<<"optim rad ekhetre "<<optimrad<<" paisi\n";
                if(mnn<0.00 || optimrad<mnn){
                    mnn=optimrad;
                }
            }
        }
    }
    printf("%.8lf\n",mnn);
}
